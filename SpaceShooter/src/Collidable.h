#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace ss
{
	class Collidable : public Entity
	{
	public:
		virtual void OnCollision(const Collidable& other) { }
	};
}