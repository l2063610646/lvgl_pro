/**
 * @file ha_control_select_menu_simple_gen.h
 *
 */

#ifndef HA_CONTROL_SELECT_MENU_SIMPLE_GEN_H
#define HA_CONTROL_SELECT_MENU_SIMPLE_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#include "../../demo3_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a ha_control_select_menu_simple object
 * @param parent pointer to an object, it will be the parent of the new ha_control_select_menu_simple
 * @return pointer to the created ha_control_select_menu_simple
 */
lv_obj_t * ha_control_select_menu_simple_create(lv_obj_t * parent);
/**
 * Selected value
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param value  Selected value
 */
void ha_control_select_menu_simple_set_value(lv_obj_t * ha_control_select_menu_simple, const char * value);

/**
 * Semicolon-separated options (value,label,symbol)
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param options  Semicolon-separated options (value,label,symbol)
 */
void ha_control_select_menu_simple_set_options(lv_obj_t * ha_control_select_menu_simple, const char * options);

/**
 * Control label title
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param label  Control label title
 */
void ha_control_select_menu_simple_set_label(lv_obj_t * ha_control_select_menu_simple, const char * label);

/**
 * Disabled state
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param disabled  Disabled state
 */
void ha_control_select_menu_simple_set_disabled(lv_obj_t * ha_control_select_menu_simple, bool disabled);

/**
 * Hide title label on trigger
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param hide_label  Hide title label on trigger
 */
void ha_control_select_menu_simple_set_hide_label(lv_obj_t * ha_control_select_menu_simple, bool hide_label);

/**
 * Show dropdown indicator arrow
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param show_arrow  Show dropdown indicator arrow
 */
void ha_control_select_menu_simple_set_show_arrow(lv_obj_t * ha_control_select_menu_simple, bool show_arrow);

/**
 * Accent / selected highlight color
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param color  Accent / selected highlight color
 */
void ha_control_select_menu_simple_set_color(lv_obj_t * ha_control_select_menu_simple, lv_color_t color);

/**
 * Modal popup background color
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param modal_bg_color  Modal popup background color
 */
void ha_control_select_menu_simple_set_modal_bg_color(lv_obj_t * ha_control_select_menu_simple, lv_color_t modal_bg_color);

/**
 * Modal popup text color
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param modal_text_color  Modal popup text color
 */
void ha_control_select_menu_simple_set_modal_text_color(lv_obj_t * ha_control_select_menu_simple, lv_color_t modal_text_color);

/**
 * Height of the trigger control
 * @param obj   pointer to a ha_control_select_menu_simple
 * @param height  Height of the trigger control
 */
void ha_control_select_menu_simple_set_height(lv_obj_t * ha_control_select_menu_simple, lv_coord_t height);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SELECT_MENU_SIMPLE_GEN_H*/