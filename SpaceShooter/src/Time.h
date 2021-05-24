#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	class Time
	{
	private:
		sf::Clock clock;
		float lastFrameTime = 0.0f;

	public:
		Time();

		float GlobalTime();
		float DeltaTime();
		void AdvanceFrame();
	};
}