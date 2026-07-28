/**
 * @file demo3_gen.h
 */

#ifndef DEMO3_GEN_H
#define DEMO3_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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



/* Prototypes for target functions, needed by responsive const definitions */

void demo3_set_target(uint32_t target);
uint32_t demo3_get_target(void);
bool demo3_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define DEMO3_TARGET_UNDEFINED  (0 << 1)
#define DEMO3_TARGET_TARGET1    (1 << 1)
#define DEMO3_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef DEMO3_COMPILE_TARGET
#define DEMO3_COMPILE_TARGET DEMO3_TARGET_ALL
#endif

#define DEMO3_CHECK_COMPILE_TARGET(target) (DEMO3_COMPILE_TARGET & (target) ? 1 : 0)

#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * mdi_icon_font24_4;
extern lv_font_t * mdi_icon_font16_4;
extern lv_font_t * mdi_icon_font18_4;
extern lv_font_t * roboto_regular_16_4;
extern lv_font_t * roboto_regular_12_4;


/*----------------
 * Images
 *----------------*/



/*----------------
 * Subjects
 *----------------*/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void demo3_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "screens/home/home_gen.h"
#include "widgets/ha_heading_card/ha_heading_card_gen.h"
#include "widgets/ha_ripple/ha_ripple_gen.h"
#include "widgets/hui_heading_badge/hui_heading_badge_gen.h"
#include "widgets/hui_heading_card/hui_heading_card_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*DEMO3_GEN_H*/