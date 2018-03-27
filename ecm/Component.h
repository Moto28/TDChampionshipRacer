#pragma once
#include "SFML\Graphics.hpp"
#include "ecm.h"
//#include "positionComponent.h"

class Component {
protected:
	Entity* const parent;
	bool forDeletion;
	const bool dynamic;
	explicit Component(Entity* const, const bool);

public:
	//default constructor
	Component();

	bool isForDeletion() const;
	virtual void update(double);
	virtual void render();
	

	//de-constructor
	virtual ~Component();

};