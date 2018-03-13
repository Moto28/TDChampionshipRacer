#pragma once
#include "SFML\Graphics.hpp"

#include "ecm.h"
#include "positionComponent.h"
#include "SpriteComponent.h"

Manager manager;

auto& player(manager.addEntity());
auto& player2(manager.addEntity());

void Load() {
	player.addComponent<SpriteComponent>(sf::IntRect(0,0,41,69), 100, 100, "bin/car_green_small_1.png");
	player2.addComponent<SpriteComponent>(sf::IntRect(0, 0, 100, 100), 500, 500, "bin/Cars.jpg");


	//player2.addComponent<PositionComponent>(500, 500);
}

void Update() {
	player.update();
	//manager.update();
}

void Render(sf::RenderWindow & window)
{
	//player.draw(window);
	manager.draw(window);
}

int main()
{
	//creates window and sets to fullscreen 
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "TD Championship Racer", sf::Style::Fullscreen);
	//limts ramte rate
	window.setFramerateLimit(120);
	//turns on Vsync ********* Helps prevent screen tearing. caps to 60 FPS or 30 FPS ********* 
	window.setVerticalSyncEnabled(true);

	Load();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			//closes window if the game crashes
			if (event.type == sf::Event::Closed)
				window.close();

			// closes game window when game esc pressed
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			// game loop			
			window.clear();
			Render(window);
			window.display();
		}
	}
}

