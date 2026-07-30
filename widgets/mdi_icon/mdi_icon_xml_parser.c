/**
 * @file mdi_icon_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "mdi_icon_gen.h"

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

void * mdi_icon_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = mdi_icon_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create mdi_icon");
        return NULL;
    }

    return item;
}

void mdi_icon_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq("size", name)) {
            mdi_icon_set_size(item, lv_xml_atoi(value));
        } else if(lv_streq("symbol", name)) {
            mdi_icon_set_symbol(item, value);
        }
    }
}

void mdi_icon_register(void)
{
    lv_xml_register_widget("mdi_icon", mdi_icon_xml_create, mdi_icon_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */
