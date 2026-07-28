/**
 * @file hui_heading_badge_private_gen.h
 *
 */

#ifndef HUI_HEADING_BADGE_PRIVATE_H
#define HUI_HEADING_BADGE_PRIVATE_H

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
#include "hui_heading_badge.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HUI_HEADING_BADGE_USER_DATA
#define HUI_HEADING_BADGE_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    hui_heading_badge_type_def_t h_type;
    const char * text;
    const char * icon;
    lv_color_t text_color;
    lv_color_t icon_color;
    lv_obj_t * ripple;
    lv_obj_t * label_icon;
    lv_obj_t * label_text;
    HUI_HEADING_BADGE_USER_DATA
} hui_heading_badge_t;

extern const lv_obj_class_t hui_heading_badge_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void hui_heading_badge_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HUI_HEADING_BADGE_PRIVATE_H*/