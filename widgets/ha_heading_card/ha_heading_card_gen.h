/**
 * @file ha_heading_card_gen.h
 *
 */

#ifndef HA_HEADING_CARD_GEN_H
#define HA_HEADING_CARD_GEN_H

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
 * Create a ha_heading_card object
 * @param parent pointer to an object, it will be the parent of the new ha_heading_card
 * @return pointer to the created ha_heading_card
 */
lv_obj_t * ha_heading_card_create(lv_obj_t * parent);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_HEADING_CARD_GEN_H*/