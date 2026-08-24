/**
 * @file ha_control_select.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "ha_control_select_private_gen.h"
#include "../../demo3.h"

#include <string.h>

/*********************
 *      DEFINES
 *********************/

#define DEFAULT_HEIGHT       40
#define DEFAULT_RADIUS       10
#define DEFAULT_PAD          4
#define BUTTON_RADIUS        6

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void update_button_styles(ha_control_select_t * st);
static void clear_options(ha_control_select_t * st);
static void relayout(ha_control_select_t * st);
static void button_click_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ha_control_select_constructor_hook(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st != NULL) {
        st->buttons = NULL;
        st->options_data = NULL;
        st->option_count = 0;
        st->selected_value[0] = '\0';
        st->color = lv_color_hex(0x2196f3);
        st->height = DEFAULT_HEIGHT;
        st->disabled = false;
        st->vertical = false;
        st->hide_option_label = false;

        if(st->row != NULL) {
            lv_obj_set_style_radius(st->row, DEFAULT_RADIUS, 0);
            lv_obj_set_style_bg_color(st->row, lv_color_hex(0x727272), 0);
            lv_obj_set_style_bg_opa(st->row, (255 * 20 / 100), 0);
            lv_obj_set_style_pad_all(st->row, DEFAULT_PAD, 0);
            lv_obj_set_style_pad_column(st->row, DEFAULT_PAD, 0);
            lv_obj_set_style_pad_row(st->row, DEFAULT_PAD, 0);
        }
    }
}

void ha_control_select_destructor_hook(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st != NULL) {
        clear_options(st);
    }
}

void ha_control_select_event_hook(lv_event_t * e)
{
    LV_UNUSED(e);
}

void ha_control_select_set_options_array(lv_obj_t * obj, const ha_control_select_option_t * options, uint32_t count)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL || st->row == NULL) return;

    clear_options(st);
    if(options == NULL || count == 0) return;

    st->options_data = lv_malloc(sizeof(ha_control_select_option_store_t) * count);
    st->buttons = lv_malloc(sizeof(lv_obj_t *) * count);
    LV_ASSERT_MALLOC(st->options_data);
    LV_ASSERT_MALLOC(st->buttons);
    if(st->options_data == NULL || st->buttons == NULL) {
        clear_options(st);
        return;
    }
    memset(st->buttons, 0, sizeof(lv_obj_t *) * count);
    st->option_count = count;

    for(uint32_t i = 0; i < count; i++) {
        lv_strlcpy(st->options_data[i].value, options[i].value ? options[i].value : "", sizeof(st->options_data[i].value));
        lv_strlcpy(st->options_data[i].label, options[i].label ? options[i].label : st->options_data[i].value, sizeof(st->options_data[i].label));
        lv_strlcpy(st->options_data[i].symbol, options[i].symbol ? options[i].symbol : "", sizeof(st->options_data[i].symbol));

        lv_obj_t * btn = lv_button_create(st->row);
        lv_obj_remove_style_all(btn);
        lv_obj_set_flex_grow(btn, 1);
        if(st->vertical) {
            lv_obj_set_width(btn, LV_PCT(100));
        } else {
            lv_obj_set_height(btn, LV_PCT(100));
        }
        lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_style_radius(btn, BUTTON_RADIUS, 0);
        lv_obj_set_style_pad_all(btn, 2, 0);
        lv_obj_set_style_pad_gap(btn, 2, 0);
        lv_obj_set_user_data(btn, (void *)(uintptr_t)i);
        lv_obj_add_event_cb(btn, button_click_cb, LV_EVENT_CLICKED, obj);

        if(st->options_data[i].symbol[0] != '\0') {
            lv_obj_t * symbol = lv_label_create(btn);
            lv_label_set_text(symbol, st->options_data[i].symbol);
            lv_obj_set_style_text_font(symbol, mdi_icon_font18_4 ? mdi_icon_font18_4 : LV_FONT_DEFAULT, 0);
            lv_obj_remove_flag(symbol, LV_OBJ_FLAG_CLICKABLE);
        }
        if(st->options_data[i].label[0] != '\0') {
            lv_obj_t * label = lv_label_create(btn);
            lv_label_set_text(label, st->options_data[i].label);
            lv_obj_set_style_text_font(label, roboto_regular_12_4 ? roboto_regular_12_4 : LV_FONT_DEFAULT, 0);
            lv_label_set_long_mode(label, LV_LABEL_LONG_DOT);
            lv_obj_set_width(label, LV_PCT(100));
            lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
            lv_obj_remove_flag(label, LV_OBJ_FLAG_CLICKABLE);
            if(st->hide_option_label) {
                lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
            }
        }
        st->buttons[i] = btn;
    }

    if(st->selected_value[0] == '\0' && count > 0) {
        lv_strlcpy(st->selected_value, st->options_data[0].value, sizeof(st->selected_value));
        st->value = st->selected_value;
    }
    update_button_styles(st);
}

