/**
 * @file ha_control_slider.c
 * User logic implementation for ha_control_slider widget in LVGL Pro.
 */

#include "ha_control_slider_private_gen.h"
#include "../../demo3.h"

#define HA_SLIDER_DEFAULT_LENGTH 240
#define HA_SLIDER_THICKNESS      40
#define HA_SLIDER_HANDLE_SIZE     4

static int32_t clamp_i32(int32_t value, int32_t min, int32_t max)
{
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

static int32_t snap_value(const ha_control_slider_t * slider, int32_t value)
{
    int32_t step = slider->step > 0 ? slider->step : 1;
    int32_t offset = value - slider->min;
    value = slider->min + ((offset + step / 2) / step) * step;
    return clamp_i32(value, slider->min, slider->max);
}

static int32_t visual_position(const ha_control_slider_t * slider, int32_t length)
{
    int32_t range = slider->max - slider->min;
    if(range <= 0) return 0;
    int32_t position = ((slider->value - slider->min) * length + range / 2) / range;
    if(slider->inverted) position = length - position;
    return clamp_i32(position, 0, length);
}

static void refresh_tooltip_text(ha_control_slider_t * slider)
{
    char text[48];
    lv_snprintf(text, sizeof(text), "%ld%s", (long)slider->value, slider->unit ? slider->unit : "");
    lv_label_set_text(slider->tooltip, text);
}

static void refresh_layout(lv_obj_t * obj)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    if(slider->touch_slider == NULL) return;
    lv_obj_update_layout(obj);

    int32_t width = lv_obj_get_content_width(obj);
    int32_t height = lv_obj_get_content_height(obj);
    if(width <= 0 || height <= 0) return;

    /* 1. Track setup - capsule shape container with clip_corner enabled */
    lv_obj_set_pos(slider->track, 0, 0);
    lv_obj_set_size(slider->track, width, height);
    lv_obj_set_style_bg_color(slider->track, slider->track_color, 0);
    lv_obj_set_style_bg_opa(slider->track, LV_OPA_20, 0);
    lv_obj_set_style_radius(slider->track, 12, 0);
    lv_obj_set_style_clip_corner(slider->track, true, 0);

    /* Reparent bar inside track for overflow clipping */
    if(lv_obj_get_parent(slider->bar) != slider->track) {
        lv_obj_set_parent(slider->bar, slider->track);
    }

    /* Reparent handle inside bar for smooth relative movement */
    if(lv_obj_get_parent(slider->handle) != slider->bar) {
        lv_obj_set_parent(slider->handle, slider->bar);
    }

    /* 2. Bar setup - fixed 100% full width and height */
    lv_obj_set_style_bg_color(slider->bar, slider->active_color, 0);
    lv_obj_set_style_bg_opa(slider->bar, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(slider->bar, 12, 0);

    /* 3. Handle setup */
    lv_obj_set_style_bg_color(slider->handle, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_bg_opa(slider->handle, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(slider->handle, HA_SLIDER_HANDLE_SIZE, 0);

    /* 4. Cursor setup */
    lv_obj_set_style_bg_color(slider->cursor, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_bg_opa(slider->cursor, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(slider->cursor, HA_SLIDER_HANDLE_SIZE, 0);
    lv_obj_set_style_shadow_width(slider->cursor, 5, 0);
    lv_obj_set_style_shadow_opa(slider->cursor, LV_OPA_20, 0);
    lv_obj_set_style_bg_color(slider->cursor_mark, lv_color_hex(0x727272), 0);
    lv_obj_set_style_bg_opa(slider->cursor_mark, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(slider->cursor_mark, HA_SLIDER_HANDLE_SIZE, 0);

    int32_t length = slider->vertical ? height : width;
    int32_t cross = slider->vertical ? width : height;
    int32_t handle_margin = cross / 8;

    if(slider->mode == HA_CONTROL_SLIDER_MODE_CURSOR) {
        lv_obj_add_flag(slider->bar, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(slider->handle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(slider->cursor, LV_OBJ_FLAG_HIDDEN);

        int32_t cursor_size = LV_MAX(HA_SLIDER_HANDLE_SIZE, cross / 4);
        int32_t position = visual_position(slider, LV_MAX(1, length - cursor_size));

        if(slider->vertical) {
            /* Vertical CURSOR mode: 0 at bottom, 100% at top */
            lv_obj_set_pos(slider->cursor, 0, height - cursor_size - position);
            lv_obj_set_size(slider->cursor, width, cursor_size);
            lv_obj_set_size(slider->cursor_mark, width / 2, HA_SLIDER_HANDLE_SIZE);
        } else {
            /* Horizontal CURSOR mode: 0 at left, 100% at right */
            lv_obj_set_pos(slider->cursor, position, 0);
            lv_obj_set_size(slider->cursor, cursor_size, height);
            lv_obj_set_size(slider->cursor_mark, HA_SLIDER_HANDLE_SIZE, height / 2);
        }
        lv_obj_center(slider->cursor_mark);
    } else {
        lv_obj_remove_flag(slider->bar, LV_OBJ_FLAG_HIDDEN);
        if(slider->show_handle) lv_obj_remove_flag(slider->handle, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(slider->handle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(slider->cursor, LV_OBJ_FLAG_HIDDEN);

        int32_t position = visual_position(slider, length);

        if(slider->vertical) {
            /* Vertical START/END mode: fixed 100% size bar translated vertically */
            lv_obj_set_size(slider->bar, width, height);
            if(slider->mode == HA_CONTROL_SLIDER_MODE_END) {
                /* END mode: filled from top down to position */
                lv_obj_set_pos(slider->bar, 0, -position);
                lv_obj_set_pos(slider->handle, width / 4, height - handle_margin - HA_SLIDER_HANDLE_SIZE);
            } else {
                /* START mode: filled from bottom up to position */
                lv_obj_set_pos(slider->bar, 0, height - position);
                lv_obj_set_pos(slider->handle, width / 4, handle_margin);
            }
            lv_obj_set_size(slider->handle, width / 2, HA_SLIDER_HANDLE_SIZE);
        } else {
            /* Horizontal START/END mode: fixed 100% size bar translated horizontally */
            lv_obj_set_size(slider->bar, width, height);
            if(slider->mode == HA_CONTROL_SLIDER_MODE_END) {
                /* END mode: filled from right to left */
                lv_obj_set_pos(slider->bar, position, 0);
                lv_obj_set_pos(slider->handle, handle_margin, height / 4);
            } else {
                /* START mode: filled from left to right */
                lv_obj_set_pos(slider->bar, position - width, 0);
                lv_obj_set_pos(slider->handle, width - handle_margin - HA_SLIDER_HANDLE_SIZE, height / 4);
            }
            lv_obj_set_size(slider->handle, HA_SLIDER_HANDLE_SIZE, height / 2);
        }
    }

    /* 5. Tooltip positioning */
    refresh_tooltip_text(slider);
    lv_obj_update_layout(slider->tooltip);
    int32_t tooltip_width = lv_obj_get_width(slider->tooltip);
    int32_t tooltip_height = lv_obj_get_height(slider->tooltip);
    if(slider->vertical) {
        int32_t y = height - visual_position(slider, height) - tooltip_height / 2;
        lv_obj_set_pos(slider->tooltip, -tooltip_width - 4,
                       clamp_i32(y, -tooltip_height / 2, height - tooltip_height / 2));
    } else {
        int32_t x = visual_position(slider, width) - tooltip_width / 2;
        lv_obj_set_pos(slider->tooltip,
                       clamp_i32(x, -tooltip_width / 2, width - tooltip_width / 2),
                       -tooltip_height - 4);
    }

    bool show_tooltip = slider->tooltip_mode == HA_CONTROL_SLIDER_TOOLTIP_ALWAYS ||
                        (slider->tooltip_mode == HA_CONTROL_SLIDER_TOOLTIP_INTERACTION && slider->pressed);
    if(show_tooltip) lv_obj_remove_flag(slider->tooltip, LV_OBJ_FLAG_HIDDEN);
    else lv_obj_add_flag(slider->tooltip, LV_OBJ_FLAG_HIDDEN);

    /* 6. Touch slider overlay */
    lv_obj_set_pos(slider->touch_slider, 0, 0);
    lv_obj_set_size(slider->touch_slider, width, height);
    lv_slider_set_orientation(slider->touch_slider,
                               slider->vertical ? LV_SLIDER_ORIENTATION_VERTICAL : LV_SLIDER_ORIENTATION_HORIZONTAL);
    lv_obj_move_to_index(slider->touch_slider, lv_obj_get_child_count(obj) - 1);
    lv_obj_move_to_index(slider->tooltip, lv_obj_get_child_count(obj) - 1);
}

static void touch_event_cb(lv_event_t * e)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_PRESSED) {
        slider->pressed = true;
        refresh_layout((lv_obj_t *)slider);
    } else if(code == LV_EVENT_VALUE_CHANGED) {
        int32_t input_value = lv_slider_get_value(slider->touch_slider);
        if(slider->inverted) input_value = slider->max - (input_value - slider->min);
        int32_t value = snap_value(slider, input_value);
        if(value != slider->value) {
            slider->value = value;
            refresh_layout((lv_obj_t *)slider);
            lv_obj_send_event((lv_obj_t *)slider, LV_EVENT_VALUE_CHANGED, &slider->value);
        }
    } else if(code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
        slider->pressed = false;
        refresh_layout((lv_obj_t *)slider);
    }
}

void ha_control_slider_constructor_hook(lv_obj_t * obj)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    slider->value = 0;
    slider->min = 0;
    slider->max = 100;
    slider->step = 1;
    slider->mode = HA_CONTROL_SLIDER_MODE_START;
    slider->tooltip_mode = HA_CONTROL_SLIDER_TOOLTIP_INTERACTION;
    slider->vertical = false;
    slider->show_handle = true;
    slider->inverted = false;
    slider->disabled = false;
    slider->pressed = false;
    slider->unit = "";
    slider->track_color = lv_color_hex(0x9E9E9E);
    slider->active_color = lv_color_hex(0x03A9F4);

    lv_slider_set_range(slider->touch_slider, slider->min, slider->max);
    lv_slider_set_value(slider->touch_slider, slider->value, LV_ANIM_OFF);
    lv_obj_add_event_cb(slider->touch_slider, touch_event_cb, LV_EVENT_PRESSED, slider);
    lv_obj_add_event_cb(slider->touch_slider, touch_event_cb, LV_EVENT_VALUE_CHANGED, slider);
    lv_obj_add_event_cb(slider->touch_slider, touch_event_cb, LV_EVENT_RELEASED, slider);
    lv_obj_add_event_cb(slider->touch_slider, touch_event_cb, LV_EVENT_PRESS_LOST, slider);
    refresh_layout(obj);
}

void ha_control_slider_destructor_hook(lv_obj_t * obj)
{
    LV_UNUSED(obj);
}

void ha_control_slider_event_hook(lv_event_t * e)
{
    if(lv_event_get_code(e) == LV_EVENT_SIZE_CHANGED) refresh_layout(lv_event_get_target_obj(e));
}

int32_t ha_control_slider_get_value(lv_obj_t * obj)
{
    return ((ha_control_slider_t *)obj)->value;
}

void ha_control_slider_set_value(lv_obj_t * obj, int32_t value)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    slider->value = snap_value(slider, value);
    int32_t input_value = slider->inverted ? slider->max - (slider->value - slider->min) : slider->value;
    lv_slider_set_value(slider->touch_slider, input_value, LV_ANIM_OFF);
    refresh_layout(obj);
}

void ha_control_slider_set_range(lv_obj_t * obj, int32_t min, int32_t max)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    if(max < min) {
        int32_t swap = min;
        min = max;
        max = swap;
    }
    if(max == min) max = min + 1;
    slider->min = min;
    slider->max = max;
    lv_slider_set_range(slider->touch_slider, min, max);
    ha_control_slider_set_value(obj, slider->value);
}

void ha_control_slider_set_min(lv_obj_t * obj, int32_t min)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    ha_control_slider_set_range(obj, min, slider->max);
}

void ha_control_slider_set_max(lv_obj_t * obj, int32_t max)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    ha_control_slider_set_range(obj, slider->min, max);
}

void ha_control_slider_set_step(lv_obj_t * obj, int32_t step)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    slider->step = step > 0 ? step : 1;
    ha_control_slider_set_value(obj, slider->value);
}

void ha_control_slider_set_mode(lv_obj_t * obj, ha_control_slider_mode_t mode)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    slider->mode = mode;
    refresh_layout(obj);
}

void ha_control_slider_set_vertical(lv_obj_t * obj, bool vertical)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    if(slider->vertical == vertical) return;
    slider->vertical = vertical;
    lv_obj_set_size(obj, vertical ? HA_SLIDER_THICKNESS : HA_SLIDER_DEFAULT_LENGTH,
                    vertical ? HA_SLIDER_DEFAULT_LENGTH : HA_SLIDER_THICKNESS);
    refresh_layout(obj);
}

