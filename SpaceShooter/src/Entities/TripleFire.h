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
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(-90, 300), shipPosition);
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(-110, 300), shipPosition);
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(-70, 300), shipPosition);
		}
	};
}