#include "GameScene.h"
#include "../Entities/Player.h"
#include "../Entities/Star.h"
#include "../Entities/Enemies.h"
#include <random>
#include "../UI/UI.h"

namespace ss
{
	void GameScene::Load()
	{
		srand(time(0));

		for (int i = 0; i < 1000; i++)
			SpawnParticle(new Star(i % 5));

		Text* hpText = new Text();
		hpText->SetWindowAlignment(Alignment::TopCenter);
		hpText->SetTextAlignment(Alignment::TopCenter);
		UICanvas->elements.push_back(hpText);

		Player* player = new Player;
		player->hpText = hpText;
		SpawnGameObject(player);



		SpawnGameObject(new Enemy(new SinusoidalMovePattern(100, 2, 50), new SingleFire(1.0f, 180)), sf::Vector2f(200, 0));
		SpawnGameObject(new Enemy(new SinusoidalMovePattern(100, -2, 50), new SingleFire(1.0f, 180)), sf::Vector2f(1000, 0));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new TripleFire(1.0f, 180)), sf::Vector2f(550, -100));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(400, -200));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(800, -200));
		SpawnGameObject(new Enemy(new SinusoidalMovePattern(300, 4, 20), new SingleFire(0.4f, 180)), sf::Vector2f(550, -200));
	}
}