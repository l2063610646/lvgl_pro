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

void ha_heading_card_constructor_hook(lv_obj_t * obj)
{
    ha_heading_card_t *root = (ha_heading_card_t *)obj;
    lv_obj_set_width(root->title_ctn, 50);
    lv_obj_set_width(root->badges_ctn, 250);
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