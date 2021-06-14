#pragma once

#include <SFML/Graphics.hpp>
#include "Alignment.h"
#include "UIElement.h"

namespace ss
{
	class Image : public UIElement
	{
	private:
		sf::Sprite sprite;
		sf::Texture texture;

	public:
		Image::Image(const std::string& filePath);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual void UpdateAlignment(sf::Vector2u windowSize) override;
	};
}