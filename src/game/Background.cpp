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
#include "Background.h"
#include "gui/GuiTrigger.h"
#include "gui/GuiController.h"

/**
 * Constructor for the GuiButton class.
 */

Background::Background(char *picture, float scroll_speed)
{
    loc_x=0.0f;

    bgImg = Resources::GetImageData(picture);

    bg = new GuiImage(bgImg);
    bgs = new GuiImage(bgImg);
  
    bg->setPosition(0, 0);
    bgs->setPosition(-1280, 0);

    speed=scroll_speed;
}

/**
 * Destructor for the GuiButton class.
 */
Background::~Background()
{
    speed=0.0f;
    loc_x=0.0f;
    delete(bgImg);
    delete(bg);
    delete(bgs);
}

void Background::setScrollSpeed(float scroll_speed)
{
        speed=scroll_speed;
}

/**
 * Draw the button on screen
 */
void Background::draw(CVideo *v)
{
        if(speed>0.0f) {
            loc_x-=speed;
            if(loc_x<0.0f) loc_x=1280.0f;

            bg->setPosition((int)loc_x, 0);
            bgs->setPosition((int)loc_x-1280, 0);
        }

	if(!this->isVisible())
		return;

	// draw images
	bg->draw(v);
	bgs->draw(v);
}

void Background::update(GuiController * c)
{

}
