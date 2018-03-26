#pragma once
#include "SFML\Graphics.hpp"
#include "Box2D\Box2D.h"
#include "ecm.h"
#include "menu.h"
#include "SpriteComponent.h"

Manager manager;
auto& player(manager.addEntity());
auto& player2(manager.addEntity());

void Load() {
	player.addComponent<SpriteComponent>(sf::IntRect(0, 0, 41, 69), 100, 100, "bin/car_green_small_1.png");
	player2.addComponent<SpriteComponent>(sf::IntRect(0, 0, 100, 100), 500, 500, "bin/Cars.jpg");
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
	sf::RenderWindow window(sf::VideoMode(800, 500), "TD Championship Racer");

	Menu menu(window.getSize().x, window.getSize().y);


	menu.MenuEvents(window);

}


