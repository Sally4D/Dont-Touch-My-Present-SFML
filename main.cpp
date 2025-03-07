
#include <iostream>
#include "MainMenu.h"

int main()
{
	sf::Music music;
	if (!music.openFromFile("data/audio/bg.ogg"))
	{
		std::cout << "Error loading music\n";
	}
	else
	{
		music.setLoop(true);
		music.play();
	}
	MainMenu menu;
	menu.run();

}
