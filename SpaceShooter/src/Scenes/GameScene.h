#pragma once

#include "Scene.h"

namespace ss
{
	class GameScene : public Scene
	{
		sf::Clock clock;

		virtual void Load() override;
		virtual void UserUpdate() override;

		void SpawnEnemies();
	};
}