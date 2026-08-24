/**
 * @file ha_control_select_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_select_private_gen.h"
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

void ha_control_select_constructor_hook(lv_obj_t * obj);
void ha_control_select_destructor_hook(lv_obj_t * obj);
void ha_control_select_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void ha_control_select_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_control_select_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_control_select_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t ha_control_select_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = ha_control_select_constructor,
    .destructor_cb = ha_control_select_destructor,
    .event_cb = ha_control_select_event,
    .instance_size = sizeof(ha_control_select_t),
    .editable = 1,
    .name = "ha_control_select"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * ha_control_select_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&ha_control_select_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void ha_control_select_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    ha_control_select_t * widget = (ha_control_select_t *)obj;
    static lv_style_t style_base;
    static lv_style_t style_row;
    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&style_row);

        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_height(&style_base, 40);
        lv_style_set_bg_opa(&style_base, (255 * 0 / 100));
        lv_style_set_pad_all(&style_base, 0);
        lv_style_set_border_width(&style_base, 0);
        lv_style_set_width(&style_row, lv_pct(100));
        lv_style_set_height(&style_row, lv_pct(100));
        lv_style_set_radius(&style_row, 10);
        lv_style_set_bg_color(&style_row, lv_color_hex(0x727272));
        lv_style_set_bg_opa(&style_row, (255 * 20 / 100));
        lv_style_set_pad_all(&style_row, 4);
        lv_style_set_layout(&style_row, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_row, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&style_row, 4);
        lv_style_set_pad_row(&style_row, 4);
        lv_style_set_clip_corner(&style_row, true);

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_set_name(obj, "main");
        lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_remove_style_all(obj);
        lv_obj_add_style(obj, &style_base, 0);
        lv_obj_t * row = lv_obj_create(obj);
        lv_obj_set_name(row, "row");
        lv_obj_set_flag(row, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->row = row;
        lv_obj_remove_style_all(row);
        lv_obj_add_style(row, &style_row, 0);

        the_root = obj;
    }
    #endif
    ha_control_select_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void ha_control_select_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    ha_control_select_destructor_hook(obj);
}

static void ha_control_select_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&ha_control_select_class, e);
    if(res != LV_RESULT_OK) return;

    ha_control_select_event_hook(e);
}

