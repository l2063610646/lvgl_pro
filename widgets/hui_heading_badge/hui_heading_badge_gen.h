/**
 * @file hui_heading_badge_gen.h
 *
 */

#ifndef HUI_HEADING_BADGE_GEN_H
#define HUI_HEADING_BADGE_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#include "../../demo3_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum {
    HUI_HEADING_BADGE_TYPE_DEF_TEXT = 0,
    HUI_HEADING_BADGE_TYPE_DEF_BUTTON = 1
}hui_heading_badge_type_def_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a hui_heading_badge object
 * @param parent pointer to an object, it will be the parent of the new hui_heading_badge
 * @return pointer to the created hui_heading_badge
 */
lv_obj_t * hui_heading_badge_create(lv_obj_t * parent);
/**
 * hui_heading_badge h_type
 * @param obj   pointer to a hui_heading_badge
 * @param h_type  h_type
 */
void hui_heading_badge_set_h_type(lv_obj_t * hui_heading_badge, hui_heading_badge_type_def_t h_type);

/**
 * hui_heading_badge text
 * @param obj   pointer to a hui_heading_badge
 * @param text  text
 */
void hui_heading_badge_set_text(lv_obj_t * hui_heading_badge, const char * text);

/**
 * hui_heading_badge icon
 * @param obj   pointer to a hui_heading_badge
 * @param icon  icon
 */
void hui_heading_badge_set_icon(lv_obj_t * hui_heading_badge, const char * icon);

/**
 * hui_heading_badge text_color
 * @param obj   pointer to a hui_heading_badge
 * @param text_color  text_color
 */
void hui_heading_badge_set_text_color(lv_obj_t * hui_heading_badge, lv_color_t text_color);

/**
 * hui_heading_badge icon_color
 * @param obj   pointer to a hui_heading_badge
 * @param icon_color  icon_color
 */
void hui_heading_badge_set_icon_color(lv_obj_t * hui_heading_badge, lv_color_t icon_color);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HUI_HEADING_BADGE_GEN_H*/