#include "Bullet.h"

#define screenWidth 1200	
#define screenHeight 800

/**
* \brief	Konstruktor klasy Bullet.
* \details	Wczytywana jest grafika naboju, kt�ra jest skalowana. Ponadto ustawiany jest origin grafiki na jej �rodek.
*/
Bullet::Bullet()
{
	texture.loadFromFile("Graphics/fire.png");
	
	
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	
	sprite.setScale(0.25f, 0.25f);
}

/// \brief Metoda zwraca pole prywatne typu Sprite.
Sprite Bullet::getSprite()
{
	return sprite;
}

/// \brief Zwraca po�o�enie lewej kraw�dzi naboju. 
float Bullet::left()
{
	return (sprite.getPosition().x - sprite.getGlobalBounds().width / 2);
}

/// \brief Zwraca po�o�enie prawej kraw�dzi naboju. 
float Bullet::right()
{
	return (sprite.getPosition().x + sprite.getGlobalBounds().width / 2);
}

/// \brief Zwraca po�o�enie dolnej kraw�dzi naboju. 
float Bullet::bottom()
{
	return (sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
}

/// \brief Zwraca po�o�enie g�rnej kraw�dzi naboju. 
float Bullet::top()
{
	return (sprite.getPosition().y - sprite.getGlobalBounds().height / 2);
}

/// \brief	Zwraca pole prywatne typu bool, kt�re oznacza czy w danym momencie nab�j jest wystrzeliwany. 
bool Bullet::getIsFiring()
{
	return isFiring;
}

/** \brief		Metoda pozwalaj�ca na strzelanie nabojami.
*	\details	Wykorzystane s� obiekty klas Clock i Time. S�u�� one do op�nienia mi�dzy kolejnymi strza�ami.
*				Je�eli wci�ni�to klawisz odpowiedzialny za strzelanie oraz czas pomi�dzy strza�ami min�� to pole
*				isFiring zmienia swoj� warto��na true, a op�nienie liczone jest od nowa.
*/
void Bullet::shoot()
{
	
	shot = clock.getElapsedTime();
	reload = milliseconds(350);
	
	if (Keyboard::isKeyPressed(Keyboard::LControl) && shot >= reload)
	{
		this->isFiring = true;
		clock.restart();
	}
}

/** \brief	Metoda pozwala na wprawienie w ruch naboju.
 */
void Bullet::letItFly()
{
	sprite.move(0, -5);
}

/** \brief Metoda u�ywana w g��wnej p�tli gry. Ustawia pole isFiring z powrotem na false po oddaniu strza�u. 
*/
void Bullet::justFired()
{
	this->isFiring = false;
}

/** \brief		Metoda ustawia po�o�enie naboju wzgl�dem obiektu klasy Character.
*
* \param	x	Wsp�rz�dna x obiektu Character.
* \param	y	Wsp�rz�dna y obiektu Character.
*/
void Bullet::setBulletPos(float x, float y)
{
	sprite.setPosition(x, y);
}