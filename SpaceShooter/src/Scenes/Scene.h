#pragma once

#include "Scene.h"
#include <vector>
#include "../Entities/Entity.h"
#include "../Entities/Collidable.h"

namespace ss
{
	class Scene
	{
	public:
		std::vector<Entity*> Particles;
		std::vector<Collidable*> GameObjects;
		void Update(float deltaTime);

		void SpawnParticle(Entity* entity);
		void SpawnParticle(Entity* object, const sf::Vector2f& position);
		void SpawnGameObject(Collidable* object);
		void SpawnGameObject(Collidable* object, const sf::Vector2f& position);
		void DestroyObject(Entity* object);

		virtual void Load() = 0;
		virtual void Unload() = 0;
	};
}