#include "Star.h"
#include "GameWindow.h"
#include <cmath>
#include <random>

namespace ss
{
	Star::Star(int layer)
	{
		sprite = new sf::Sprite();

		sf::Texture* tex = new sf::Texture;
		tex->loadFromFile("res/sprites/star.png");
		sprite->setTexture(*tex);

		x = (rand()) % GameWindow::Width();
		y = (rand()) % GameWindow::Height();

		SetScale(sf::Vector2f(2, 2));

		moveSpeed = 100.0f / powf(1.5f, layer);
	}


	void Star::Update(float deltaTime)
	{
		y += moveSpeed * deltaTime;

		if (y > GameWindow::Height())
		{
			x = rand() % GameWindow::Width();
			y = y - GameWindow::Height();
		}

		SetPosition(sf::Vector2f(x, y));
	}
}