/**
 * @file mdi_icon_gen.h
 *
 */

#ifndef MDI_ICON_GEN_H
#define MDI_ICON_GEN_H

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

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a mdi_icon object
 * @param parent pointer to an object, it will be the parent of the new mdi_icon
 * @return pointer to the created mdi_icon
 */
lv_obj_t * mdi_icon_create(lv_obj_t * parent);
/**
 * mdi_icon size
 * @param obj   pointer to a mdi_icon
 * @param size  size
 */
void mdi_icon_set_size(lv_obj_t * mdi_icon, int32_t size);

/**
 * mdi_icon symbol
 * @param obj   pointer to a mdi_icon
 * @param symbol  symbol
 */
void mdi_icon_set_symbol(lv_obj_t * mdi_icon, const char * symbol);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MDI_ICON_GEN_H*/