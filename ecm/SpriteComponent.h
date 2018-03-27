#pragma once
#include "SFML\Graphics.hpp"
#include "ecm.h"
//#include "positionComponent.h"

class SpriteComponent : public Component {
private:
	//PositionComponent * position;
	sf::Texture spritesheet;
	sf::IntRect _sprite;
	sf::Sprite sprite;

public:
	//default constructor
	SpriteComponent();

	//constructor that takes a sprite
	SpriteComponent(sf::IntRect, float, float, const char*);

	void update() override;

	void draw(sf::RenderWindow &);
};

extern sf::Texture spritesheet;