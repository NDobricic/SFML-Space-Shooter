#include "UIElement.h"

namespace ss
{
	void UIElement::SetWindowAlignment(Alignment alignment)
	{
		if (alignment == Alignment::BottomLeft || alignment == Alignment::CenterLeft || alignment == Alignment::TopLeft)
			xPos = 0;
		else if (alignment == Alignment::BottomRight || alignment == Alignment::CenterRight || alignment == Alignment::TopRight)
			xPos = 1;
		else
			xPos = 0.5;

		if (alignment == Alignment::TopLeft || alignment == Alignment::TopCenter || alignment == Alignment::TopRight)
			yPos = 0;
		else if (alignment == Alignment::BottomLeft || alignment == Alignment::BottomCenter || alignment == Alignment::BottomRight)
			yPos = 1;
		else
			yPos = 0.5;
	}
}