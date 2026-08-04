/**
 * @file ha_button.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_button_private_gen.h"

/*********************
 *      DEFINES
 *********************/

#define DEFAULT_HEIGHT 40
#define DEFAULT_PAD_X  16
#define ICON_PAD_X     8
#define ICON_GAP       4

/**********************
 *  STATIC PROTOTYPES
 **********************/

static lv_color_t fill_color(ha_button_variant_t variant, ha_button_appearance_t appearance);
static lv_color_t pressed_fill_color(ha_button_variant_t variant, ha_button_appearance_t appearance);
static lv_color_t on_color(ha_button_variant_t variant, ha_button_appearance_t appearance);
static lv_color_t border_loud_color(ha_button_variant_t variant);
static void update_text(ha_button_t * widget);
static void update_styles(ha_button_t * widget);
static void set_label_color(ha_button_t * widget, lv_color_t color);
static bool string_is_empty(const char * str);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ha_button_refresh(lv_obj_t * obj)
{
    ha_button_t * widget = (ha_button_t *) obj;
    update_text(widget);
    update_styles(widget);
}

void ha_button_constructor_hook(lv_obj_t * obj)
{
    ha_button_t * widget = (ha_button_t *) obj;

    if(widget->label == NULL) widget->label = "Button";
    if(widget->variant < HA_BUTTON_VARIANT_BRAND || widget->variant > HA_BUTTON_VARIANT_DANGER) {
        widget->variant = HA_BUTTON_VARIANT_BRAND;
    }
    if(widget->appearance < HA_BUTTON_APPEARANCE_ACCENT || widget->appearance > HA_BUTTON_APPEARANCE_OUTLINED) {
        widget->appearance = HA_BUTTON_APPEARANCE_ACCENT;
    }
    if(widget->size < HA_BUTTON_SIZE_XS || widget->size > HA_BUTTON_SIZE_XL) {
        widget->size = HA_BUTTON_SIZE_M;
    }

    lv_obj_remove_style_all(obj);
    lv_obj_set_width(obj, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_remove_flag(widget->start_icon_obj, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(widget->label_obj, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(widget->end_icon_obj, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(widget->spinner_obj, LV_OBJ_FLAG_HIDDEN);

    ha_button_refresh(obj);
}

void ha_button_destructor_hook(lv_obj_t * obj)
{
    LV_UNUSED(obj);
}

void ha_button_event_hook(lv_event_t * e)
{
    LV_UNUSED(e);
}

void ha_button_set_label(lv_obj_t * obj, const char * label)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->label = label;
    update_text(widget);
}

void ha_button_set_text(lv_obj_t * obj, const char * text)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->text = text;
    widget->label = text;
    update_text(widget);
}

void ha_button_set_start_icon(lv_obj_t * obj, const char * icon)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->start_icon = icon;
    update_text(widget);
    update_styles(widget);
}

void ha_button_set_start_symbol(lv_obj_t * obj, const char * symbol)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->start_symbol = symbol;
    widget->start_icon = symbol;
    update_text(widget);
    update_styles(widget);
}

void ha_button_set_end_icon(lv_obj_t * obj, const char * icon)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->end_icon = icon;
    update_text(widget);
    update_styles(widget);
}

void ha_button_set_end_symbol(lv_obj_t * obj, const char * symbol)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->end_symbol = symbol;
    widget->end_icon = symbol;
    update_text(widget);
    update_styles(widget);
}

void ha_button_set_variant(lv_obj_t * obj, ha_button_variant_t variant)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->variant = variant;
    update_styles(widget);
}

void ha_button_set_appearance(lv_obj_t * obj, ha_button_appearance_t appearance)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->appearance = appearance;
    update_styles(widget);
}

void ha_button_set_size(lv_obj_t * obj, ha_button_size_t size)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->size = size;
    update_styles(widget);
}

void ha_button_set_height(lv_obj_t * obj, lv_coord_t height)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->height = height;
    update_styles(widget);
}

void ha_button_set_disabled(lv_obj_t * obj, bool disabled)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->disabled = disabled;
    update_styles(widget);
}

void ha_button_set_loading(lv_obj_t * obj, bool loading)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->loading = loading;
    update_text(widget);
    update_styles(widget);
}

