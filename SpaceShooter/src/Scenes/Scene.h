#pragma once

#include "Scene.h"
#include <vector>
#include "../Entities/Entity.h"
#include "../Entities/Collidable.h"
#include "../UI/UI.h"
#include "../GameWindow.h"

namespace ss
{
	class Scene
	{
	private:
		std::vector<Entity*> objectsToDelete;

		bool unloading = false;

	public:
		std::vector<Entity*> Particles;
		std::vector<Collidable*> GameObjects;
		Canvas* UICanvas = new Canvas(GameWindow::Width(), GameWindow::Height());

		void Update(float deltaTime);

		void SpawnParticle(Entity* entity);
		void SpawnParticle(Entity* object, const sf::Vector2f& position);
		void SpawnGameObject(Collidable* object);
		void SpawnGameObject(Collidable* object, const sf::Vector2f& position);
		void DestroyObject(Entity* object);

		virtual ~Scene();

		virtual void Load();
		virtual void Unload();
		virtual void UserUpdate();
	};
}