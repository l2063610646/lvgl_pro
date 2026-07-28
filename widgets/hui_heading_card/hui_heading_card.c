/**
 * @file hui_heading_card.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_card_private_gen.h"
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
static void hui_heading_card_layout_update(lv_obj_t * obj);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void hui_heading_card_constructor_hook(lv_obj_t * obj)
{
    hui_heading_card_t * root = (hui_heading_card_t *) obj;
    // 初始化时，触发排版计算
    hui_heading_card_layout_update(obj);
}

void hui_heading_card_destructor_hook(lv_obj_t * obj)
{

}

void hui_heading_card_event_hook(lv_event_t * e)
{

}



/**********************
 *   STATIC FUNCTIONS
 **********************/
static void hui_heading_card_layout_update(lv_obj_t * obj)
{
    hui_heading_card_t * root = (hui_heading_card_t *) obj;
    const int32_t content_reserved_width = 150;

    lv_obj_set_width(root->content, LV_SIZE_CONTENT);
    lv_obj_set_width(root->label, LV_SIZE_CONTENT);
    lv_obj_set_width(root->badges, LV_SIZE_CONTENT);
    lv_obj_update_layout(root->label);
    lv_obj_update_layout(root->badges);

    int32_t content_natural_width = lv_obj_get_width(root->label);
    content_natural_width += lv_obj_get_style_pad_left(root->content, 0);
    content_natural_width += lv_obj_get_style_pad_right(root->content, 0);
    int32_t badges_natural_width = lv_obj_get_width(root->badges);
    int32_t card_content_w = lv_obj_get_width(&root->obj);
    if (card_content_w <= 0) {
        return;
    }
    int32_t gap = lv_obj_get_style_pad_column(root->card, 0);
    int32_t available_width = card_content_w - gap;

    if (available_width < 0) {
        available_width = 0;
    }

    int32_t content_width = content_natural_width;
    int32_t badges_width = badges_natural_width;
    if (content_natural_width + badges_natural_width <= available_width) {
        content_width = available_width - badges_width;
    }
    else {
        int32_t badges_max_width = available_width - content_reserved_width;
        if (badges_max_width < 0) {
            badges_max_width = 0;
        }
        if (badges_width > badges_max_width) {
            badges_width = badges_max_width;
        }

        content_width = available_width - badges_width;
        if (content_width < 0) {
            content_width = 0;
        }
    }

    lv_obj_set_width(root->content, content_width);
    lv_obj_set_width(root->badges, badges_width);

    lv_obj_mark_layout_as_dirty(root->badges);
    lv_obj_mark_layout_as_dirty(root->content);
    
}