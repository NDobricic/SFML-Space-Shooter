#pragma once

#include "Bullet.h"
#include "Enemy.h"
#include "Explosion.h"
#include "../Scenes/SceneManager.h"

namespace ss
{
	class PlayerBullet : public Bullet
	{
	public:
		PlayerBullet(const sf::Vector2f& position, float rotation, float travelSpeed)
			: Bullet(position, rotation, travelSpeed)
		{
			sprite = new sf::Sprite();

			sf::Texture* tex = new sf::Texture;
			tex->loadFromFile("res/sprites/bullet_blue.png");
			sprite->setTexture(*tex);
		}

		void OnCollision(Collidable& other) override
		{
			Enemy* object = dynamic_cast<Enemy*> (&other);
			if (object != nullptr)
			{
				SceneManager::CurrentScene()->SpawnParticle(new Explosion, object->Position());
				SceneManager::CurrentScene()->DestroyObject(object);
				SceneManager::CurrentScene()->DestroyObject(this);
			}
		}
	};
}