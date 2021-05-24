#include "Scene.h"

namespace ss
{
	void Scene::Update(float deltaTime)
	{
		for (int i = 0; i < GameObjects.size(); i++)
			GameObjects[i]->Update(deltaTime);
	}
}