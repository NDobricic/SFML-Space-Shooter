#pragma once

#include <SFML/Graphics.hpp>
#include "Alignment.h"

namespace ss
{
	class UIElement : public sf::Drawable
	{
	protected:
		Alignment windowAlignment = Alignment::TopLeft;

		float xPos = 0, yPos = 0;

	public:
		int X = 0, Y = 0;
		bool Visible = true;


		void SetWindowAlignment(Alignment alignment);

		virtual void UpdateAlignment(sf::Vector2u windowSize) = 0;
	};
}