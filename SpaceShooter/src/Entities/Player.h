#pragma once

#include "../Utilities/AnimatedSprite.h"
#include "Collidable.h"
#include "../UI/UI.h"

namespace ss
{
	class Player : public Collidable
	{
	private:
		AnimatedSprite anim;

		float fireDelay = 0.2f;
		float timeSinceLastFire = 0.0f;

		sf::Clock clock;
		int hp = 100;
		int ammo = 20;
		int score = 0;

		void Move(float deltaTime);

		Text* hpText;
		Text* ammoText;
		Text* scoreText;
		Text* gameOverText;

	public:
		float moveSpeed = 300;
		float fallingSpeed = 50;

		Player(Text* hpText, Text* ammoText, Text* scoreText, Text* gameOverText);
		void Start() override;
		void Update(float deltaTime) override;
		void OnCollision(Collidable& other) override;
		void Damage(int amount);
		const sf::Sprite& GetSprite() override;
	};
}