#include "Bullet.h"
#include "../GameWindow.h"
#include "../Scenes/SceneManager.h"

#define PI 3.14159265f

namespace ss
{
	Bullet::Bullet(const sf::Vector2f& position, float rotation, float travelSpeed)
	{
		pos = position;
		speed = travelSpeed;
		rot = rotation;

		cosr = cos(rot * 2.0f * PI / 360.0f);
		sinr = sin(rot * 2.0f * PI / 360.0f);
	}

	void Bullet::Start()
	{
		SetPosition(pos);
	}

	void Bullet::Update(float deltaTime)
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