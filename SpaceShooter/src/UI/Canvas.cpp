#include "Canvas.h"

namespace ss
{
	Canvas::Canvas(int width, int height)
	{
		canvasTexture.create(width, height);
		sprite.setTexture(canvasTexture.getTexture());
	}

	void Canvas::Render()
	{
		for (auto& element : elements)
		{
			canvasTexture.draw(element);
		}
	}

	const sf::Sprite& Canvas::GetSprite()
	{
		return sprite;
	}
}