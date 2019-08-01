#include "Background.h"
#define screenWidth 1200
#define screenHeight 800

/// \brief		Konstruktor klasy Background. 
/// \details	Do tekstury wczytywany jest plik graficzny z map¹ gry, nastêpnie jest ona ustawiana w Spricie.
Background::Background()
{
	texture.loadFromFile("Graphics/bg.png");
	
	sprite.setTexture(texture);
}

/// \brief	Metoda zwraca pole prywatne typu Sprite.
Sprite Background::getSprite()
{
	return sprite;
}

/// \brief		Metoda ustawiaj¹ca pozycjê mapy na ekranie. Pozwala na dzia³anie 'kamery' w grze.
/// \param	y	Wartoœæ zale¿na od pozycja postaci na mapie. 
void Background::setPosition(float y)
{
	sprite.setPosition(screenWidth / 2, 1200 - y );
}
