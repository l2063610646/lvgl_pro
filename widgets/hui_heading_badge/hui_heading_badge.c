/**
 * @file hui_heading_badge.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_badge_private_gen.h"
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
static void refresh(lv_obj_t * obj);

void hui_heading_badge_constructor_hook(lv_obj_t * obj)
{

}

void hui_heading_badge_destructor_hook(lv_obj_t * obj)
{

}

void hui_heading_badge_event_hook(lv_event_t * e)
{

}


void hui_heading_badge_set_h_type(lv_obj_t * hui_heading_badge, hui_heading_badge_type_def_t h_type)
{
    hui_heading_badge_t * root = (hui_heading_badge_t *) hui_heading_badge;
    root->h_type = h_type;
    refresh(hui_heading_badge);
}

void hui_heading_badge_set_text(lv_obj_t * hui_heading_badge, const char * text)
{
    hui_heading_badge_t * root = (hui_heading_badge_t *) hui_heading_badge;
    root->text = text;
    lv_label_set_text(root->label_text, text);
}

void hui_heading_badge_set_icon(lv_obj_t * hui_heading_badge, const char * icon)
{
    hui_heading_badge_t * root = (hui_heading_badge_t *) hui_heading_badge;
    root->icon = icon;
    lv_label_set_text(root->label_icon, icon);
}

void hui_heading_badge_set_text_color(lv_obj_t * hui_heading_badge, lv_color_t color)
{
    hui_heading_badge_t * root = (hui_heading_badge_t *) hui_heading_badge;
    root->text_color = color;
    ha_ripple_set_p_color(root->ripple, color);
    refresh(hui_heading_badge);
}

void hui_heading_badge_set_icon_color(lv_obj_t * hui_heading_badge, lv_color_t color)
{
    hui_heading_badge_t * root = (hui_heading_badge_t *) hui_heading_badge;
    root->icon_color = color;
    refresh(hui_heading_badge);
}



/**********************
 *   STATIC FUNCTIONS
 **********************/
static void refresh(lv_obj_t * obj)
{
    hui_heading_badge_t * root = (hui_heading_badge_t *) obj;
    if (root->h_type == HUI_HEADING_BADGE_TYPE_DEF_TEXT) {
        lv_obj_set_style_pad_all(&root->obj, 0, 0);
        lv_obj_set_style_pad_gap(&root->obj, 3, 0);
        lv_obj_set_style_bg_opa(&root->obj, 0, 0);
        lv_obj_clear_flag(&root->obj, LV_OBJ_FLAG_CLICKABLE);
    } else {
        lv_obj_set_style_pad_all(&root->obj, 0, 0);
        lv_obj_set_style_pad_left(&root->obj, 8, 0);
        lv_obj_set_style_pad_right(&root->obj, 8, 0);
        lv_obj_set_style_bg_color(&root->obj, root->text_color, 0);
        lv_obj_set_style_bg_opa(&root->obj, LV_OPA_20, 0);
        lv_obj_add_flag(&root->obj, LV_OBJ_FLAG_CLICKABLE);
    }
    lv_obj_set_style_text_color(root->label_text, root->text_color, 0);
    lv_obj_set_style_text_color(root->label_icon, root->icon_color, 0);
}