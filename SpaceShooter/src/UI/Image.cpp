#include "Image.h"

namespace ss
{
	Image::Image(const std::string& filePath)
	{
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);
	}

	void ss::Image::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(sprite);
	}

	void Image::UpdateAlignment(sf::Vector2u windowSize)
	{
		int x = xPos * windowSize.x - sprite.getLocalBounds().width / 2 + X;
		int y = yPos * windowSize.y - sprite.getLocalBounds().height / 2 + Y;

		sprite.setPosition(x, y);
	}
}