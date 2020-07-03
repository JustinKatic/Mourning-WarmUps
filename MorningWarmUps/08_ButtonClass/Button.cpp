#include "Button.h"

Button::Button(std::string words, Rectangle rectangle)
{
	m_text = words;
	m_ButtonRec = rectangle;
}

Button::~Button()
{

}

void Button::DrawButton()
{
	DrawRectangle(m_ButtonRec.x, m_ButtonRec.y, m_ButtonRec.width, m_ButtonRec.height, m_buttonColourOnMouseOver);
	DrawText(m_text.c_str(), m_ButtonRec.x, m_ButtonRec.y, 50, m_buttonColourOnClick);
}

bool Button::MouseOver()
{
	if (CheckCollisionPointRec(GetMousePosition(), m_ButtonRec))
	{
		return true;
	}
	return false;
}



