#include<SFML/Graphics.hpp>
#pragma once

/**
* \brief	Klasa zawieraj¹ca teksturê bêd¹c¹ map¹ gry. 
*/

using namespace sf;

class Background
{
private:
	Sprite sprite;
	Texture texture;
public:
	Background();
	Sprite getSprite();
	void setPosition(float y);
};

