#include "Player.h"

#include <iostream>

Player::Player()
{
	hand.loadImage("data/assets/santa_hand.png");
	gift.loadImage("data/assets/gift.png");
	setPosition(200,600);
}


void Player::playerMovement()
{
	constexpr float offset = 20.f; //speed of hand movement

	//movement in direction specific to user input, w moves up, s down etc.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(0, -offset);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(0, offset);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-offset, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(offset, 0);

	//restrict hand movement outside windows boundaries
	if (gift.getPosition().x <= -20)
		setPosition(-20, gift.getPosition().y);
	else if (gift.getPosition().x >= 300)
		setPosition(300, gift.getPosition().y);

	if (gift.getPosition().y <= 30)
		setPosition(gift.getPosition().x, 30);
	else if (gift.getPosition().y >= 600)
		setPosition(gift.getPosition().x, 600);
}

void Player::setPosition(const float x, const float y)
{ //got to keep gift in middle of hand using this function
	hand.setPosition(x-20,y-20);
	gift.setPosition(x, y);
}

void Player::move(const float x, const float y)
{
	hand.move(x, y);
	gift.move(x, y);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(hand);
	window.draw(gift);
}


bool Player::collision(const Image& enemy)
{
	sf::FloatRect collisionDomain = gift.getGlobalBounds();
	collisionDomain.width -= 50;
	collisionDomain.height -= 20;
	collisionDomain.left += 50;
	collisionDomain.top += 20;

	return collisionDomain.intersects(enemy.getGlobalBounds());
}

