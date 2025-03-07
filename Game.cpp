#include "Game.h"

#include <fstream>
#include <iostream>
#include <random>

#include "MainMenu.h"
#include "ResourceManager.h"

Game::Game() : music(nullptr), scoreMusic(nullptr)
{
	window.create(sf::VideoMode(360, 640), "Don't touch my presents!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	leftHand.create(sf::Vector2f(-200, -100), "data/assets/enemy_left.png");
	rightHand.create(sf::Vector2f(100, 200), "data/assets/enemy_right.png");
	rightHand.getEnemy().move(0, 200);
	rightHand.getEnemy().setY();
	scoreBoard = Image(90, 40);
	scoreBoard.loadImage("data/assets/scoreboard.png");

	scoreText = TextField(150, 50);
	scoreText.create("data/assets/font.ttf");

	score = 0;
	highScore = 0;
	scoreText.setString("0");
	scoreMusic = ResourceManager::getInstance().getMusic("data/audio/score.wav");
	std::ifstream highScoreFile("data/highscore.txt");
	if (highScoreFile.is_open())
	{
		highScoreFile >> highScore;
		highScoreFile.close();
	}
	//scoreBoard.setPosition(130, 30);
	//gotta create score too 😭
}

void Game::drawGame()
{
	window.clear(sf::Color::White);
	player.drawPlayer(window);
	window.draw(leftHand.getLine());
	window.draw(rightHand.getLine());
	window.draw(leftHand.getEnemy());
	window.draw(rightHand.getEnemy());
	window.draw(scoreBoard);
	window.draw(scoreText);
	window.display();
}

void Game::updateGame()
{
	player.playerMovement();
	leftHand.enemyMovement();
	rightHand.enemyMovement();
	leftHand.preventCollision(rightHand);
	updateScore();
	//game end case
	if (player.collision(leftHand.getEnemy()) || player.collision(rightHand.getEnemy())) {
		//high score logic
		if (score > highScore) {
			highScore = score;
			std::ofstream highScoreFile("data/highscore.txt");
			if (highScoreFile.is_open()) {
				highScoreFile << highScore;
				highScoreFile.close();
			}
		}
		std::cout << "\n\nScore: " << score;
		std::cout << "\nHighScore: "<<highScore;
		music = ResourceManager::getInstance().getMusic("data/audio/slap.wav");
		if (music) music->play();
		sf::sleep(sf::seconds(3));
		window.close();
		MainMenu menu;
		menu.run();
	}
}

void Game::updateScore()
{
	if (leftHand.scoreCalc(player.getGift()) || rightHand.scoreCalc(player.getGift()))
	{
		score++;
		scoreText.setString(std::to_string(score));
		//playing scoring sound
		if (scoreMusic) scoreMusic->play();
		
	}

	//playing cheer sounds
	if (clock.getElapsedTime().asSeconds()>(float)randomNo(5,15))
	{
		clock.restart();
		playCheerSound(randomNo(1, 4));
	}

	//animating scoreboard
	float elapsedTime = clock.getElapsedTime().asSeconds();
	scoreBoard.animateShape(0.f,10.f,elapsedTime);
	scoreText.animateShape(0.f, 10.f, elapsedTime);
}

void Game::playCheerSound(int val)
{
	if (val == 1)
        music = ResourceManager::getInstance().getMusic("data/audio/cheer.wav");
    else if (val == 2)
        music = ResourceManager::getInstance().getMusic("data/audio/cheer_2.wav");
    else if (val == 3)
        music = ResourceManager::getInstance().getMusic("data/audio/cheer_3.wav");
    else
        music = ResourceManager::getInstance().getMusic("data/audio/cheer_4.wav");
    if (music) music->play();
}

int Game::randomNo(const int min,const int max)
{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(min, max);
		return dist(gen);
}

void Game::start()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
					MainMenu menu;
					menu.run();
				}
			}
		}

		updateGame();
		drawGame();
	}
}
