#pragma once
#include "ecm.h"

class PositionComponent : public Component {
private:
	int xPos;
	int yPos;
public:
	void init() override {
		xPos = 0;
		yPos = 0;
	}
	
	//Default Constructor
	PositionComponent() {
		xPos = 0;
		yPos = 0;
	}

	//Constructor that takes two ints 
	PositionComponent(int x, int y) {
		xPos = x;
		yPos = y;
	}

	void update() override {
		xPos++;
		yPos++;
	}

	int x() { return xPos; }
	//Added
	void x(int x) {
		xPos = x;
	}

	int y() { return yPos; }
	//Added
	void y(int y) {
		yPos = y;
	}

	void setPos(int x, int y) {
		xPos = x;
		yPos = y;
	}
};