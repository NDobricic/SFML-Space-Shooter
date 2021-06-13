#include "GameScene.h"
#include "../Entities/Player.h"
#include "../Entities/Star.h"
#include "../Entities/Enemies.h"
#include <random>

namespace ss
{
	void GameScene::Load()
	{
		srand(time(0));

		for (int i = 0; i < 1000; i++)
			SpawnParticle(new Star(i % 5));

		SpawnGameObject(new Player);

		SpawnGameObject(new Enemy(sf::Vector2f(200, 0), new SinusoidalMovePattern(100, 2, 50), new SingleFire(1.0f, 180)));
		SpawnGameObject(new Enemy(sf::Vector2f(1000, 0), new SinusoidalMovePattern(100, -2, 50), new SingleFire(1.0f, 180)));
		SpawnGameObject(new Enemy(sf::Vector2f(550, -100), new StraightMovePattern(50), new TripleFire(1.0f, 180)));
		SpawnGameObject(new Enemy(sf::Vector2f(400, -200), new StraightMovePattern(50), new SingleFire(2.0f, 180)));
		SpawnGameObject(new Enemy(sf::Vector2f(800, -200), new StraightMovePattern(50), new SingleFire(2.0f, 180)));
		SpawnGameObject(new Enemy(sf::Vector2f(550, -300), new SinusoidalMovePattern(300, 4, 20), new SingleFire(0.4f, 180)));
	}
}