void ha_control_select_set_options(lv_obj_t * obj, const char * options_str)
{
    if(obj == NULL || options_str == NULL || options_str[0] == '\0') return;

    /* Count items delimited by ';' */
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

        /* Parse item fields: "value,label,symbol" or "value,label" or "value" */
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
        idx++;

        item = next_item;
    }

    ha_control_select_set_options_array(obj, opts, idx);

    lv_free(buf);
    lv_free(opts);
}

void ha_control_select_set_value(lv_obj_t * obj, const char * value)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    lv_strlcpy(st->selected_value, value ? value : "", sizeof(st->selected_value));
    st->value = st->selected_value;
    update_button_styles(st);
}

void ha_control_select_set_label(lv_obj_t * obj, const char * label)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    st->label = label;
}

void ha_control_select_set_disabled(lv_obj_t * obj, bool disabled)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    st->disabled = disabled;
    update_button_styles(st);
}

void ha_control_select_set_vertical(lv_obj_t * obj, bool vertical)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    st->vertical = vertical;
    relayout(st);
}

void ha_control_select_set_hide_option_label(lv_obj_t * obj, bool hide_option_label)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    st->hide_option_label = hide_option_label;

    if(st->buttons != NULL) {
        for(uint32_t i = 0; i < st->option_count; i++) {
            lv_obj_t * btn = st->buttons[i];
            if(btn == NULL) continue;
            uint32_t child_cnt = lv_obj_get_child_count(btn);
            for(uint32_t c = 0; c < child_cnt; c++) {
                lv_obj_t * child = lv_obj_get_child(btn, c);
                if(st->options_data[i].symbol[0] != '\0' && c == 0) {
                    /* First child is symbol icon, keep visible */
                    continue;
                }
                if(hide_option_label) {
                    lv_obj_add_flag(child, LV_OBJ_FLAG_HIDDEN);
                } else {
                    lv_obj_clear_flag(child, LV_OBJ_FLAG_HIDDEN);
                }
            }
        }
    }
}

void ha_control_select_set_color(lv_obj_t * obj, lv_color_t color)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    st->color = color;
    update_button_styles(st);
}

void ha_control_select_set_height(lv_obj_t * obj, lv_coord_t height)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL) return;
    st->height = height;
    relayout(st);
}

const char * ha_control_select_get_value(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->selected_value : "";
}

uint32_t ha_control_select_get_option_count(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->option_count : 0;
}

const char * ha_control_select_get_label(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->label : "";
}

bool ha_control_select_get_disabled(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->disabled : false;
}

bool ha_control_select_get_vertical(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->vertical : false;
}

bool ha_control_select_get_hide_option_label(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->hide_option_label : false;
}

