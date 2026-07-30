/**
 * @file ha_control_circular_slider.h
 *
 */

#ifndef HA_CONTROL_CIRCULAR_SLIDER_H
#define HA_CONTROL_CIRCULAR_SLIDER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_circular_slider_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    int32_t value;
    bool is_low;
} ha_control_circular_slider_value_changed_event_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
int32_t ha_control_circular_slider_get_current(lv_obj_t * ha_control_circular_slider);
int32_t ha_control_circular_slider_get_value(lv_obj_t * ha_control_circular_slider);
int32_t ha_control_circular_slider_get_low(lv_obj_t * ha_control_circular_slider);
int32_t ha_control_circular_slider_get_high(lv_obj_t * ha_control_circular_slider);
void ha_control_circular_slider_set_range(lv_obj_t * ha_control_circular_slider, int32_t min, int32_t max);
void ha_control_circular_slider_set_step(lv_obj_t * ha_control_circular_slider, int32_t step);

/**********************
 *      MACROS
 **********************/

#define HA_CONTROL_CIRCULAR_SLIDER_USER_DATA \
    int32_t slider_step; \
    bool updating_low; \
    bool updating_high;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_CIRCULAR_SLIDER_H*/
