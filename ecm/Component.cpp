#pragma once
#include "SFML\Graphics.hpp"
#include "Component.h"



bool Component::isForDeletion() const {
	return forDeletion;
}

Component::~Component() {

}