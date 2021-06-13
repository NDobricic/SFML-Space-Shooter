#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace ss
{
	class Canvas
	{
	private:
		sf::RenderTexture canvasTexture;
		sf::Sprite sprite;

		std::vector<sf::Drawable> elements;

	public:
		Canvas(int width, int height);

		void Render();

		const sf::Sprite& GetSprite();
	};
}