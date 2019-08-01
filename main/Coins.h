#include<SFML/Graphics.hpp>
#pragma once

using namespace sf;

/** \brief Klasa przedstawiaj�ca 'monety' (w�a�ciwie jab�ka) zbierane podczas rozgrywki. 
*/

class Coins
{
private:
	Texture texture;
	Sprite sprite;
	
	bool disappeared = false;	

public:
	Coins(float x, float y);
	Sprite getSprite();
	
	float left();
	float right();
	float bottom();
	float top();
	
	void disappear();
	bool isDisappeared();
};

