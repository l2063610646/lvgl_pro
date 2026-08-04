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
        lv_obj_t * test = lv_obj_create(col);
        lv_obj_set_name(test, "test");
        lv_obj_set_style_layout(test, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(test, LV_FLEX_FLOW_ROW);
        lv_obj_set_align(test, LV_ALIGN_TOP_MID);
        lv_obj_set_width(test, LV_SIZE_CONTENT);
        lv_obj_set_height(test, LV_SIZE_CONTENT);
        lv_obj_t * mdi_icon_0 = mdi_icon_create(test);
        mdi_icon_set_size(mdi_icon_0, 32);
        mdi_icon_set_symbol(mdi_icon_0, "󰋜");

        lv_obj_t * mdi_icon_1 = mdi_icon_create(test);
        mdi_icon_set_size(mdi_icon_1, 48);
        mdi_icon_set_symbol(mdi_icon_1, "󰋜");

        lv_obj_t * ha_big_number_0 = ha_big_number_create(test);
        ha_big_number_set_value(ha_big_number_0, 876);
        ha_big_number_set_unit(ha_big_number_0, "%");
        ha_big_number_set_unit_position(ha_big_number_0, UNIT_POSITION_DEF_HA_BIG_NUMBER_UNIT_TOP);
        ha_big_number_set_decimal_places(ha_big_number_0, 1);

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
        hui_heading_card_set_actionable(hui_heading_card_1, true);
        lv_obj_t * hui_heading_card_badge_0 = hui_heading_card_add_badge(hui_heading_card_1, "BUTTON", "󰋜", "BBB");
        lv_obj_t * hui_heading_card_badge_1 = hui_heading_card_add_badge(hui_heading_card_1, "TEXT", "󰋜", "BBB");

        lv_obj_t * ha_control_circular_slider_0 = ha_control_circular_slider_create(col);
        ha_control_circular_slider_set_dual(ha_control_circular_slider_0, true);
        ha_control_circular_slider_set_size(ha_control_circular_slider_0, 200);
        ha_control_circular_slider_set_min(ha_control_circular_slider_0, 0);
        ha_control_circular_slider_set_max(ha_control_circular_slider_0, 1000);
        ha_control_circular_slider_set_low(ha_control_circular_slider_0, 0);
        ha_control_circular_slider_set_high(ha_control_circular_slider_0, 1000);
        ha_control_circular_slider_set_current(ha_control_circular_slider_0, 555);

        lv_obj_t * ha_control_slider_0 = ha_control_slider_create(col);
        ha_control_slider_set_value(ha_control_slider_0, 100);
        lv_obj_set_width(ha_control_slider_0, 200);
        lv_obj_set_height(ha_control_slider_0, 50);
        ha_control_slider_set_mode(ha_control_slider_0, HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_START);

        lv_obj_t * ha_control_slider_1 = ha_control_slider_create(col);
        ha_control_slider_set_value(ha_control_slider_1, 100);
        lv_obj_set_width(ha_control_slider_1, 200);
        lv_obj_set_height(ha_control_slider_1, 50);
        ha_control_slider_set_mode(ha_control_slider_1, HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_END);

        lv_obj_t * ha_control_slider_2 = ha_control_slider_create(col);
        ha_control_slider_set_value(ha_control_slider_2, 100);
        lv_obj_set_width(ha_control_slider_2, 200);
        lv_obj_set_height(ha_control_slider_2, 50);
        ha_control_slider_set_mode(ha_control_slider_2, HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_CURSOR);

        lv_obj_t * ha_control_slider_3 = ha_control_slider_create(col);
        ha_control_slider_set_value(ha_control_slider_3, 100);
        lv_obj_set_width(ha_control_slider_3, 200);
        lv_obj_set_height(ha_control_slider_3, 50);

        lv_obj_t * lv_obj_2 = lv_obj_create(col);
        lv_obj_set_style_layout(lv_obj_2, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_ROW);
        lv_obj_set_align(lv_obj_2, LV_ALIGN_TOP_MID);
        lv_obj_set_width(lv_obj_2, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_2, LV_SIZE_CONTENT);
        lv_obj_t * ha_control_slider_4 = ha_control_slider_create(lv_obj_2);
        ha_control_slider_set_value(ha_control_slider_4, 100);
        ha_control_slider_set_vertical(ha_control_slider_4, true);
        lv_obj_set_width(ha_control_slider_4, 50);
        lv_obj_set_height(ha_control_slider_4, 200);
        ha_control_slider_set_show_handle(ha_control_slider_4, true);
        ha_control_slider_set_mode(ha_control_slider_4, HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_START);

        lv_obj_t * ha_control_slider_5 = ha_control_slider_create(lv_obj_2);
        ha_control_slider_set_value(ha_control_slider_5, 100);
        ha_control_slider_set_vertical(ha_control_slider_5, true);
        lv_obj_set_width(ha_control_slider_5, 50);
        lv_obj_set_height(ha_control_slider_5, 200);
        ha_control_slider_set_show_handle(ha_control_slider_5, true);
        ha_control_slider_set_mode(ha_control_slider_5, HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_END);

        lv_obj_t * ha_control_slider_6 = ha_control_slider_create(lv_obj_2);
        ha_control_slider_set_value(ha_control_slider_6, 100);
        ha_control_slider_set_vertical(ha_control_slider_6, true);
        lv_obj_set_width(ha_control_slider_6, 50);
        lv_obj_set_height(ha_control_slider_6, 200);
        ha_control_slider_set_show_handle(ha_control_slider_6, true);
        ha_control_slider_set_mode(ha_control_slider_6, HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_CURSOR);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

