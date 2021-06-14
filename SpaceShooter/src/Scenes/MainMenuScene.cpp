#include "MainMenuScene.h"

#include "SceneManager.h"
#include "GameScene.h"
#include "../Entities/Star.h"
#include <iostream>

namespace ss
{
	void ss::MainMenuScene::Load()
	{
		srand(time(0));

		for (int i = 0; i < 1000; i++)
			SpawnParticle(new Star(i % 5));

		Image* logo = new Image("res/sprites/title_logo.png");
		logo->SetWindowAlignment(Alignment::Center);
		logo->Y = -50;
		UICanvas->elements.push_back(logo);

		Text* startText = new Text("- Press SPACE to start -");
		startText->SetWindowAlignment(Alignment::Center);
		startText->SetTextAlignment(Alignment::Center);
		startText->Y = 150;
		UICanvas->elements.push_back(startText);
	}

	void MainMenuScene::UserUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			SceneManager::ChangeScene<GameScene>();
		}
	}
}