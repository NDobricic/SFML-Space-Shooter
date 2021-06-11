#pragma once

#include "../Utilities/AnimatedSprite.h"
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
		void OnCollision(Collidable& other) override;
		const sf::Sprite& GetSprite() override;
	};
}