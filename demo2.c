/**
 * @file demo2.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "demo2.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void demo2_init(const char * asset_path)
{
    LV_LOG("Initializing custom C code using LVGL v%d.%d.%d", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH);

    demo2_init_gen(asset_path);

    /* Add your own custom code here if needed */
}

/**********************
 *   STATIC FUNCTIONS
 **********************/