/**
 * @file ha_ripple_private_gen.h
 *
 */

#ifndef HA_RIPPLE_PRIVATE_H
#define HA_RIPPLE_PRIVATE_H

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
#include "ha_ripple.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_RIPPLE_USER_DATA
#define HA_RIPPLE_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_color_t p_color;
    int32_t p_hover_opacity;
    int32_t p_pressed_opacity;
    int32_t p_radius;
    bool p_disabled;
    HA_RIPPLE_USER_DATA
} ha_ripple_t;

extern const lv_obj_class_t ha_ripple_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_ripple_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_RIPPLE_PRIVATE_H*/