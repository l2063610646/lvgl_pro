/**
 * @file ha_control_circular_slider_gen.h
 *
 */

#ifndef HA_CONTROL_CIRCULAR_SLIDER_GEN_H
#define HA_CONTROL_CIRCULAR_SLIDER_GEN_H

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
    CIRCULAR_SLIDER_MODE_START = 0,
    CIRCULAR_SLIDER_MODE_END = 1,
    CIRCULAR_SLIDER_MODE_FULL = 2
}circular_slider_mode_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a ha_control_circular_slider object
 * @param parent pointer to an object, it will be the parent of the new ha_control_circular_slider
 * @return pointer to the created ha_control_circular_slider
 */
lv_obj_t * ha_control_circular_slider_create(lv_obj_t * parent);
/**
 * ha_control_circular_slider current
 * @param obj   pointer to a ha_control_circular_slider
 * @param current  current
 */
void ha_control_circular_slider_set_current(lv_obj_t * ha_control_circular_slider, int32_t current);

/**
 * ha_control_circular_slider value
 * @param obj   pointer to a ha_control_circular_slider
 * @param value  value
 */
void ha_control_circular_slider_set_value(lv_obj_t * ha_control_circular_slider, int32_t value);

/**
 * ha_control_circular_slider low
 * @param obj   pointer to a ha_control_circular_slider
 * @param low  low
 */
void ha_control_circular_slider_set_low(lv_obj_t * ha_control_circular_slider, int32_t low);

/**
 * ha_control_circular_slider high
 * @param obj   pointer to a ha_control_circular_slider
 * @param high  high
 */
void ha_control_circular_slider_set_high(lv_obj_t * ha_control_circular_slider, int32_t high);

/**
 * ha_control_circular_slider dual
 * @param obj   pointer to a ha_control_circular_slider
 * @param dual  dual
 */
void ha_control_circular_slider_set_dual(lv_obj_t * ha_control_circular_slider, bool dual);

/**
 * ha_control_circular_slider min
 * @param obj   pointer to a ha_control_circular_slider
 * @param min  min
 */
void ha_control_circular_slider_set_min(lv_obj_t * ha_control_circular_slider, int32_t min);

/**
 * ha_control_circular_slider max
 * @param obj   pointer to a ha_control_circular_slider
 * @param max  max
 */
void ha_control_circular_slider_set_max(lv_obj_t * ha_control_circular_slider, int32_t max);

/**
 * ha_control_circular_slider step
 * @param obj   pointer to a ha_control_circular_slider
 * @param step  step
 */
void ha_control_circular_slider_set_step(lv_obj_t * ha_control_circular_slider, int32_t step);

/**
 * ha_control_circular_slider size
 * @param obj   pointer to a ha_control_circular_slider
 * @param size  size
 */
void ha_control_circular_slider_set_size(lv_obj_t * ha_control_circular_slider, int32_t size);

/**
 * ha_control_circular_slider low_color
 * @param obj   pointer to a ha_control_circular_slider
 * @param low_color  low_color
 */
void ha_control_circular_slider_set_low_color(lv_obj_t * ha_control_circular_slider, lv_color_t low_color);

/**
 * ha_control_circular_slider high_color
 * @param obj   pointer to a ha_control_circular_slider
 * @param high_color  high_color
 */
void ha_control_circular_slider_set_high_color(lv_obj_t * ha_control_circular_slider, lv_color_t high_color);

/**
 * ha_control_circular_slider active_color
 * @param obj   pointer to a ha_control_circular_slider
 * @param active_color  active_color
 */
void ha_control_circular_slider_set_active_color(lv_obj_t * ha_control_circular_slider, lv_color_t active_color);

/**
 * ha_control_circular_slider mode
 * @param obj   pointer to a ha_control_circular_slider
 * @param mode  mode
 */
void ha_control_circular_slider_set_mode(lv_obj_t * ha_control_circular_slider, circular_slider_mode_t mode);

/**
 * ha_control_circular_slider inactive
 * @param obj   pointer to a ha_control_circular_slider
 * @param inactive  inactive
 */
void ha_control_circular_slider_set_inactive(lv_obj_t * ha_control_circular_slider, bool inactive);

/**
 * ha_control_circular_slider show_knob
 * @param obj   pointer to a ha_control_circular_slider
 * @param show_knob  show_knob
 */
void ha_control_circular_slider_set_show_knob(lv_obj_t * ha_control_circular_slider, bool show_knob);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_CIRCULAR_SLIDER_GEN_H*/