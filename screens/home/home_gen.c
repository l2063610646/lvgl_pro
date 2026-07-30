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
        lv_obj_t * lv_obj_1 = lv_obj_create(test);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_HIDDEN, true);

        lv_obj_t * lv_label_0 = lv_label_create(test);
        lv_label_set_text(lv_label_0, "VV");

        lv_obj_t * lv_obj_2 = lv_obj_create(col);
        lv_obj_set_width(lv_obj_2, 300);
        lv_obj_set_style_pad_all(lv_obj_2, 0, 0);
        lv_obj_set_style_layout(lv_obj_2, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_t * hui_heading_card_0 = hui_heading_card_create(lv_obj_2);
        hui_heading_card_set_heading(hui_heading_card_0, "012345678901234012345671128123123");

        lv_obj_t * hui_heading_card_1 = hui_heading_card_create(lv_obj_2);
        hui_heading_card_set_heading(hui_heading_card_1, "01234567890");

        lv_obj_t * hui_heading_card_2 = hui_heading_card_create(lv_obj_2);
        hui_heading_card_set_heading(hui_heading_card_2, "01234");

        lv_obj_t * hui_heading_card_3 = hui_heading_card_create(lv_obj_2);
        hui_heading_card_set_heading(hui_heading_card_3, "012345678901234012345671128123123");
        hui_heading_card_set_actionable(hui_heading_card_3, true);

        lv_obj_t * hui_heading_card_4 = hui_heading_card_create(lv_obj_2);
        hui_heading_card_set_heading(hui_heading_card_4, "01234567890");
        hui_heading_card_set_actionable(hui_heading_card_4, true);

        lv_obj_t * hui_heading_card_5 = hui_heading_card_create(lv_obj_2);
        hui_heading_card_set_heading(hui_heading_card_5, "01234");
        hui_heading_card_set_actionable(hui_heading_card_5, true);

        lv_obj_t * hui_heading_card_6 = hui_heading_card_create(col);
        lv_obj_set_width(hui_heading_card_6, 300);
        hui_heading_card_set_heading(hui_heading_card_6, "01234");

        lv_obj_t * hui_heading_card_7 = hui_heading_card_create(col);
        lv_obj_set_width(hui_heading_card_7, 400);
        hui_heading_card_set_heading(hui_heading_card_7, "01234");

        lv_obj_t * hui_heading_card_8 = hui_heading_card_create(col);
        lv_obj_set_width(hui_heading_card_8, 500);
        hui_heading_card_set_heading(hui_heading_card_8, "01234");

        lv_obj_t * hui_heading_card_9 = hui_heading_card_create(col);
        lv_obj_set_width(hui_heading_card_9, 600);
        hui_heading_card_set_heading(hui_heading_card_9, "01234");
        hui_heading_card_set_actionable(hui_heading_card_9, true);
        lv_obj_t * hui_heading_card_badge_0 = hui_heading_card_add_badge(hui_heading_card_9, "BUTTON", "󰋜", "BBB");
        lv_obj_t * hui_heading_card_badge_1 = hui_heading_card_add_badge(hui_heading_card_9, "TEXT", "󰋜", "BBB");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