void ha_button_set_selected(lv_obj_t * obj, bool selected)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->selected = selected;
    update_styles(widget);
}

void ha_button_set_colors(lv_obj_t * obj, lv_color_t fg, lv_color_t bg, lv_color_t border)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->fg_color = fg;
    widget->bg_color = bg;
    widget->border_color = border;
    widget->custom_colors = true;
    update_styles(widget);
}

void ha_button_set_fg_color(lv_obj_t * obj, lv_color_t fg_color)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->fg_color = fg_color;
    widget->custom_colors = true;
    update_styles(widget);
}

void ha_button_set_bg_color(lv_obj_t * obj, lv_color_t bg_color)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->bg_color = bg_color;
    widget->custom_colors = true;
    update_styles(widget);
}

void ha_button_set_border_color(lv_obj_t * obj, lv_color_t border_color)
{
    ha_button_t * widget = (ha_button_t *) obj;
    widget->border_color = border_color;
    widget->custom_colors = true;
    update_styles(widget);
}

const char * ha_button_get_label(lv_obj_t * obj)
{
    ha_button_t * widget = (ha_button_t *) obj;
    return widget->label ? widget->label : "";
}

bool ha_button_get_disabled(lv_obj_t * obj)
{
    ha_button_t * widget = (ha_button_t *) obj;
    return widget->disabled;
}

bool ha_button_get_loading(lv_obj_t * obj)
{
    ha_button_t * widget = (ha_button_t *) obj;
    return widget->loading;
}

