#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	struct MovePattern
	{
	protected:
		float totalTime = 0.0f;

	public:
		virtual sf::Vector2f GetPositionOffset(float deltaTime) = 0;
	};
}