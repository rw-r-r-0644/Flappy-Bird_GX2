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
#include "MainWindowTV.h"
#include "utils/logger.h"

MainWindowTV::MainWindowTV(int w, int h)
    : GuiMainWindowScreen(w, h)
    , width(w)
    , height(h)
    ,bgImageColor(w, h, (GX2Color){ 0, 0, 0, 0 })
{
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 0);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 1);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 2);
    bgImageColor.setImageColor((GX2Color){  248, 248, 249, 255 }, 3);
    append(&bgImageColor);
        



    wingSound = new GuiSound(Resources::GetFile("sfx_wing.ogg"), Resources::GetFileSize("sfx_wing.ogg"));
    pointSound = new GuiSound(Resources::GetFile("sfx_point.ogg"), Resources::GetFileSize("sfx_point.ogg"));
    swooshSound = new GuiSound(Resources::GetFile("sfx_swooshing.ogg"), Resources::GetFileSize("sfx_swooshing.ogg"));
    dieSound = new GuiSound(Resources::GetFile("sfx_die.ogg"), Resources::GetFileSize("sfx_die.ogg"));

    // The below code will draw a pumpkin_pie.jpg mage from
    // the /data folder when uncommented
    splashImgData = Resources::GetImageData("splash.png");
    looseImgData = Resources::GetImageData("loose.png");

    flappy_bird_frm[0] = Resources::GetImageData("flappy_bird_1.png");
    flappy_bird_frm[1] = Resources::GetImageData("flappy_bird_2.png");
    flappy_bird_frm[2] = Resources::GetImageData("flappy_bird_3.png");
    flappy_bird_frm[3] = Resources::GetImageData("flappy_bird_4.png");

    splash = new SplashScreen(splashImgData);
    //splash = new GuiImage(splashImgData);
    flappy_bird = new GuiImage(flappy_bird_frm[0]);

    for (int i=0;i<4;i++) pipes[i] = new Pipe(150.0f+((float)i*320.0f));

    bg = new Background("bg_back.png",0);
    fg = new Background("bg_front.png",0);

    score_img = new ScoreImage(-54, 200);



    //splash->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    flappy_bird->setAlignment(ALIGN_CENTER | ALIGN_CENTER);

    //splash->setPosition(0, 0);
    flappy_bird->setPosition(-150, -5);

    append(bg);
    append(flappy_bird);
    for (int i=0;i<4;i++) append(pipes[i]);
    append(fg);
    append(splash);


    // The below code wll draw "Hello World!" as a string
    // opionally underneath the pie, if it is available
    //const char* cpName = "Hello World!";
    //GuiText* hello = new GuiText(cpName, 28, glm::vec4(0, 0, 0, 1));
    //hello->setAlignment(ALIGN_RIGHT | ALIGN_CENTER); // start from midright
    //hello->setPosition(-250, 0); // move the text left 200 from the right
    //append(hello);
}

MainWindowTV::~MainWindowTV()
{
    remove(&bgImageColor);
    delete(wingSound);
    delete(swooshSound);
    delete(dieSound);
    //delete(bg);
    //for (int i=0;i<4;i++) delete pipes[i];
    //pipes = NULL;
    //delete(fg);
    delete(splash);
    delete(flappy_bird);
}

void MainWindowTV::draw(CVideo *v){
	GuiMainWindowScreen::draw(v);
	//gets called on every frame for drawing
}