void ha_control_slider_set_show_handle(lv_obj_t * obj, bool show_handle)
{
    ((ha_control_slider_t *)obj)->show_handle = show_handle;
    refresh_layout(obj);
}

void ha_control_slider_set_inverted(lv_obj_t * obj, bool inverted)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    slider->inverted = inverted;
    ha_control_slider_set_value(obj, slider->value);
}

void ha_control_slider_set_disabled(lv_obj_t * obj, bool disabled)
{
    ha_control_slider_t * slider = (ha_control_slider_t *)obj;
    slider->disabled = disabled;
    if(disabled) lv_obj_add_state(slider->touch_slider, LV_STATE_DISABLED);
    else lv_obj_remove_state(slider->touch_slider, LV_STATE_DISABLED);
}

void ha_control_slider_set_tooltip_mode(lv_obj_t * obj, ha_control_slider_tooltip_mode_t mode)
{
    ((ha_control_slider_t *)obj)->tooltip_mode = mode;
    refresh_layout(obj);
}

void ha_control_slider_set_unit(lv_obj_t * obj, const char * unit)
{
    ((ha_control_slider_t *)obj)->unit = unit ? unit : "";
    refresh_layout(obj);
}

void ha_control_slider_set_track_color(lv_obj_t * obj, lv_color_t color)
{
    ((ha_control_slider_t *)obj)->track_color = color;
    refresh_layout(obj);
}

void ha_control_slider_set_active_color(lv_obj_t * obj, lv_color_t color)
{
    ((ha_control_slider_t *)obj)->active_color = color;
    refresh_layout(obj);
}