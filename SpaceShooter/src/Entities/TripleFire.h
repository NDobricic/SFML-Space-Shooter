#pragma once

#include "Weapon.h"
#include "../Scenes/SceneManager.h"
#include "EnemyBullet.h"

namespace ss
{
	struct TripleFire : public Weapon
	{
		using Weapon::Weapon;

		virtual void Fire(const sf::Vector2f& shipPosition) override
		{
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(shipPosition, -90, 300));
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(shipPosition, -110, 300));
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(shipPosition, -70, 300));
		}
	};
}