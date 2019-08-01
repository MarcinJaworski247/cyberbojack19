#include<SFML/Graphics.hpp>
#pragma once

/**
* \brief	Klasa zawieraj�ca tekstur� b�d�c� map� gry. 
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

