#include "Text.h"

namespace ss
{
	Text::Text(const std::string& text, int fontSize)
	{
		textObj.setString(text);
		fontObj.loadFromFile("res/fonts/arial.ttf");
		textObj.setCharacterSize(fontSize);
		textObj.setFont(fontObj);
	}

	void Text::SetTextAlignment(Alignment alignment)
	{
		if (alignment == Alignment::BottomLeft || alignment == Alignment::CenterLeft || alignment == Alignment::TopLeft)
			localXPos = 0;
		else if (alignment == Alignment::BottomRight || alignment == Alignment::CenterRight || alignment == Alignment::TopRight)
			localXPos = 1;
		else
			localXPos = 0.5;

		if (alignment == Alignment::TopLeft || alignment == Alignment::TopCenter || alignment == Alignment::TopRight)
			localYPos = 0;
		else if (alignment == Alignment::BottomLeft || alignment == Alignment::BottomCenter || alignment == Alignment::BottomRight)
			localYPos = 1;
		else
			localYPos = 0.5;
	}

	void Text::SetFontSize(int size)
	{
		textObj.setCharacterSize(size);
	}

	void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(textObj, states);
	}

	void Text::UpdateAlignment(sf::Vector2u windowSize)
	{
		int x = xPos * windowSize.x - localXPos * textObj.getLocalBounds().width + X;
		int y = yPos * windowSize.y - localYPos * textObj.getLocalBounds().height + Y;

		textObj.setPosition(x, y);
	}

	void Text::SetText(const std::string& text)
	{
		textObj.setString(text);
	}
}