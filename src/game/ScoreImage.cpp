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
#include "ScoreImage.h"
#include "gui/GuiTrigger.h"
#include "gui/GuiController.h"

/**
 * Constructor for the GuiButton class.
 */

ScoreImage::ScoreImage(int x, int y)
{
    digitsImagesData[0] = Resources::GetImageData("font_big_0.png");
    digitsImagesData[1] = Resources::GetImageData("font_big_1.png");
    digitsImagesData[2] = Resources::GetImageData("font_big_2.png");
    digitsImagesData[3] = Resources::GetImageData("font_big_3.png");
    digitsImagesData[4] = Resources::GetImageData("font_big_4.png");
    digitsImagesData[5] = Resources::GetImageData("font_big_5.png");
    digitsImagesData[6] = Resources::GetImageData("font_big_6.png");
    digitsImagesData[7] = Resources::GetImageData("font_big_7.png");
    digitsImagesData[8] = Resources::GetImageData("font_big_8.png");
    digitsImagesData[9] = Resources::GetImageData("font_big_9.png");
    digitsImagesData[10] = Resources::GetImageData("font_big_null.png");
 
    for (int i=0;i<3;i++) {
       digitsImages[i] = new GuiImage(digitsImagesData[10]);
       digitsImages[i]->setAlignment(ALIGN_CENTER | ALIGN_CENTER);
       digitsImages[i]->setPosition(x+(i*36),y);
    }

    digitsImages[2]->setImageData(digitsImagesData[0]);
}

/**
 * Destructor for the GuiButton class.
 */
ScoreImage::~ScoreImage()
{
    //for (int i=0;i<11;i++) delete(digitsImagesData[i]);
}

void ScoreImage::setScore(int score)
{
    //Yeah, that's hacky and there are unusefull functions :P
    if (score>999) score=999; //That's unlikey but...
    for(int a=0;a<3;a++) digits[a]=10; //Initialize digits to 10 (=don't draw)
    
    digits[0]=(int)(score/pow(10, 0))%10;
    if (score>9) digits[1]=(int)(score/pow(10, 1))%10;
    if (score>99) digits[2]=(int)(score/pow(10, 2))%10;

    for(int a=0; a<3; a++) digitsImages[a]->setImageData(digitsImagesData[digits[2-a]]);
}


/**
 * Draw the button on screen
 */
void ScoreImage::draw(CVideo *v)
{
	if(!this->isVisible())
		return;

	// draw images
	digitsImages[0]->draw(v);
	digitsImages[1]->draw(v);
        digitsImages[2]->draw(v);
}

void ScoreImage::update(GuiController * c)
{

}
