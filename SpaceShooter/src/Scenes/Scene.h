#pragma once

#include "Scene.h"
#include <vector>
#include "../Entities/Entity.h"
#include "../Entities/Collidable.h"
#include "../UI/UI.h"

namespace ss
{
	class Scene
	{
	public:
		std::vector<Entity*> Particles;
		std::vector<Collidable*> GameObjects;
		std::vector<UIElement*> UIElements;
		void Update(float deltaTime);

		void SpawnParticle(Entity* entity);
		void SpawnParticle(Entity* object, const sf::Vector2f& position);
		void SpawnGameObject(Collidable* object);
		void SpawnGameObject(Collidable* object, const sf::Vector2f& position);
		void DestroyObject(Entity* object);

		virtual void Load();
		virtual void Unload();
	};
}