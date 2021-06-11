#pragma once

#include "Weapon.h"
#include "../Scenes/SceneManager.h"
#include "EnemyBullet.h"

namespace ss
{
	struct SingleFire : public Weapon
	{
		using Weapon::Weapon;

		virtual void Fire(const sf::Vector2f& shipPosition) override
		{
			SceneManager::CurrentScene()->SpawnGameObject(new EnemyBullet(shipPosition, -90, 200));
		}
	};
}