
#ifndef MAINMENU_H
#define MAINMENU_H


#include "SFML/Graphics.hpp"
#include "Component.h"
#include "SFML/Audio.hpp"

class MainMenu
{
public:
    MainMenu();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Music music;

    TextField highScoreText;

    Image title;
	Image cont;
    Image bg;

    sf::Clock clock;
    float amplitudeY;
};


//int main()
//{
//    MainMenu menu;
//    menu.run();
//    return 0;
//}

#endif // !MAINMENU_H