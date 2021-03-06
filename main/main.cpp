#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>

#include<vector>

#include "Character.h"
#include "Coins.h"
#include "Score.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include "Cup.h"
#include "screens.h"

/// Stałe opisujące rozdzielczość okna wyświetlającego program.
#define screenWidth 1200
#define screenHeight 800	

/// Zadeklarowanie używania przestrzeni nazw standardowej oraz biblioteki SFML.
using namespace std;
using namespace sf;		

/// Prototypy funkcji.
template <class T1, class T2> bool isIntersecting(T1 &a, T2 &b);	
bool collisionTestCharacterCoin(Coins& coin, Character &character);	
bool collisionTestEnemyBullet(Bullet& bullet, Enemy& enemy);
void setBulletPos(Character &character, Bullet &bullet);
bool collisionTestCharacterCup(Character& character, Cup& cup);
bool collisionTestCharacterEnemy(Character& character, Enemy& enemy);



int main()
{
	/**
	* \brief	Włączenie muzyki w tle.
	* \details	Do obiektu klasy Music wczytywany jest plik dźwiękowy, następnie jest uruchamiany.
	*/
	Music music;
	music.openFromFile("Music/theme.wav");
	music.setLoop(true);
	music.setVolume(50);
	music.setPosition(0, 1, 0);
	music.setPitch(1);
	music.play();

	/// Utworzenie głownego okna z grą.
	RenderWindow window(VideoMode(screenWidth, screenHeight), "CyberBojack");	
	/// Utworzenie okna z grafiką początkową.
	RenderWindow windowFirst(VideoMode(screenWidth, screenHeight), "CyberBojack");	
	
	
	Event event;
	Background background;
	Cup cup;
	Screens screen;
	Texture backgroundtexture;
	backgroundtexture.loadFromFile("Graphics/background.png");
	Sprite backgroundsprite;
	backgroundsprite.setTexture(backgroundtexture);
	backgroundsprite.setOrigin(backgroundsprite.getGlobalBounds().width / 2, backgroundsprite.getGlobalBounds().height / 2);
	backgroundsprite.setPosition(screenWidth / 2, screenHeight / 2);
	Character character;	
	Score score;	
	Bullet bullet;
	vector<Bullet> bullets;
	
	/// Obiekt klasy SFML - View. Służy do przemieszczania się "kamery" wraz z poruszaniem się główną postacią.
	View view;
	view.setSize(1200, 800);
	view.setCenter(600, 2000);
	
	Coins coin1(200, 1770);
	Coins coin2(750, 1770);
	Coins coin3(1000, 1900);
	Coins coin4(450, 1900);
	Coins coin5(750, 1700);
	Coins coin6(300, 300);
	Coins coin7(700, 700);
	Coins coin8(600, 1000);
	Coins coin9(600,400);
	Coins coin10(750,600);
	Coins coin11(750,1200);
	Coins coin12(150,1300);
	Coins coin13(400,500);
	
	vector<Coins> coins;
	coins.push_back(coin1);
	coins.push_back(coin2);
	coins.push_back(coin3);
	coins.push_back(coin4);
	coins.push_back(coin5);
	coins.push_back(coin6);
	coins.push_back(coin7);
	coins.push_back(coin8);
	coins.push_back(coin9);
	coins.push_back(coin10);
	coins.push_back(coin11);
	coins.push_back(coin12);
	coins.push_back(coin13);
	
	
	Enemy enemy1(450, 1750);
	Enemy enemy2(750, 1900);
	Enemy enemy3(150, 2000);
	Enemy enemy4(450, 1300);
	Enemy enemy5(750, 1150);
	Enemy enemy6(150, 1000);
	Enemy enemy7(450, 450);
	Enemy enemy8(750, 600);
	Enemy enemy9(150, 750);
	Enemy enemy10(450, 350);
	Enemy enemy11(750, 900);
	vector<Enemy> enemies;
	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);
	enemies.push_back(enemy5);
	enemies.push_back(enemy6);
	enemies.push_back(enemy7);
	enemies.push_back(enemy8);
	enemies.push_back(enemy9);
	enemies.push_back(enemy10);
	enemies.push_back(enemy11);

	/// Pętla gry z ekranem początkowym.
	while (windowFirst.isOpen())
	{
		/// Utworzenie na ekranie grafiki z planszą początkową.
		windowFirst.draw(screen.getSprite1());
		if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) 
		{
			windowFirst.close();
			break;
			/// Funkcja goto przechodząca do etykiety end 
			goto end;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			windowFirst.close();
			window.close();
			break;
		}
		windowFirst.display();
	}
	
	/// Główna pętla gry
	while (window.isOpen())
	{
			window.pollEvent(event);
				
			window.draw(background.getSprite());
						
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape))
			{
				window.close();
				break;
			}

			/// \brief Rysowanie na ekranie obiektów. 
			for (auto & coin : coins) {
				window.draw(coin.getSprite());
			}

			for (auto & enemy : enemies) {
				window.draw(enemy.getSprite());
			}
			window.draw(cup.getSprite());
			window.draw(character.getSprite());
			
			
			/// \brief Dodawanie punktów do wyniku po zbieranie monet. 
			for (auto & coin : coins)
			{
				if (collisionTestCharacterCoin(coin, character))
					score._score = score._score + 10;
			}

			/// \brief Znikanie monet po zebraniu ich.
			auto coinIterator = remove_if(begin(coins), end(coins), [](Coins &coin) { return coin.isDisappeared(); });
			coins.erase(coinIterator, end(coins));
			
			
			/// \brief Mechanizm strzelania. 

			if (bullet.getIsFiring())
			{
				setBulletPos(character, bullet);
				bullets.push_back(bullet);
				bullet.justFired();
			}

			for (int i = 0; i < bullets.size(); i++)
			{
				window.draw(bullets[i].getSprite());
				bullets[i].letItFly();
			}

			/// \brief Zmniejszanie życia przeciwników. 

			for (auto & enemy : enemies)
			{
				for (auto it = bullets.begin(); it != bullets.end(); it++)
				{
					if (collisionTestEnemyBullet(*it, enemy)) {

						bullets.erase(it, end(bullets));
						break;
					}
				}
			}
			
			/// \brief Sprawdzanie czy przeciwnik żyje.

			for (auto & enemy : enemies)
			{
				enemy.isKilled();
			}

			/// \brief Dodawanie punktów do wyniku po zabiciu przeciwnika.

			for (auto & enemy : enemies)
			{
				if (enemy.getDead() == true)
					score._score = score._score + 25;
			}

			/// \brief Znikanie przeciwników po spadnięciu życia do 0,

			auto enemyIterator = remove_if(begin(enemies), end(enemies), [](Enemy &enemy) { return enemy.getDead(); });
			enemies.erase(enemyIterator, end(enemies));

			/// \brief Wywołanie metody umożliwiającej poruszanie się dla wszystkich przeciwników.
			for (auto & enemy : enemies)
			{
				enemy.enemyMoving();
			}

			/// \brief Plansza po dotarciu do pucharu.
			if (collisionTestCharacterCup(character, cup)) {
												
				goto win;
				
			}
			
			/// \brief Plansza po przegraniu/
			/// \details Jeśli zetkniemy się z przeciwnikiem to przegrywamy pokazuje się plansza końcowa.
			
			for (auto& enemy : enemies)
			{
				if (collisionTestCharacterEnemy(character, enemy)) 
				{
					goto lose;
				}
			}
					
			window.setView(view);
			
			
			/// Aktualizacja wyniku.
			score.updateScore(score._score);
			/// Metoda pozwalająca na poruszanie się postacią.
			character.walking();
			/// \brief Ustawianie kamery względem pozycji postaci.
			view.setCenter(600,character.getCharacterPosition().y - 200);
			if (character.getCharacterPosition().y >= 2200)
				view.setCenter(600, 2000);
			if (character.getCharacterPosition().y <= 600)
				view.setCenter(600, 400);
			/// Metoda umożliwiająca strzelanie.
			bullet.shoot();
			
			/// Pokazanie na ekranie obiektów
			window.display();
	}

