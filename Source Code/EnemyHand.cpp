#include "EnemyHand.h"
#include <random>

#include "ResourceManager.h"

void EnemyHand::create( const sf::Vector2f range, const char* path)
{
	spawnRange = range; //save range for spawning
	this->enemy = Image(spawnRange.x, 0);
	this->line.loadImage("data/assets/line.png");
	line.setPosition(0, enemy.getPosition().y + 60);
	this->enemy.loadImage(path);
	//this->speed = randomNumber(3.f, 6.f); //random speed
	respawnEnemy();
}

float EnemyHand::randomNumber(float min, float max)
{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dist(min, max);
		return dist(gen);
}

void EnemyHand::enemyMovement()
{
	enemy.setY(); //setY for updating Y every Frame for that swiggy animation
	float elapsedTime = clock.getElapsedTime().asSeconds(); //for animating
	enemy.animateShape(20.f,0.f,elapsedTime); //yeah, for this
	enemy.move(0, speed); //update position (like move it)
	line.move(0, speed);
	if (enemy.getPosition().y > 660) //respawn if hand is out of bounds
	{
		respawnEnemy();
	}
}

bool EnemyHand::scoreCalc(const Image& player)
{
	if (line.getGlobalBounds().intersects(player.getGlobalBounds()) && !isIntersecting)
	{
			isIntersecting = true;
			return true;
	}
	return false;
}

//edited on day 3
void EnemyHand::respawnEnemy()
{
	isIntersecting = false;
	this->speed = randomNumber(1.5f, 9.f);
	if (speed >= 7.f && speed < 8.f) { //added on day3
		music = ResourceManager::getInstance().getMusic("data/audio/chop_3.wav");
		if (music)
			music->play();
	} else if (speed>8)
	{
		music = ResourceManager::getInstance().getMusic("data/audio/chop.wav");
		if (music)
			music->play();
	} //y position also randomized on day 3
	this->enemy.setPosition(randomNumber(spawnRange.x,spawnRange.y),randomNumber(-100.f,-10.f));
	line.setPosition(0, enemy.getPosition().y + 60);
	this->enemy.setX(); //update X for animation
}

//created on day2
void EnemyHand::preventCollision(EnemyHand& otherHand)
{
	const float y1 = enemy.getPosition().y;
	const float y2 = otherHand.getEnemy().getPosition().y;
	if (enemy.getGlobalBounds().intersects(otherHand.getEnemy().getGlobalBounds()))
	{
		constexpr float adjustment = 40.f;
		if (y1 > y2)
		{
			//enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y + 40);
			enemy.move(0.f, adjustment);
			line.move(0.f, adjustment);
			enemy.setY();
			if (speed < otherHand.speed)
			{
				std::swap(speed, otherHand.speed);
			}
		}
		else
		{
			otherHand.getEnemy().move(0, adjustment);
			otherHand.getLine().move(0, adjustment);
			otherHand.getEnemy().setY();
			if (speed > otherHand.speed)
			{
				std::swap(speed, otherHand.speed);
			}
		}
	}
}


