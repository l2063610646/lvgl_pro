/**
 * @file ha_big_number_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_big_number_gen.h"

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
static unit_position_def_t unit_position_text_to_enum(const char * txt);

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

void * ha_big_number_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = ha_big_number_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create ha_big_number");
        return NULL;
    }

    return item;
}

void ha_big_number_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq("value", name)) {
            ha_big_number_set_value(item, lv_xml_atoi(value));
        } else if(lv_streq("decimal_places", name)) {
            ha_big_number_set_decimal_places(item, lv_xml_atoi(value));
        } else if(lv_streq("unit", name)) {
            ha_big_number_set_unit(item, value);
        } else if(lv_streq("unit_position", name)) {
            ha_big_number_set_unit_position(item, unit_position_text_to_enum(value));
        } else if(lv_streq("text_color", name)) {
            ha_big_number_set_text_color(item, lv_color_hex(lv_xml_atoi(value)));
        }
    }
}

void ha_big_number_register(void)
{
    lv_xml_register_widget("ha_big_number", ha_big_number_xml_create, ha_big_number_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static unit_position_def_t unit_position_text_to_enum(const char * txt)
{
    if(lv_streq(txt, "HA_BIG_NUMBER_UNIT_TOP")) {
        return UNIT_POSITION_DEF_HA_BIG_NUMBER_UNIT_TOP;
    }

    if(lv_streq(txt, "HA_BIG_NUMBER_UNIT_BOTTOM")) {
        return UNIT_POSITION_DEF_HA_BIG_NUMBER_UNIT_BOTTOM;
    }

    LV_LOG_WARN("%s is an unknown value for ha_big_number unit_position", txt);
    return UNIT_POSITION_DEF_HA_BIG_NUMBER_UNIT_BOTTOM;
}

#endif /* LV_USE_XML */
