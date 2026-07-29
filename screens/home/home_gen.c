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
        lv_obj_set_align(col, LV_ALIGN_CENTER);
        lv_obj_set_width(col, LV_SIZE_CONTENT);
        lv_obj_set_height(col, LV_SIZE_CONTENT);
        lv_obj_t * test = lv_obj_create(col);
        lv_obj_set_name(test, "test");
        lv_obj_set_style_layout(test, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(test, LV_FLEX_FLOW_ROW);
        lv_obj_set_align(test, LV_ALIGN_CENTER);
        lv_obj_set_width(test, LV_SIZE_CONTENT);
        lv_obj_set_height(test, LV_SIZE_CONTENT);
        lv_obj_t * hui_heading_badge_0 = hui_heading_badge_create(test);
        hui_heading_badge_set_h_type(hui_heading_badge_0, HUI_HEADING_BADGE_TYPE_DEF_BUTTON);
        hui_heading_badge_set_text(hui_heading_badge_0, "Hello");
        hui_heading_badge_set_icon(hui_heading_badge_0, "󰋜");

        lv_obj_t * hui_heading_badge_1 = hui_heading_badge_create(test);
        hui_heading_badge_set_h_type(hui_heading_badge_1, HUI_HEADING_BADGE_TYPE_DEF_TEXT);
        hui_heading_badge_set_text(hui_heading_badge_1, "World");
        hui_heading_badge_set_icon(hui_heading_badge_1, "󰋜");

        lv_obj_t * lv_obj_1 = lv_obj_create(col);
        lv_obj_set_width(lv_obj_1, 400);
        hui_heading_card_create(lv_obj_1);

        lv_obj_t * ha_heading_card_0 = ha_heading_card_create(col);
        lv_obj_set_width(ha_heading_card_0, 400);
        ha_heading_card_set_heading(ha_heading_card_0, "012345678901234");

        lv_obj_t * ha_heading_card_1 = ha_heading_card_create(col);
        lv_obj_set_width(ha_heading_card_1, 400);
        ha_heading_card_set_heading(ha_heading_card_1, "01234");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

