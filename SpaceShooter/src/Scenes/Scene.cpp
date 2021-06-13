#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace ss
{
	void Scene::Update(float deltaTime)
	{
		for (int i = 0; i < Particles.size(); i++)
			Particles[i]->Update(deltaTime);

		for (int i = 0; i < GameObjects.size(); i++)
			GameObjects[i]->Update(deltaTime);

		for (int i = 0; i < GameObjects.size(); i++)
			for (int j = i + 1; j < GameObjects.size(); j++)
			{
				sf::FloatRect colliderA(GameObjects[i]->Position(), GameObjects[i]->Size());
				sf::FloatRect colliderB(GameObjects[j]->Position(), GameObjects[j]->Size());

				if (colliderA.intersects(colliderB))
				{
					GameObjects[i]->OnCollision(*GameObjects[j]);
					GameObjects[j]->OnCollision(*GameObjects[i]);
				}
			}
	}

	void Scene::SpawnParticle(Entity* object)
	{
		Particles.push_back(object);
		object->Start();
	}

	void Scene::SpawnParticle(Entity* object, const sf::Vector2f& position)
	{
		Particles.push_back(object);

		float w = object->Size().x;
		float h = object->Size().y;

		object->SetPosition(sf::Vector2f(position.x - w / 2, position.y - h / 2));
		object->Start();
	}

	void Scene::SpawnGameObject(Collidable* object)
	{
		GameObjects.push_back(object);
		object->Start();
	}

	void Scene::SpawnGameObject(Collidable* object, const sf::Vector2f& position)
	{
		GameObjects.push_back(object);

		float w = object->Size().x;
		float h = object->Size().y;

		object->SetPosition(sf::Vector2f(position.x - w / 2, position.y - h / 2));
		object->Start();
	}

	void Scene::DestroyObject(Entity* object)
	{
		// TODO: Delay object destruction until the end of current frame to avoid references to destroyed objects

		Particles.erase(std::remove(Particles.begin(), Particles.end(), object), Particles.end());
		GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), object), GameObjects.end());

		delete object;
	}

	void Scene::Load() { }

	void Scene::Unload()
	{
		for (auto& object : Particles)
			delete object;

		for (auto& object : GameObjects)
			delete object;

		for (auto& object : UIElements)
			delete object;
	}
}