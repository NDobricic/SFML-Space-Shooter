#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "UIElement.h"

namespace ss
{
	class Canvas
	{
	private:
		sf::RenderTexture canvasTexture;
		sf::Sprite sprite;

	public:
		std::vector<UIElement*> elements;

		Canvas(int width, int height);

		void Render();

		const sf::Sprite& GetSprite() const;

		~Canvas()
		{
			for (auto& element : elements)
				delete element;
		}
	};
}