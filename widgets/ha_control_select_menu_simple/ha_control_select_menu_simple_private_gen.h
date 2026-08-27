/**
 * @file ha_control_select_menu_simple_private_gen.h
 *
 */

#ifndef HA_CONTROL_SELECT_MENU_SIMPLE_PRIVATE_H
#define HA_CONTROL_SELECT_MENU_SIMPLE_PRIVATE_H

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
#include "ha_control_select_menu_simple.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_CONTROL_SELECT_MENU_SIMPLE_USER_DATA
#define HA_CONTROL_SELECT_MENU_SIMPLE_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    const char * value;
    const char * options;
    const char * label;
    bool disabled;
    bool hide_label;
    bool show_arrow;
    lv_color_t color;
    lv_color_t modal_bg_color;
    lv_color_t modal_text_color;
    lv_coord_t height;
    HA_CONTROL_SELECT_MENU_SIMPLE_USER_DATA
} ha_control_select_menu_simple_t;

extern const lv_obj_class_t ha_control_select_menu_simple_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_control_select_menu_simple_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SELECT_MENU_SIMPLE_PRIVATE_H*/