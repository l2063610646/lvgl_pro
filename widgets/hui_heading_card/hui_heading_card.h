/**
 * @file hui_heading_card.h
 *
 */

#ifndef HUI_HEADING_CARD_H
#define HUI_HEADING_CARD_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "hui_heading_card_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
int32_t clamp_i32(int32_t value, int32_t min, int32_t max);
void refresh(lv_obj_t *obj);

/**********************
 *      MACROS
 **********************/

#define HUI_HEADING_CARD_USER_DATA

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HUI_HEADING_CARD_H*/