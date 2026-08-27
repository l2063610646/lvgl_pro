/**
 * @file ha_control_select_menu_simple.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_select_menu_simple_private_gen.h"
#include "../../demo3.h"

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/

#define DEFAULT_HEIGHT       48
#define DEFAULT_RADIUS       12
#define MODAL_RADIUS         16
#define ITEM_RADIUS          10

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void update_trigger_ui(ha_control_select_menu_simple_t * st);
static void clear_options(ha_control_select_menu_simple_t * st);
static void trigger_clicked_cb(lv_event_t * e);
static void mask_clicked_cb(lv_event_t * e);
static void dialog_clicked_cb(lv_event_t * e);
static void option_clicked_cb(lv_event_t * e);
static void open_modal(ha_control_select_menu_simple_t * st);
static void close_modal(ha_control_select_menu_simple_t * st);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ha_control_select_menu_simple_constructor_hook(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st != NULL) {
        st->options_data = NULL;
        st->option_count = 0;
        st->selected_value[0] = '\0';
        st->active_mask = NULL;
        st->color = lv_color_hex(0x2196F3);
        st->modal_bg_color = lv_color_hex(0xFFFFFF);
        st->modal_text_color = lv_color_hex(0x141414);
        st->height = DEFAULT_HEIGHT;
        st->disabled = false;
        st->hide_label = false;
        st->show_arrow = true;

        /* Set trigger container styling */
        lv_obj_set_height(obj, DEFAULT_HEIGHT);
        lv_obj_set_style_radius(obj, DEFAULT_RADIUS, LV_PART_MAIN);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x727272), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(obj, (255 * 18 / 100), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(obj, (255 * 30 / 100), LV_STATE_PRESSED);
        lv_obj_set_style_pad_hor(obj, 14, LV_PART_MAIN);
        lv_obj_set_style_pad_ver(obj, 6, LV_PART_MAIN);
        lv_obj_set_style_pad_column(obj, 10, LV_PART_MAIN);
        lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
        lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN);

        lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
        lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);

        /* 1. Icon symbol (non-clickable so root handles click) */
        st->icon_obj = lv_label_create(obj);
        const lv_font_t * sym_font = mdi_icon_font20_4 ? mdi_icon_font20_4 : (mdi_icon_font18_4 ? mdi_icon_font18_4 : LV_FONT_DEFAULT);
        lv_obj_set_style_text_font(st->icon_obj, sym_font, 0);
        lv_obj_set_style_text_color(st->icon_obj, lv_color_hex(0x141414), 0);
        lv_label_set_text(st->icon_obj, "");
        lv_obj_remove_flag(st->icon_obj, LV_OBJ_FLAG_CLICKABLE);

        /* 2. Middle column: Title + Value (non-clickable so whole widget responds) */
        st->content_col = lv_obj_create(obj);
        lv_obj_remove_style_all(st->content_col);
        lv_obj_set_flex_grow(st->content_col, 1);
        lv_obj_set_flex_flow(st->content_col, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(st->content_col, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_style_pad_all(st->content_col, 0, 0);
        lv_obj_set_style_pad_row(st->content_col, 1, 0);
        lv_obj_remove_flag(st->content_col, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_remove_flag(st->content_col, LV_OBJ_FLAG_SCROLLABLE);

        st->title_label = lv_label_create(st->content_col);
        const lv_font_t * title_font = roboto_regular_12_4 ? roboto_regular_12_4 : LV_FONT_DEFAULT;
        lv_obj_set_style_text_font(st->title_label, title_font, 0);
        lv_obj_set_style_text_color(st->title_label, lv_color_hex(0x727272), 0);
        lv_label_set_text(st->title_label, "");
        lv_obj_remove_flag(st->title_label, LV_OBJ_FLAG_CLICKABLE);

        st->value_label = lv_label_create(st->content_col);
        const lv_font_t * val_font = roboto_regular_14_4 ? roboto_regular_14_4 : LV_FONT_DEFAULT;
        lv_obj_set_style_text_font(st->value_label, val_font, 0);
        lv_obj_set_style_text_color(st->value_label, lv_color_hex(0x141414), 0);
        lv_label_set_text(st->value_label, "");
        lv_obj_remove_flag(st->value_label, LV_OBJ_FLAG_CLICKABLE);

        /* 3. Arrow icon (non-clickable so root handles click) */
        st->arrow_obj = lv_label_create(obj);
        lv_obj_set_style_text_font(st->arrow_obj, LV_FONT_DEFAULT, 0);
        lv_obj_set_style_text_color(st->arrow_obj, lv_color_hex(0x727272), 0);
        lv_label_set_text(st->arrow_obj, LV_SYMBOL_DOWN);
        lv_obj_remove_flag(st->arrow_obj, LV_OBJ_FLAG_CLICKABLE);

        lv_obj_add_event_cb(obj, trigger_clicked_cb, LV_EVENT_CLICKED, NULL);
    }
}

void ha_control_select_menu_simple_destructor_hook(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st != NULL) {
        close_modal(st);
        clear_options(st);
    }
}

