/**
 * @file ha_control_slider_private_gen.h
 *
 */

#ifndef HA_CONTROL_SLIDER_PRIVATE_H
#define HA_CONTROL_SLIDER_PRIVATE_H

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
#include "ha_control_slider.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_CONTROL_SLIDER_USER_DATA
#define HA_CONTROL_SLIDER_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t value;
    int32_t min;
    int32_t max;
    int32_t step;
    ha_control_slider_mode_t mode;
    bool vertical;
    bool show_handle;
    bool inverted;
    bool disabled;
    ha_control_slider_tooltip_mode_t tooltip_mode;
    const char * unit;
    lv_color_t track_color;
    lv_color_t active_color;
    lv_obj_t * track;
    lv_obj_t * bar;
    lv_obj_t * handle;
    lv_obj_t * cursor;
    lv_obj_t * cursor_mark;
    lv_obj_t * tooltip;
    lv_obj_t * touch_slider;
    HA_CONTROL_SLIDER_USER_DATA
} ha_control_slider_t;

extern const lv_obj_class_t ha_control_slider_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_control_slider_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SLIDER_PRIVATE_H*/