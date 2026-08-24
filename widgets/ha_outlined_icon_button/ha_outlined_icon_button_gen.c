/**
 * @file ha_outlined_icon_button_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_outlined_icon_button_private_gen.h"
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

void ha_outlined_icon_button_constructor_hook(lv_obj_t * obj);
void ha_outlined_icon_button_destructor_hook(lv_obj_t * obj);
void ha_outlined_icon_button_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void ha_outlined_icon_button_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_outlined_icon_button_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_outlined_icon_button_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t ha_outlined_icon_button_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = ha_outlined_icon_button_constructor,
    .destructor_cb = ha_outlined_icon_button_destructor,
    .event_cb = ha_outlined_icon_button_event,
    .instance_size = sizeof(ha_outlined_icon_button_t),
    .editable = 1,
    .name = "ha_outlined_icon_button"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * ha_outlined_icon_button_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&ha_outlined_icon_button_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void ha_outlined_icon_button_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    ha_outlined_icon_button_t * widget = (ha_outlined_icon_button_t *)obj;
    static lv_style_t style_base;
    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);

        lv_style_set_radius(&style_base, 9999);
        lv_style_set_border_width(&style_base, 1);
        lv_style_set_border_color(&style_base, lv_color_hex(0x5e5e5e));
        lv_style_set_bg_opa(&style_base, (255 * 0 / 100));
        lv_style_set_pad_all(&style_base, 0);
        lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_width(&style_base, 48);
        lv_style_set_height(&style_base, 48);
        lv_style_set_clip_corner(&style_base, true);

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_set_name(obj, "main");
        lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(obj, LV_OBJ_FLAG_CLICKABLE, true);

        lv_obj_remove_style_all(obj);
        lv_obj_add_style(obj, &style_base, 0);
        lv_obj_t * ripple = ha_ripple_create(obj);
        lv_obj_set_name(ripple, "ripple");
        ha_ripple_set_p_color(ripple, lv_color_hex(0x5e5e5e));
        ha_ripple_set_p_pressed_opacity(ripple, 20);
        ha_ripple_set_p_radius(ripple, 9999);
        widget->ripple = ripple;

        lv_obj_t * icon = mdi_icon_create(obj);
        lv_obj_set_name(icon, "icon");
        mdi_icon_set_size(icon, 24);
        widget->icon = icon;

        the_root = obj;
    }
    #endif
    ha_outlined_icon_button_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void ha_outlined_icon_button_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    ha_outlined_icon_button_destructor_hook(obj);
}

static void ha_outlined_icon_button_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&ha_outlined_icon_button_class, e);
    if(res != LV_RESULT_OK) return;

    ha_outlined_icon_button_event_hook(e);
}

