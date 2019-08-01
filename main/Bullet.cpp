#include "Bullet.h"

#define screenWidth 1200	
#define screenHeight 800

/**
* \brief	Konstruktor klasy Bullet.
* \details	Wczytywana jest grafika naboju, która jest skalowana. Ponadto ustawiany jest origin grafiki na jej œrodek.
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

/// \brief Zwraca po³o¿enie lewej krawêdzi naboju. 
float Bullet::left()
{
	return (sprite.getPosition().x - sprite.getGlobalBounds().width / 2);
}

/// \brief Zwraca po³o¿enie prawej krawêdzi naboju. 
float Bullet::right()
{
	return (sprite.getPosition().x + sprite.getGlobalBounds().width / 2);
}

/// \brief Zwraca po³o¿enie dolnej krawêdzi naboju. 
float Bullet::bottom()
{
	return (sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
}

/// \brief Zwraca po³o¿enie górnej krawêdzi naboju. 
float Bullet::top()
{
	return (sprite.getPosition().y - sprite.getGlobalBounds().height / 2);
}

/// \brief	Zwraca pole prywatne typu bool, które oznacza czy w danym momencie nabój jest wystrzeliwany. 
bool Bullet::getIsFiring()
{
	return isFiring;
}

/** \brief		Metoda pozwalaj¹ca na strzelanie nabojami.
*	\details	Wykorzystane s¹ obiekty klas Clock i Time. S³u¿¹ one do opóŸnienia miêdzy kolejnymi strza³ami.
*				Je¿eli wciœniêto klawisz odpowiedzialny za strzelanie oraz czas pomiêdzy strza³ami min¹³ to pole
*				isFiring zmienia swoj¹ wartoœæna true, a opóŸnienie liczone jest od nowa.
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

/** \brief Metoda u¿ywana w g³ównej pêtli gry. Ustawia pole isFiring z powrotem na false po oddaniu strza³u. 
*/
void Bullet::justFired()
{
	this->isFiring = false;
}

/** \brief		Metoda ustawia po³o¿enie naboju wzglêdem obiektu klasy Character.
*
* \param	x	Wspó³rzêdna x obiektu Character.
* \param	y	Wspó³rzêdna y obiektu Character.
*/
void Bullet::setBulletPos(float x, float y)
{
	sprite.setPosition(x, y);
}