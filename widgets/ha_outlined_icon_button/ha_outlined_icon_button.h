/**
 * @file ha_outlined_icon_button.h
 *
 */

#ifndef HA_OUTLINED_ICON_BUTTON_H
#define HA_OUTLINED_ICON_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "ha_outlined_icon_button_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

int32_t ha_outlined_icon_button_get_size(lv_obj_t * obj);
int32_t ha_outlined_icon_button_get_icon_size(lv_obj_t * obj);
const char * ha_outlined_icon_button_get_symbol(lv_obj_t * obj);
lv_color_t ha_outlined_icon_button_get_outline_color(lv_obj_t * obj);
lv_color_t ha_outlined_icon_button_get_text_color(lv_obj_t * obj);
bool ha_outlined_icon_button_get_disabled(lv_obj_t * obj);
bool ha_outlined_icon_button_get_no_ripple(lv_obj_t * obj);

/**********************
 *      MACROS
 **********************/

#define HA_OUTLINED_ICON_BUTTON_USER_DATA

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_OUTLINED_ICON_BUTTON_H*/
