#include "Score.h"
#include<sstream>
#define screenWidth 1200
#define screenHeight 800

using namespace std;
using namespace sf;

Score::Score()
{
	font.loadFromFile("Fonts/Gourmet Hearth df.otf");
	textInt.setFont(font);
	textInt.setCharacterSize(charSize);
	textInt.setFillColor(Color::Yellow);
	textInt.setStyle(Text::Bold);
	textInt.setPosition(screenWidth / 2 + 250,  screenHeight / 2);

	textScore.setFont(font);
	textScore.setCharacterSize(charSize);
	textScore.setFillColor(Color::Yellow);
	textScore.setStyle(Text::Bold);
	textScore.setPosition(screenWidth / 2, screenHeight / 2);

	
	textScore.setString("SCORE");
	textInt.setString(to_string(_score));

}

Text Score::getTextInt()
{
	return textInt;
}

Text Score::getTextScore()
{
	return textScore;
}

void Score::updateScore(int _score)
{
	textInt.setString(to_string(_score));
}