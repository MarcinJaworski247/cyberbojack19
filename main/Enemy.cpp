#include "Enemy.h"

#define screenWidth 1200	
#define screenHeight 800


/**
* \brief	Konstruktor klasy Enemy.
* \details	Wczytanie grafiki, ustawienie pozycji, przeskalowanie, ustawienie origina.
* \param	x	Wsp�rz�dna x nadawana podczas inicjalizacji obiektu.
* \param	y	Wsp�rz�dna y nadawana podczas inicjalizacji obiektu.
*/
Enemy::Enemy(float x, float y)
{
	texture.loadFromFile("Graphics/android.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setScale(0.3f, 0.3f);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	
}

/// \brief	Zwraca pole prywatne typu Sprite potrzebne do narysowania obiektu na ekranie.
Sprite Enemy::getSprite()
{
	return sprite;
}
/// \brief Zwr�cenie po�o�enia prawej kraw�dzi obiektu.
float Enemy::right()
{
	return sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
}
/// \brief Zwr�cenie po�o�enia lewej kraw�dzi obiektu.
float Enemy::left()
{
	return sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
}
/// \brief Zwr�cenie po�o�enia dolnej kraw�dzi obiektu.
float Enemy::bottom()
{
	return sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
}
/// \brief Zwr�cenie po�o�enia g�rnej kraw�dzi obiektu/
float Enemy::top()
{
	return sprite.getPosition().y - sprite.getGlobalBounds().height / 2;
}

/// \brief Metoda obni�aj�ca �ycie przeciwnika. 
void Enemy::decreaseLife()
{
	life = life - 0.34 ;
}

/// \brief Je�li �ycie przeciwnika wynosi 0 to pole dead ustawiane jest jako true. 
void Enemy::isKilled()
{	
	if(life <= 0 )
		dead = true;
}

/// \brief Zwraca pole prywatne typu bool - dead - oznaczaj�ce czy przeciwnik �yje.
bool Enemy::getDead()
{
	return dead;
}



/**
* \brief	Poruszanie si� przeciwnika w prawo.
* \details	Po napotkaniu kraw�dzi mapy flaga direction ustawiana jest na L.
*/
void Enemy::enemyMovingRight()
{
	if (sprite.getPosition().x <= 960)
		sprite.move(2, 0);
	else
		direction = 'L';
}

/** 
* \brief	Poruszanie si� przeciwnika w lewo.
* \details	Po napotkaniu kraw�dzi mapy flaga direction ustawiana jest na R.
*/
void Enemy::enemyMovingLeft()
{
	if (sprite.getPosition().x >= 160)
		sprite.move(-2, 0);
	else
		direction = 'R';
}

/**
* \brief	Metoda pozwalaj�ca na automatyczne poruszanie si� przeciwnik�w.
* \details	Zale�nie od aktualnej warto�ci flagi direction wywo�ywana jest metoda pozwalaj�ca na poruszanie si� w lewo lub prawo.
*/
void Enemy::enemyMoving()
{
	if (direction == 'L')
		enemyMovingLeft();
	else if (direction == 'R')
		enemyMovingRight();
}


/// \brief Zwr�cenie po�o�enia przeciwnika w poziomie.
float Enemy::getX()
{
	return sprite.getPosition().x;
}







