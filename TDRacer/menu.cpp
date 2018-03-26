#pragma once
#include "menu.h"
#include "gameScreen.h"
#include <iostream>

sf::Texture texture;
sf::Sprite sprite;
GameScreen gameScreen(1980, 1020);

Menu::Menu(float width, float height) {

	//loads menu text font
	if (!font.loadFromFile("bin/XpressiveBlack Regular.ttf"))
	{
		std::cerr << "failed to load font!" << std::endl;
	}

	//loads background image
	if (!texture.loadFromFile("bin/background.png", sf::IntRect(0, 0, 1000, 1000)))
	{
		std::cerr << "failed to load spritesheet!" << std::endl;
	}

	//adds texture to sprite then stretchs it 
	sprite.setTexture(texture);

	//sets menu items on screen
	menu[0].setFont(font);
	menu[0].setCharacterSize(30);
	menu[0].setFillColor(sf::Color(255, 0, 0, 255));
	menu[0].setString("Single Player");
	menu[0].setPosition(sf::Vector2f(width / 2, 200));
	menu[0].setOrigin(menu->getGlobalBounds().width / 2.f, menu->getGlobalBounds().height / 2.f);


	menu[1].setFont(font);
	menu[1].setCharacterSize(30);
	menu[1].setFillColor(sf::Color(255, 255, 255, 255));
	menu[1].setString("Multiplayer");
	menu[1].setPosition(sf::Vector2f(width / 2 + 13, 250));
	menu[1].setOrigin(menu->getGlobalBounds().width / 2.f, menu->getGlobalBounds().height / 2.2f);


	menu[2].setFont(font);
	menu[2].setCharacterSize(30);
	menu[2].setFillColor(sf::Color(255, 255, 255, 255));
	menu[2].setString("Options");
	menu[2].setPosition(sf::Vector2f(width / 2 + 40, 300));
	menu[2].setOrigin(menu->getGlobalBounds().width / 2.f, menu->getGlobalBounds().height / 2.f);


	menu[3].setFont(font);
	menu[3].setCharacterSize(30);
	menu[3].setFillColor(sf::Color(255, 255, 255, 255));
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 2 + 70, 350));
	menu[3].setOrigin(menu->getGlobalBounds().width / 2.f, menu->getGlobalBounds().height / 2.f);

	selectedItemIndex = 0;

}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {

	window.draw(sprite);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}

}

void Menu::MoveUp() {

	//used for keyboard movement in menus
	if (selectedItemIndex - 1 >= 0) {

		menu[selectedItemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}

void Menu::MoveDown() {

	//used for keyboard movement in menus
	if (selectedItemIndex + 1 >= 0) {

		menu[selectedItemIndex].setFillColor(sf::Color(255, 255, 255, 255));
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(255, 0, 0, 255));
	}
}


void Menu::MenuEvents(sf::RenderWindow &window) {

	while (window.isOpen()) {

		sf::Event event;
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		while (window.pollEvent(event)) {

			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {

				case sf::Keyboard::Up:

					if (GetPressedItem() != 0)
					{
						MoveUp();
					}
					break;

				case sf::Keyboard::Down:

					if (GetPressedItem() != 3)
					{
						MoveDown();
					}
					break;

				case sf::Keyboard::Return:
					switch (GetPressedItem()) {

					case 0:
						std::cout << "Single player button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Multiplayer button has been pressed" << std::endl;
						break;
					case 2:
						std::cout << "Options button has been pressed" << std::endl;
						break;
					case 3:
						window.close();
						break;
					}
				}

				//works but f's up keyboard with keyboard input
			case sf::Event::MouseMoved:
			{
				if (menu[0].getGlobalBounds().contains(mousePosF)) {
					menu[0].setFillColor(sf::Color(255, 0, 0, 255));
					menu[1].setFillColor(sf::Color(255, 255, 255, 255));
					menu[2].setFillColor(sf::Color(255, 255, 255, 255));
					menu[3].setFillColor(sf::Color(255, 255, 255, 255));
					selectedItemIndex = 0;
				}

				if (menu[1].getGlobalBounds().contains(mousePosF)) {
					menu[1].setFillColor(sf::Color(255, 0, 0, 255));
					menu[0].setFillColor(sf::Color(255, 255, 255, 255));
					menu[2].setFillColor(sf::Color(255, 255, 255, 255));
					menu[3].setFillColor(sf::Color(255, 255, 255, 255));
					selectedItemIndex = 1;
				}

				if (menu[2].getGlobalBounds().contains(mousePosF)) {
					menu[2].setFillColor(sf::Color(255, 0, 0, 255));
					menu[0].setFillColor(sf::Color(255, 255, 255, 255));
					menu[1].setFillColor(sf::Color(255, 255, 255, 255));
					menu[3].setFillColor(sf::Color(255, 255, 255, 255));
					selectedItemIndex = 2;
				}

				if (menu[3].getGlobalBounds().contains(mousePosF)) {
					menu[3].setFillColor(sf::Color(255, 0, 0, 255));
					menu[0].setFillColor(sf::Color(255, 255, 255, 255));
					menu[1].setFillColor(sf::Color(255, 255, 255, 255));
					menu[2].setFillColor(sf::Color(255, 255, 255, 255));
					selectedItemIndex = 3;
				}
				break;
			case sf::Event::MouseButtonPressed:
			{

				if (menu[0].getGlobalBounds().contains(mousePosF))
				{
					std::cout << "Clicked single player, yay!" << std::endl;

					sf::RenderWindow gameWindow(sf::VideoMode(900, 900), "TD Championship Racer ");

					while (true)
					{
						window.close();
						gameScreen.draw(gameWindow);
					}
				}

				else if (menu[1].getGlobalBounds().contains(mousePosF))
				{
					std::cout << "Clicked multiplayer, yay!" << std::endl;
				}

				else if (menu[2].getGlobalBounds().contains(mousePosF))
				{
					std::cout << "Clicked options, yay!" << std::endl;
				}

				else if (menu[3].getGlobalBounds().contains(mousePosF))
				{
					window.close();
				}
			}


			}
			//menu loop
			window.clear();
			draw(window);
			window.display();

			}

		}
	}
}







