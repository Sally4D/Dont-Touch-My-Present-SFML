#ifndef GAME_H
#define GAME_H
#include "EnemyHand.h"
#include "Player.h"

class Game
{
private:
	EnemyHand leftHand, rightHand;
	Player player;
	Image scoreBoard;
	TextField scoreText;
	sf::RenderWindow window;
	int score,highScore;
	void drawGame();
	void updateGame();
	void updateScore();
	void playCheerSound(int);
	int randomNo(const int min, const int max);
	sf::Music* music;
	sf::Music* scoreMusic;
	sf::Clock clock;
public:
	Game();
	void start();
};
#endif