void ha_control_select_menu_simple_event_hook(lv_event_t * e)
{
    LV_UNUSED(e);
}

void ha_control_select_menu_simple_set_options_array(lv_obj_t * obj, const ha_control_select_option_t * options, uint32_t count)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;

    clear_options(st);
    if(options == NULL || count == 0) return;

    st->options_data = lv_malloc(sizeof(ha_control_select_menu_simple_option_store_t) * count);
    LV_ASSERT_MALLOC(st->options_data);
    if(st->options_data == NULL) return;

    st->option_count = count;

    for(uint32_t i = 0; i < count; i++) {
        lv_strlcpy(st->options_data[i].value, options[i].value ? options[i].value : "", sizeof(st->options_data[i].value));
        lv_strlcpy(st->options_data[i].label, options[i].label ? options[i].label : st->options_data[i].value, sizeof(st->options_data[i].label));
        lv_strlcpy(st->options_data[i].symbol, options[i].symbol ? options[i].symbol : "", sizeof(st->options_data[i].symbol));
    }

    if(st->selected_value[0] == '\0' && count > 0) {
        lv_strlcpy(st->selected_value, st->options_data[0].value, sizeof(st->selected_value));
        st->value = st->selected_value;
    }

    update_trigger_ui(st);
}

void ha_control_select_menu_simple_set_options(lv_obj_t * obj, const char * options_str)
{
    if(obj == NULL || options_str == NULL || options_str[0] == '\0') return;

    uint32_t count = 1;
    for(const char * p = options_str; *p; p++) {
        if(*p == ';') count++;
    }

    ha_control_select_option_t * opts = lv_malloc(sizeof(ha_control_select_option_t) * count);
    if(opts == NULL) return;

    char * buf = lv_strdup(options_str);
    if(buf == NULL) {
        lv_free(opts);
        return;
    }

    char * item = buf;
    uint32_t idx = 0;
    while(item != NULL && idx < count) {
        char * next_item = strchr(item, ';');
        if(next_item != NULL) {
            *next_item = '\0';
            next_item++;
        }

        char * v = item;
        char * l = strchr(v, ',');
        char * s = NULL;
        if(l != NULL) {
            *l = '\0';
            l++;
            s = strchr(l, ',');
            if(s != NULL) {
                *s = '\0';
                s++;
            }
        }

        opts[idx].value = v;
        opts[idx].label = l ? l : v;
        opts[idx].symbol = s ? s : "";
        opts[idx].color = lv_color_hex(0);
        opts[idx].has_color = false;

        idx++;
        item = next_item;
    }

    ha_control_select_menu_simple_set_options_array(obj, opts, idx);

    lv_free(buf);
    lv_free(opts);
}

void ha_control_select_menu_simple_set_value(lv_obj_t * obj, const char * value)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    lv_strlcpy(st->selected_value, value ? value : "", sizeof(st->selected_value));
    st->value = st->selected_value;
    update_trigger_ui(st);
}

