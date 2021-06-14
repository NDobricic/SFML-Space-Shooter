#include "GameScene.h"
#include "MainMenuScene.h"
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

		clock.restart();

		for (int i = 0; i < 1000; i++)
			SpawnParticle(new Star(i % 5));

		Text* hpText = new Text();
		hpText->SetWindowAlignment(Alignment::TopCenter);
		hpText->SetTextAlignment(Alignment::TopCenter);
		hpText->X = -250;
		UICanvas->elements.push_back(hpText);

		Text* ammoText = new Text();
		ammoText->SetWindowAlignment(Alignment::TopCenter);
		ammoText->SetTextAlignment(Alignment::TopCenter);
		ammoText->X = 0;
		UICanvas->elements.push_back(ammoText);

		Text* scoreText = new Text();
		scoreText->SetWindowAlignment(Alignment::TopCenter);
		scoreText->SetTextAlignment(Alignment::TopCenter);
		scoreText->X = 250;
		UICanvas->elements.push_back(scoreText);

		Text* gameOverText = new Text("GAME OVER", 100);
		gameOverText->SetWindowAlignment(Alignment::Center);
		gameOverText->SetTextAlignment(Alignment::Center);
		gameOverText->Y = -50;
		gameOverText->Visible = false;
		UICanvas->elements.push_back(gameOverText);

		Player* player = new Player(hpText, ammoText, scoreText, gameOverText);
		SpawnGameObject(player);

		SpawnEnemies();
	}

	void GameScene::UserUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			SceneManager::ChangeScene<MainMenuScene>();

		if (clock.getElapsedTime().asSeconds() > 20.0f)
		{
			SpawnEnemies();

			clock.restart();
		}
	}
	void GameScene::SpawnEnemies()
	{
		SpawnGameObject(new Enemy(new SinusoidalMovePattern(100, 2, 50), new SingleFire(1.0f, 180)), sf::Vector2f(200, -100));
		SpawnGameObject(new Enemy(new SinusoidalMovePattern(100, -2, 50), new SingleFire(1.0f, 180)), sf::Vector2f(1000, -100));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new TripleFire(1.0f, 180)), sf::Vector2f(600, -200));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(400, -300));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(800, -300));

		SpawnGameObject(new Enemy(new SinusoidalMovePattern(300, 4, 50), new SingleFire(0.4f, 180)), sf::Vector2f(550, -400));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new TripleFire(1.0f, 180)), sf::Vector2f(600, -500));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(400, -600));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(800, -600));

		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(200, -700));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(600, -700));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(1000, -700));

		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(200, -850));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(600, -850));
		SpawnGameObject(new Enemy(new StraightMovePattern(50), new SingleFire(2.0f, 180)), sf::Vector2f(1000, -850));
	}
}