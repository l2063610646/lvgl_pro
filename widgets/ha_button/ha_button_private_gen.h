/**
 * @file ha_button_private_gen.h
 *
 */

#ifndef HA_BUTTON_PRIVATE_H
#define HA_BUTTON_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl_private.h"
#endif
#include "ha_button.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_BUTTON_USER_DATA
#define HA_BUTTON_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    const char * label;
    const char * text;
    const char * start_icon;
    const char * start_symbol;
    const char * end_icon;
    const char * end_symbol;
    ha_button_variant_t variant;
    ha_button_appearance_t appearance;
    ha_button_size_t size;
    lv_coord_t height;
    bool disabled;
    bool loading;
    bool selected;
    lv_color_t fg_color;
    lv_color_t bg_color;
    lv_color_t border_color;
    lv_obj_t * start_icon_obj;
    lv_obj_t * label_obj;
    lv_obj_t * end_icon_obj;
    lv_obj_t * spinner_obj;
    HA_BUTTON_USER_DATA
} ha_button_t;

extern const lv_obj_class_t ha_button_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_button_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_BUTTON_PRIVATE_H*/