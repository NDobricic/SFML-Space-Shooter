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
		void SetWindowAlignment(Alignment alignment);
	};
}