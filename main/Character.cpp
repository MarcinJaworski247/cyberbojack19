#include "Character.h"

#define screenWidth 1200
#define screenHeight 800

/**
* \brief	Kostruktor klasy Character
*
* \details	Do tekstur �adowane s� obrazki g��wnej postaci przedstawiaj�ce je z 8 stron. Nast�pnie do sprita �adowana jest
*			pocz�tkowa tekstura. Kolejne czynno�ci to ustawienie �rodka sprita, ustawienie pocz�kowej pozycji oraz
*			przeskalowanie za�adowanej tekstury.
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

/// \brief	Metoda zwraca sprita aby umo�liwi� narysowanie postaci w g��wnej p�tli gry.
/// \return	Pole typu Sprite.
Sprite Character::getSprite()
{
	return sprite;
}

/** \brief		Metoda pozwalaj�ca na sterowanie postaci�.
* \details	Zale�nie od wci�ni�cia r�nych strza�ek sprawdzane s� wsp�rz�dne postaci wzgl�dem granic mapy gry.
*				Je�li to mo�liwe to sprite porusza si� z okre�lon� pr�dko�ci�. W innym wypadku 'odbija si�' od granicy mapy.
*				Przy zmianie kierunku poruszania si� do sprita �adowana jest tekstura przedstawiaj�ca posta� pod odpowiednim k�tem.
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

/// \brief	Zwraca wsp�rz�dne lewej kraw�dzi sprita.
float Character::left()
{
	return sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
}
/// \brief	Zwraca wsp�rz�dne prawej kraw�dzi sprita.
float Character::right()
{
	return sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
}
/// \brief	Zwraca wsp�rz�dne g�rnej kraw�dzi sprita.
float Character::top()
{
	return sprite.getPosition().y - sprite.getGlobalBounds().height / 2;
}
/// \brief	Zwraca wsp�rz�dne dolnej kraw�dzi sprita.
float Character::bottom()
{
	return sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
}

/// \brief	Zwraca warto�� typu Vector2f, kt�r� jest pozycja postaci.
Vector2f Character::getCharacterPosition()
{
	return sprite.getPosition();
}

/// \brief	Zwraca warto�� typu float, kt�r� jest pozycja postaci w pionie.
float Character::getY()
{
	return sprite.getPosition().y;
}

/// \brief	Zwraca warto�� typu float, kt�r� jest pozycja postaci w poziomie.
float Character::getX()
{
	return sprite.getPosition().x;
}

/// \brief Zwraca wysoko�� sprita postaci.
float Character::getHeight()
{
	return sprite.getGlobalBounds().height;
}