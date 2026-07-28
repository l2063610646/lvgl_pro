/**
 * @file ha_heading_card_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_heading_card_private_gen.h"
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

void ha_heading_card_constructor_hook(lv_obj_t * obj);
void ha_heading_card_destructor_hook(lv_obj_t * obj);
void ha_heading_card_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void ha_heading_card_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_heading_card_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void ha_heading_card_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t ha_heading_card_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = ha_heading_card_constructor,
    .destructor_cb = ha_heading_card_destructor,
    .event_cb = ha_heading_card_event,
    .instance_size = sizeof(ha_heading_card_t),
    .editable = 1,
    .name = "ha_heading_card"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * ha_heading_card_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&ha_heading_card_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void ha_heading_card_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    ha_heading_card_t * widget = (ha_heading_card_t *)obj;

    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_set_width(obj, lv_pct(100));
        lv_obj_set_height(obj, LV_SIZE_CONTENT);
        lv_obj_set_style_pad_all(obj, 0, 0);
        lv_obj_set_style_border_width(obj, 0, 0);

        lv_obj_t * main = lv_obj_create(obj);
        lv_obj_set_name(main, "main");
        lv_obj_set_style_layout(main, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(main, LV_FLEX_FLOW_ROW);
        lv_obj_set_width(main, lv_pct(100));
        lv_obj_set_height(main, LV_SIZE_CONTENT);
        lv_obj_set_style_pad_all(main, 0, 0);
        lv_obj_set_style_pad_column(main, 8, 0);
        lv_obj_set_style_flex_main_place(main, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        widget->main = main;
        lv_obj_t * title_ctn = lv_obj_create(main);
        lv_obj_set_name(title_ctn, "title_ctn");
        lv_obj_set_flag(title_ctn, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(title_ctn, 0, 0);
        lv_obj_set_style_border_width(title_ctn, 0, 0);
        widget->title_ctn = title_ctn;
        lv_obj_t * title_row = lv_obj_create(title_ctn);
        lv_obj_set_name(title_row, "title_row");
        lv_obj_set_style_layout(title_row, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(title_row, LV_FLEX_FLOW_ROW);
        lv_obj_set_flag(title_row, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_width(title_row, lv_pct(100));
        lv_obj_set_style_clip_corner(title_row, true, 0);
        widget->title_row = title_row;
        lv_obj_t * title_icon = lv_label_create(title_row);
        lv_obj_set_name(title_icon, "title_icon");
        lv_label_set_text(title_icon, "󰋜");
        lv_obj_set_style_text_font(title_icon, mdi_icon_font18_4, 0);
        widget->title_icon = title_icon;

        lv_obj_t * title_label = lv_label_create(title_row);
        lv_obj_set_name(title_label, "title_label");
        lv_label_set_text(title_label, "Helloaaaaaaaaaaaaaaaaaaaa");
        lv_obj_set_style_text_font(title_label, roboto_regular_12_4, 0);
        widget->title_label = title_label;

        lv_obj_t * badges_ctn = lv_obj_create(main);
        lv_obj_set_name(badges_ctn, "badges_ctn");
        lv_obj_set_style_pad_all(badges_ctn, 0, 0);
        lv_obj_set_style_border_width(badges_ctn, 0, 0);
        lv_obj_set_width(badges_ctn, LV_SIZE_CONTENT);
        widget->badges_ctn = badges_ctn;
        lv_obj_t * badges_row = lv_obj_create(badges_ctn);
        lv_obj_set_name(badges_row, "badges_row");
        lv_obj_set_style_layout(badges_row, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(badges_row, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(badges_row, LV_FLEX_ALIGN_END, 0);
        lv_obj_set_width(badges_row, LV_SIZE_CONTENT);
        widget->badges_row = badges_row;
        lv_obj_t * hui_heading_badge_0 = hui_heading_badge_create(badges_row);
        hui_heading_badge_set_h_type(hui_heading_badge_0, HUI_HEADING_BADGE_TYPE_DEF_BUTTON);
        hui_heading_badge_set_icon(hui_heading_badge_0, "󰋜");
        hui_heading_badge_set_text(hui_heading_badge_0, "Hello");
        widget->hui_heading_badge_0 = hui_heading_badge_0;

        lv_obj_t * hui_heading_badge_1 = hui_heading_badge_create(badges_row);
        hui_heading_badge_set_h_type(hui_heading_badge_1, HUI_HEADING_BADGE_TYPE_DEF_TEXT);
        hui_heading_badge_set_icon(hui_heading_badge_1, "󰋜");
        hui_heading_badge_set_text(hui_heading_badge_1, "World");
        widget->hui_heading_badge_1 = hui_heading_badge_1;

        lv_obj_t * hui_heading_badge_2 = hui_heading_badge_create(badges_row);
        hui_heading_badge_set_h_type(hui_heading_badge_2, HUI_HEADING_BADGE_TYPE_DEF_BUTTON);
        hui_heading_badge_set_icon(hui_heading_badge_2, "󰋜");
        hui_heading_badge_set_text(hui_heading_badge_2, "AAAA");
        widget->hui_heading_badge_2 = hui_heading_badge_2;

        lv_obj_t * hui_heading_badge_3 = hui_heading_badge_create(badges_row);
        hui_heading_badge_set_h_type(hui_heading_badge_3, HUI_HEADING_BADGE_TYPE_DEF_TEXT);
        hui_heading_badge_set_icon(hui_heading_badge_3, "󰋜");
        hui_heading_badge_set_text(hui_heading_badge_3, "World");
        widget->hui_heading_badge_3 = hui_heading_badge_3;

        the_root = obj;
    }
    #endif
    ha_heading_card_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void ha_heading_card_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    ha_heading_card_destructor_hook(obj);
}

static void ha_heading_card_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&ha_heading_card_class, e);
    if(res != LV_RESULT_OK) return;

    ha_heading_card_event_hook(e);
}

