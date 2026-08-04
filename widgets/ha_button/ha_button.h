/**
 * @file ha_button.h
 *
 */

#ifndef HA_BUTTON_H
#define HA_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "ha_button_gen.h"

/*********************
 *      DEFINES
 *********************/

#define HA_BUTTON_USER_DATA    \
    bool custom_colors;

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void ha_button_refresh(lv_obj_t * obj);
void ha_button_set_colors(lv_obj_t * obj, lv_color_t fg, lv_color_t bg, lv_color_t border);

const char * ha_button_get_label(lv_obj_t * obj);
bool ha_button_get_disabled(lv_obj_t * obj);
bool ha_button_get_loading(lv_obj_t * obj);
bool ha_button_get_selected(lv_obj_t * obj);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_BUTTON_H*/
