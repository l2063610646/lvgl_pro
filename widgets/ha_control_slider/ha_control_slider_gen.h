/**
 * @file ha_control_slider_gen.h
 *
 */

#ifndef HA_CONTROL_SLIDER_GEN_H
#define HA_CONTROL_SLIDER_GEN_H

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
    HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_START = 0,
    HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_END = 1,
    HA_CONTROL_SLIDER_MODE_HA_CONTROL_SLIDER_MODE_CURSOR = 2
}ha_control_slider_mode_t;

typedef enum {
    HA_CONTROL_SLIDER_TOOLTIP_MODE_HA_CONTROL_SLIDER_TOOLTIP_NEVER = 0,
    HA_CONTROL_SLIDER_TOOLTIP_MODE_HA_CONTROL_SLIDER_TOOLTIP_ALWAYS = 1,
    HA_CONTROL_SLIDER_TOOLTIP_MODE_HA_CONTROL_SLIDER_TOOLTIP_INTERACTION = 2
}ha_control_slider_tooltip_mode_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a ha_control_slider object
 * @param parent pointer to an object, it will be the parent of the new ha_control_slider
 * @return pointer to the created ha_control_slider
 */
lv_obj_t * ha_control_slider_create(lv_obj_t * parent);
/**
 * Current slider value
 * @param obj   pointer to a ha_control_slider
 * @param value  Current slider value
 */
void ha_control_slider_set_value(lv_obj_t * ha_control_slider, int32_t value);

/**
 * Minimum value
 * @param obj   pointer to a ha_control_slider
 * @param min  Minimum value
 */
void ha_control_slider_set_min(lv_obj_t * ha_control_slider, int32_t min);

/**
 * Maximum value
 * @param obj   pointer to a ha_control_slider
 * @param max  Maximum value
 */
void ha_control_slider_set_max(lv_obj_t * ha_control_slider, int32_t max);

/**
 * Step increment
 * @param obj   pointer to a ha_control_slider
 * @param step  Step increment
 */
void ha_control_slider_set_step(lv_obj_t * ha_control_slider, int32_t step);

/**
 * Slider bar mode
 * @param obj   pointer to a ha_control_slider
 * @param mode  Slider bar mode
 */
void ha_control_slider_set_mode(lv_obj_t * ha_control_slider, ha_control_slider_mode_t mode);

/**
 * Vertical layout orientation
 * @param obj   pointer to a ha_control_slider
 * @param vertical  Vertical layout orientation
 */
void ha_control_slider_set_vertical(lv_obj_t * ha_control_slider, bool vertical);

/**
 * Reserve endpoint space for the handle line
 * @param obj   pointer to a ha_control_slider
 * @param show_handle  Reserve endpoint space for the handle line
 */
void ha_control_slider_set_show_handle(lv_obj_t * ha_control_slider, bool show_handle);

/**
 * Invert direction mapping
 * @param obj   pointer to a ha_control_slider
 * @param inverted  Invert direction mapping
 */
void ha_control_slider_set_inverted(lv_obj_t * ha_control_slider, bool inverted);

/**
 * Whether the slider is disabled
 * @param obj   pointer to a ha_control_slider
 * @param disabled  Whether the slider is disabled
 */
void ha_control_slider_set_disabled(lv_obj_t * ha_control_slider, bool disabled);

/**
 * Tooltip visibility mode
 * @param obj   pointer to a ha_control_slider
 * @param tooltip_mode  Tooltip visibility mode
 */
void ha_control_slider_set_tooltip_mode(lv_obj_t * ha_control_slider, ha_control_slider_tooltip_mode_t tooltip_mode);

/**
 * Unit string
 * @param obj   pointer to a ha_control_slider
 * @param unit  Unit string
 */
void ha_control_slider_set_unit(lv_obj_t * ha_control_slider, const char * unit);

/**
 * Track background color
 * @param obj   pointer to a ha_control_slider
 * @param track_color  Track background color
 */
void ha_control_slider_set_track_color(lv_obj_t * ha_control_slider, lv_color_t track_color);

/**
 * Active fill bar color
 * @param obj   pointer to a ha_control_slider
 * @param active_color  Active fill bar color
 */
void ha_control_slider_set_active_color(lv_obj_t * ha_control_slider, lv_color_t active_color);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SLIDER_GEN_H*/