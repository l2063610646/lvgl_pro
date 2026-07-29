/**
 * @file ha_heading_card.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_heading_card_private_gen.h"
#include "../../demo3.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int32_t clamp_i32(int32_t value, int32_t min, int32_t max)
{
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

void refresh(lv_obj_t *obj)
{
    ha_heading_card_t *root = (ha_heading_card_t *) obj;

    lv_obj_set_width(root->title_ctn, LV_SIZE_CONTENT);
    lv_obj_set_width(root->badges_ctn, LV_SIZE_CONTENT);
    lv_obj_set_width(root->title_label, LV_SIZE_CONTENT);

    lv_obj_update_layout(root->title_ctn);
    lv_obj_update_layout(root->badges_ctn);
    lv_obj_update_layout(root->main);

    int32_t DEFAULT_TITLE_CTN_WIDTH = 150;
    int32_t t1 = lv_obj_get_width(root->title_icon);
    int32_t t2 = lv_obj_get_width(root->title_next);
    int32_t t3 = lv_obj_get_style_pad_column(root->title_row, 0);
    int32_t t4 = lv_obj_get_content_width(root->title_label);

    int32_t title_ctn_width = t1 + t2 + t3 *2 + t4;
    int32_t badges_ctn_width = lv_obj_get_width(root->badges_ctn);
    int32_t main_ctn_width = lv_obj_get_content_width(lv_obj_get_parent(&root->obj));

    int32_t gap = lv_obj_get_style_pad_column(root->main, 0);
    if (title_ctn_width + badges_ctn_width + gap > main_ctn_width) {
        if (main_ctn_width - gap - badges_ctn_width > DEFAULT_TITLE_CTN_WIDTH) {
            // 说明title_ctn宽了，badges窄了，需要保持badges的宽度，调整title_ctn的宽度
            int32_t remaining_title_ctn_width = main_ctn_width - gap - badges_ctn_width;
            lv_obj_set_width(root->title_ctn, remaining_title_ctn_width);
            lv_obj_set_width(root->title_row, remaining_title_ctn_width);
            lv_obj_set_style_clip_corner(root->title_ctn, true, 0);

            int32_t temp = remaining_title_ctn_width - t3 * 2 - t2 - t1;
            lv_obj_set_width(root->title_label, temp);
            lv_obj_set_height(root->title_label, 16);
            lv_label_set_long_mode(root->title_label, LV_LABEL_LONG_DOT);
        } else {
            // 说明badges宽了，title_ctn窄了，需要限制title_ctn的最小宽度，调整badges的宽度
            int32_t target_title_ctn_width = title_ctn_width > DEFAULT_TITLE_CTN_WIDTH ? DEFAULT_TITLE_CTN_WIDTH : title_ctn_width;
            lv_obj_set_width(root->title_ctn, target_title_ctn_width);
            lv_obj_set_width(root->title_row, target_title_ctn_width);
            lv_obj_set_style_clip_corner(root->title_ctn, true, 0);

            int32_t temp = DEFAULT_TITLE_CTN_WIDTH - t3 * 2 - t2 - t1;
            lv_obj_set_width(root->title_label, temp);
            lv_obj_set_height(root->title_label, 16);
            lv_label_set_long_mode(root->title_label, LV_LABEL_LONG_DOT);

            int32_t target_badges_ctn_width = main_ctn_width - gap - target_title_ctn_width;
            lv_obj_set_width(root->badges_ctn, target_badges_ctn_width);
        }
    }

    int32_t max_scroll_x = lv_obj_get_scroll_right(root->badges_ctn);
    lv_obj_scroll_to_x(root->badges_ctn, max_scroll_x, LV_ANIM_OFF);
    lv_obj_update_layout(root->title_row);
    lv_obj_update_layout(root->title_ctn);
    lv_obj_update_layout(root->badges_ctn);
    lv_obj_update_layout(root->main);
}

void ha_heading_card_constructor_hook(lv_obj_t * obj)
{
    refresh(obj);
}

void ha_heading_card_destructor_hook(lv_obj_t * obj)
{

}

void ha_heading_card_event_hook(lv_event_t * e)
{

}

void ha_heading_card_set_heading(lv_obj_t * obj, const char * heading)
{
    ha_heading_card_t *root = (ha_heading_card_t *) obj;
    lv_label_set_text(root->title_label, heading);
    refresh(obj);
}

void ha_heading_card_set_icon(lv_obj_t * obj, const char * icon)
{
    ha_heading_card_t *root = (ha_heading_card_t *) obj;
    lv_label_set_text(root->title_icon, icon);
    refresh(obj);
}

void ha_heading_card_set_actionable(lv_obj_t * obj, bool actionable)
{
    ha_heading_card_t *root = (ha_heading_card_t *) obj;
    refresh(obj);
    
}



/**********************
 *   STATIC FUNCTIONS
 **********************/
