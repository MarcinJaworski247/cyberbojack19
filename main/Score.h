#include<SFML/Graphics.hpp>
#pragma once

using namespace sf;

/**
* \brief Klasa reprezentuj�ca wynik osi�gni�ty podczas rozgrywki. 
*/
class Score
{
private:
	Text textScore;
	Text textInt;
	
	Font font;
	int charSize = 64;
	
	
public:
	Score();
	Text getTextInt();
	Text getTextScore();
	int _score = 0;
	
	void updateScore(int _score);
	int score = 0;
};

