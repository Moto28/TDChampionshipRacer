#pragma once
#include "SFML\Graphics.hpp"
//#include "positionComponent.h"

class SpriteComponent : public Component {
private:
	//PositionComponent * position;
	sf::Texture spritesheet;
	sf::IntRect _sprite;

public:

	//default constructor
	SpriteComponent() = default;

	//constructor that takes a sprite
	SpriteComponent(sf::IntRect ir, float x, float y, const char* path) {
		_sprite = ir;

		if (!spritesheet.loadFromFile(path))
		{
			std::cerr << "Failed to load spritesheet" << std::endl;
		}
		setTexture(spritesheet);
		setTextureRect(_sprite);
		setPosition(x, y);
	}

	void init() override {
		//position = &entity->getComponent<PositionComponent>();
		//this->setPosition(100,100);


	}

	void update() override {

	}

	//might need to re-add overrride later
	void draw(sf::RenderWindow &window) {
		window.draw(*this);
	}
};

extern sf::Texture spritesheet;