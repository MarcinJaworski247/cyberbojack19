#include "Character.h"

#define screenWidth 1200
#define screenHeight 800

/**
* \brief	Kostruktor klasy Character
*
* \details	Do tekstur ³adowane s¹ obrazki g³ównej postaci przedstawiaj¹ce je z 8 stron. Nastêpnie do sprita ³adowana jest
*			pocz¹tkowa tekstura. Kolejne czynnoœci to ustawienie œrodka sprita, ustawienie pocz¹kowej pozycji oraz
*			przeskalowanie za³adowanej tekstury.
*
*/
Character::Character()
{	textureFront.loadFromFile("Graphics/bojackFront.png");
	textureBack.loadFromFile("Graphics/bojackBack.png");
	textureLeftFront.loadFromFile("Graphics/bojackLeftFront.png");
	textureRightFront.loadFromFile("Graphics/bojackRightFront.png");
	textureLeftBack.loadFromFile("Graphics/bojackLeftBack.png");
	textureRightBack.loadFromFile("Graphics/bojackRightBack.png");
	textureLeft.loadFromFile("Graphics/bojackLeft.png");
	textureRight.loadFromFile("Graphics/bojackRight.png");
	
	sprite.setTexture(textureFront);	
		
	sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);		
	sprite.setPosition(screenWidth/2, 2200);	
	sprite.setScale(0.5f, 0.5f);
}

/// \brief	Metoda zwraca sprita aby umo¿liwiæ narysowanie postaci w g³ównej pêtli gry.
/// \return	Pole typu Sprite.
Sprite Character::getSprite()
{
	return sprite;
}

/** \brief		Metoda pozwalaj¹ca na sterowanie postaci¹.
* \details	Zale¿nie od wciœniêcia ró¿nych strza³ek sprawdzane s¹ wspó³rzêdne postaci wzglêdem granic mapy gry.
*				Jeœli to mo¿liwe to sprite porusza siê z okreœlon¹ prêdkoœci¹. W innym wypadku 'odbija siê' od granicy mapy.
*				Przy zmianie kierunku poruszania siê do sprita ³adowana jest tekstura przedstawiaj¹ca postaæ pod odpowiednim k¹tem.
*/
void Character::walking()
{	
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		if (sprite.getPosition().x - sprite.getGlobalBounds().width / 2 <= 160)	
		{
			
			sprite.move(10, 0);	
						
		}
		else
		{
			sprite.move(-1.5, 0);
			sprite.setTexture(textureLeft);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		if ((sprite.getPosition().x) + sprite.getGlobalBounds().width / 2 >= 1040)
		{
			
			sprite.move(-10, 0);
			
		}
		else
		{
			sprite.move(1.5, 0);
			sprite.setTexture(textureRight);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		if (sprite.getPosition().y - sprite.getGlobalBounds().height / 2 <= 0)
		{
			
			sprite.move(0, 10);
		}
		else
		{
			sprite.move(0, -1.5);
			sprite.setTexture(textureBack);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		if (sprite.getPosition().y + sprite.getGlobalBounds().height / 2 >= 2400)
		{
			
			sprite.move(0, -10);
		}
		else
		{
			sprite.move(0, 1.5);
			sprite.setTexture(textureFront);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		sprite.move(-0.5, -0.5);
		sprite.setTexture(textureLeftBack);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		sprite.move(-0.5, 0.5);
		sprite.setTexture(textureLeftFront);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		sprite.move(0.5, -0.5);
		sprite.setTexture(textureRightBack);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		sprite.move(0.5, 0.5);
		sprite.setTexture(textureRightFront);
	}

}

/// \brief	Zwraca wspó³rzêdne lewej krawêdzi sprita.
float Character::left()
{
	return sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
}
/// \brief	Zwraca wspó³rzêdne prawej krawêdzi sprita.
float Character::right()
{
	return sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
}
/// \brief	Zwraca wspó³rzêdne górnej krawêdzi sprita.
float Character::top()
{
	return sprite.getPosition().y - sprite.getGlobalBounds().height / 2;
}
/// \brief	Zwraca wspó³rzêdne dolnej krawêdzi sprita.
float Character::bottom()
{
	return sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
}

/// \brief	Zwraca wartoœæ typu Vector2f, któr¹ jest pozycja postaci.
Vector2f Character::getCharacterPosition()
{
	return sprite.getPosition();
}

/// \brief	Zwraca wartoœæ typu float, któr¹ jest pozycja postaci w pionie.
float Character::getY()
{
	return sprite.getPosition().y;
}

/// \brief	Zwraca wartoœæ typu float, któr¹ jest pozycja postaci w poziomie.
float Character::getX()
{
	return sprite.getPosition().x;
}

/// \brief Zwraca wysokoœæ sprita postaci.
float Character::getHeight()
{
	return sprite.getGlobalBounds().height;
}