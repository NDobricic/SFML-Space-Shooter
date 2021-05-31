#pragma once

#include "Scene.h"
#include <vector>
#include "Entity.h"
#include "Collidable.h"

namespace ss
{
	class Scene
	{
	public:
		std::vector<Entity*> Particles;
		std::vector<Collidable*> GameObjects;
		void Update(float deltaTime);
		void Start();

		void SpawnParticle(Entity* entity);
		void SpawnGameObject(Collidable* object);
		void DestroyObject(Entity* object);

		virtual void Load() = 0;
		virtual void Unload() = 0;
	};
}