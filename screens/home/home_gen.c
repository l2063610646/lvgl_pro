/**
 * @file home_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "home_gen.h"
#include "../../demo3.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "home_#");

        lv_obj_t * col = lv_obj_create(lv_obj_0);
        lv_obj_set_name(col, "col");
        lv_obj_set_flex_flow(col, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_layout(col, LV_LAYOUT_FLEX, 0);
        lv_obj_set_align(col, LV_ALIGN_TOP_MID);
        lv_obj_set_width(col, LV_SIZE_CONTENT);
        lv_obj_set_height(col, LV_SIZE_CONTENT);
        lv_obj_t * lv_obj_1 = lv_obj_create(col);
        lv_obj_set_width(lv_obj_1, 300);
        lv_obj_set_height(lv_obj_1, LV_SIZE_CONTENT);
        lv_obj_set_style_pad_all(lv_obj_1, 0, 0);
        lv_obj_set_style_layout(lv_obj_1, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_COLUMN);
        lv_obj_t * hui_heading_card_0 = hui_heading_card_create(lv_obj_1);
        hui_heading_card_set_heading(hui_heading_card_0, "012345678901234012345671128123123");

        lv_obj_t * hui_heading_card_1 = hui_heading_card_create(lv_obj_1);
        hui_heading_card_set_heading(hui_heading_card_1, "01234567890");
        lv_obj_t * hui_heading_card_badge_0 = hui_heading_card_add_badge(hui_heading_card_1, "BUTTON", "󰋜", "BBB");
        lv_obj_t * hui_heading_card_badge_1 = hui_heading_card_add_badge(hui_heading_card_1, "TEXT", "󰋜", "BBB");

        lv_obj_t * ha_control_circular_slider_0 = ha_control_circular_slider_create(col);
        ha_control_circular_slider_set_value(ha_control_circular_slider_0, 10);
        ha_control_circular_slider_set_size(ha_control_circular_slider_0, 200);
        ha_control_circular_slider_set_current(ha_control_circular_slider_0, 20);
        ha_control_circular_slider_set_low(ha_control_circular_slider_0, 15);
        ha_control_circular_slider_set_high(ha_control_circular_slider_0, 30);
        ha_control_circular_slider_set_min(ha_control_circular_slider_0, 10);
        ha_control_circular_slider_set_max(ha_control_circular_slider_0, 30);

        lv_obj_t * ha_control_circular_slider_1 = ha_control_circular_slider_create(col);
        ha_control_circular_slider_set_dual(ha_control_circular_slider_1, true);
        ha_control_circular_slider_set_size(ha_control_circular_slider_1, 200);
        ha_control_circular_slider_set_min(ha_control_circular_slider_1, 0);
        ha_control_circular_slider_set_max(ha_control_circular_slider_1, 1000);
        ha_control_circular_slider_set_low(ha_control_circular_slider_1, 0);
        ha_control_circular_slider_set_high(ha_control_circular_slider_1, 1000);
        ha_control_circular_slider_set_current(ha_control_circular_slider_1, 555);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

