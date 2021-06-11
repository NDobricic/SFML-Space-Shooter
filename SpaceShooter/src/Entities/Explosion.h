#pragma once

#include "Entity.h"
#include "../Utilities/AnimatedSprite.h"

namespace ss
{
	class Explosion : public Entity
	{
	private:
		AnimatedSprite anim;
		sf::Vector2f pos;

	public:
		Explosion();
		virtual void Update(float deltaTime) override;
	};
}