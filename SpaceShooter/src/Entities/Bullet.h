#pragma once

#include "Collidable.h"

namespace ss
{
	class Bullet : public Collidable
	{
	private:
		sf::Vector2f pos;
		float rot;
		float speed;
		float cosr, sinr;

	public:
		Bullet(const sf::Vector2f& position, float rotation, float travelSpeed);
		void Start() override;
		void Update(float deltaTime) override;
	};
}