/// Etykieta funkcji goto, uruchamiana przy dotarciu do pucharu. 
win:
	{
	/// Dodanie do wyniku 100 pkt.
	score._score = score._score + 100;
		/// Utworzenie okna z planszą końcową po wygraniu.  
		RenderWindow windowWin(VideoMode(screenWidth, screenHeight), "CyberBojack");
		/// Pętla rysująca z każdym cyklem planszę końcową oraz osiągnięty wynik.
		while (windowWin.isOpen())
		{
			windowWin.draw(screen.getSprite2());
			windowWin.draw(score.getTextScore());
			windowWin.draw(score.getTextInt());
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			{
				windowWin.close();
				break;
				goto end;
			}
			windowWin.display();
		}
	}

/// Etykieta funkcji goto. Uruchamia się po zetknięciu się z przeciwnikiem. 
lose:
	{
		RenderWindow windowLose(VideoMode(screenWidth, screenHeight), "CyberBojack");
		/// Pętla wyświetlająca planszę końcową po przegraniu oraz osiągnięty wynik.
		while (windowLose.isOpen())
		{
			windowLose.draw(screen.getSprite3());
			windowLose.draw(score.getTextScore());
			windowLose.draw(score.getTextInt());
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			{
				windowLose.close();
				break;
			}
			windowLose.display();
		}
	}
