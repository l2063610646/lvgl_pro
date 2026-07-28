/**
 * @file ha_ripple_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_ripple_gen.h"

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

void * ha_ripple_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = ha_ripple_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create ha_ripple");
        return NULL;
    }

    return item;
}

void ha_ripple_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("p_color", name)) {
            ha_ripple_set_p_color(item, lv_xml_to_color(value));
        } else if(lv_streq("p_hover_opacity", name)) {
            ha_ripple_set_p_hover_opacity(item, lv_xml_atoi(value));
        } else if(lv_streq("p_pressed_opacity", name)) {
            ha_ripple_set_p_pressed_opacity(item, lv_xml_atoi(value));
        } else if(lv_streq("p_radius", name)) {
            ha_ripple_set_p_radius(item, lv_xml_atoi(value));
        } else if(lv_streq("p_disabled", name)) {
            ha_ripple_set_p_disabled(item, lv_xml_to_bool(value));
        }
    }
}

void ha_ripple_register(void)
{
    lv_xml_register_widget("ha_ripple", ha_ripple_xml_create, ha_ripple_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */