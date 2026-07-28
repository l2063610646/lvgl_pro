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
void refresh(lv_obj_t *obj)
{
    // LV_LOG_INFO("111");
    // LV_LOG_USER("A: %d, b: %d, c: %d", 1, 2, 3);
    
    // int32_t content_natural_width = lv_obj_get_width(root->label);
    // content_natural_width += lv_obj_get_style_pad_left(root->content, 0);
    // content_natural_width += lv_obj_get_style_pad_right(root->content, 0);

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



/**********************
 *   STATIC FUNCTIONS
 **********************/
