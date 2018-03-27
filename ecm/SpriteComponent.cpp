#pragma once
#include "SFML\Graphics.hpp"
#include "SpriteComponent.h"

SpriteComponent::SpriteComponent() {

}

SpriteComponent::SpriteComponent(sf::IntRect ir, float x, float y, const char *path) {
	_sprite = ir;

	if (!spritesheet.loadFromFile(path)) {
		std::cerr << "Failed to load spritesheet" << std::endl;
		std::cout << path;
	}
	sprite.setTexture(spritesheet);
	sprite.setTextureRect(_sprite);
	sprite.setPosition(x, y);
}

void SpriteComponent::draw(sf::RenderWindow &window) {
	window.draw(sprite);
	
}