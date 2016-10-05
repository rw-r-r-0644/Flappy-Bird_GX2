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
#ifndef PIPE_H_
#define PIPE_H_

#include "gui/GuiElement.h"
#include "gui/GuiText.h"
#include "gui/GuiController.h"
#include "gui/GuiImage.h"
#include "gui/GuiSound.h"
#include "gui/GuiTrigger.h"

//!Display, manage, and manipulate buttons in the GUI. Buttons can have images, icons, text, and sound set (all of which are optional)
class Pipe : public GuiElement
{
	public:
		Pipe(float x);
		virtual ~Pipe();
                void setPosX(float x);
       		void setScroll(bool state);
                int checkCollision(GuiImage* check);
		void draw(CVideo *video);
		void update(GuiController * c);
	protected:
            GuiImageData* pipeBottomImg;
            GuiImageData* pipeTopImg;
            GuiImage * pipebottom;
            GuiImage * pipetop;
            float loc_x;
            int loc_y;
            int poss_collision=0;
            bool scroll_state;
};

#endif
