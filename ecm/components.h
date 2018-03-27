#pragma once

#include <SFML\Graphics.hpp>

class components {
public:
	// Define SFML Circle 
	float radius = 20.0f;
	sf::CircleShape  rcShape();
	
	components() {
		setPosition(shapePosition);
		rcShape.setFillColor(sf::Color(255, 255, 0, 255));
	}
};