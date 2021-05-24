#include "GameScene.h"
#include "Player.h"

namespace ss
{
	void GameScene::Load()
	{
		GameObjects.push_back(new Player);
	}

	void GameScene::Unload()
	{

	}
}