void ha_control_select_menu_simple_set_label(lv_obj_t * obj, const char * label)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->label = label ? label : "";
    update_trigger_ui(st);
}

void ha_control_select_menu_simple_set_disabled(lv_obj_t * obj, bool disabled)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->disabled = disabled;
    if(disabled) {
        lv_obj_add_state(obj, LV_STATE_DISABLED);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_opa(obj, LV_OPA_40, LV_PART_MAIN);
        close_modal(st);
    } else {
        lv_obj_remove_state(obj, LV_STATE_DISABLED);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_opa(obj, LV_OPA_COVER, LV_PART_MAIN);
    }
}

void ha_control_select_menu_simple_set_hide_label(lv_obj_t * obj, bool hide_label)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->hide_label = hide_label;
    update_trigger_ui(st);
}

void ha_control_select_menu_simple_set_show_arrow(lv_obj_t * obj, bool show_arrow)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->show_arrow = show_arrow;
    if(st->arrow_obj != NULL) {
        if(show_arrow) lv_obj_clear_flag(st->arrow_obj, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(st->arrow_obj, LV_OBJ_FLAG_HIDDEN);
    }
}

void ha_control_select_menu_simple_set_color(lv_obj_t * obj, lv_color_t color)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->color = color;
}

void ha_control_select_menu_simple_set_modal_bg_color(lv_obj_t * obj, lv_color_t modal_bg_color)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->modal_bg_color = modal_bg_color;
}

void ha_control_select_menu_simple_set_modal_text_color(lv_obj_t * obj, lv_color_t modal_text_color)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->modal_text_color = modal_text_color;
}

void ha_control_select_menu_simple_set_height(lv_obj_t * obj, int32_t height)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL) return;
    st->height = height;
    lv_obj_set_height(obj, height > 0 ? height : DEFAULT_HEIGHT);
}

const char * ha_control_select_menu_simple_get_value(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->selected_value : "";
}

uint32_t ha_control_select_menu_simple_get_option_count(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->option_count : 0;
}

const char * ha_control_select_menu_simple_get_label(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->label : "";
}

bool ha_control_select_menu_simple_get_disabled(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->disabled : false;
}

bool ha_control_select_menu_simple_get_hide_label(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->hide_label : false;
}

bool ha_control_select_menu_simple_get_show_arrow(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->show_arrow : true;
}

lv_color_t ha_control_select_menu_simple_get_color(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->color : lv_color_hex(0x2196F3);
}

lv_color_t ha_control_select_menu_simple_get_modal_bg_color(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->modal_bg_color : lv_color_hex(0xFFFFFF);
}

