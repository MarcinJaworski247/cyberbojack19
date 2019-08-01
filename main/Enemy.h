#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

/**
* \brief Klasa reprezentuj¹ca przeciwników. 
*/
class Enemy
{
private:
	Texture texture;
	Sprite sprite;
	float life = 1.0f;
	bool dead = false;
public:
	Enemy(float x, float y);
	Sprite getSprite();

	float right();
	float left();
	float bottom();
	float top();

	float firstPositionX;


	
	void isKilled();
	bool getDead();
	void decreaseLife();


	void enemyMovingLeft();
	void enemyMovingRight();
	void enemyMoving();
	
	float getX();

	char direction = 'L';

	Clock clock;
	Time realtime;
	Time retreat;
};

