/**
 * @file ha_control_slider_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_slider_private_gen.h"
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif
#include "../../demo3.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void ha_control_slider_constructor_hook(lv_obj_t * obj);
void ha_control_slider_destructor_hook(lv_obj_t * obj);
void ha_control_slider_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void ha_control_slider_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_control_slider_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_control_slider_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t ha_control_slider_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = ha_control_slider_constructor,
    .destructor_cb = ha_control_slider_destructor,
    .event_cb = ha_control_slider_event,
    .instance_size = sizeof(ha_control_slider_t),
    .editable = 1,
    .name = "ha_control_slider"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * ha_control_slider_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&ha_control_slider_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void ha_control_slider_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    ha_control_slider_t * widget = (ha_control_slider_t *)obj;
    static lv_style_t style_base;
    static lv_style_t style_tooltip;
    static lv_style_t style_touch_slider_main;
    static lv_style_t style_touch_slider_indicator;
    static lv_style_t style_touch_slider_knob;
    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&style_tooltip);
        lv_style_init(&style_touch_slider_main);
        lv_style_init(&style_touch_slider_indicator);
        lv_style_init(&style_touch_slider_knob);

        lv_style_set_width(&style_base, 240);
        lv_style_set_height(&style_base, 40);
        lv_style_set_bg_opa(&style_base, (255 * 0 / 100));
        lv_style_set_pad_all(&style_base, 0);
        lv_style_set_border_width(&style_base, 0);
        lv_style_set_bg_color(&style_tooltip, lv_color_hex(0xFFFFFF));
        lv_style_set_bg_opa(&style_tooltip, (255 * 100 / 100));
        lv_style_set_text_color(&style_tooltip, lv_color_hex(0x212121));
        lv_style_set_radius(&style_tooltip, 8);
        lv_style_set_pad_hor(&style_tooltip, 6);
        lv_style_set_pad_ver(&style_tooltip, 3);
        lv_style_set_shadow_width(&style_tooltip, 5);
        lv_style_set_shadow_opa(&style_tooltip, (255 * 20 / 100));
        lv_style_set_bg_opa(&style_touch_slider_main, (255 * 0 / 100));
        lv_style_set_border_opa(&style_touch_slider_main, (255 * 0 / 100));
        lv_style_set_bg_opa(&style_touch_slider_indicator, (255 * 0 / 100));
        lv_style_set_bg_opa(&style_touch_slider_knob, (255 * 0 / 100));

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE, true);

        lv_obj_remove_style_all(obj);
        lv_obj_add_style(obj, &style_base, 0);
        lv_obj_t * track = lv_obj_create(obj);
        lv_obj_set_name(track, "track");
        lv_obj_set_flag(track, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(track, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->track = track;
        lv_obj_remove_style_all(track);
        lv_obj_t * bar = lv_obj_create(track);
        lv_obj_set_name(bar, "bar");
        lv_obj_set_flag(bar, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(bar, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->bar = bar;
        lv_obj_remove_style_all(bar);
        lv_obj_t * handle = lv_obj_create(bar);
        lv_obj_set_name(handle, "handle");
        lv_obj_set_flag(handle, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(handle, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->handle = handle;
        lv_obj_remove_style_all(handle);

        lv_obj_t * cursor = lv_obj_create(track);
        lv_obj_set_name(cursor, "cursor");
        lv_obj_set_flag(cursor, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(cursor, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->cursor = cursor;
        lv_obj_remove_style_all(cursor);
        lv_obj_t * cursor_mark = lv_obj_create(cursor);
        lv_obj_set_name(cursor_mark, "cursor_mark");
        lv_obj_set_flag(cursor_mark, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(cursor_mark, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->cursor_mark = cursor_mark;
        lv_obj_remove_style_all(cursor_mark);

        lv_obj_t * tooltip = lv_label_create(obj);
        lv_obj_set_name(tooltip, "tooltip");
        lv_label_set_text(tooltip, "0");
        widget->tooltip = tooltip;
        lv_obj_add_style(tooltip, &style_tooltip, 0);

        lv_obj_t * touch_slider = lv_slider_create(obj);
        lv_obj_set_name(touch_slider, "touch_slider");
        lv_obj_set_ext_click_area(touch_slider, 8);
        widget->touch_slider = touch_slider;
        lv_obj_add_style(touch_slider, &style_touch_slider_main, LV_PART_MAIN);
        lv_obj_add_style(touch_slider, &style_touch_slider_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(touch_slider, &style_touch_slider_knob, LV_PART_KNOB);

        the_root = obj;
    }
    #endif
    ha_control_slider_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void ha_control_slider_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    ha_control_slider_destructor_hook(obj);
}

static void ha_control_slider_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&ha_control_slider_class, e);
    if(res != LV_RESULT_OK) return;

    ha_control_slider_event_hook(e);
}

