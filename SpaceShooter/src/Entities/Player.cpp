#include "Player.h"
#include <algorithm>
#include "../GameWindow.h"
#include "../Scenes/SceneManager.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"

namespace ss
{
	Player::Player(Text* hpText, Text* ammoText, Text* scoreText, Text* gameOverText)
		: hpText(hpText), ammoText(ammoText), scoreText(scoreText), gameOverText(gameOverText), anim("res/sprites/player_sheet.png", 32, 32, 8)
	{
		sprite = &anim;

		anim.SetLoopMode(ss::AnimationLoopMode::Reverse);
		anim.SetSpeed(5);
	}

	void Player::Start()
	{
		clock.restart();

		SetScale(sf::Vector2f(2, 2));

		hpText->SetText("HP: " + std::to_string(hp));
		ammoText->SetText("AMMO: " + std::to_string(ammo));
		scoreText->SetText("SCORE: " + std::to_string(score));

		SetPosition(sf::Vector2f(GameWindow::Width() / 2.0f - Size().x / 2, GameWindow::Height() / 1.5f));
	}

	void Player::Update(float deltaTime)
	{
		Move(deltaTime);

		if (clock.getElapsedTime().asMilliseconds() > 1000)
		{
			ammo++;
			if (ammo > 20) ammo = 20;

			ammoText->SetText("AMMO: " + std::to_string(ammo));

			score++;
			scoreText->SetText("SCORE: " + std::to_string(score));

			clock.restart();
		}

		timeSinceLastFire += deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (timeSinceLastFire > fireDelay && ammo > 0)
			{
 				timeSinceLastFire = 0;

				sf::Vector2f bulletPos = Position();
				bulletPos.x += Size().x / 2;
				SceneManager::CurrentScene()->SpawnGameObject(new PlayerBullet(90, 500), bulletPos);

				ammo--;
				ammoText->SetText("AMMO: " + std::to_string(ammo));
			}
		}

		anim.Update(deltaTime);
	}

	void Player::OnCollision(Collidable& other)
	{
		EnemyBullet* object = dynamic_cast<EnemyBullet*> (&other);
		if (object != nullptr)
		{
			SceneManager::CurrentScene()->DestroyObject(object);
			Damage(10);
		}
	}

	void Player::Damage(int amount)
	{
		hp -= amount;
		if (hp <= 0)
		{
			hp = 0;

			sf::Vector2f shipCenter = Position();
			shipCenter.y += Size().y / 2;
			shipCenter.x += Size().x / 2;

			gameOverText->Visible = true;

			SceneManager::CurrentScene()->SpawnParticle(new Explosion, shipCenter);
			SceneManager::CurrentScene()->DestroyObject(this);
		}

		hpText->SetText("HP: " + std::to_string(hp));
	}

	void Player::Move(float deltaTime)
	{
		sf::Vector2f currentPos = Position();

		currentPos.y += fallingSpeed * deltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			currentPos.x += moveSpeed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			currentPos.x -= moveSpeed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			currentPos.y -= moveSpeed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			currentPos.y += moveSpeed * deltaTime;

		if (currentPos.x < 0)
			currentPos.x = 0;
		else if (currentPos.x > GameWindow::Width() - Size().x)
			currentPos.x = GameWindow::Width() - Size().x;

		if (currentPos.y < 0)
			currentPos.y = 0;
		else if (currentPos.y > GameWindow::Height() - Size().y)
			currentPos.y = GameWindow::Height() - Size().y;

		SetPosition(currentPos);
	}

	const sf::Sprite& Player::GetSprite()
	{
		return anim;
	}
}