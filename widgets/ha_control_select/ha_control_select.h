/**
 * @file ha_control_select.h
 *
 */

#ifndef HA_CONTROL_SELECT_H
#define HA_CONTROL_SELECT_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      DEFINES
 *********************/

#define HA_CONTROL_SELECT_MAX_VALUE_LEN   32
#define HA_CONTROL_SELECT_MAX_LABEL_LEN   48
#define HA_CONTROL_SELECT_MAX_SYMBOL_LEN  16

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    char value[HA_CONTROL_SELECT_MAX_VALUE_LEN];
    char label[HA_CONTROL_SELECT_MAX_LABEL_LEN];
    char symbol[HA_CONTROL_SELECT_MAX_SYMBOL_LEN];
} ha_control_select_option_store_t;

typedef struct {
    const char * value;
    const char * label;
    const char * symbol;
} ha_control_select_option_t;

#define HA_CONTROL_SELECT_USER_DATA \
    lv_obj_t ** buttons; \
    ha_control_select_option_store_t * options_data; \
    uint32_t option_count; \
    char selected_value[HA_CONTROL_SELECT_MAX_VALUE_LEN];

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_select_gen.h"

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void ha_control_select_set_options_array(lv_obj_t * obj, const ha_control_select_option_t * options, uint32_t count);

const char * ha_control_select_get_value(lv_obj_t * obj);
uint32_t ha_control_select_get_option_count(lv_obj_t * obj);
const char * ha_control_select_get_label(lv_obj_t * obj);
bool ha_control_select_get_disabled(lv_obj_t * obj);
bool ha_control_select_get_vertical(lv_obj_t * obj);
bool ha_control_select_get_hide_option_label(lv_obj_t * obj);
lv_color_t ha_control_select_get_color(lv_obj_t * obj);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SELECT_H*/
