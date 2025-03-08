#pragma once
//created o day 2 (fully)
#ifndef COMPONENT_H	
#define COMPONENT_H
#include <SFML/Graphics.hpp>

 class Image final: public sf::Sprite
{
public:
	Image()=default;
	Image(const float x, const float y);
	void loadImage(const char* path);
	void animateShape(const float x, const float y, const float elapsedTime);
	void setX() { this->x = this->getPosition().x; }
	void setY() { this->y = this->getPosition().y; }

private:
 	sf::Texture texture;
 	float x, y;
};

class TextField final : public sf::Text
{
private:
	sf::Font font;
	float x, y;
public:
	TextField()=default;
	TextField(const float x, const float y);
	void create(const char* fontPath);
	void animateShape(const float x, const float y, const float elapsedTime);
	void setX() { this->x = this->getPosition().x; }
	void setY() { this->y = this->getPosition().y; }
};

#endif // 0

