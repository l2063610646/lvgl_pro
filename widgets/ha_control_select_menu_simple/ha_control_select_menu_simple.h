/**
 * @file ha_control_select_menu_simple.h
 *
 */

#ifndef HA_CONTROL_SELECT_MENU_SIMPLE_H
#define HA_CONTROL_SELECT_MENU_SIMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl/lvgl.h"
#include "../ha_control_select/ha_control_select.h"

/*********************
 *      DEFINES
 *********************/

#define HA_CONTROL_SELECT_MENU_SIMPLE_MAX_VAL_LEN    32
#define HA_CONTROL_SELECT_MENU_SIMPLE_MAX_LABEL_LEN  48
#define HA_CONTROL_SELECT_MENU_SIMPLE_MAX_SYM_LEN    32

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    char value[HA_CONTROL_SELECT_MENU_SIMPLE_MAX_VAL_LEN];
    char label[HA_CONTROL_SELECT_MENU_SIMPLE_MAX_LABEL_LEN];
    char symbol[HA_CONTROL_SELECT_MENU_SIMPLE_MAX_SYM_LEN];
} ha_control_select_menu_simple_option_store_t;

#define HA_CONTROL_SELECT_MENU_SIMPLE_USER_DATA \
    ha_control_select_menu_simple_option_store_t * options_data; \
    uint32_t option_count; \
    char selected_value[HA_CONTROL_SELECT_MENU_SIMPLE_MAX_VAL_LEN]; \
    lv_obj_t * icon_obj; \
    lv_obj_t * content_col; \
    lv_obj_t * title_label; \
    lv_obj_t * value_label; \
    lv_obj_t * arrow_obj; \
    lv_obj_t * active_mask;

#include "ha_control_select_menu_simple_gen.h"

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void ha_control_select_menu_simple_set_options_array(lv_obj_t * obj, const ha_control_select_option_t * options, uint32_t count);

const char * ha_control_select_menu_simple_get_value(lv_obj_t * obj);
uint32_t ha_control_select_menu_simple_get_option_count(lv_obj_t * obj);
const char * ha_control_select_menu_simple_get_label(lv_obj_t * obj);
bool ha_control_select_menu_simple_get_disabled(lv_obj_t * obj);
bool ha_control_select_menu_simple_get_hide_label(lv_obj_t * obj);
bool ha_control_select_menu_simple_get_show_arrow(lv_obj_t * obj);
lv_color_t ha_control_select_menu_simple_get_color(lv_obj_t * obj);
lv_color_t ha_control_select_menu_simple_get_modal_bg_color(lv_obj_t * obj);
lv_color_t ha_control_select_menu_simple_get_modal_text_color(lv_obj_t * obj);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_CONTROL_SELECT_MENU_SIMPLE_H*/