/// Etykieta funkcji goto. Zakończenie funckji main() programu. 	
end: {
	return 0;
	}
}

/**
* \brief	Szablon służący do sprawdzania nachodzenia na siebie obiektów różnych klas.
*
* \details	Jako parametry przekazywane są obiekty dwóch klas. Muszą one zawierać metody right(), 
*			left(), top(), bottom() zwracające położenie kolejnych krawędzi.
*
* \return	W razie zetknęcia się krawędzi dwóch obiektów funkcja zwraca true, w innym wypadku false.
*
*/


template <class T1, class T2> bool isIntersecting(T1 &a, T2 &b)
{
	return a.right() >= b.left() && a.left() <= b.right()
		&& a.bottom() >= b.top() && a.top() <= b.bottom();
}


/**
* \brief	Funkcja sprawdza czy obiekty klas Character i Coin nachodzą na siebie.
*
* \details	Wykorzystywany jest szablon funkcji isIntersecting(). Jeśli zwróci false, ta funkcja również zwraca false
*			i nic się nie dzieje. Jeśli zwróci true - uruchamiana jest metoda disappear() obiektu klasy Coin.

*/

bool collisionTestCharacterCoin(Coins& coin, Character &character)
{
	if (!isIntersecting(coin, character)) return false;

	else {
		coin.disappear();
	}
}


/**
* \brief	Funkcja sprawdza czy obiekty klas Bullet i Enemy nachodzą na siebie.
*	
* \details	Jeśli wystąpi kolizja pomiędzy obiektami klas Bullet i Enemy - tj. jeśli przeciwnik zostanie trafiony
*			nabojem uruchamiana jest metoda klasy Enemy - decreaseLife() powodująca zmniejszenie życia danego przeciwnika
*
*
*/

bool collisionTestEnemyBullet(Bullet& bullet, Enemy& enemy)
{
	if (!isIntersecting(bullet, enemy)) return false;

	else {
		enemy.decreaseLife();
	}
}

/**
* \brief	Sprawdzenie czy wystąpiła kolizja obiektów klas Character i Cup.
*/

bool collisionTestCharacterCup(Character& character, Cup& cup)
{
	if (!isIntersecting(character, cup)) return false;
	else true;
}

/**
* \brief	Sprawdzenie czy wystąpiła kolizja obiektów klas Character i Enemy.
*/

bool collisionTestCharacterEnemy(Character& character, Enemy& enemy)
{
	if (!isIntersecting(character, enemy)) return false;
	else true;
}

/**
* \brief	Ustawienie pozycji obiektu klasy Bullet względem obiektu klay Character
*
* \details	Funkcja pozwala pobrać współrzędne położenia postaci i za pomocą metody setBulletPos() klasy Bullet
*			wystrzelić nabój właśnie z tego miejsca, w którym znajduje się postać.
*/

void setBulletPos(Character &character, Bullet &bullet) {
	bullet.setBulletPos(character.getX(), character.getY());
}


