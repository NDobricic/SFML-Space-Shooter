#pragma once

#include "Entity.h"

namespace ss
{
	class Star : public Entity
	{
	private:
		float x, y;

		float moveSpeed;

	public:
		Star(int layer);

		void Update(float deltaTime) override;
	};
}