lv_color_t ha_control_select_get_color(lv_obj_t * obj)
{
    ha_control_select_t * st = (ha_control_select_t *)obj;
    return st ? st->color : lv_color_hex(0x2196f3);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void update_button_styles(ha_control_select_t * st)
{
    if(st == NULL || st->buttons == NULL || st->options_data == NULL) return;

    for(uint32_t i = 0; i < st->option_count; i++) {
        lv_obj_t * btn = st->buttons[i];
        if(btn == NULL) continue;
        bool selected = (strcmp(st->options_data[i].value, st->selected_value) == 0);

        lv_obj_set_style_radius(btn, BUTTON_RADIUS, 0);
        lv_obj_set_style_border_width(btn, 0, 0);
        lv_obj_set_style_bg_color(btn, selected ? st->color : lv_color_hex(0x727272), 0);
        lv_obj_set_style_bg_opa(btn, selected ? LV_OPA_COVER : LV_OPA_0, 0);
        lv_obj_set_style_text_color(btn, selected ? lv_color_hex(0xffffff) : lv_color_hex(0x141414), 0);

        if(st->disabled) {
            lv_obj_add_state(btn, LV_STATE_DISABLED);
            lv_obj_clear_flag(btn, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_opa(btn, LV_OPA_40, 0);
        } else {
            lv_obj_remove_state(btn, LV_STATE_DISABLED);
            lv_obj_add_flag(btn, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_opa(btn, LV_OPA_COVER, 0);
        }
    }
}

static void button_click_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_user_data(e);
    ha_control_select_t * st = (ha_control_select_t *)obj;
    if(st == NULL || st->disabled || st->options_data == NULL) return;

    uint32_t idx = (uint32_t)(uintptr_t)lv_obj_get_user_data(btn);
    if(idx >= st->option_count) return;
    if(strcmp(st->selected_value, st->options_data[idx].value) == 0) return;

    lv_strlcpy(st->selected_value, st->options_data[idx].value, sizeof(st->selected_value));
    st->value = st->selected_value;
    update_button_styles(st);
    lv_obj_send_event(obj, LV_EVENT_VALUE_CHANGED, (void *)st->selected_value);
}

static void clear_options(ha_control_select_t * st)
{
    if(st == NULL) return;
    if(st->buttons != NULL) {
        for(uint32_t i = 0; i < st->option_count; i++) {
            if(st->buttons[i] != NULL) {
                lv_obj_delete(st->buttons[i]);
            }
        }
        lv_free(st->buttons);
        st->buttons = NULL;
    }
    if(st->options_data != NULL) {
        lv_free(st->options_data);
        st->options_data = NULL;
    }
    st->option_count = 0;
}

static void relayout(ha_control_select_t * st)
{
    if(st == NULL || st->row == NULL) return;
    int32_t height = st->height > 0 ? st->height : DEFAULT_HEIGHT;
    if(st->vertical) {
        lv_obj_set_size(&st->obj, DEFAULT_HEIGHT, LV_PCT(100));
        lv_obj_set_size(st->row, LV_PCT(100), LV_PCT(100));
        lv_obj_set_flex_flow(st->row, LV_FLEX_FLOW_COLUMN);
    } else {
        lv_obj_set_size(&st->obj, LV_PCT(100), height);
        lv_obj_set_size(st->row, LV_PCT(100), LV_PCT(100));
        lv_obj_set_flex_flow(st->row, LV_FLEX_FLOW_ROW);
    }
    lv_obj_set_style_pad_all(st->row, DEFAULT_PAD, 0);
    lv_obj_set_style_pad_column(st->row, DEFAULT_PAD, 0);
    lv_obj_set_style_pad_row(st->row, DEFAULT_PAD, 0);

    if(st->buttons != NULL) {
        for(uint32_t i = 0; i < st->option_count; i++) {
            if(st->buttons[i] != NULL) {
                if(st->vertical) {
                    lv_obj_set_width(st->buttons[i], LV_PCT(100));
                } else {
                    lv_obj_set_height(st->buttons[i], LV_PCT(100));
                }
            }
        }
    }
}
