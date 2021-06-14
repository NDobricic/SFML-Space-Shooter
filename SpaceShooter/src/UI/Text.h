#pragma once

#include <SFML/Graphics.hpp>
#include "Alignment.h"
#include "UIElement.h"

namespace ss
{
	class Text : public UIElement
	{
	private:
		sf::Text textObj;
		sf::Font fontObj;

		Alignment textAlignment = Alignment::TopLeft;

		float localXPos = 0, localYPos = 0;

	public:
		Text::Text(const std::string& text = "", int fontSize = 30);

		void SetTextAlignment(Alignment alignment);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual void UpdateAlignment(sf::Vector2u windowSize) override;

		void SetText(const std::string& text);
	};
}