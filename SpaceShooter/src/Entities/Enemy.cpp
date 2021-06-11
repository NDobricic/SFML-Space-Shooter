#pragma once

#include "Enemy.h"
#include "../GameWindow.h"
#include "../Scenes/SceneManager.h"

namespace ss
{
	Enemy::Enemy(const sf::Vector2f& position, MovePattern* pattern, Weapon* weapon)
		: originalPos(position), movePattern(pattern), weapon(weapon), anim("res/sprites/enemy_sheet.png", 32, 32, 8, 0, 32 * 4)
	{
		sprite = &anim;

		anim.SetLoopMode(ss::AnimationLoopMode::Reverse);
		anim.SetSpeed(5);
	}

	void Enemy::Start()
	{
		SetScale(sf::Vector2f(2, 2));

		SetPosition(originalPos);
	}

	void Enemy::Update(float deltaTime)
	{
		sf::Vector2f posOffset = movePattern->GetPositionOffset(deltaTime);
		SetPosition(Position() + posOffset);
		
		sf::Vector2f weaponPos = Position();
		weaponPos.y += Size().y;
		weaponPos.x += Size().x / 2;
		weapon->Update(deltaTime, weaponPos);

		if (Position().y > GameWindow::Height())
			SceneManager::CurrentScene()->DestroyObject(this);
	}

	Enemy::~Enemy()
	{
		delete weapon;
		delete movePattern;
	}
}