lv_color_t ha_control_select_menu_simple_get_modal_text_color(lv_obj_t * obj)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    return st ? st->modal_text_color : lv_color_hex(0x141414);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void update_trigger_ui(ha_control_select_menu_simple_t * st)
{
    if(st == NULL) return;

    /* Update title label */
    if(st->title_label != NULL) {
        if(st->hide_label || st->label == NULL || st->label[0] == '\0') {
            lv_obj_add_flag(st->title_label, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_clear_flag(st->title_label, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(st->title_label, st->label);
        }
    }

    /* Find selected option info */
    const char * cur_label = st->selected_value;
    const char * cur_symbol = "";

    if(st->options_data != NULL && st->option_count > 0) {
        for(uint32_t i = 0; i < st->option_count; i++) {
            if(strcmp(st->options_data[i].value, st->selected_value) == 0) {
                cur_label = st->options_data[i].label;
                cur_symbol = st->options_data[i].symbol;
                break;
            }
        }
    }

    if(st->value_label != NULL) {
        lv_label_set_text(st->value_label, cur_label ? cur_label : "");
    }

    if(st->icon_obj != NULL) {
        if(cur_symbol != NULL && cur_symbol[0] != '\0') {
            lv_obj_clear_flag(st->icon_obj, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(st->icon_obj, cur_symbol);
        } else {
            lv_obj_add_flag(st->icon_obj, LV_OBJ_FLAG_HIDDEN);
        }
    }

    if(st->arrow_obj != NULL) {
        if(st->show_arrow) lv_obj_clear_flag(st->arrow_obj, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(st->arrow_obj, LV_OBJ_FLAG_HIDDEN);
    }
}

static void clear_options(ha_control_select_menu_simple_t * st)
{
    if(st == NULL) return;
    if(st->options_data != NULL) {
        lv_free(st->options_data);
        st->options_data = NULL;
    }
    st->option_count = 0;
}

static void trigger_clicked_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)obj;
    if(st == NULL || st->disabled) return;

    open_modal(st);
}

static void mask_clicked_cb(lv_event_t * e)
{
    ha_control_select_menu_simple_t * st = (ha_control_select_menu_simple_t *)lv_event_get_user_data(e);
    if(st != NULL) {
        close_modal(st);
    }
}

static void dialog_clicked_cb(lv_event_t * e)
{
    /* Consume click to prevent closing mask */
    lv_event_stop_bubbling(e);
}

static void option_clicked_cb(lv_event_t * e)
{
    lv_event_stop_bubbling(e);
    lv_obj_t * btn = lv_event_get_target(e);
    uint32_t idx = (uint32_t)(uintptr_t)lv_event_get_user_data(e);

    /* btn -> list -> dialog */
    lv_obj_t * list = lv_obj_get_parent(btn);
    lv_obj_t * dialog = list ? lv_obj_get_parent(list) : NULL;
    ha_control_select_menu_simple_t * st = dialog ? (ha_control_select_menu_simple_t *)lv_obj_get_user_data(dialog) : NULL;
    if(st == NULL) return;

    if(st->options_data != NULL && idx < st->option_count) {
        lv_strlcpy(st->selected_value, st->options_data[idx].value, sizeof(st->selected_value));
        st->value = st->selected_value;

        update_trigger_ui(st);
        lv_obj_send_event((lv_obj_t *)st, LV_EVENT_VALUE_CHANGED, (void *)st->selected_value);
    }

    close_modal(st);
}

static void open_modal(ha_control_select_menu_simple_t * st)
{
    if(st == NULL || st->disabled || st->options_data == NULL || st->option_count == 0) return;
    if(st->active_mask != NULL) return;

    /* Mount on top layer to ensure 100% overlay and block screen background scrolling */
    lv_obj_t * top_layer = lv_layer_top();
    if(top_layer == NULL) top_layer = lv_screen_active();
    if(top_layer == NULL) return;

    /* 1. Mask backdrop covering 100% */
    lv_obj_t * mask = lv_obj_create(top_layer);
    lv_obj_remove_style_all(mask);
    lv_obj_set_size(mask, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(mask, lv_color_hex(0x000000), 0);
    lv_obj_set_style_bg_opa(mask, LV_OPA_50, 0);
    lv_obj_add_flag(mask, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(mask, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(mask, LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_obj_add_event_cb(mask, mask_clicked_cb, LV_EVENT_CLICKED, st);

    /* 2. Modal Dialog box (80% W x 80% H) */
    lv_obj_t * dialog = lv_obj_create(mask);
    lv_obj_remove_style_all(dialog);
    lv_obj_set_size(dialog, LV_PCT(80), LV_PCT(80));
    lv_obj_set_align(dialog, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(dialog, MODAL_RADIUS, 0);
    lv_obj_set_style_bg_color(dialog, st->modal_bg_color, 0);
    lv_obj_set_style_bg_opa(dialog, LV_OPA_COVER, 0);
    lv_obj_set_style_clip_corner(dialog, true, 0);
    lv_obj_set_style_shadow_width(dialog, 28, 0);
    lv_obj_set_style_shadow_opa(dialog, LV_OPA_40, 0);
    lv_obj_set_style_shadow_color(dialog, lv_color_hex(0x000000), 0);
    lv_obj_set_flex_flow(dialog, LV_FLEX_FLOW_COLUMN);
    lv_obj_remove_flag(dialog, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(dialog, LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_obj_add_flag(dialog, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_user_data(dialog, st);
    lv_obj_add_event_cb(dialog, dialog_clicked_cb, LV_EVENT_CLICKED, NULL);

    /* 3. Modal Header Bar (方案B) */
    lv_obj_t * header = lv_obj_create(dialog);
    lv_obj_remove_style_all(header);
    lv_obj_set_size(header, LV_PCT(100), 44);
    lv_obj_set_flex_flow(header, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(header, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_hor(header, 16, 0);
    lv_obj_set_style_border_side(header, LV_BORDER_SIDE_BOTTOM, 0);
    lv_obj_set_style_border_width(header, 1, 0);
    lv_obj_set_style_border_color(header, lv_color_hex(0xEDEDED), 0);

    lv_obj_t * header_title = lv_label_create(header);
    const lv_font_t * h_font = roboto_regular_14_4 ? roboto_regular_14_4 : LV_FONT_DEFAULT;
    lv_obj_set_style_text_font(header_title, h_font, 0);
    lv_obj_set_style_text_color(header_title, st->modal_text_color, 0);
    lv_label_set_text(header_title, (st->label && st->label[0]) ? st->label : "Select Option");

    /* 4. Options List */
    lv_obj_t * list = lv_obj_create(dialog);
    lv_obj_remove_style_all(list);
    lv_obj_set_size(list, LV_PCT(100), LV_PCT(100));
    lv_obj_set_flex_grow(list, 1);
    lv_obj_set_flex_flow(list, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(list, 8, 0);
    lv_obj_set_style_pad_row(list, 4, 0);
    lv_obj_add_flag(list, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(list, LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_obj_set_scroll_dir(list, LV_DIR_VER);

    const lv_font_t * sym_font = mdi_icon_font20_4 ? mdi_icon_font20_4 : (mdi_icon_font18_4 ? mdi_icon_font18_4 : LV_FONT_DEFAULT);
    const lv_font_t * opt_font = roboto_regular_14_4 ? roboto_regular_14_4 : LV_FONT_DEFAULT;

    for(uint32_t i = 0; i < st->option_count; i++) {
        bool is_selected = (strcmp(st->selected_value, st->options_data[i].value) == 0);

        lv_obj_t * btn = lv_button_create(list);
        lv_obj_remove_style_all(btn);
        lv_obj_set_size(btn, LV_PCT(100), 44);
        lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_ROW);
        lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_style_pad_hor(btn, 14, 0);
        lv_obj_set_style_pad_column(btn, 12, 0);
        lv_obj_set_style_radius(btn, ITEM_RADIUS, 0);

        lv_color_t item_color = is_selected ? st->color : st->modal_text_color;

        if(is_selected) {
            lv_obj_set_style_bg_color(btn, lv_color_hex(0xEBF5FB), 0);
            lv_obj_set_style_bg_opa(btn, LV_OPA_COVER, 0);
        } else {
            lv_obj_set_style_bg_opa(btn, LV_OPA_0, 0);
            lv_obj_set_style_bg_color(btn, lv_color_hex(0x000000), LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(btn, (255 * 8 / 100), LV_STATE_PRESSED);
        }

        /* Symbol icon */
        if(st->options_data[i].symbol[0] != '\0') {
            lv_obj_t * sym = lv_label_create(btn);
            lv_obj_set_style_text_font(sym, sym_font, 0);
            lv_obj_set_style_text_color(sym, item_color, 0);
            lv_label_set_text(sym, st->options_data[i].symbol);
        }

        /* Label text */
        lv_obj_t * lbl = lv_label_create(btn);
        lv_obj_set_style_text_font(lbl, opt_font, 0);
        lv_obj_set_style_text_color(lbl, item_color, 0);
        lv_label_set_text(lbl, st->options_data[i].label);

        lv_obj_add_event_cb(btn, option_clicked_cb, LV_EVENT_CLICKED, (void *)(uintptr_t)i);
    }

    st->active_mask = mask;
}

static void close_modal(ha_control_select_menu_simple_t * st)
{
    if(st == NULL || st->active_mask == NULL) return;
    lv_obj_delete_async(st->active_mask);
    st->active_mask = NULL;
}
