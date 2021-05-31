#pragma once

#include "Collidable.h"

namespace ss
{
	class PlayerBullet : public Collidable
	{
	private:
		sf::Vector2f pos;
		float rot;
		float speed;
		float cosr, sinr;

	public:
		PlayerBullet(const sf::Vector2f& position, float rotation, float travelSpeed);
		void Update(float deltaTime) override;
	};
}