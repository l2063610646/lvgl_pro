/**
 * @file ha_control_slider_xml_parser.c
 */

#include "ha_control_slider_private_gen.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML

static ha_control_slider_mode_t mode_from_text(const char * value)
{
    if(lv_streq(value, "end") || lv_streq(value, "HA_CONTROL_SLIDER_MODE_END")) return HA_CONTROL_SLIDER_MODE_END;
    if(lv_streq(value, "cursor") || lv_streq(value, "HA_CONTROL_SLIDER_MODE_CURSOR")) return HA_CONTROL_SLIDER_MODE_CURSOR;
    return HA_CONTROL_SLIDER_MODE_START;
}

static ha_control_slider_tooltip_mode_t tooltip_mode_from_text(const char * value)
{
    if(lv_streq(value, "never") || lv_streq(value, "HA_CONTROL_SLIDER_TOOLTIP_NEVER")) return HA_CONTROL_SLIDER_TOOLTIP_NEVER;
    if(lv_streq(value, "always") || lv_streq(value, "HA_CONTROL_SLIDER_TOOLTIP_ALWAYS")) return HA_CONTROL_SLIDER_TOOLTIP_ALWAYS;
    return HA_CONTROL_SLIDER_TOOLTIP_INTERACTION;
}

void * ha_control_slider_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    return ha_control_slider_create(lv_xml_state_get_parent(state));
}

void ha_control_slider_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    lv_obj_t * item = lv_xml_state_get_item(state);
    lv_xml_obj_apply(state, attrs);

    ha_control_slider_set_range(item, 0, 100);
    ha_control_slider_set_step(item, 1);
    ha_control_slider_set_value(item, 40);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq(name, "value")) ha_control_slider_set_value(item, lv_xml_atoi(value));
        else if(lv_streq(name, "min")) ha_control_slider_set_min(item, lv_xml_atoi(value));
        else if(lv_streq(name, "max")) ha_control_slider_set_max(item, lv_xml_atoi(value));
        else if(lv_streq(name, "step")) ha_control_slider_set_step(item, lv_xml_atoi(value));
        else if(lv_streq(name, "mode")) ha_control_slider_set_mode(item, mode_from_text(value));
        else if(lv_streq(name, "vertical")) ha_control_slider_set_vertical(item, lv_streq(value, "true") || lv_streq(value, "1"));
        else if(lv_streq(name, "show_handle")) ha_control_slider_set_show_handle(item, lv_streq(value, "true") || lv_streq(value, "1"));
        else if(lv_streq(name, "inverted")) ha_control_slider_set_inverted(item, lv_streq(value, "true") || lv_streq(value, "1"));
        else if(lv_streq(name, "disabled")) ha_control_slider_set_disabled(item, lv_streq(value, "true") || lv_streq(value, "1"));
        else if(lv_streq(name, "tooltip_mode")) ha_control_slider_set_tooltip_mode(item, tooltip_mode_from_text(value));
        else if(lv_streq(name, "unit")) ha_control_slider_set_unit(item, value);
        else if(lv_streq(name, "track_color")) ha_control_slider_set_track_color(item, lv_xml_to_color(value));
        else if(lv_streq(name, "active_color")) ha_control_slider_set_active_color(item, lv_xml_to_color(value));
    }
}

void ha_control_slider_register(void)
{
    lv_xml_register_widget("ha_control_slider", ha_control_slider_xml_create, ha_control_slider_xml_apply);
}

#endif /* LV_USE_XML */