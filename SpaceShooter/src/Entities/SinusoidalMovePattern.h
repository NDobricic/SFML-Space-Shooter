#pragma once

#include "MovePattern.h"

namespace ss
{
	struct SinusoidalMovePattern : public MovePattern
	{
	private:
		float moveRadius;
		float horizontalSpeed, verticalSpeed;

	public:
		SinusoidalMovePattern(float moveRadius, float horizontalSpeed, float verticalSpeed)
			: moveRadius(moveRadius), horizontalSpeed(horizontalSpeed), verticalSpeed(verticalSpeed)
		{ }

		virtual sf::Vector2f GetPositionOffset(float deltaTime) override
		{
			totalTime += deltaTime;

			float hDiff = (sin(totalTime * horizontalSpeed) - sin((totalTime - deltaTime) * horizontalSpeed)) * moveRadius;
			float vDiff = verticalSpeed * deltaTime;

			return sf::Vector2f(hDiff, vDiff);
		}
	};
}