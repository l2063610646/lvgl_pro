/**
 * @file ha_control_circular_slider_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_circular_slider.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if LV_USE_XML



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * ha_control_circular_slider_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = ha_control_circular_slider_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create ha_control_circular_slider");
        return NULL;
    }

    return item;
}

void ha_control_circular_slider_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    ha_control_circular_slider_set_cur_value(item, 40);
    ha_control_circular_slider_set_low_knob_value(item, 0);
    ha_control_circular_slider_set_high_knob_value(item, 100);
    ha_control_circular_slider_set_low(item, 20);
    ha_control_circular_slider_set_high(item, 80);
    ha_control_circular_slider_set_dual(item, false);
    ha_control_circular_slider_set_min(item, 0);
    ha_control_circular_slider_set_max(item, 100);
    ha_control_circular_slider_set_step(item, 1);
    ha_control_circular_slider_set_size(item, 320);
    ha_control_circular_slider_set_updating_low(item, false);
    ha_control_circular_slider_set_updating_high(item, false);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq("cur_value", name)) {
            ha_control_circular_slider_set_cur_value(item, lv_xml_atoi(value));
        } else if(lv_streq("low_knob_value", name)) {
            ha_control_circular_slider_set_low_knob_value(item, lv_xml_atoi(value));
        } else if(lv_streq("high_knob_value", name)) {
            ha_control_circular_slider_set_high_knob_value(item, lv_xml_atoi(value));
        } else if(lv_streq("low", name)) {
            ha_control_circular_slider_set_low(item, lv_xml_atoi(value));
        } else if(lv_streq("high", name)) {
            ha_control_circular_slider_set_high(item, lv_xml_atoi(value));
        } else if(lv_streq("dual", name)) {
            ha_control_circular_slider_set_dual(item, lv_streq(value, "true") || lv_streq(value, "1"));
        } else if(lv_streq("updating_low", name)) {
            ha_control_circular_slider_set_updating_low(item, lv_streq(value, "true") || lv_streq(value, "1"));
        } else if(lv_streq("updating_high", name)) {
            ha_control_circular_slider_set_updating_high(item, lv_streq(value, "true") || lv_streq(value, "1"));
        } else if(lv_streq("min", name)) {
            ha_control_circular_slider_set_min(item, lv_xml_atoi(value));
        } else if(lv_streq("max", name)) {
            ha_control_circular_slider_set_max(item, lv_xml_atoi(value));
        } else if(lv_streq("step", name)) {
            ha_control_circular_slider_set_step(item, lv_xml_atoi(value));
        } else if(lv_streq("size", name)) {
            ha_control_circular_slider_set_size(item, lv_xml_atoi(value));
        }
    }
}

void ha_control_circular_slider_register(void)
{
    lv_xml_register_widget("ha_control_circular_slider", ha_control_circular_slider_xml_create, ha_control_circular_slider_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */
