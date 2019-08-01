#include "Cup.h"

#define screenWidth 1200
#define screenHeight 800

/**
* \brief		Konstruktor klasy Cup.
* \details		Za�adowanie odpowiedniej grafiki, ustawienie sta�ej pozycji, przeskalowanie grafiki oraz ustawienie origina.
*/
Cup::Cup()
{
	texture.loadFromFile("Graphics/cup.png");
	sprite.setTexture(texture);
	sprite.setPosition(screenWidth / 2, 50);
	sprite.setScale(0.5, 0.5);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

/// \brief Zwraca pole prywatne typu Sprite potrzebne do narysowania obiektu na ekranie.
Sprite Cup::getSprite()
{
	return sprite;
}

/// \brief Zwraca praw� kraw�d� obiektu.
float Cup::right()
{
	return sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
}
/// \brief Zwraca lew� kraw�d� obiektu.
float Cup::left()
{
	return sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
}
/// \brief Zwraca doln� kraw�d� obiektu.
float Cup::bottom()
{
	return sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
}
/// \brief Zwraca g�rn� kraw�d� obiektu.
float Cup::top()
{
	return sprite.getPosition().y - sprite.getGlobalBounds().height / 2;
}

