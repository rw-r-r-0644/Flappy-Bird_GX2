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
#ifndef SCORE_IMG_H_
#define SCORE_IMG_H_

#include "gui/GuiElement.h"
#include "gui/GuiText.h"
#include "gui/GuiController.h"
#include "gui/GuiImage.h"
#include "gui/GuiSound.h"
#include "gui/GuiTrigger.h"

//!Display, manage, and manipulate buttons in the GUI. Buttons can have images, icons, text, and sound set (all of which are optional)
class ScoreImage : public GuiElement
{
	public:
		ScoreImage(int x, int y);
		virtual ~ScoreImage();
                void setScore(int score);
		void draw(CVideo *video);
		void update(GuiController * c);
	protected:
            GuiImageData* digitsImagesData[11]; //Our 10 numers + 1 null digit :P
            GuiImage * digitsImages[3];
            int digits[3];
};

#endif
