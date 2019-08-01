#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

/**
* \brief	Klasa reprezentuj¹ca naboje wystrzeliwane przez g³ówn¹ postaæ. 
*/

class Bullet
{
private:
	Texture texture;
	Sprite sprite;
	bool isFiring = false;
	
	
public:
	Bullet();
	Sprite getSprite();
	float left();
	float right();
	float top();
	float bottom();
	bool getIsFiring();
	void justFired();
	void shoot();
	void letItFly();
		
	void setBulletPos(float x, float y);

	Clock clock;
	Time shot;
	Time reload;
};

