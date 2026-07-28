/**
 * @file ha_ripple.h
 *
 */

#ifndef HA_RIPPLE_H
#define HA_RIPPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "ha_ripple_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void ha_ripple_attach(lv_obj_t * obj, lv_obj_t * control);
void ha_ripple_detach(lv_obj_t * obj);


/**********************
 *      MACROS
 **********************/

#define HA_RIPPLE_USER_DATA \
    lv_obj_t * control;     \
    lv_color_t color;       \
    uint8_t hover_opacity;  \
    uint8_t pressed_opacity;\
    int32_t radius;         \
    bool disabled;          \
    int32_t ripple_x;       \
    int32_t ripple_y;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_RIPPLE_H*/