/**
 * @file ha_ripple_gen.h
 *
 */

#ifndef HA_RIPPLE_GEN_H
#define HA_RIPPLE_GEN_H

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
 * Create a ha_ripple object
 * @param parent pointer to an object, it will be the parent of the new ha_ripple
 * @return pointer to the created ha_ripple
 */
lv_obj_t * ha_ripple_create(lv_obj_t * parent);
/**
 * ha_ripple p_color
 * @param obj   pointer to a ha_ripple
 * @param p_color  p_color
 */
void ha_ripple_set_p_color(lv_obj_t * ha_ripple, lv_color_t p_color);

/**
 * ha_ripple p_hover_opacity
 * @param obj   pointer to a ha_ripple
 * @param p_hover_opacity  p_hover_opacity
 */
void ha_ripple_set_p_hover_opacity(lv_obj_t * ha_ripple, int32_t p_hover_opacity);

/**
 * ha_ripple p_pressed_opacity
 * @param obj   pointer to a ha_ripple
 * @param p_pressed_opacity  p_pressed_opacity
 */
void ha_ripple_set_p_pressed_opacity(lv_obj_t * ha_ripple, int32_t p_pressed_opacity);

/**
 * ha_ripple p_radius
 * @param obj   pointer to a ha_ripple
 * @param p_radius  p_radius
 */
void ha_ripple_set_p_radius(lv_obj_t * ha_ripple, int32_t p_radius);

/**
 * ha_ripple p_disabled
 * @param obj   pointer to a ha_ripple
 * @param p_disabled  p_disabled
 */
void ha_ripple_set_p_disabled(lv_obj_t * ha_ripple, bool p_disabled);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_RIPPLE_GEN_H*/