/**
 * @file ha_heading_card.h
 *
 */

#ifndef HA_HEADING_CARD_H
#define HA_HEADING_CARD_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "ha_heading_card_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void refresh(lv_obj_t *obj);

/**********************
 *      MACROS
 **********************/

#define HA_HEADING_CARD_USER_DATA

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HA_HEADING_CARD_H*/