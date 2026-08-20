/**
 * @file ha_big_number_private_gen.h
 *
 */

#ifndef HA_BIG_NUMBER_PRIVATE_H
#define HA_BIG_NUMBER_PRIVATE_H

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
#include "ha_big_number.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_BIG_NUMBER_USER_DATA
#define HA_BIG_NUMBER_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t value;
    int32_t decimal_places;
    const char * unit;
    unit_position_def_t unit_position;
    lv_color_t text_color;
    lv_font_t * integer_label_text_font;
    lv_font_t * decimal_label_text_font;
    lv_font_t * unit_label_text_font;
    lv_obj_t * integer_label;
    lv_obj_t * addon;
    lv_obj_t * decimal_label;
    lv_obj_t * unit_label;
    HA_BIG_NUMBER_USER_DATA
} ha_big_number_t;

extern const lv_obj_class_t ha_big_number_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_big_number_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_BIG_NUMBER_PRIVATE_H*/