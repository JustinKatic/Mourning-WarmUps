#pragma once
#include "raylib.h"
#include <iostream>
class Button
{
public:
	Button(std::string, Rectangle rectangle);
	~Button();


	void DrawButton();
	bool MouseOver();

	Color m_buttonColourOnClick = Color(RED);
	Color m_buttonColourOnMouseOver = Color(WHITE);


private:
	Rectangle m_ButtonRec;
	std::string m_text;


	

};

