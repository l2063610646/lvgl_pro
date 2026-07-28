/**
 * @file hui_heading_badge_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_badge_gen.h"

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

void * hui_heading_badge_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = hui_heading_badge_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create hui_heading_badge");
        return NULL;
    }

    return item;
}

void hui_heading_badge_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("text", name)) {
            hui_heading_badge_set_text(item, value);
        } else if(lv_streq("icon", name)) {
            hui_heading_badge_set_icon(item, value);
        } else if(lv_streq("h_type", name)) {
            if(lv_streq(value, "TEXT")) {
                hui_heading_badge_set_h_type(item, HUI_HEADING_BADGE_TYPE_DEF_TEXT);
            } else {
                hui_heading_badge_set_h_type(item, HUI_HEADING_BADGE_TYPE_DEF_BUTTON);
            }
        } else if(lv_streq("text_color", name)) {
            hui_heading_badge_set_text_color(item, lv_xml_to_color(value));
        } else if(lv_streq("icon_color", name)) {
            hui_heading_badge_set_icon_color(item, lv_xml_to_color(value));
        }
    }
}

void hui_heading_badge_register(void)
{
    lv_xml_register_widget("hui_heading_badge", hui_heading_badge_xml_create, hui_heading_badge_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */