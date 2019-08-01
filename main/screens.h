#include<SFML/Graphics.hpp>
#pragma once

/**
* \brief Klasa zawiera plansz� pocz�tkow� oraz ko�cow� w razie pora�ki oraz zwyci�stwa.
*/
using namespace sf;
class Screens
{
private:
	Texture texture1;
	Texture texture2;
	Texture texture3;
	Sprite sprite1;
	Sprite sprite2;
	Sprite sprite3;
public:
	Screens();
	Sprite getSprite1();
	Sprite getSprite2();
	Sprite getSprite3();
};

