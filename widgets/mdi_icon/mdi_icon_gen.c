/**
 * @file mdi_icon_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "mdi_icon_private_gen.h"
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

void mdi_icon_constructor_hook(lv_obj_t * obj);
void mdi_icon_destructor_hook(lv_obj_t * obj);
void mdi_icon_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void mdi_icon_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void mdi_icon_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void mdi_icon_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t mdi_icon_class = {
    .base_class = &lv_label_class,
    .constructor_cb = mdi_icon_constructor,
    .destructor_cb = mdi_icon_destructor,
    .event_cb = mdi_icon_event,
    .instance_size = sizeof(mdi_icon_t),
    .editable = 1,
    .name = "mdi_icon"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * mdi_icon_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&mdi_icon_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void mdi_icon_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    mdi_icon_t * widget = (mdi_icon_t *)obj;

    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        lv_label_set_text(obj, "󰅂");
        lv_obj_set_flag(obj, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_style_text_font(obj, mdi_icon_font24_4, 0);

        the_root = obj;
    }
    #endif
    mdi_icon_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void mdi_icon_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    mdi_icon_destructor_hook(obj);
}

static void mdi_icon_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&mdi_icon_class, e);
    if(res != LV_RESULT_OK) return;

    mdi_icon_event_hook(e);
}

