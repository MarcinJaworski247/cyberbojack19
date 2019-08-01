#include "screens.h"
#define screenWidth 1200
#define screenHeight 800


Screens::Screens()
{
	texture1.loadFromFile("Graphics/mainpage.png");
	texture2.loadFromFile("Graphics/win.png");
	texture3.loadFromFile("Graphics/lose.png");
	sprite1.setTexture(texture1);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture3);
	sprite1.setOrigin(sprite1.getGlobalBounds().width / 2, sprite1.getGlobalBounds().height / 2);
	sprite1.setPosition(screenWidth / 2, screenHeight / 2);
	sprite2.setOrigin(sprite2.getGlobalBounds().width / 2, sprite2.getGlobalBounds().height / 2);
	sprite2.setPosition(screenWidth / 2, screenHeight / 2);
	sprite3.setOrigin(sprite3.getGlobalBounds().width / 2, sprite3.getGlobalBounds().height / 2);
	sprite3.setPosition(screenWidth / 2, screenHeight / 2);
}

Sprite Screens::getSprite1()
{
	return sprite1;
}

Sprite Screens::getSprite2()
{
	return sprite2;
}

Sprite Screens::getSprite3()
{
	return sprite3;
}


