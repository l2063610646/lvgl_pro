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
 *      INCLUDES
 *********************/

#include "lvgl/lvgl.h"

/*********************
 *      DEFINES
 *********************/

#define HA_CONTROL_SELECT_MAX_VALUE_LEN   32
#define HA_CONTROL_SELECT_MAX_LABEL_LEN   48
#define HA_CONTROL_SELECT_MAX_SYMBOL_LEN  32

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    const char * value;
    const char * label;
    const char * symbol;
} ha_control_select_option_t;

typedef struct {
    char value[HA_CONTROL_SELECT_MAX_VALUE_LEN];
    char label[HA_CONTROL_SELECT_MAX_LABEL_LEN];
    char symbol[HA_CONTROL_SELECT_MAX_SYMBOL_LEN];
    char display_text[96];
} ha_control_select_option_store_t;

#define HA_CONTROL_SELECT_USER_DATA \
    ha_control_select_option_store_t * options_data; \
    const char ** map; \
    uint32_t option_count; \
    char selected_value[HA_CONTROL_SELECT_MAX_VALUE_LEN];

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

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SELECT_H*/
