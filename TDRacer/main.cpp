#include "SFML\Graphics.hpp"
#include ""
int main()
{
	//creates window and sets to fullscreen 
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "TD Championship Racer", sf::Style::Fullscreen);
	//limts ramte rate
	window.setFramerateLimit(120);
	//turns on Vsync ********* Helps prevent screen tearing. caps to 60 FPS or 30 FPS ********* 
	window.setVerticalSyncEnabled(true);



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
			window.display();
		}
	}
}