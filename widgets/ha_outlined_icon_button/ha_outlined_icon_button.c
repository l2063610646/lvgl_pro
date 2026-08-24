/**
 * @file ha_outlined_icon_button.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_outlined_icon_button_private_gen.h"
#include "../../demo3.h"
#include "../ha_ripple/ha_ripple.h"
#include "../mdi_icon/mdi_icon.h"

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

void ha_outlined_icon_button_constructor_hook(lv_obj_t * obj)
{
    LV_UNUSED(obj);
}

void ha_outlined_icon_button_destructor_hook(lv_obj_t * obj)
{
    LV_UNUSED(obj);
}

void ha_outlined_icon_button_event_hook(lv_event_t * e)
{
    LV_UNUSED(e);
}

void ha_outlined_icon_button_set_size(lv_obj_t * obj, int32_t size)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->size = size;
    lv_obj_set_size(&root->obj, size, size);
}

void ha_outlined_icon_button_set_icon_size(lv_obj_t * obj, int32_t icon_size)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->icon_size = icon_size;
    if(root->icon != NULL) {
        mdi_icon_set_size(root->icon, icon_size);
    }
}

void ha_outlined_icon_button_set_symbol(lv_obj_t * obj, const char * symbol)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->symbol = symbol;
    if(root->icon != NULL) {
        mdi_icon_set_symbol(root->icon, symbol);
    }
}

void ha_outlined_icon_button_set_outline_color(lv_obj_t * obj, lv_color_t outline_color)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->outline_color = outline_color;
    lv_obj_set_style_border_color(&root->obj, outline_color, 0);
    if(root->ripple != NULL) {
        ha_ripple_set_p_color(root->ripple, outline_color);
    }
}

void ha_outlined_icon_button_set_text_color(lv_obj_t * obj, lv_color_t text_color)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->text_color = text_color;
    if(root->icon != NULL) {
        lv_obj_set_style_text_color(root->icon, text_color, 0);
    }
}

void ha_outlined_icon_button_set_disabled(lv_obj_t * obj, bool disabled)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->disabled = disabled;
    if(disabled) {
        lv_obj_add_state(&root->obj, LV_STATE_DISABLED);
        lv_obj_clear_flag(&root->obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_opa(&root->obj, LV_OPA_40, 0);
        if(root->ripple != NULL) {
            ha_ripple_set_p_disabled(root->ripple, true);
        }
    } else {
        lv_obj_remove_state(&root->obj, LV_STATE_DISABLED);
        lv_obj_add_flag(&root->obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_opa(&root->obj, LV_OPA_COVER, 0);
        if(root->ripple != NULL) {
            ha_ripple_set_p_disabled(root->ripple, false);
        }
    }
}

void ha_outlined_icon_button_set_no_ripple(lv_obj_t * obj, bool no_ripple)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    root->no_ripple = no_ripple;
    if(root->ripple != NULL) {
        if(no_ripple) {
            lv_obj_add_flag(root->ripple, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_remove_flag(root->ripple, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

int32_t ha_outlined_icon_button_get_size(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->size : 48;
}

int32_t ha_outlined_icon_button_get_icon_size(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->icon_size : 24;
}

const char * ha_outlined_icon_button_get_symbol(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->symbol : "";
}

lv_color_t ha_outlined_icon_button_get_outline_color(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->outline_color : lv_color_hex(0x5e5e5e);
}

lv_color_t ha_outlined_icon_button_get_text_color(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->text_color : lv_color_hex(0x5e5e5e);
}

bool ha_outlined_icon_button_get_disabled(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->disabled : false;
}

bool ha_outlined_icon_button_get_no_ripple(lv_obj_t * obj)
{
    ha_outlined_icon_button_t * root = (ha_outlined_icon_button_t *)obj;
    return root ? root->no_ripple : false;
}
