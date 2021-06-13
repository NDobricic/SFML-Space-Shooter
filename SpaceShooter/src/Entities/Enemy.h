#pragma once

#include "Collidable.h"
#include "MovePattern.h"
#include "Weapon.h"

#include "../Utilities/AnimatedSprite.h"

namespace ss
{
	class Enemy : public Collidable
	{
	private:
		sf::Vector2f originalPos;
		MovePattern* movePattern;
		Weapon* weapon;

		AnimatedSprite anim;

	public:
		Enemy(const sf::Vector2f& position, MovePattern* pattern, Weapon* weapon);
		virtual void Start() override;
		virtual void Update(float deltaTime) override;
		void OnCollision(Collidable& other) override;
		~Enemy();
	};
}