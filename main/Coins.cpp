#include "Coins.h"

#define screenWidth 1200
#define screenHeight 800

/** 
* \brief	Konstruktor klasy Coins
* \details	Ustawienie odopowiedniej grafiki, pozycji, originu, skali.
* \param	x	Wspó³rzêdna x nadawana podczas inicjalizacji obiektu.
* \param	y	Wspó³rzêdna y nadawana podczas inicjalizacji obiektu.
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

/// \brief Zwraca pozycjê lewej krawêdzi. 
float Coins::left()
{
	return sprite.getPosition().x - sprite.getGlobalBounds().width/2;
}
/// \brief Zwraca pozycjê prawej krawêdzi. 
float Coins::right()
{
	return sprite.getPosition().x + sprite.getGlobalBounds().width/2;
}
/// \brief Zwraca pozycjê górnej krawêdzi. 
float Coins::top()
{
	return sprite.getPosition().y - sprite.getGlobalBounds().height/2;
}
/// \brief Zwraca pozycjê dolnej krawêdzi. 
float Coins::bottom()
{
	return sprite.getPosition().y + sprite.getGlobalBounds().height/2;
}

/// \brief	Metoda zmienia wartoœæ pola prywatnego disappeared na true.
void Coins::disappear()
{
	this->disappeared = true;
}

/// \brief	Metoda zwraca wartoœæ pola prywatnego disappeared.
bool Coins::isDisappeared()
{
	return this->disappeared;
}