#include "Coins.h"

#define screenWidth 1200
#define screenHeight 800

/** 
* \brief	Konstruktor klasy Coins
* \details	Ustawienie odopowiedniej grafiki, pozycji, originu, skali.
* \param	x	Wsp�rz�dna x nadawana podczas inicjalizacji obiektu.
* \param	y	Wsp�rz�dna y nadawana podczas inicjalizacji obiektu.
*/
Coins::Coins(float x,float y)
{
	texture.loadFromFile("Graphics/apple.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);	
	sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);	
	sprite.setScale(0.5f, 0.5f);
}

/// \brief Metoda zwraca pole prywatne typu Sprite.
Sprite Coins::getSprite()
{
	return sprite;
}

/// \brief Zwraca pozycj� lewej kraw�dzi. 
float Coins::left()
{
	return sprite.getPosition().x - sprite.getGlobalBounds().width/2;
}
/// \brief Zwraca pozycj� prawej kraw�dzi. 
float Coins::right()
{
	return sprite.getPosition().x + sprite.getGlobalBounds().width/2;
}
/// \brief Zwraca pozycj� g�rnej kraw�dzi. 
float Coins::top()
{
	return sprite.getPosition().y - sprite.getGlobalBounds().height/2;
}
/// \brief Zwraca pozycj� dolnej kraw�dzi. 
float Coins::bottom()
{
	return sprite.getPosition().y + sprite.getGlobalBounds().height/2;
}

/// \brief	Metoda zmienia warto�� pola prywatnego disappeared na true.
void Coins::disappear()
{
	this->disappeared = true;
}

/// \brief	Metoda zwraca warto�� pola prywatnego disappeared.
bool Coins::isDisappeared()
{
	return this->disappeared;
}