#pragma once
#include "SFML\Graphics.hpp"



class GameScreen {
public:
	GameScreen(float width, float height);
	~GameScreen();

	void draw(sf::RenderWindow &window);
};