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
		PlayerBullet(float rotation, float travelSpeed)
			: Bullet(rotation, travelSpeed)
		{
			sprite = new sf::Sprite();

			sf::Texture* tex = new sf::Texture;
			tex->loadFromFile("res/sprites/bullet_blue.png");
			sprite->setTexture(*tex);
		}
	};
}