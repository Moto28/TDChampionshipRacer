#pragma once
#include "SFML\Graphics.hpp"

//taken from lets make games https://www.youtube.com/watch?v=XsvI8Sng6dk

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component; // forward declare class
class Entity;

//sets ComponentID to std size_t
using ComponentID = std::size_t;

//creates a ComponentID
inline ComponentID getComponentTypeID() {

	static ComponentID lastID = 0;
	return lastID++;
}

//gets the same id for each type
template<typename T> inline ComponentID getComponentTypeID() noexcept {

	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

//sets the max components of each entity
constexpr std::size_t maxComponents = 32;

//allows is check what components entity has
using ComponentBitSet = std::bitset<maxComponents>;
//array of component pointer the length of maxComponents
using ComponentArray = std::array<Component*, maxComponents>;


class Component : public sf::Sprite {
public:
	Entity * entity;

	virtual void init() {}
	virtual	void update() {}
	virtual	void draw(sf::RenderWindow & window) {}

	virtual ~Component() {}
};


class Entity : public sf::Sprite {
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
public:
	//Moved from private to public and added Static - This removes 
	//the error in update function in ecm.cpp

	//we should move this into ecm.cpp if we can!!!!!
	void update() {
		for (auto& c : components) c->update();	
	}

	void draw(sf::RenderWindow & window) {
		for (auto& c : components) c->draw(window);
	}

	bool isActive() const { return active; }
	void destroy() { active = false; }

	//checks if component is attached
	template<typename T> bool hasComponent() const {
		return componentBitSet[getComponentTypeID<T>];
	}

	template<typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		//makes sure component types are added to same position in array
		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();

		return *c;
	}

	template<typename T> T& getComponent() const {

		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};


class Manager {
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update() {

		for (auto& e : entities) e->update();
	}

	void draw(sf::RenderWindow & window) {
		for (auto& e : entities) e->draw(window);
	}

	void refresh() {
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity> &mEntity)
		{
			return !mEntity->isActive();
		}),
			std::end(entities));
	}

	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};

