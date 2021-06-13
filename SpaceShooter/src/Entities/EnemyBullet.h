#pragma once

#include "Bullet.h"

namespace ss
{
	class EnemyBullet : public Bullet
	{
	public:
		EnemyBullet(float rotation, float travelSpeed)
			: Bullet(rotation, travelSpeed)
		{
			sprite = new sf::Sprite();

			sf::Texture* tex = new sf::Texture;
			tex->loadFromFile("res/sprites/bullet_red.png");
			sprite->setTexture(*tex);
		}
	};
}