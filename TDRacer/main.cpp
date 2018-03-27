#pragma once
//SFML
#include "SFML\Graphics.hpp"
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")

//Box2D
#include "Box2D\Box2D.h"
#pragma comment(lib, "Box2D.lib")

//Libraries
#include "ecm.h"
#include "menu.h"
#include "SpriteComponent.h"
#include <iostream>




#define B2_PIXEL_RATIO 30.0f

Manager manager;
auto& player(manager.addEntity());
auto& player2(manager.addEntity());

//// can be moved
//sf::RenderWindow window(sf::VideoMode(800, 500), "TD Championship Racer Menu");
//
////Initialise the Box2D world
//b2Vec2 gravity(0, 9.8f);
//b2World world(gravity);
//

void Init() {
	
}

void Load() {
	player.addComponent<SpriteComponent>(sf::IntRect(0, 0, 41, 69), 100, 100, "bin/car_green_small_1.png");
	//player2.addComponent<SpriteComponent>(sf::IntRect(0, 0, 100, 100), 500, 500, "bin/Cars.jpg");
}

void Update() {
	manager.update();
}

void Render(sf::RenderWindow & window)
{
	manager.draw(window);
}


	//*************************************************
	//*************************************************
	//*********								***********
	//*********		WORKING BOUNCY BALL		***********
	//*********								***********
	//*************************************************
	//*************************************************


	//Create Physics World
	//b2World  phWorld(b2Vec2(-2,-2));

	//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	//sf::Vector2f winSize = window.getDefaultView().getSize();


	int main()
	{

		//creates window and sets to fullscreen 
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "TD Championship Racer", sf::Style::Fullscreen);
		//limts ramte rate
		window.setFramerateLimit(120);
		//turns on Vsync ********* Helps prevent screen tearing. caps to 60 FPS or 30 FPS ********* 
		window.setVerticalSyncEnabled(true);


		//Comment this to use menu

		Load();

		while (window.isOpen())
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				//closes window if the game crashes
				if (event.type == sf::Event::Closed)
					window.close();

				// closes game window when game esc pressed
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

				// game loop			
				window.clear();
				Update();
				Render(window);
				window.display();
			}
		}

		////////////////////////////////////////////


		//Menu menu(window.getSize().x, window.getSize().y);

		//int Imenu = 0;

		//while (Imenu == 0)
		//{
		//menu.MenuEvents(window);
		//Imenu = 1;
		//}

		
		//sf::Vector2f shapePosition(winSize.x * 0.5f, winSize.y * 0.5f);
//
		//// Define SFML Circle 
		//float radius = 20.0f;
		//sf::CircleShape  rcShape(radius);
		//rcShape.setPosition(shapePosition);
		//rcShape.setFillColor(sf::Color(255, 255, 0, 255));
//
		//
		////Defines the Physics body????
		//b2BodyDef shapeBodyDef;
		//shapeBodyDef.type = b2_dynamicBody;
		////This ties the physics body to the position of the shape
		//shapeBodyDef.position = b2Vec2(shapePosition.x / B2_PIXEL_RATIO, shapePosition.y / B2_PIXEL_RATIO);
		//b2Body* shapeBody = phWorld.CreateBody(&shapeBodyDef);
//
//
		////Creates a Box2D circle shape
		//b2CircleShape circleShape;
		//circleShape.m_radius = radius / B2_PIXEL_RATIO;
//
		////Creates the circle box2d fixture and connects to shape
		//b2FixtureDef rcShapeFixDef;
		//rcShapeFixDef.shape = &circleShape;
		//rcShapeFixDef.density = 10.0f;
		//rcShapeFixDef.friction = 0.4f;
		//rcShapeFixDef.restitution = 1.0f;
		//shapeBody->CreateFixture(&rcShapeFixDef);
//
		//// Surround screen with static edges
		//b2FixtureDef groundBoxDef;
		//b2BodyDef groundBodyDef;
		//groundBodyDef.position.Set(0, 0);
		//b2Body* groundBody = phWorld.CreateBody(&groundBodyDef);
		//
		//b2Vec2 vs[5];
		//vs[0].Set(winSize.x / B2_PIXEL_RATIO, 0.0f);
		//vs[1].Set(winSize.x / B2_PIXEL_RATIO, winSize.y / B2_PIXEL_RATIO);
		//vs[2].Set(0.0f, winSize.y / B2_PIXEL_RATIO);
		//vs[3].Set(0.0f, 0.0f);
		//vs[4].Set(winSize.x / B2_PIXEL_RATIO, 0.0f);
		//b2ChainShape wallShape;
		//wallShape.CreateChain(vs, 5);
		//groundBoxDef.shape = &wallShape;
		//groundBody->CreateFixture(&groundBoxDef);
		//
		//float scale = 5.0f;
		//shapeBody->SetLinearVelocity(b2Vec2(scale, scale));
		//
		//while (window.isOpen())
		//{
		//	sf::Event event;
		//	while (window.pollEvent(event))
		//	{
		//		if (event.type == sf::Event::Closed)
		//			window.close();
		//	}
		//
		//	float timeStep = 1.0f / 4000.0f;
		//	phWorld.Step(timeStep, 10, 10);
		//
		//	float x = shapeBody->GetPosition().x * B2_PIXEL_RATIO;
		//	float y = shapeBody->GetPosition().y * B2_PIXEL_RATIO;
		//	rcShape.setPosition(x, y);
		//
		//	window.clear();
		//	window.draw(rcShape);
		//	window.display();
		//}
		//return EXIT_SUCCESS;
	}
















