#pragma once

#include "AnimatedSprite.h"
#include "GameObject.h"

namespace ss
{
	class Player : public GameObject
	{
	private:
		AnimatedSprite anim;

	public:
		Player();
		void Update(float deltaTime) override;
		const sf::Sprite& GetSprite() override;
	};
}