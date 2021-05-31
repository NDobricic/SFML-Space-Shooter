#pragma once

#include "AnimatedSprite.h"
#include "Collidable.h"

namespace ss
{
	class Player : public Collidable
	{
	private:
		AnimatedSprite anim;

		float fireDelay = 0.2f;
		float timeSinceLastFire = 0.0f;

		void Move(float deltaTime);

	public:
		float moveSpeed = 300;
		float fallingSpeed = 50;

		Player();
		void Start() override;
		void Update(float deltaTime) override;
		const sf::Sprite& GetSprite() override;
	};
}