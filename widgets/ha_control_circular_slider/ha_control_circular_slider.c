/**
 * @file ha_control_circular_slider.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_circular_slider_gen.h"
#include "ha_control_circular_slider_private_gen.h"
#include "../../demo3.h"
#include "lvgl/src/core/lv_obj_event.h"
#include "lvgl/src/core/lv_obj_pos.h"
#include "lvgl/src/core/lv_obj_style.h"
#include "lvgl/src/core/lv_obj_style_gen.h"
#include "lvgl/src/misc/lv_color.h"
#include "lvgl/src/misc/lv_event.h"
#include "lvgl/src/indev/lv_indev.h"
#include "lvgl/src/widgets/arc/lv_arc.h"
#include "lvgl/src/widgets/label/lv_label.h"

/*********************
 *      DEFINES
 *********************/

#define HA_CIRCULAR_SLIDER_DEFAULT_SIZE 320
#define HA_CIRCULAR_SLIDER_MIN_SIZE     80
#define HA_CIRCULAR_SLIDER_LINE_WIDTH   24
#define HA_CIRCULAR_SLIDER_KNOB_SIZE    18
#define HA_CIRCULAR_SLIDER_EXT_CLICK    12

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static int32_t clamp_i32(int32_t value, int32_t min, int32_t max)
{
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
bool is_low_active(ha_control_circular_slider_t * root) 
{
    int32_t touch_value = lv_arc_get_value(root->touch_arc);
    int32_t cur_value = root->cur_value;
    return touch_value <= cur_value;
}

int32_t scale_dim(int32_t size, int32_t base)
{
    int32_t scaled = (size * base + HA_CIRCULAR_SLIDER_DEFAULT_SIZE / 2) / HA_CIRCULAR_SLIDER_DEFAULT_SIZE;
    return scaled < 1 ? 1 : scaled;
}

int32_t value_to_angle(const ha_control_circular_slider_t * state, int32_t value)
{
    int32_t range = state->max - state->min;
    if(range <= 0) return 0;

    value = clamp_i32(value, state->min, state->max);
    return ((value - state->min) * 270) / range;
}

int32_t point_to_value(const ha_control_circular_slider_t * state, lv_obj_t * arc, const lv_point_t * point)
{
    lv_area_t coords;
    lv_obj_get_coords(arc, &coords);
    lv_coord_t cx = coords.x1 + lv_area_get_width(&coords) / 2;
    lv_coord_t cy = coords.y1 + lv_area_get_height(&coords) / 2;
    lv_value_precise_t angle = lv_atan2(point->y - cy, point->x - cx);

    angle -= 135;
    while(angle < 0) angle += 360;
    while(angle >= 360) angle -= 360;
    if(angle > 270) {
        angle = angle > 315 ? 0 : 270;
    }

    int32_t range = state->max - state->min;
    if(range <= 0) return state->min;
    return state->min + ((int32_t)angle * range + 135) / 270;
}

int32_t snap_value_to_step(const ha_control_circular_slider_t * state, int32_t value, int32_t min, int32_t max)
{
    int32_t step = state->slider_step < 1 ? 1 : state->slider_step;
    value = clamp_i32(value, min, max);
    value = state->min + (((value - state->min) + step / 2) / step) * step;
    return clamp_i32(value, min, max);
}

void apply_dual_visibility(ha_control_circular_slider_t * root)
{
    if(root->dual) {
        lv_obj_remove_flag(root->high_arc, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(root->high_active_arc, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(root->high_dot_knob_arc, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(root->high_arc, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(root->high_active_arc, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(root->high_dot_knob_arc, LV_OBJ_FLAG_HIDDEN);
        ha_control_circular_slider_set_updating_high((lv_obj_t *)root, false);
    }
}

void apply_value_arc_range(ha_control_circular_slider_t * root)
{
    lv_obj_t * arcs[] = {
        root->cur_dot_knob_arc,
        root->low_dot_knob_arc,
        root->high_dot_knob_arc,
        root->touch_arc,
    };

    for(uint32_t i = 0; i < sizeof(arcs) / sizeof(arcs[0]); i++) {
        if(arcs[i] == NULL) continue;
        lv_arc_set_min_value(arcs[i], root->min);
        lv_arc_set_max_value(arcs[i], root->max);
    }
}

void apply_touch_arc_value(ha_control_circular_slider_t * root, int32_t value)
{
    lv_arc_set_value(root->touch_arc, clamp_i32(value, root->min, root->max));
}

void refresh_value_arcs(ha_control_circular_slider_t * root)
{
    int32_t c_angle = value_to_angle(root, root->cur_value);
    int32_t low_angle = value_to_angle(root, root->low_knob_value);
    int32_t high_angle = root->dual ? value_to_angle(root, root->high_knob_value) : 270;

    lv_arc_set_angles(root->low_arc, 0, clamp_i32(low_angle, 0, c_angle));
    if(root->low_knob_value <= root->cur_value) {
        lv_arc_set_angles(root->low_active_arc, 0, 0);
    } else {
        lv_arc_set_angles(root->low_active_arc, c_angle, clamp_i32(low_angle, c_angle, high_angle));
    }

    if(root->dual) {
        lv_arc_set_angles(root->high_arc, clamp_i32(high_angle, c_angle, 270), 270);
        if(root->high_knob_value > root->cur_value) {
            lv_arc_set_angles(root->high_active_arc, 0, 0);
        } else {
            lv_arc_set_angles(root->high_active_arc, clamp_i32(high_angle, low_angle, c_angle), c_angle);
        }
    }
}

void touch_event_cb(lv_event_t * e)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED) {
        int32_t t_value = lv_arc_get_value(root->touch_arc);
        lv_indev_t * indev = lv_indev_active();
        if(indev != NULL) {
            lv_point_t point;
            lv_indev_get_point(indev, &point);
            t_value = point_to_value(root, root->touch_arc, &point);
            t_value = clamp_i32(t_value, root->min, root->max);
        }
        int32_t low_distance = LV_ABS(t_value - root->low_knob_value);
        int32_t high_distance = LV_ABS(t_value - root->high_knob_value);
        bool choose_low;
        if(!root->dual) {
            choose_low = true;
        } else if(low_distance == high_distance) {
            choose_low = t_value < root->low_knob_value;
        } else {
            choose_low = low_distance < high_distance;
        }

        ha_control_circular_slider_set_updating_low((lv_obj_t *)root, choose_low);
        ha_control_circular_slider_set_updating_high((lv_obj_t *)root, !choose_low);
    } else if (code == LV_EVENT_VALUE_CHANGED) {
        int32_t t_value = lv_arc_get_value(root->touch_arc);       
        int32_t c_angle = value_to_angle(root, root->cur_value);
        ha_control_circular_slider_value_changed_event_t value_changed_event;
        bool value_changed = false;

        if (root->updating_low) {
            int32_t low_max = root->dual ? root->high_knob_value : root->max;
            t_value = snap_value_to_step(root, t_value, root->min, low_max);
            int32_t old_value = root->low_knob_value;
            int32_t t_angle = value_to_angle(root, t_value);
            int32_t high_knob_angle = root->dual ? value_to_angle(root, root->high_knob_value) : 270;

            ha_control_circular_slider_set_updating_low((lv_obj_t *)root, true);
            ha_control_circular_slider_set_low_knob_value((lv_obj_t *)root, t_value);
            apply_touch_arc_value(root, t_value);
            // low_arc
            lv_arc_set_angles(root->low_arc, 0, clamp_i32(t_angle, 0, c_angle));
            // low_active_arc
            if (t_value <= root->cur_value) {
                lv_arc_set_angles(root->low_active_arc, 0, 0);
            } else {
                lv_arc_set_angles(root->low_active_arc, c_angle, clamp_i32(t_angle, c_angle, high_knob_angle));
            }
            value_changed = old_value != t_value;
            value_changed_event.value = t_value;
            value_changed_event.is_low = true;
        } else if (root->dual && root->updating_high) {
            t_value = snap_value_to_step(root, t_value, root->low_knob_value, root->max);
            int32_t old_value = root->high_knob_value;
            int32_t t_angle = value_to_angle(root, t_value);
            int32_t low_knob_angle = value_to_angle(root, root->low_knob_value);

            ha_control_circular_slider_set_updating_high((lv_obj_t *)root, true);
            ha_control_circular_slider_set_high_knob_value((lv_obj_t *)root, t_value);
            apply_touch_arc_value(root, t_value);
            // high_arc
            lv_arc_set_angles(root->high_arc, clamp_i32(t_angle, c_angle, 270), 270);
            // high_active_arc
            if (t_value > root->cur_value) {
                lv_arc_set_angles(root->high_active_arc, 0, 0);
            } else {
                lv_arc_set_angles(root->high_active_arc, clamp_i32(t_angle, low_knob_angle, c_angle), c_angle);
            }
            value_changed = old_value != t_value;
            value_changed_event.value = t_value;
            value_changed_event.is_low = false;
        }
        if (lv_arc_get_value(root->low_dot_knob_arc) >= root->cur_value ||
            (root->dual && lv_arc_get_value(root->high_dot_knob_arc) <= root->cur_value)) {
            lv_obj_set_style_bg_opa(root->cur_dot_knob_arc, LV_OPA_30, LV_PART_KNOB);
        } else {
            lv_obj_set_style_bg_opa(root->cur_dot_knob_arc, LV_OPA_COVER, LV_PART_KNOB);
        }
        // char buf[64] = "";
        // lv_snprintf(buf, sizeof(buf), "%d, %d, %d", lv_arc_get_value(root->low_dot_knob_arc), t_value, lv_arc_get_value(root->high_dot_knob_arc));
        // lv_label_set_text(root->debug, buf);
        if(value_changed) {
            lv_obj_send_event((lv_obj_t *)root, LV_EVENT_VALUE_CHANGED, &value_changed_event);
        }
    } else if (code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
        ha_control_circular_slider_set_updating_low((lv_obj_t *)root, false);
        ha_control_circular_slider_set_updating_high((lv_obj_t *)root, false);
    }
}

void ha_control_circular_slider_constructor_hook(lv_obj_t * obj)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) obj;
    root->cur_value = lv_arc_get_value(root->cur_dot_knob_arc);
    root->low_knob_value = lv_arc_get_value(root->low_dot_knob_arc);
    root->high_knob_value = lv_arc_get_value(root->high_dot_knob_arc);
    root->min = 0;
    root->max = 100;
    apply_value_arc_range(root);
    root->low = root->min;
    root->high = root->max;
    root->slider_step = 1;
    lv_obj_add_event_cb(root->touch_arc, touch_event_cb, LV_EVENT_PRESSED,  root);
    lv_obj_add_event_cb(root->touch_arc, touch_event_cb, LV_EVENT_VALUE_CHANGED,  root);
    lv_obj_add_event_cb(root->touch_arc, touch_event_cb, LV_EVENT_RELEASED,  root);
    lv_obj_add_event_cb(root->touch_arc, touch_event_cb, LV_EVENT_PRESS_LOST,  root);
    lv_arc_set_change_rate(root->touch_arc, 36000);
    ha_control_circular_slider_set_size(obj, HA_CIRCULAR_SLIDER_DEFAULT_SIZE);
    root->dual = false;
    apply_dual_visibility(root);
}

void ha_control_circular_slider_destructor_hook(lv_obj_t * obj)
{

}

void ha_control_circular_slider_event_hook(lv_event_t * e)
{
    
}

int32_t ha_control_circular_slider_get_cur_value(lv_obj_t * ha_control_circular_slider)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    return root->cur_value;
}

int32_t ha_control_circular_slider_get_low_knob_value(lv_obj_t * ha_control_circular_slider)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    return root->low_knob_value;
}

