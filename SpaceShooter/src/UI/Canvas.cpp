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
		canvasTexture.clear(sf::Color::Transparent);

		for (auto& element : elements)
		{
			element->UpdateAlignment(canvasTexture.getSize());

			if(element->Visible)
				canvasTexture.draw(*element);

			canvasTexture.display();
		}
	}

	const sf::Sprite& Canvas::GetSprite() const
	{
		return sprite;
	}
}