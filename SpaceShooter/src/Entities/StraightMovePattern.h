#pragma once

#include "MovePattern.h"

namespace ss
{
	struct StraightMovePattern : public MovePattern
	{
	private:
		float speed;

	public:
		StraightMovePattern(float moveSpeed)
			: speed(moveSpeed)
		{ }

		virtual sf::Vector2f GetPositionOffset(float deltaTime) override
		{
			totalTime += deltaTime;

			float vDiff = speed * deltaTime;

			return sf::Vector2f(0, vDiff);
		}
	};
}