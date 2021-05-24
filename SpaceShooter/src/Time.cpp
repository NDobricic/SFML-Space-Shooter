#include "Time.h"

namespace ss
{
	Time::Time()
	{
		clock.restart();
	}

	float Time::GlobalTime()
	{
		return clock.getElapsedTime().asSeconds();
	}

	float Time::DeltaTime()
	{
		return clock.getElapsedTime().asSeconds() - lastFrameTime;
	}

	void Time::AdvanceFrame()
	{
		lastFrameTime = clock.getElapsedTime().asSeconds();
	}
}
