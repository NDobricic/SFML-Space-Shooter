#include "PlayerBullet.h"
#include "GameWindow.h"
#include "SceneManager.h"

#define PI 3.14159265

namespace ss
{
	PlayerBullet::PlayerBullet(const sf::Vector2f& position, float rotation, float travelSpeed)
	{
		pos = position;
		speed = travelSpeed;
		rot = rotation;

		cosr = cos(rot * 2 * PI / 360.0f);
		sinr = sin(rot * 2 * PI / 360.0f);

		sprite = new sf::Sprite();

		sf::Texture* tex = new sf::Texture;
		tex->loadFromFile("res/sprites/bullet_blue.png");
		sprite->setTexture(*tex);

		SetPosition(pos);
	}

	void PlayerBullet::Update(float deltaTime)
	{
		sf::Vector2f currentPos = Position();

		currentPos.y -= speed * deltaTime * sinr;
		currentPos.x += speed * deltaTime * cosr;

		SetPosition(currentPos);

		if (currentPos.x < 0 - Size().x || currentPos.y < 0 - Size().y
			|| currentPos.x > GameWindow::Width() || currentPos.y > GameWindow::Height())
		{
			SceneManager::CurrentScene()->DestroyObject(this);
		}
	}
}