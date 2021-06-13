#include "Text.h"

namespace ss
{
	Text::Text()
	{

	}

	Text::Text(const std::string& text)
	{

	}

	void Text::SetTextAlignment(Alignment alignment)
	{
		textAlignment = alignment;
	}

	void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		sf::Vector2u wSize = target.getSize();
		//sf::Vector2u tSize =  textObj.getLocalBounds();


	}
}