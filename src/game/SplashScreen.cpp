/****************************************************************************
 * Copyright (C) 2015 Dimok
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
#include "SplashScreen.h"
#include "gui/GuiTrigger.h"
#include "gui/GuiController.h"

/**
 * Constructor for the GuiButton class.
 */

SplashScreen::SplashScreen(GuiImageData * img)
{
    img_real = new GuiImage(img);
    img_real->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    img_real->setPosition(0, 0);
}

/**
 * Destructor for the GuiButton class.
 */
SplashScreen::~SplashScreen()
{
    state=0;
    delete(img_real);
}

void SplashScreen::setSplashImageData(GuiImageData * img)
{
    img_real->setImageData(img);
}

void SplashScreen::FadeExit()
{
        trasparency=1.0f;
        state=1;
        img_real->setAlpha(trasparency);
}
void SplashScreen::FadeEnter()
{
        trasparency=0.0f;
        state=2;
        img_real->setAlpha(trasparency);
}


/**
 * Draw the button on screen
 */
void SplashScreen::draw(CVideo *v)
{
        if(state!=0) {
            switch(state) {
                case 1:
                    if (trasparency>0.0f) {
                        trasparency=trasparency-0.05f;
                        img_real->setAlpha(trasparency);
                    } else state=0;
                    break;
                case 2:
                    if (trasparency<1.0f) {
                        trasparency=trasparency+0.05f;
                        img_real->setAlpha(trasparency);
                    } else state=0;
                    break;
            }
        }

	if(!this->isVisible())
		return;

	// draw images
	img_real->draw(v);
}

void SplashScreen::update(GuiController * c)
{

}
