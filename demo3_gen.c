/**
 * @file demo3_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "demo3_gen.h"

#if defined(LV_USE_XML) && LV_USE_XML
#include "widgets/ha_heading_card/ha_heading_card_private_gen.h"
#include "widgets/ha_ripple/ha_ripple_private_gen.h"
#include "widgets/hui_heading_badge/hui_heading_badge_private_gen.h"
#include "widgets/hui_heading_card/hui_heading_card_private_gen.h"
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t demo3_target = DEMO3_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", NULL};
    static const char * translation_tags[] = {"dog", "cat", "house", NULL};
    static const char * translation_texts[] = {
        "This is a dog", "Das ist ein Hund", /* dog */
        "A curious little cat", "Eine neugierige kleine Katze", /* cat */
        "The house is cozy and warm", "Das Haus ist gemütlich und warm", /* house */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * mdi_icon_font24_4;
extern lv_font_t mdi_icon_font24_4_data;
lv_font_t * mdi_icon_font16_4;
extern lv_font_t mdi_icon_font16_4_data;
lv_font_t * mdi_icon_font18_4;
extern lv_font_t mdi_icon_font18_4_data;
lv_font_t * roboto_regular_16_4;
extern lv_font_t roboto_regular_16_4_data;
lv_font_t * roboto_regular_12_4;
extern lv_font_t roboto_regular_12_4_data;

/*----------------
 * Images
 *----------------*/



/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void demo3_init_gen(const char * asset_path)
{

    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if DEMO3_CHECK_COMPILE_TARGET(DEMO3_TARGET_ALL)
    if (demo3_check_target(DEMO3_TARGET_ALL)) {
        if (!mdi_icon_font24_4) {
            /* mdi_icon_font24_4 */
            /* get font 'mdi_icon_font24_4' from a C array */
            mdi_icon_font24_4 = &mdi_icon_font24_4_data;

        }
        if (!mdi_icon_font16_4) {
            /* mdi_icon_font16_4 */
            /* get font 'mdi_icon_font16_4' from a C array */
            mdi_icon_font16_4 = &mdi_icon_font16_4_data;

        }
        if (!mdi_icon_font18_4) {
            /* mdi_icon_font18_4 */
            /* get font 'mdi_icon_font18_4' from a C array */
            mdi_icon_font18_4 = &mdi_icon_font18_4_data;

        }
        if (!roboto_regular_16_4) {
            /* roboto_regular_16_4 */
            /* get font 'roboto_regular_16_4' from a C array */
            roboto_regular_16_4 = &roboto_regular_16_4_data;

        }
        if (!roboto_regular_12_4) {
            /* roboto_regular_12_4 */
            /* get font 'roboto_regular_12_4' from a C array */
            roboto_regular_12_4 = &roboto_regular_12_4_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/



    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */
    ha_heading_card_register();
    ha_ripple_register();
    hui_heading_badge_register();
    hui_heading_card_register();

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&mdi_icon_font24_4, "mdi_icon_font24_4");
    check_font(&mdi_icon_font16_4, "mdi_icon_font16_4");
    check_font(&mdi_icon_font18_4, "mdi_icon_font18_4");
    check_font(&roboto_regular_16_4, "roboto_regular_16_4");
    check_font(&roboto_regular_12_4, "roboto_regular_12_4");

    /* Register fonts */
    lv_xml_register_font(NULL, "mdi_icon_font24_4", mdi_icon_font24_4);
    lv_xml_register_font(NULL, "mdi_icon_font16_4", mdi_icon_font16_4);
    lv_xml_register_font(NULL, "mdi_icon_font18_4", mdi_icon_font18_4);
    lv_xml_register_font(NULL, "roboto_regular_16_4", roboto_regular_16_4);
    lv_xml_register_font(NULL, "roboto_regular_12_4", roboto_regular_12_4);

    /* Register subjects */

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if defined(LV_USE_XML) && LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void demo3_set_target(uint32_t target)
{
    demo3_target = target;
}

uint32_t demo3_get_target(void)
{
    return demo3_target;
}

bool demo3_check_target(uint32_t target)
{
    return (demo3_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}