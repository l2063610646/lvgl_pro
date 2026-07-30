/**
 * @file hui_heading_card_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_card_gen.h"

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

void * hui_heading_card_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = hui_heading_card_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create hui_heading_card");
        return NULL;
    }

    return item;
}

void hui_heading_card_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("heading", name)) {
            hui_heading_card_set_heading(item, value);
        } else if(lv_streq("icon", name)) {
            hui_heading_card_set_icon(item, value);
        } else if(lv_streq("actionable", name)) {
            hui_heading_card_set_actionable(item, lv_streq(value, "true") || lv_streq(value, "1"));
        }
    }
}

void hui_heading_card_badge_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);
    lv_xml_obj_apply(state, attrs);
}

void * hui_heading_card_badge_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    lv_obj_t * parent = lv_xml_state_get_parent(state);
    const char * h_type = NULL;
    const char * icon = NULL;
    const char * text = NULL;

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq("h_type", name)) {
            h_type = value;
        } else if(lv_streq("icon", name)) {
            icon = value;
        } else if(lv_streq("text", name)) {
            text = value;
        }
    }

    void * item = hui_heading_card_add_badge(parent, h_type, icon, text);
    return item;
}

void hui_heading_card_register(void)
{
    lv_xml_register_widget("hui_heading_card", hui_heading_card_xml_create, hui_heading_card_xml_apply);
    lv_xml_register_widget("hui_heading_card-badge", hui_heading_card_badge_xml_create, hui_heading_card_badge_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */