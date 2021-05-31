#include "Player.h"
#include <algorithm>
#include "GameWindow.h"
#include "SceneManager.h"
#include "PlayerBullet.h"

namespace ss
{
	Player::Player()
		: anim("res/sprites/player_sheet.png", 32, 32, 8)
	{
		sprite = &anim;

		anim.SetLoopMode(ss::AnimationLoopMode::Reverse);
		anim.SetSpeed(5);
	}

	void Player::Start()
	{
		SetScale(sf::Vector2f(2, 2));
	}

	void Player::Update(float deltaTime)
	{
		Move(deltaTime);

		timeSinceLastFire += deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (timeSinceLastFire > fireDelay)
			{
				timeSinceLastFire = 0;

				sf::Vector2f bulletPos = Position();
				bulletPos.x += Size().x / 2;
				SceneManager::CurrentScene()->GameObjects.push_back(new PlayerBullet(bulletPos, 90, 500));
			}
		}

		anim.Update(deltaTime);
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