#include "MainMenu.h"
#include <iostream>
#include <fstream>
#include "Game.h"

using namespace std;
MainMenu::MainMenu()
    : window(sf::VideoMode(360, 640), "SFML works!", sf::Style::Titlebar | sf::Style::Close)
{
	window.setFramerateLimit(300); // Set the window framerate to 60fps
	//playing background music
    /*if (!music.openFromFile("data/audio/bg.ogg"))
    {
        cout << "Error loading music\n";
    }
    else
    {
        music.setLoop(true);
        music.play();
    }*/

	//title image
	title = Image(10, 80); // Create a new Image object with the position of the title image
	title.loadImage("data/menu/title.png");

	//press any key to continue image
	cont.loadImage("data/menu/cont.png"); // Load the Press Any Key to Continue image into texture
    cont.setPosition(5, (float)window.getSize().y);
    amplitudeY = (float)window.getSize().y - 200; // top position until it'll slide from bottom

	//hands holding gift image
    bg.loadImage("data/menu/bg.png");
    bg.setPosition(0, amplitudeY - 130);

    // Now for the High Score Text
    int highScore = 0;
    std::ifstream highScoreFile("data/highscore.txt");
    if (highScoreFile.is_open()) {
        highScoreFile >> highScore;
        highScoreFile.close();
    }

    highScoreText.create("data/assets/font.ttf");
    highScoreText.setPosition(130.f, 180.f);
    highScoreText.setString("BEST: "+to_string(highScore));
}

void MainMenu::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void MainMenu::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
                return;
            }
			//code for key press
            //cout << "Key pressed\n";
            window.close();
            Game game;
			game.start();
        }
    }
}

void MainMenu::update()
{
    float elapsedTime = clock.getElapsedTime().asSeconds();
	title.animateShape(10, 10,elapsedTime);
    // animating lower press any key to continue
    if (cont.getPosition().y > amplitudeY)
    {
        cont.move(0, -1);
    }
}

void MainMenu::render()
{
    window.clear(sf::Color::White);
    window.draw(title);
	window.draw(cont);
	window.draw(bg);
    window.draw(highScoreText);
    window.display();
}