void MainWindowTV::update(GuiController * c){
    GuiMainWindowScreen::update(c);
    //CONTROLLER UPDATE!!!
    switch(game_state) {
        case state_splash: //Start screen
            if(c->data.buttons_d & VPAD_BUTTON_A || c->data.buttons_d & VPAD_BUTTON_B) {
                splash->FadeExit();
                append(score_img);
                for(int i=0;i<4;i++) pipes[i]->setScroll(true);
                bg->setScrollSpeed(0.5f);
                fg->setScrollSpeed(1.5f);
                flappy_bird_velocity = jump; //Jump after start
                wingSound->Stop();
                wingSound->Play();

                game_state=state_ingame;
            }
            break;
        case state_ingame:
            if(c->data.buttons_d & VPAD_BUTTON_A || c->data.buttons_d & VPAD_BUTTON_B) {
                flappy_bird_velocity = jump;
                wingSound->Stop();
                wingSound->Play();
            }
            break;
        case state_gameover:
            if(dieSound->IsPlaying() == false && (c->data.buttons_d & VPAD_BUTTON_A || c->data.buttons_d & VPAD_BUTTON_B)) {
                flappy_bird_position=-5;
                flappy_bird_rotation = 0.0f;
                flappy_bird_velocity = 0.0f;
                flappy_bird->setPosition(-150, -5);
                flappy_bird->setAngle(0.0f);

                score=0;
                score_img->setScore(score);

                for (int i=0;i<4;i++) pipes[i]->setPosX(150.0f+((float)i*320.0f));

                splash->setSplashImageData(splashImgData);
                splash->FadeEnter();
                swooshSound->Stop();
                swooshSound->Play();
                game_state=state_splash;
            }
            break;
        default:
            break;
    }
        
}

void MainWindowTV::process(){
    GuiMainWindowScreen::process();
    if (game_state!=2) { //If not game over
	if (++flappy_bird_change_skip==6) { //Animate picture
            flappy_bird_change_skip=0;
            if (++flappy_bird_curr_frame==4) flappy_bird_curr_frame=0;
            flappy_bird->setImageData(flappy_bird_frm[flappy_bird_curr_frame]);
        }
    }

    switch(game_state) {
        case state_ingame:
            flappy_bird_velocity += gravity;
            flappy_bird_position -= flappy_bird_velocity;

            if(flappy_bird_position<-224) flappy_bird_position=-224;
            if(flappy_bird_position>320) flappy_bird_position=320;

            flappy_bird->setPosition(-150, (int)flappy_bird_position);
            if ((((float)flappy_bird_velocity / 10.0f) * 90.0f)<90.0f) flappy_bird_rotation = (((float)flappy_bird_velocity / 10.0f) * 90.0f);
            else flappy_bird_rotation = 90.0f;
            flappy_bird->setAngle(flappy_bird_rotation);

            for (int i=0;i<4;i++) {
                collision_state[i]=pipes[i]->checkCollision(flappy_bird);
                if(collision_state[i]!=0) {
                    if(collision_state[i]==-1) {
                        //Add point
                        score_img->setScore(++score);
                        pointSound->Stop();
                        pointSound->Play();
                    }
                    if(collision_state[i]==1) {
                        bg->setScrollSpeed(0.0f);
                        fg->setScrollSpeed(0.0f); 
                        for(int i=0;i<4;i++) pipes[i]->setScroll(false);
                        dieSound->Stop();
                        dieSound->Play();
                        game_state=state_collided;
                    }
                }
            }
            if (flappy_bird_position<-220) game_state=state_die;
            break;
        case state_collided: //is dying from a pipe: go down by gravity
            flappy_bird_velocity += gravity;
            flappy_bird_position -= flappy_bird_velocity;

            if(flappy_bird_position<-224) flappy_bird_position=-224;
            if(flappy_bird_position>320) flappy_bird_position=320;

            flappy_bird->setPosition(-150, (int)flappy_bird_position);
            if ((((float)flappy_bird_velocity / 10.0f) * 90.0f)<90.0f) flappy_bird_rotation = (((float)flappy_bird_velocity / 10.0f) * 90.0f);
            else flappy_bird_rotation = 90.0f;
            flappy_bird->setAngle(flappy_bird_rotation);

            if (flappy_bird_position<-220) game_state=state_show_gameover;
            break;
        case state_show_gameover: //IsDying
            if(dieSound->IsPlaying() == false) {
                swooshSound->Stop();
                swooshSound->Play();
                splash->setSplashImageData(looseImgData);
                splash->FadeEnter();
                remove(score_img);
                game_state=state_gameover;
            }
            break;
        case state_die: //Die
            bg->setScrollSpeed(0.0f);
            fg->setScrollSpeed(0.0f); 
            for(int i=0;i<4;i++) pipes[i]->setScroll(false);
            dieSound->Stop();
            dieSound->Play();
            game_state=state_show_gameover;
            break;
        default:
            break;
    }
}
