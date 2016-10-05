/****************************************************************************
 * Copyright (C) 2015 Dimok
 * Modified by Maschell, 2016 for GX2_GUI_Template
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#ifndef _MAIN_WINDOW_TV_H_
#define _MAIN_WINDOW_TV_H_

#include "gui/Gui.h"
#include "gui/GuiMainWindowScreen.h"
#include "gui/VPadController.h"
#include "game/Pipe.h"
#include "game/Background.h"
#include "game/ScoreImage.h"
#include "game/SplashScreen.h"

#define state_splash 0
#define state_ingame 1
#define state_gameover 2
#define state_die 5
#define state_collided 3
#define state_show_gameover 4

class CVideo;

class MainWindowTV : public GuiMainWindowScreen{
public:
    MainWindowTV(int w, int h);
    virtual ~MainWindowTV();
private:
    int width, height;

    GuiImage bgImageColor;

    GuiSound *wingSound;
    GuiSound *pointSound;
    GuiSound *swooshSound;
    GuiSound *dieSound;

    GuiImageData* bgImgData;
    GuiImageData* fgImgData;
    GuiImageData* splashImgData;
    GuiImageData* looseImgData;

    Background* bg;
    Background* fg;
    //GuiImage* splash; //Splash screen
    SplashScreen* splash;

    ScoreImage *score_img;
    int score=0;

    Pipe* pipes[4];
    int collision_state[4];

    int bg_offset=0;
    int fg_offset=0;

    GuiImageData *flappy_bird_frm[4];

    GuiImage* flappy_bird;

    int flappy_bird_change_skip=0;
    int flappy_bird_curr_frame=0;


    int game_state=0; //0=start, 1=in-game, 2=game over
    int set_gameover=0;

    #define gravity 0.25f
    #define jump -4.6f

    float flappy_bird_position=-5.0f;
    float flappy_bird_velocity = 0.0f;
    float flappy_bird_rotation = 0.0f;

    void draw(CVideo *v);
    void update(GuiController * c);
    void process();
};

#endif //_MAIN_WINDOW_TV_H_
