#include "GameScene.h"
#include "Player.h"
#include "Star.h"
#include <random>

namespace ss
{
	void GameScene::Load()
	{
		srand(time(0));

		for (int i = 0; i < 1000; i++)
			Particles.push_back(new Star(i % 5));

		GameObjects.push_back(new Player);
	}

	void GameScene::Unload()
	{
		for (auto it : Particles)
			delete it;
	}
}