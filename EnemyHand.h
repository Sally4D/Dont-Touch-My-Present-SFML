//created on day 2 and edited on day 3
#pragma once
#ifndef ENEMYHAND_H
#include <SFML/Audio/Music.hpp>
#include "Component.h"

class EnemyHand
{
private:
	Image enemy;
	Image line;
	sf::Vector2f spawnRange; //left = (-150 to -50),0 right = (100,200),30
	float speed;
	sf::Clock clock;
	//int respawnTimes; //for score actually - nope i got another idea -
	bool isIntersecting;
	void respawnEnemy();
	static float randomNumber(float min, float max);
	sf::Music* music;
public:
	void create(const sf::Vector2f, const char*);
	EnemyHand() = default;
	void enemyMovement();
	bool scoreCalc(const Image&); //for detecting collision with line
	void preventCollision(EnemyHand&);
	Image getEnemy() { return enemy; }
	Image getLine() { return line; }

};

#endif // 0

