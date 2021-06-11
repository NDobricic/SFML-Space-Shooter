#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	struct Weapon
	{
	protected:
		float timeSinceLastFire = 0.0f;
		float fireDelay = 0.5f;
		float rotation = 180.0f;

		virtual void Fire(const sf::Vector2f& shipPosition) = 0;

	public:
		Weapon(float fireDelay, float rotationOffset)
			: timeSinceLastFire(0), fireDelay(fireDelay), rotation(rotationOffset)
		{ }

		void Update(float deltaTime, const sf::Vector2f& shipPosition)
		{
			timeSinceLastFire += deltaTime;

			if (timeSinceLastFire > fireDelay)
			{
				timeSinceLastFire = 0.0f;
				Fire(shipPosition);
			}
		}
	};
}