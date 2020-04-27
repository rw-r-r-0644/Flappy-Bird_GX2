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
#include <coreinit/time.h>
#include "Pipe.h"
#include "gui/GuiTrigger.h"
#include "gui/GuiController.h"
#include "resources/Resources.h"

/**
 * Constructor for the GuiButton class.
 */

Pipe::Pipe(float x)
{
    srand(OSGetTime());
    loc_y=rand() % 250 - 125;
    loc_x = x;
    pipeBottomImg = Resources::GetImageData("pipe_down.png");
    pipeTopImg = Resources::GetImageData("pipe_up.png");
    pipebottom = new GuiImage(pipeBottomImg);
    pipetop = new GuiImage(pipeTopImg);

    pipebottom->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
    pipetop->setAlignment(ALIGN_CENTER | ALIGN_CENTER);

    pipebottom->setPosition((int)loc_x,-410-loc_y);
    pipetop->setPosition((int)loc_x,410-loc_y);

    scroll_state=false;
}

/**
 * Destructor for the GuiButton class.
 */
Pipe::~Pipe()
{
    loc_x=0.0f;
    loc_y=0.0f;
    scroll_state=0;
    delete(pipetop);
    delete(pipebottom);
    delete(pipeTopImg);
    delete(pipeBottomImg);
}

void Pipe::setPosX(float x)
{
    loc_x=x;
    pipebottom->setPosition((int)loc_x,-410-loc_y);
    pipetop->setPosition((int)loc_x,410-loc_y);
}

void Pipe::setScroll(bool state)
{
        scroll_state=state;
}

int Pipe::checkCollision(GuiImage* check)
{
    if((pipetop->getLeft()-pipetop->getWidth()/4.0f)<(check->getLeft()+check->getWidth()/2.0f) && (pipetop->getLeft()+pipetop->getWidth()/2)>(check->getLeft()-check->getWidth()/2.0f)) { //How can that thing work? No, really...
        poss_collision=1;
        if((check->getTop()+check->getHeight()/2.0f)>(pipetop->getTop()-720.0f) || ((check->getTop()-check->getHeight()/2.0f))<pipebottom->getTop()) {
            poss_collision=0; //we already collided
            return 1;
        }
    } else if (poss_collision==1) { //We just surpassed the problem
        poss_collision=0;
        return -1; //Add point
    }
    return 0;
}


/**
 * Draw the button on screen
 */
void Pipe::draw(CVideo *v)
{
        if(scroll_state==true) {
            loc_x-=1.5f;
            if (loc_x<-640.0f) {
                loc_x=700.0f;
                loc_y=rand() % 250 - 125;
            }
            pipebottom->setPosition((int)loc_x,-410-loc_y);
            pipetop->setPosition((int)loc_x,410-loc_y);
        }

	if(!this->isVisible())
		return;

	// draw images
	pipebottom->draw(v);
	pipetop->draw(v);
}

void Pipe::update(GuiController * c)
{

}
