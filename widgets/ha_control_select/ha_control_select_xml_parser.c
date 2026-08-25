/**
 * @file ha_control_select_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_select_gen.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML

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

void * ha_control_select_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = ha_control_select_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create ha_control_select");
        return NULL;
    }

    return item;
}

void ha_control_select_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    /* Apply common object properties like width, height, align, etc. */
    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs && attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("value", name)) {
            ha_control_select_set_value(item, value);
        } else if(lv_streq("options", name)) {
            ha_control_select_set_options(item, value);
        } else if(lv_streq("label", name)) {
            ha_control_select_set_label(item, value);
        } else if(lv_streq("disabled", name)) {
            ha_control_select_set_disabled(item, lv_xml_to_bool(value));
        } else if(lv_streq("vertical", name)) {
            ha_control_select_set_vertical(item, lv_xml_to_bool(value));
        } else if(lv_streq("hide_option_label", name) || lv_streq("hide-option-label", name)) {
            ha_control_select_set_hide_option_label(item, lv_xml_to_bool(value));
        } else if(lv_streq("color", name)) {
            ha_control_select_set_color(item, lv_xml_to_color(value));
        } else if(lv_streq("height", name)) {
            ha_control_select_set_height(item, lv_xml_to_size(value));
        }
    }
}

void ha_control_select_register(void)
{
    lv_xml_register_widget("ha_control_select", ha_control_select_xml_create, ha_control_select_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */
