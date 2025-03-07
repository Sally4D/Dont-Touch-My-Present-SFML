#pragma once
#include "Component.h"

class Player
{
private:
	Image hand;
	Image gift;
public:
	Player();
	void playerMovement();
	void setPosition(float x, float y);
	void move(const float x, const float y);
	void drawPlayer(sf::RenderWindow&);
	Image getHand() { return hand; }
	Image getGift() { return gift; }
	bool collision(const Image&);

};

