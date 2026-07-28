/**
 * @file hui_heading_badge_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_badge_private_gen.h"
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

void hui_heading_badge_constructor_hook(lv_obj_t * obj);
void hui_heading_badge_destructor_hook(lv_obj_t * obj);
void hui_heading_badge_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void hui_heading_badge_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void hui_heading_badge_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void hui_heading_badge_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t hui_heading_badge_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = hui_heading_badge_constructor,
    .destructor_cb = hui_heading_badge_destructor,
    .event_cb = hui_heading_badge_event,
    .instance_size = sizeof(hui_heading_badge_t),
    .editable = 1,
    .name = "hui_heading_badge"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * hui_heading_badge_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&hui_heading_badge_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void hui_heading_badge_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    hui_heading_badge_t * widget = (hui_heading_badge_t *)obj;
    static lv_style_t style_base;
    static lv_style_t button_style;
    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&button_style);

        lv_style_set_bg_opa(&style_base, (255 * 0 / 100));
        lv_style_set_border_width(&style_base, 0);
        lv_style_set_border_opa(&style_base, 0);
        lv_style_set_pad_all(&style_base, 0);
        lv_style_set_pad_row(&style_base, 8);
        lv_style_set_pad_column(&style_base, 3);
        lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_width(&style_base, LV_SIZE_CONTENT);
        lv_style_set_height(&style_base, 26);
        lv_style_set_bg_color(&style_base, lv_color_hex(0x6080e0));
        lv_style_set_bg_color(&button_style, lv_color_hex(0x5e5e5e));
        lv_style_set_bg_opa(&button_style, (255 * 50 / 100));
        lv_style_set_radius(&button_style, 9999);
        lv_style_set_pad_right(&button_style, 8);
        lv_style_set_pad_left(&button_style, 8);

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_set_name(obj, "main");

        lv_obj_add_style(obj, &style_base, 0);
        lv_obj_add_style(obj, &button_style, 0);
        lv_obj_t * ripple = ha_ripple_create(obj);
        lv_obj_set_name(ripple, "ripple");
        ha_ripple_set_p_pressed_opacity(ripple, 15);
        ha_ripple_set_p_radius(ripple, 12);
        widget->ripple = ripple;

        lv_obj_t * label_icon = lv_label_create(obj);
        lv_obj_set_name(label_icon, "label_icon");
        lv_label_set_text(label_icon, "");
        lv_obj_set_style_text_font(label_icon, mdi_icon_font16_4, 0);
        widget->label_icon = label_icon;

        lv_obj_t * label_text = lv_label_create(obj);
        lv_obj_set_name(label_text, "label_text");
        lv_label_set_text(label_text, "");
        lv_obj_set_style_text_font(label_text, roboto_regular_12_4, 0);
        widget->label_text = label_text;

        the_root = obj;
    }
    #endif
    hui_heading_badge_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void hui_heading_badge_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    hui_heading_badge_destructor_hook(obj);
}

static void hui_heading_badge_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&hui_heading_badge_class, e);
    if(res != LV_RESULT_OK) return;

    hui_heading_badge_event_hook(e);
}