bool ha_button_get_selected(lv_obj_t * obj)
{
    ha_button_t * widget = (ha_button_t *) obj;
    return widget->selected;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static lv_color_t fill_color(ha_button_variant_t variant, ha_button_appearance_t appearance)
{
    if(appearance == HA_BUTTON_APPEARANCE_FILLED) {
        switch(variant) {
            case HA_BUTTON_VARIANT_NEUTRAL:
                return lv_color_hex(0xe6e6e6);
            case HA_BUTTON_VARIANT_SUCCESS:
                return lv_color_hex(0xc2f2c1);
            case HA_BUTTON_VARIANT_WARNING:
                return lv_color_hex(0xffe0c8);
            case HA_BUTTON_VARIANT_DANGER:
                return lv_color_hex(0xffdedc);
            case HA_BUTTON_VARIANT_BRAND:
            default:
                return lv_color_hex(0xdff3fc);
        }
    }

    if(appearance == HA_BUTTON_APPEARANCE_PLAIN || appearance == HA_BUTTON_APPEARANCE_OUTLINED) {
        switch(variant) {
            case HA_BUTTON_VARIANT_NEUTRAL:
                return lv_color_hex(0xe6e6e6);
            case HA_BUTTON_VARIANT_SUCCESS:
                return lv_color_hex(0xc2f2c1);
            case HA_BUTTON_VARIANT_WARNING:
                return lv_color_hex(0xffe0c8);
            case HA_BUTTON_VARIANT_DANGER:
                return lv_color_hex(0xffdedc);
            case HA_BUTTON_VARIANT_BRAND:
            default:
                return lv_color_hex(0xdff3fc);
        }
    }

    switch(variant) {
        case HA_BUTTON_VARIANT_NEUTRAL:
            return lv_color_hex(0x5e5e5e);
        case HA_BUTTON_VARIANT_SUCCESS:
            return lv_color_hex(0x00883c);
        case HA_BUTTON_VARIANT_WARNING:
            return lv_color_hex(0xff9342);
        case HA_BUTTON_VARIANT_DANGER:
            return lv_color_hex(0xdc3146);
        case HA_BUTTON_VARIANT_BRAND:
        default:
            return lv_color_hex(0x009ac7);
    }
}

static lv_color_t pressed_fill_color(ha_button_variant_t variant, ha_button_appearance_t appearance)
{
    if(appearance == HA_BUTTON_APPEARANCE_PLAIN || appearance == HA_BUTTON_APPEARANCE_OUTLINED) {
        switch(variant) {
            case HA_BUTTON_VARIANT_NEUTRAL:
                return lv_color_hex(0xe6e6e6);
            case HA_BUTTON_VARIANT_SUCCESS:
                return lv_color_hex(0xe3f9e3);
            case HA_BUTTON_VARIANT_WARNING:
                return lv_color_hex(0xfff0e4);
            case HA_BUTTON_VARIANT_DANGER:
                return lv_color_hex(0xfff0ef);
            case HA_BUTTON_VARIANT_BRAND:
            default:
                return lv_color_hex(0xeff9fe);
        }
    }

    return fill_color(variant, appearance);
}

static lv_color_t on_color(ha_button_variant_t variant, ha_button_appearance_t appearance)
{
    if(appearance == HA_BUTTON_APPEARANCE_ACCENT) {
        return lv_color_hex(0xffffff);
    }

    switch(variant) {
        case HA_BUTTON_VARIANT_NEUTRAL:
            return lv_color_hex(0x5e5e5e);
        case HA_BUTTON_VARIANT_SUCCESS:
            return lv_color_hex(0x036730);
        case HA_BUTTON_VARIANT_WARNING:
            return lv_color_hex(0x9d3800);
        case HA_BUTTON_VARIANT_DANGER:
            return lv_color_hex(0xb30532);
        case HA_BUTTON_VARIANT_BRAND:
        default:
            return lv_color_hex(0x009ac7);
    }
}

static lv_color_t border_loud_color(ha_button_variant_t variant)
{
    switch(variant) {
        case HA_BUTTON_VARIANT_NEUTRAL:
            return lv_color_hex(0x5e5e5e);
        case HA_BUTTON_VARIANT_SUCCESS:
            return lv_color_hex(0x036730);
        case HA_BUTTON_VARIANT_WARNING:
            return lv_color_hex(0x9d3800);
        case HA_BUTTON_VARIANT_DANGER:
            return lv_color_hex(0xb30532);
        case HA_BUTTON_VARIANT_BRAND:
        default:
            return lv_color_hex(0x009ac7);
    }
}

static void update_text(ha_button_t * widget)
{
    if(widget == NULL) return;

    lv_label_set_text(widget->start_icon_obj, widget->start_icon ? widget->start_icon : "");
    lv_label_set_text(widget->label_obj, widget->loading ? "..." : (widget->label ? widget->label : ""));
    lv_label_set_text(widget->end_icon_obj, widget->end_icon ? widget->end_icon : "");

    if(string_is_empty(widget->start_icon)) lv_obj_add_flag(widget->start_icon_obj, LV_OBJ_FLAG_HIDDEN);
    else lv_obj_remove_flag(widget->start_icon_obj, LV_OBJ_FLAG_HIDDEN);

    if(string_is_empty(widget->end_icon)) lv_obj_add_flag(widget->end_icon_obj, LV_OBJ_FLAG_HIDDEN);
    else lv_obj_remove_flag(widget->end_icon_obj, LV_OBJ_FLAG_HIDDEN);
}

static void update_styles(ha_button_t * widget)
{
    if(widget == NULL) return;

    int32_t height = DEFAULT_HEIGHT;
    int32_t pad_x = DEFAULT_PAD_X;
    const lv_font_t * font = roboto_regular_14_4;

    switch(widget->size) {
        case HA_BUTTON_SIZE_XS:
            height = 28;
            pad_x = 10;
            font = roboto_regular_12_4;
            break;
        case HA_BUTTON_SIZE_S:
            height = 32;
            pad_x = 12;
            break;
        case HA_BUTTON_SIZE_L:
            height = 48;
            pad_x = 18;
            font = roboto_regular_16_4;
            break;
        case HA_BUTTON_SIZE_XL:
            height = 56;
            pad_x = 20;
            font = roboto_regular_18_4;
            break;
        case HA_BUTTON_SIZE_M:
        default:
            break;
    }

    if(widget->height > 0) height = widget->height;

    bool has_start = !string_is_empty(widget->start_icon);
    bool has_end = !string_is_empty(widget->end_icon);
    lv_color_t fg = widget->custom_colors ? widget->fg_color : on_color(widget->variant, widget->appearance);
    lv_color_t bg = widget->custom_colors ? widget->bg_color : fill_color(widget->variant, widget->appearance);
    lv_color_t pressed_bg = widget->custom_colors ? widget->bg_color : pressed_fill_color(widget->variant, widget->appearance);
    lv_color_t border = widget->custom_colors ? widget->border_color : bg;
    lv_opa_t bg_opa = LV_OPA_COVER;
    lv_opa_t pressed_bg_opa = LV_OPA_COVER;
    uint8_t border_width = 0;

    if(widget->appearance == HA_BUTTON_APPEARANCE_PLAIN) {
        bg_opa = widget->selected ? LV_OPA_10 : LV_OPA_TRANSP;
    }
    else if(widget->appearance == HA_BUTTON_APPEARANCE_OUTLINED) {
        bg_opa = widget->selected ? LV_OPA_10 : LV_OPA_TRANSP;
        border = widget->custom_colors ? widget->border_color : border_loud_color(widget->variant);
        border_width = 1;
    }

    /* Keep a visible press response for opaque appearances.  Their HA active
     * tokens currently resolve to the resting fill, so a fully opaque pressed
     * style would be visually identical to the default state. */

    // TODO 按照ts源码的处理，按下时的opa应该是不变的
    // 但是由于没有增加hover的处理，看不出opa的变化，看不出按下效果，所以这里先修改opa，以模拟按下效果
    if(widget->appearance == HA_BUTTON_APPEARANCE_ACCENT ||
       widget->appearance == HA_BUTTON_APPEARANCE_FILLED) {
        pressed_bg_opa = LV_OPA_20;
    }

    if(widget->custom_colors &&
       (widget->appearance == HA_BUTTON_APPEARANCE_PLAIN || widget->appearance == HA_BUTTON_APPEARANCE_OUTLINED)) {
        pressed_bg_opa = LV_OPA_20;
    }

    lv_obj_set_height((lv_obj_t *) widget, height);
    lv_obj_set_width((lv_obj_t *) widget, LV_SIZE_CONTENT);
    lv_obj_set_style_min_width((lv_obj_t *) widget, height, 0);
    lv_obj_set_style_radius((lv_obj_t *) widget, height / 2, 0);
    lv_obj_set_style_pad_left((lv_obj_t *) widget, has_start ? ICON_PAD_X : pad_x, 0);
    lv_obj_set_style_pad_right((lv_obj_t *) widget, has_end ? ICON_PAD_X : pad_x, 0);
    lv_obj_set_style_pad_top((lv_obj_t *) widget, 0, 0);
    lv_obj_set_style_pad_bottom((lv_obj_t *) widget, 0, 0);
    lv_obj_set_style_pad_column((lv_obj_t *) widget, ICON_GAP, 0);
    lv_obj_set_style_bg_color((lv_obj_t *) widget, bg, 0);
    lv_obj_set_style_bg_opa((lv_obj_t *) widget, bg_opa, 0);
    lv_obj_set_style_bg_color((lv_obj_t *) widget, pressed_bg, LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa((lv_obj_t *) widget, pressed_bg_opa, LV_STATE_PRESSED);
    lv_obj_set_style_border_color((lv_obj_t *) widget, border, 0);
    lv_obj_set_style_border_width((lv_obj_t *) widget, border_width, 0);
    lv_obj_set_style_text_font((lv_obj_t *) widget, font, 0);
    lv_obj_set_style_text_font(widget->label_obj, font, 0);

    lv_obj_add_flag(widget->spinner_obj, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(widget->label_obj, LV_OBJ_FLAG_HIDDEN);
    set_label_color(widget, fg);

    if(widget->disabled || widget->loading) {
        lv_obj_add_state((lv_obj_t *) widget, LV_STATE_DISABLED);
        lv_obj_clear_flag((lv_obj_t *) widget, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_opa((lv_obj_t *) widget, LV_OPA_40, 0);
    }
    else {
        lv_obj_remove_state((lv_obj_t *) widget, LV_STATE_DISABLED);
        lv_obj_add_flag((lv_obj_t *) widget, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_opa((lv_obj_t *) widget, LV_OPA_COVER, 0);
    }
}

static void set_label_color(ha_button_t * widget, lv_color_t color)
{
    lv_obj_set_style_text_color(widget->start_icon_obj, color, 0);
    lv_obj_set_style_text_color(widget->label_obj, color, 0);
    lv_obj_set_style_text_color(widget->end_icon_obj, color, 0);
}

static bool string_is_empty(const char * str)
{
    return str == NULL || str[0] == '\0';
}