int32_t ha_control_circular_slider_get_high_knob_value(lv_obj_t * ha_control_circular_slider)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    return root->high_knob_value;
}

void ha_control_circular_slider_set_cur_value(lv_obj_t * ha_control_circular_slider, int32_t cur_value)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->cur_value = clamp_i32(cur_value, root->min, root->max);
    lv_arc_set_value(root->cur_dot_knob_arc, root->cur_value);
    refresh_value_arcs(root);
}

void ha_control_circular_slider_set_low_knob_value(lv_obj_t * ha_control_circular_slider, int32_t low_knob_value)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->low_knob_value = clamp_i32(low_knob_value, root->min, root->max);
    lv_arc_set_value(root->low_dot_knob_arc, root->low_knob_value);
    refresh_value_arcs(root);
}

void ha_control_circular_slider_set_high_knob_value(lv_obj_t * ha_control_circular_slider, int32_t high_knob_value)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->high_knob_value = clamp_i32(high_knob_value, root->min, root->max);
    lv_arc_set_value(root->high_dot_knob_arc, root->high_knob_value);
    refresh_value_arcs(root);
}

void ha_control_circular_slider_set_low(lv_obj_t * ha_control_circular_slider, int32_t low)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->low = low;
}

void ha_control_circular_slider_set_high(lv_obj_t * ha_control_circular_slider, int32_t high)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->high = high;
}

