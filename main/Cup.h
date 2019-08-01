#include<SFML/Graphics.hpp>
#pragma once

using namespace sf;

/// \brief Klasa przedstawiaj¹ca puchar, którego zebranie powoduje wygranie rozgrywki.
class Cup
{
private:
	Sprite sprite;
	Texture texture;
public:
	Cup();
	Sprite getSprite();
	float left();
	float right();
	float bottom();
	float top();
};

