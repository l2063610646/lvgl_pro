/**
 * @file ha_outlined_icon_button_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_outlined_icon_button_gen.h"

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

void * ha_outlined_icon_button_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = ha_outlined_icon_button_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create ha_outlined_icon_button");
        return NULL;
    }

    return item;
}

void ha_outlined_icon_button_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq("size", name)) {
            ha_outlined_icon_button_set_size(item, lv_xml_atoi(value));
        } else if(lv_streq("icon_size", name)) {
            ha_outlined_icon_button_set_icon_size(item, lv_xml_atoi(value));
        } else if(lv_streq("symbol", name)) {
            ha_outlined_icon_button_set_symbol(item, value);
        } else if(lv_streq("outline_color", name)) {
            ha_outlined_icon_button_set_outline_color(item, lv_xml_to_color(value));
        } else if(lv_streq("text_color", name)) {
            ha_outlined_icon_button_set_text_color(item, lv_xml_to_color(value));
        } else if(lv_streq("disabled", name)) {
            ha_outlined_icon_button_set_disabled(item, lv_xml_to_bool(value));
        } else if(lv_streq("no_ripple", name)) {
            ha_outlined_icon_button_set_no_ripple(item, lv_xml_to_bool(value));
        }
    }
}

void ha_outlined_icon_button_register(void)
{
    lv_xml_register_widget("ha_outlined_icon_button", ha_outlined_icon_button_xml_create, ha_outlined_icon_button_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */
