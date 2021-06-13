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

		Alignment textAlignment = Alignment::TopLeft;
		std::string value = "text";

	public:
		Text();
		Text(const std::string& text);

		void SetTextAlignment(Alignment alignment);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}