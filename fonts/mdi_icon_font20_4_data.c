/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --font /fonts/materialdesignicons-webfont.ttf -o /fonts/mdi_icon_font20_4_data.c --size 20 --bpp 4 --format lvgl --no-compress --range 0xF02DC,0xF0415,0xF0374,0xF0142
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef MDI_ICON_FONT20_4_DATA
#define MDI_ICON_FONT20_4_DATA 1
#endif

#if MDI_ICON_FONT20_4_DATA

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+F0142 "󰅂" */
    0x03, 0x00, 0x00, 0x09, 0xf5, 0x00, 0x00, 0x2e,
    0xf5, 0x00, 0x00, 0x2e, 0xf5, 0x00, 0x00, 0x2e,
    0xf5, 0x00, 0x00, 0x4f, 0xf1, 0x00, 0x2e, 0xf5,
    0x00, 0x2e, 0xf5, 0x00, 0x2e, 0xf5, 0x00, 0x09,
    0xf5, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,

    /* U+F02DC "󰋜" */
    0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xa0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0xff, 0xfb,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0xff, 0xff,
    0xff, 0xd1, 0x00, 0x00, 0x00, 0x02, 0xef, 0xff,
    0xff, 0xff, 0xfe, 0x20, 0x00, 0x00, 0x3e, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe3, 0x00, 0x05, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50, 0x17,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x71,
    0x00, 0x0e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0x00, 0x00, 0x0e, 0xff, 0xf5, 0x22, 0x5f, 0xff,
    0xe0, 0x00, 0x00, 0x0e, 0xff, 0xf3, 0x00, 0x3f,
    0xff, 0xe0, 0x00, 0x00, 0x0e, 0xff, 0xf3, 0x00,
    0x3f, 0xff, 0xe0, 0x00, 0x00, 0x0e, 0xff, 0xf3,
    0x00, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x0e, 0xff,
    0xf3, 0x00, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x02,
    0x22, 0x20, 0x00, 0x02, 0x22, 0x20, 0x00,

    /* U+F0374 "󰍴" */
    0x68, 0x88, 0x88, 0x88, 0x88, 0x88, 0xbf, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11,

    /* U+F0415 "󰐕" */
    0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x0b, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0b, 0xe0,
    0x00, 0x00, 0x00, 0x00, 0x0b, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x0b, 0xe0, 0x00, 0x00, 0x68, 0x88,
    0x8d, 0xf8, 0x88, 0x88, 0xbf, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x11, 0x11, 0x1b, 0xe1, 0x11, 0x11,
    0x00, 0x00, 0x0b, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x0b, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0b, 0xe0,
    0x00, 0x00, 0x00, 0x00, 0x0b, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x10, 0x00, 0x00
};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 320, .box_w = 7, .box_h = 11, .ofs_x = 7, .ofs_y = 2},
    {.bitmap_index = 39, .adv_w = 320, .box_w = 18, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 320, .box_w = 12, .box_h = 3, .ofs_x = 4, .ofs_y = 6},
    {.bitmap_index = 192, .adv_w = 320, .box_w = 12, .box_h = 13, .ofs_x = 4, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x00, 0x19a, 0x232, 0x2d3
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 983362, .range_length = 724, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t mdi_icon_font20_4_data = {
#else
lv_font_t mdi_icon_font20_4_data = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if LV_VERSION_CHECK(9, 6, 0) || LVGL_VERSION_MAJOR >= 10
    .cap_height = 0,           /*Cap height of the font*/
    .x_height = 0,               /*x-height of the font*/
#endif
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif

#if LV_VERSION_CHECK(9, 3, 0)
    .static_bitmap = 1,    /*Bitmaps are stored as const so they are always static if not compressed */
#endif

    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if MDI_ICON_FONT20_4_DATA*/
