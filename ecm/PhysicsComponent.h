#pragma once
#include "SFML\Graphics.hpp"
#include "ecm.h"
//#include "positionComponent.h"

class PhysicsComponent : public Component {
private:
	b2Body* body;
	b2Fixture* fixture;

public:
	//default constructor
	PhysicsComponent();

	//constructor that takes a sprite
	PhysicsComponent(Entity*, bool, const sf::Vector2f&);
	
	b2Fixture* const getFixture() const;
	bool isTouching(PhysicsComponent&) const;
	bool isTouching(PhysicsComponent&, b2Contact const*) const;

	std::vector<const b2Contact*> getTouching() const;
	const sf::Vector2f getVelocity() const;

	void setRestitution(float);
	void setFriction(float);
	void setMass(float);
//	void update(double) override;
//	void render() override;
	void setVelocity(const sf::Vector2f&);

	~PhysicsComponent() override;


};

extern sf::Texture spritesheet;