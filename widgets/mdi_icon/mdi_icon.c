/**
 * @file mdi_icon.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "mdi_icon_private_gen.h"
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

void mdi_icon_constructor_hook(lv_obj_t * obj)
{

}

void mdi_icon_destructor_hook(lv_obj_t * obj)
{

}

void mdi_icon_event_hook(lv_event_t * e)
{

}

void mdi_icon_set_size(lv_obj_t * mdi_icon, int32_t size)
{
    mdi_icon_t * root = (mdi_icon_t *) mdi_icon;
    root->size = size;

    if (size > 24) {
        if (size > 36) {
            lv_obj_set_style_text_font((lv_obj_t *)&root->obj, mdi_icon_font48_4, 0);
        } else {
            lv_obj_set_style_text_font((lv_obj_t *)&root->obj, mdi_icon_font36_4, 0);
        }
    } else {
        lv_obj_set_style_text_font((lv_obj_t *)&root->obj, mdi_icon_font24_4, 0);
    }
}

void mdi_icon_set_symbol(lv_obj_t * mdi_icon, const char * symbol)
{
    mdi_icon_t * root = (mdi_icon_t *) mdi_icon;
    root->symbol = symbol;
    lv_label_set_text((lv_obj_t *)&root->obj, symbol);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
