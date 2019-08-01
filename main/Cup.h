#include<SFML/Graphics.hpp>
#pragma once

using namespace sf;

/// \brief Klasa przedstawiaj�ca puchar, kt�rego zebranie powoduje wygranie rozgrywki.
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

