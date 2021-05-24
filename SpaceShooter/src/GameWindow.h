#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "AnimatedSprite.h"

namespace ss
{
	class GameWindow
	{
	private:
		sf::RenderWindow window;


		void RunGameLoop();
	public:
		GameWindow(int width, int height, const std::string& title = "New SFML Window");
		
	protected:
		void Start() { }
		void Update(float deltaTime) { }
		void OnKeyDown(sf::Keyboard key) { }
		void OnKeyUp(sf::Keyboard key) { }
		void OnKeyPress(sf::Keyboard key) { }
	};
}