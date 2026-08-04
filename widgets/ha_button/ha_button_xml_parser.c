/**
 * @file ha_button_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_button.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML

/**********************
 *  STATIC PROTOTYPES
 **********************/

static bool text_to_bool(const char * value);
static ha_button_variant_t variant_text_to_enum(const char * value);
static ha_button_appearance_t appearance_text_to_enum(const char * value);
static ha_button_size_t size_text_to_enum(const char * value);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * ha_button_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = ha_button_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create ha_button");
        return NULL;
    }

    return item;
}

void ha_button_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    bool has_fg = false;
    bool has_bg = false;
    bool has_border = false;
    lv_color_t fg = lv_color_hex(0xffffff);
    lv_color_t bg = lv_color_hex(0x009ac7);
    lv_color_t border = lv_color_hex(0x009ac7);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("label", name) || lv_streq("text", name)) {
            ha_button_set_label(item, value);
        }
        else if(lv_streq("start_icon", name) || lv_streq("start_symbol", name)) {
            ha_button_set_start_icon(item, value);
        }
        else if(lv_streq("end_icon", name) || lv_streq("end_symbol", name)) {
            ha_button_set_end_icon(item, value);
        }
        else if(lv_streq("variant", name)) {
            ha_button_set_variant(item, variant_text_to_enum(value));
        }
        else if(lv_streq("appearance", name)) {
            ha_button_set_appearance(item, appearance_text_to_enum(value));
        }
        else if(lv_streq("size", name)) {
            ha_button_set_size(item, size_text_to_enum(value));
        }
        else if(lv_streq("height", name)) {
            ha_button_set_height(item, lv_xml_atoi(value));
        }
        else if(lv_streq("disabled", name)) {
            ha_button_set_disabled(item, text_to_bool(value));
        }
        else if(lv_streq("loading", name)) {
            ha_button_set_loading(item, text_to_bool(value));
        }
        else if(lv_streq("selected", name)) {
            ha_button_set_selected(item, text_to_bool(value));
        }
        else if(lv_streq("fg_color", name)) {
            fg = lv_xml_to_color(value);
            has_fg = true;
        }
        else if(lv_streq("bg_color", name)) {
            bg = lv_xml_to_color(value);
            has_bg = true;
        }
        else if(lv_streq("border_color", name)) {
            border = lv_xml_to_color(value);
            has_border = true;
        }
    }

    if(has_fg || has_bg || has_border) {
        if(!has_border) border = bg;
        ha_button_set_colors(item, fg, bg, border);
    }
}

void ha_button_register(void)
{
    lv_xml_register_widget("ha_button", ha_button_xml_create, ha_button_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static bool text_to_bool(const char * value)
{
    return lv_streq(value, "true") || lv_streq(value, "1");
}

static ha_button_variant_t variant_text_to_enum(const char * value)
{
    if(lv_streq(value, "NEUTRAL") || lv_streq(value, "neutral") || lv_streq(value, "1")) {
        return HA_BUTTON_VARIANT_NEUTRAL;
    }
    if(lv_streq(value, "SUCCESS") || lv_streq(value, "success") || lv_streq(value, "2")) {
        return HA_BUTTON_VARIANT_SUCCESS;
    }
    if(lv_streq(value, "WARNING") || lv_streq(value, "warning") || lv_streq(value, "3")) {
        return HA_BUTTON_VARIANT_WARNING;
    }
    if(lv_streq(value, "DANGER") || lv_streq(value, "danger") || lv_streq(value, "4")) {
        return HA_BUTTON_VARIANT_DANGER;
    }
    return HA_BUTTON_VARIANT_BRAND;
}

static ha_button_appearance_t appearance_text_to_enum(const char * value)
{
    if(lv_streq(value, "FILLED") || lv_streq(value, "filled") || lv_streq(value, "1")) {
        return HA_BUTTON_APPEARANCE_FILLED;
    }
    if(lv_streq(value, "PLAIN") || lv_streq(value, "plain") || lv_streq(value, "2")) {
        return HA_BUTTON_APPEARANCE_PLAIN;
    }
    if(lv_streq(value, "OUTLINED") || lv_streq(value, "outlined") || lv_streq(value, "3")) {
        return HA_BUTTON_APPEARANCE_OUTLINED;
    }
    return HA_BUTTON_APPEARANCE_ACCENT;
}

static ha_button_size_t size_text_to_enum(const char * value)
{
    if(lv_streq(value, "XS") || lv_streq(value, "xs") || lv_streq(value, "0")) {
        return HA_BUTTON_SIZE_XS;
    }
    if(lv_streq(value, "S") || lv_streq(value, "s") || lv_streq(value, "1")) {
        return HA_BUTTON_SIZE_S;
    }
    if(lv_streq(value, "L") || lv_streq(value, "l") || lv_streq(value, "3")) {
        return HA_BUTTON_SIZE_L;
    }
    if(lv_streq(value, "XL") || lv_streq(value, "xl") || lv_streq(value, "4")) {
        return HA_BUTTON_SIZE_XL;
    }
    return HA_BUTTON_SIZE_M;
}

#endif /* LV_USE_XML */
