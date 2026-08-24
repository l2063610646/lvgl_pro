/**
 * @file ha_outlined_icon_button_private_gen.h
 *
 */

#ifndef HA_OUTLINED_ICON_BUTTON_PRIVATE_H
#define HA_OUTLINED_ICON_BUTTON_PRIVATE_H

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
#include "ha_outlined_icon_button.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_OUTLINED_ICON_BUTTON_USER_DATA
#define HA_OUTLINED_ICON_BUTTON_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t size;
    int32_t icon_size;
    const char * symbol;
    lv_color_t outline_color;
    lv_color_t text_color;
    bool disabled;
    bool no_ripple;
    lv_obj_t * ripple;
    lv_obj_t * icon;
    HA_OUTLINED_ICON_BUTTON_USER_DATA
} ha_outlined_icon_button_t;

extern const lv_obj_class_t ha_outlined_icon_button_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_outlined_icon_button_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_OUTLINED_ICON_BUTTON_PRIVATE_H*/