/**
 * @file hui_heading_card_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_card_private_gen.h"
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif
#include "../../demo3.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void hui_heading_card_constructor_hook(lv_obj_t * obj);
void hui_heading_card_destructor_hook(lv_obj_t * obj);
void hui_heading_card_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void hui_heading_card_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void hui_heading_card_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void hui_heading_card_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t hui_heading_card_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = hui_heading_card_constructor,
    .destructor_cb = hui_heading_card_destructor,
    .event_cb = hui_heading_card_event,
    .instance_size = sizeof(hui_heading_card_t),
    .editable = 1,
    .name = "hui_heading_card"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * hui_heading_card_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&hui_heading_card_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void hui_heading_card_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    hui_heading_card_t * widget = (hui_heading_card_t *)obj;

    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_obj_set_width(obj, lv_pct(100));
        lv_obj_set_height(obj, LV_SIZE_CONTENT);

        lv_obj_t * card = lv_obj_create(obj);
        lv_obj_set_name(card, "card");
        lv_obj_set_flag(card, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_width(card, LV_SIZE_CONTENT);
        lv_obj_set_height(card, LV_SIZE_CONTENT);
        lv_obj_set_style_layout(card, LV_LAYOUT_FLEX, 0);
        lv_obj_set_style_flex_cross_place(card, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flex_flow(card, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_all(card, 0, 0);
        lv_obj_set_style_pad_column(card, 8, 0);
        lv_obj_set_style_border_width(card, 0, 0);
        widget->card = card;
        lv_obj_t * content = lv_obj_create(card);
        lv_obj_set_name(content, "content");
        lv_obj_set_height(content, LV_SIZE_CONTENT);
        lv_obj_set_style_layout(content, LV_LAYOUT_FLEX, 0);
        lv_obj_set_style_pad_all(content, 0, 0);
        lv_obj_set_style_border_width(content, 0, 0);
        lv_obj_set_flag(content, LV_OBJ_FLAG_SCROLLABLE, false);
        widget->content = content;
        lv_obj_t * lv_label_0 = lv_label_create(content);
        lv_label_set_text(lv_label_0, "󰋜");
        lv_obj_set_style_text_font(lv_label_0, mdi_icon_font18_4, 0);
        widget->lv_label_0 = lv_label_0;

        lv_obj_t * label = lv_label_create(content);
        lv_obj_set_name(label, "label");
        lv_obj_set_width(label, LV_SIZE_CONTENT);
        lv_label_set_long_mode(label, LV_LABEL_LONG_MODE_CLIP);
        widget->label = label;

        lv_obj_t * badges = lv_obj_create(card);
        lv_obj_set_name(badges, "badges");
        lv_obj_set_height(badges, LV_SIZE_CONTENT);
        lv_obj_set_style_layout(badges, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(badges, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_border_width(badges, 0, 0);
        lv_obj_set_style_pad_all(badges, 0, 0);
        lv_obj_set_style_pad_column(badges, 8, 0);
        widget->badges = badges;
        lv_obj_t * hui_heading_badge_0 = hui_heading_badge_create(badges);
        hui_heading_badge_set_icon(hui_heading_badge_0, "󰋜");
        hui_heading_badge_set_text(hui_heading_badge_0, "Hello");
        widget->hui_heading_badge_0 = hui_heading_badge_0;

        lv_obj_t * hui_heading_badge_1 = hui_heading_badge_create(badges);
        hui_heading_badge_set_h_type(hui_heading_badge_1, HUI_HEADING_BADGE_TYPE_DEF_TEXT);
        hui_heading_badge_set_text(hui_heading_badge_1, "blank");
        widget->hui_heading_badge_1 = hui_heading_badge_1;

        lv_obj_t * hui_heading_badge_2 = hui_heading_badge_create(badges);
        hui_heading_badge_set_icon(hui_heading_badge_2, "󰋜");
        hui_heading_badge_set_text(hui_heading_badge_2, "World");
        widget->hui_heading_badge_2 = hui_heading_badge_2;

        the_root = obj;
    }
    #endif
    hui_heading_card_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void hui_heading_card_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    hui_heading_card_destructor_hook(obj);
}

static void hui_heading_card_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&hui_heading_card_class, e);
    if(res != LV_RESULT_OK) return;

    hui_heading_card_event_hook(e);
}

