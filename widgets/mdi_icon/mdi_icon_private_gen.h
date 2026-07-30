/**
 * @file mdi_icon_private_gen.h
 *
 */

#ifndef MDI_ICON_PRIVATE_H
#define MDI_ICON_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl_private.h"
#endif
#include "mdi_icon.h"

/*********************
 *      DEFINES
 *********************/

#ifndef MDI_ICON_USER_DATA
#define MDI_ICON_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_label_t obj;  /* Base widget to extend */
    int32_t size;
    const char * symbol;
    MDI_ICON_USER_DATA
} mdi_icon_t;

extern const lv_obj_class_t mdi_icon_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void mdi_icon_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MDI_ICON_PRIVATE_H*/