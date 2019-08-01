#include<SFML/Graphics.hpp>
#pragma once

using namespace sf;

/** \brief Klasa przedstawiaj¹ca 'monety' (w³aœciwie jab³ka) zbierane podczas rozgrywki. 
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

