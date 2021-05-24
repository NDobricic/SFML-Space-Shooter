#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	class GameObject
	{
	public:
		sf::Vector2f position;
		float rotation = 0.0f;

		virtual void Update(float deltaTime) { }
		virtual const sf::Sprite& GetSprite() = 0;
	};
}