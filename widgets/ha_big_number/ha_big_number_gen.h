/**
 * @file ha_big_number_gen.h
 *
 */

#ifndef HA_BIG_NUMBER_GEN_H
#define HA_BIG_NUMBER_GEN_H

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
    UNIT_POSITION_DEF_HA_BIG_NUMBER_UNIT_TOP = 0,
    UNIT_POSITION_DEF_HA_BIG_NUMBER_UNIT_BOTTOM = 1
}unit_position_def_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a ha_big_number object
 * @param parent pointer to an object, it will be the parent of the new ha_big_number
 * @return pointer to the created ha_big_number
 */
lv_obj_t * ha_big_number_create(lv_obj_t * parent);
/**
 * ha_big_number value
 * @param obj   pointer to a ha_big_number
 * @param value  value
 */
void ha_big_number_set_value(lv_obj_t * ha_big_number, int32_t value);

/**
 * ha_big_number decimal_places
 * @param obj   pointer to a ha_big_number
 * @param decimal_places  decimal_places
 */
void ha_big_number_set_decimal_places(lv_obj_t * ha_big_number, int32_t decimal_places);

/**
 * ha_big_number unit
 * @param obj   pointer to a ha_big_number
 * @param unit  unit
 */
void ha_big_number_set_unit(lv_obj_t * ha_big_number, const char * unit);

/**
 * ha_big_number unit_position
 * @param obj   pointer to a ha_big_number
 * @param unit_position  unit_position
 */
void ha_big_number_set_unit_position(lv_obj_t * ha_big_number, unit_position_def_t unit_position);

/**
 * ha_big_number text_color
 * @param obj   pointer to a ha_big_number
 * @param text_color  text_color
 */
void ha_big_number_set_text_color(lv_obj_t * ha_big_number, lv_color_t text_color);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_BIG_NUMBER_GEN_H*/