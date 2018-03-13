#pragma once


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


class Component {
public:
	Entity * entity;

	virtual void init() {}
	virtual	void update() {}
	virtual	void draw() {}

	virtual ~Component() {}
};

class Entity {
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentarray;
	ComponentBitSet componentBitSet;
public:

	//we should move this into ecm.cpp if we can!!!!!
	void update() {

		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}

	void draw() {}

	bool isActive() const { return active; }
	void destroy() { active = false; }

	//checks if component is attached
	template<typename T> bool hasComponent() const {

		return componentBitSet[getComponentID<T>];
	}

	template<typename T, typename TAtgs>
	T& addComponent(TArgs&& ... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uptr{ c };
		components.emplace_back::stdmove(uptr));

		//makes sure component types are added to same position in array
		ComponentArray[getComponentTypeID<T>()] = c;
		ComponentBitSet[getComponentTypeID<T>()] = true;

		c->init();

		return *c;
	}

	template<typename T> T& getComponent() const {

		auto ptr(ComponentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

class manager {
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update() {

		for (auto& e : entities) e->update();
	}

	void draw() {
		for (auto& e : entities) e->draw();
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
