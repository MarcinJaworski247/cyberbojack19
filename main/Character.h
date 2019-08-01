#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

/**
* \brief	Klasa zawieraj�ca pola i metody g��wnej postaci, kt�r� sterujemy w grze.
*
*/
class Character 
{
private:
	Vector2f position; 
	
	Sprite sprite;	
	
	Texture textureLeft;	 
	Texture textureRight;
	Texture textureFront;
	Texture textureBack;
	Texture textureLeftBack;
	Texture textureRightBack;
	Texture textureLeftFront;
	Texture textureRightFront;

	int direction;
	
public:
	Character();
	Sprite getSprite();		
	
	void walking();
	
	Vector2f getCharacterPosition();
	

	bool LeftPressed;
	bool RightPressed;
	float right();
	float left();
	float bottom();
	float top();

	
	float getY();
	float getX();
	float getHeight();
};

