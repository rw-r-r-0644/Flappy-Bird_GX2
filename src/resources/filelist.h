/****************************************************************************
 * Loadiine resource files.
 * This file is generated automatically.
 * Includes 28 files.
 *
 * NOTE:
 * Any manual modification of this file will be overwriten by the generation.
 ****************************************************************************/
#ifndef _FILELIST_H_
#define _FILELIST_H_

#include <gctypes.h>

typedef struct _RecourceFile
{
	const char *filename;
	const u8   *DefaultFile;
	const u32  &DefaultFileSize;
	u8		   *CustomFile;
	u32		    CustomFileSize;
} RecourceFile;

extern const u8 bg_back_png[];
extern const u32 bg_back_png_size;

extern const u8 bg_front_png[];
extern const u32 bg_front_png_size;

extern const u8 bgMusic_ogg[];
extern const u32 bgMusic_ogg_size;

extern const u8 button_click_mp3[];
extern const u32 button_click_mp3_size;

extern const u8 flappy_bird_1_png[];
extern const u32 flappy_bird_1_png_size;

extern const u8 flappy_bird_2_png[];
extern const u32 flappy_bird_2_png_size;

extern const u8 flappy_bird_3_png[];
extern const u32 flappy_bird_3_png_size;

extern const u8 flappy_bird_4_png[];
extern const u32 flappy_bird_4_png_size;

extern const u8 font_big_0_png[];
extern const u32 font_big_0_png_size;

extern const u8 font_big_1_png[];
extern const u32 font_big_1_png_size;

extern const u8 font_big_2_png[];
extern const u32 font_big_2_png_size;

extern const u8 font_big_3_png[];
extern const u32 font_big_3_png_size;

extern const u8 font_big_4_png[];
extern const u32 font_big_4_png_size;

extern const u8 font_big_5_png[];
extern const u32 font_big_5_png_size;

extern const u8 font_big_6_png[];
extern const u32 font_big_6_png_size;

extern const u8 font_big_7_png[];
extern const u32 font_big_7_png_size;

extern const u8 font_big_8_png[];
extern const u32 font_big_8_png_size;

extern const u8 font_big_9_png[];
extern const u32 font_big_9_png_size;

extern const u8 font_big_null_png[];
extern const u32 font_big_null_png_size;

extern const u8 font_ttf[];
extern const u32 font_ttf_size;

extern const u8 loose_png[];
extern const u32 loose_png_size;

extern const u8 pipe_down_png[];
extern const u32 pipe_down_png_size;

extern const u8 pipe_up_png[];
extern const u32 pipe_up_png_size;

extern const u8 sfx_die_ogg[];
extern const u32 sfx_die_ogg_size;

extern const u8 sfx_point_ogg[];
extern const u32 sfx_point_ogg_size;

extern const u8 sfx_swooshing_ogg[];
extern const u32 sfx_swooshing_ogg_size;

extern const u8 sfx_wing_ogg[];
extern const u32 sfx_wing_ogg_size;

extern const u8 splash_png[];
extern const u32 splash_png_size;

static RecourceFile RecourceList[] =
{
	{"bg_back.png", bg_back_png, bg_back_png_size, NULL, 0},
	{"bg_front.png", bg_front_png, bg_front_png_size, NULL, 0},
	{"bgMusic.ogg", bgMusic_ogg, bgMusic_ogg_size, NULL, 0},
	{"button_click.mp3", button_click_mp3, button_click_mp3_size, NULL, 0},
	{"flappy_bird_1.png", flappy_bird_1_png, flappy_bird_1_png_size, NULL, 0},
	{"flappy_bird_2.png", flappy_bird_2_png, flappy_bird_2_png_size, NULL, 0},
	{"flappy_bird_3.png", flappy_bird_3_png, flappy_bird_3_png_size, NULL, 0},
	{"flappy_bird_4.png", flappy_bird_4_png, flappy_bird_4_png_size, NULL, 0},
	{"font_big_0.png", font_big_0_png, font_big_0_png_size, NULL, 0},
	{"font_big_1.png", font_big_1_png, font_big_1_png_size, NULL, 0},
	{"font_big_2.png", font_big_2_png, font_big_2_png_size, NULL, 0},
	{"font_big_3.png", font_big_3_png, font_big_3_png_size, NULL, 0},
	{"font_big_4.png", font_big_4_png, font_big_4_png_size, NULL, 0},
	{"font_big_5.png", font_big_5_png, font_big_5_png_size, NULL, 0},
	{"font_big_6.png", font_big_6_png, font_big_6_png_size, NULL, 0},
	{"font_big_7.png", font_big_7_png, font_big_7_png_size, NULL, 0},
	{"font_big_8.png", font_big_8_png, font_big_8_png_size, NULL, 0},
	{"font_big_9.png", font_big_9_png, font_big_9_png_size, NULL, 0},
	{"font_big_null.png", font_big_null_png, font_big_null_png_size, NULL, 0},
	{"font.ttf", font_ttf, font_ttf_size, NULL, 0},
	{"loose.png", loose_png, loose_png_size, NULL, 0},
	{"pipe_down.png", pipe_down_png, pipe_down_png_size, NULL, 0},
	{"pipe_up.png", pipe_up_png, pipe_up_png_size, NULL, 0},
	{"sfx_die.ogg", sfx_die_ogg, sfx_die_ogg_size, NULL, 0},
	{"sfx_point.ogg", sfx_point_ogg, sfx_point_ogg_size, NULL, 0},
	{"sfx_swooshing.ogg", sfx_swooshing_ogg, sfx_swooshing_ogg_size, NULL, 0},
	{"sfx_wing.ogg", sfx_wing_ogg, sfx_wing_ogg_size, NULL, 0},
	{"splash.png", splash_png, splash_png_size, NULL, 0},
	{NULL, NULL, 0, NULL, 0}
};

#endif