void ha_control_circular_slider_set_dual(lv_obj_t * ha_control_circular_slider, bool dual)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->dual = dual;
    apply_dual_visibility(root);
}

void ha_control_circular_slider_set_min(lv_obj_t * ha_control_circular_slider, int32_t min)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    ha_control_circular_slider_set_range(ha_control_circular_slider, min, root->max);
}

void ha_control_circular_slider_set_max(lv_obj_t * ha_control_circular_slider, int32_t max)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    ha_control_circular_slider_set_range(ha_control_circular_slider, root->min, max);
}

void ha_control_circular_slider_set_range(lv_obj_t * ha_control_circular_slider, int32_t min, int32_t max)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    if(max < min) {
        int32_t tmp = min;
        min = max;
        max = tmp;
    }

    root->min = min;
    root->max = max;
    apply_value_arc_range(root);
    ha_control_circular_slider_set_low_knob_value(ha_control_circular_slider, root->low_knob_value);
    ha_control_circular_slider_set_high_knob_value(ha_control_circular_slider, root->high_knob_value);
}

void ha_control_circular_slider_set_step(lv_obj_t * ha_control_circular_slider, int32_t step)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->slider_step = step < 1 ? 1 : step;
}

void ha_control_circular_slider_set_size(lv_obj_t * ha_control_circular_slider, int32_t size)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    if(size < HA_CIRCULAR_SLIDER_MIN_SIZE) size = HA_CIRCULAR_SLIDER_MIN_SIZE;

    root->size = size;

    lv_obj_set_size(ha_control_circular_slider, size, size);

    int32_t line_width = scale_dim(size, HA_CIRCULAR_SLIDER_LINE_WIDTH);
    int32_t knob_size = scale_dim(size, HA_CIRCULAR_SLIDER_KNOB_SIZE);
    int32_t ext_click = scale_dim(size, HA_CIRCULAR_SLIDER_EXT_CLICK);

    lv_obj_t * arcs[] = {
        root->bg_arc,
        root->low_arc,
        root->low_active_arc,
        root->high_arc,
        root->high_active_arc,
        root->cur_dot_knob_arc,
        root->low_dot_knob_arc,
        root->high_dot_knob_arc,
        root->touch_arc,
    };

    for(uint32_t i = 0; i < sizeof(arcs) / sizeof(arcs[0]); i++) {
        if(arcs[i] == NULL) continue;
        lv_obj_set_size(arcs[i], size, size);
        lv_obj_center(arcs[i]);
        lv_obj_set_style_arc_width(arcs[i], line_width, LV_PART_MAIN);
        lv_obj_set_style_arc_width(arcs[i], line_width, LV_PART_INDICATOR);
        lv_obj_set_style_arc_rounded(arcs[i], true, LV_PART_MAIN);
        lv_obj_set_style_arc_rounded(arcs[i], true, LV_PART_INDICATOR);
    }

    lv_obj_set_style_width(root->cur_dot_knob_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_height(root->cur_dot_knob_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_width(root->low_dot_knob_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_height(root->low_dot_knob_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_width(root->high_dot_knob_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_height(root->high_dot_knob_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_width(root->touch_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_style_height(root->touch_arc, knob_size, LV_PART_KNOB);
    lv_obj_set_ext_click_area(root->touch_arc, ext_click);

    // lv_obj_center(root->debug);
}

void ha_control_circular_slider_set_updating_low(lv_obj_t * ha_control_circular_slider, bool updating_low)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->updating_low = updating_low;
}

void ha_control_circular_slider_set_updating_high(lv_obj_t * ha_control_circular_slider, bool updating_high)
{
    ha_control_circular_slider_t * root = (ha_control_circular_slider_t *) ha_control_circular_slider;
    root->updating_high = updating_high;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
