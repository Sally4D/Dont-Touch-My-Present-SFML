#include "Component.h"
#include <iostream>
#include "ResourceManager.h"

Image::Image(const float x, const float y)
{
	this->setPosition(x, y);
	this->x = x;
	this->y = y;
}

void Image::loadImage(const char* path)
{
	texture = ResourceManager::getInstance().getTexture(path);
	this->setTexture(texture);
}


void Image::animateShape(const float x,const float y, const float elapsedTime)
{
	//basic function created on day 1 - albata altered did put in class on day 2
	 const float amplitudeY = y; // Amplitude of the vertical sine wave
	 constexpr float frequencyY = 2.0f;  // Frequency of the vertical sine wave
	 const float yOffset = amplitudeY * sin(frequencyY * elapsedTime);
	 const float amplitudeX = x; // Amplitude of the horizontal sine wave
	 constexpr float frequencyX = 5.f;  // Frequency of the horizontal sine wave
	 const float xOffset = amplitudeX * sin(frequencyX * elapsedTime);

	setPosition(this->x + xOffset, this->y + yOffset);
}

TextField::TextField(const float x, const float y)
{
	this->setPosition(x, y);
	this->x = x;
	this->y = y;
}

void TextField::create(const char* text)
{
	font = ResourceManager::getInstance().getFont("data/assets/font.ttf");
	this->setString(text);
	this->setFont(font);
	this->setCharacterSize(30);
	this->setFillColor(sf::Color::Black);

}

void TextField::animateShape(const float x, const float y, const float elapsedTime)
{
	//basic function created on day 1 - albata altered did put in class on day 2
	const float amplitudeY = y; // Amplitude of the vertical sine wave
	constexpr float frequencyY = 2.0f;  // Frequency of the vertical sine wave
	const float yOffset = amplitudeY * sin(frequencyY * elapsedTime);
	const float amplitudeX = x; // Amplitude of the horizontal sine wave
	constexpr float frequencyX = 5.f;  // Frequency of the horizontal sine wave
	const float xOffset = amplitudeX * sin(frequencyX * elapsedTime);

	setPosition(this->x + xOffset, this->y + yOffset);
}