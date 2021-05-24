#pragma once

#include "Scene.h"
#include <vector>
#include "GameObject.h"

namespace ss
{
	class Scene
	{
	public:
		std::vector<GameObject*> GameObjects;
		void Update(float deltaTime);
		virtual void Load() = 0;
		virtual void Unload() = 0;
	};
}