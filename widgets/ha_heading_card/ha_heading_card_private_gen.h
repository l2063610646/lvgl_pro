/**
 * @file ha_heading_card_private_gen.h
 *
 */

#ifndef HA_HEADING_CARD_PRIVATE_H
#define HA_HEADING_CARD_PRIVATE_H

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
#include "ha_heading_card.h"

/*********************
 *      DEFINES
 *********************/

#ifndef HA_HEADING_CARD_USER_DATA
#define HA_HEADING_CARD_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_obj_t * main;
    lv_obj_t * title_ctn;
    lv_obj_t * title_row;
    lv_obj_t * title_icon;
    lv_obj_t * title_label;
    lv_obj_t * badges_ctn;
    lv_obj_t * badges_row;
    lv_obj_t * hui_heading_badge_0;
    lv_obj_t * hui_heading_badge_1;
    lv_obj_t * hui_heading_badge_2;
    lv_obj_t * hui_heading_badge_3;
    HA_HEADING_CARD_USER_DATA
} ha_heading_card_t;

extern const lv_obj_class_t ha_heading_card_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void ha_heading_card_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_HEADING_CARD_PRIVATE_H*/