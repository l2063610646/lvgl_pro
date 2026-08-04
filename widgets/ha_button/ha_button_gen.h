/**
 * @file ha_button_gen.h
 *
 */

#ifndef HA_BUTTON_GEN_H
#define HA_BUTTON_GEN_H

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
typedef enum {
    HA_BUTTON_VARIANT_BRAND = 0,
    HA_BUTTON_VARIANT_NEUTRAL = 1,
    HA_BUTTON_VARIANT_SUCCESS = 2,
    HA_BUTTON_VARIANT_WARNING = 3,
    HA_BUTTON_VARIANT_DANGER = 4
}ha_button_variant_t;

typedef enum {
    HA_BUTTON_APPEARANCE_ACCENT = 0,
    HA_BUTTON_APPEARANCE_FILLED = 1,
    HA_BUTTON_APPEARANCE_PLAIN = 2,
    HA_BUTTON_APPEARANCE_OUTLINED = 3
}ha_button_appearance_t;

typedef enum {
    HA_BUTTON_SIZE_XS = 0,
    HA_BUTTON_SIZE_S = 1,
    HA_BUTTON_SIZE_M = 2,
    HA_BUTTON_SIZE_L = 3,
    HA_BUTTON_SIZE_XL = 4
}ha_button_size_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a ha_button object
 * @param parent pointer to an object, it will be the parent of the new ha_button
 * @return pointer to the created ha_button
 */
lv_obj_t * ha_button_create(lv_obj_t * parent);
/**
 * Button text label
 * @param obj   pointer to a ha_button
 * @param label  Button text label
 */
void ha_button_set_label(lv_obj_t * ha_button, const char * label);

/**
 * Alias for label
 * @param obj   pointer to a ha_button
 * @param text  Alias for label
 */
void ha_button_set_text(lv_obj_t * ha_button, const char * text);

/**
 * Prefix icon symbol
 * @param obj   pointer to a ha_button
 * @param start_icon  Prefix icon symbol
 */
void ha_button_set_start_icon(lv_obj_t * ha_button, const char * start_icon);

/**
 * Alias for start_icon
 * @param obj   pointer to a ha_button
 * @param start_symbol  Alias for start_icon
 */
void ha_button_set_start_symbol(lv_obj_t * ha_button, const char * start_symbol);

/**
 * Suffix icon symbol
 * @param obj   pointer to a ha_button
 * @param end_icon  Suffix icon symbol
 */
void ha_button_set_end_icon(lv_obj_t * ha_button, const char * end_icon);

/**
 * Alias for end_icon
 * @param obj   pointer to a ha_button
 * @param end_symbol  Alias for end_icon
 */
void ha_button_set_end_symbol(lv_obj_t * ha_button, const char * end_symbol);

/**
 * Color variant
 * @param obj   pointer to a ha_button
 * @param variant  Color variant
 */
void ha_button_set_variant(lv_obj_t * ha_button, ha_button_variant_t variant);

/**
 * Visual appearance style
 * @param obj   pointer to a ha_button
 * @param appearance  Visual appearance style
 */
void ha_button_set_appearance(lv_obj_t * ha_button, ha_button_appearance_t appearance);

/**
 * Button size
 * @param obj   pointer to a ha_button
 * @param size  Button size
 */
void ha_button_set_size(lv_obj_t * ha_button, ha_button_size_t size);

/**
 * Custom button height
 * @param obj   pointer to a ha_button
 * @param height  Custom button height
 */
void ha_button_set_height(lv_obj_t * ha_button, lv_coord_t height);

/**
 * Disabled state
 * @param obj   pointer to a ha_button
 * @param disabled  Disabled state
 */
void ha_button_set_disabled(lv_obj_t * ha_button, bool disabled);

/**
 * Loading state
 * @param obj   pointer to a ha_button
 * @param loading  Loading state
 */
void ha_button_set_loading(lv_obj_t * ha_button, bool loading);

/**
 * Selected state
 * @param obj   pointer to a ha_button
 * @param selected  Selected state
 */
void ha_button_set_selected(lv_obj_t * ha_button, bool selected);

/**
 * Custom foreground color
 * @param obj   pointer to a ha_button
 * @param fg_color  Custom foreground color
 */
void ha_button_set_fg_color(lv_obj_t * ha_button, lv_color_t fg_color);

/**
 * Custom background/accent color
 * @param obj   pointer to a ha_button
 * @param bg_color  Custom background/accent color
 */
void ha_button_set_bg_color(lv_obj_t * ha_button, lv_color_t bg_color);

/**
 * Custom border color
 * @param obj   pointer to a ha_button
 * @param border_color  Custom border color
 */
void ha_button_set_border_color(lv_obj_t * ha_button, lv_color_t border_color);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_BUTTON_GEN_H*/