#pragma once

#include "Collidable.h"

namespace ss
{
	class Bullet : public Collidable
	{
	private:
		float rot;
		float speed;
		float cosr, sinr;

	public:
		Bullet(float rotation, float travelSpeed);
		void Start() override;
		void Update(float deltaTime) override;
	};
}