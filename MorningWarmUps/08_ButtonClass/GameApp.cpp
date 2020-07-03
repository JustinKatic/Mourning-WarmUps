#include "GameApp.h"
#include "raylib.h"
#include <iostream>
#include "Button.h"

Button* button = new Button("Click Me", { 20, 50, 230, 50 });

GameApp::GameApp()
{

}
GameApp::~GameApp()
{

}

//happens before anything else once project opens up
void GameApp::Startup()
{
	//screen size
	m_screenWidth = 500;
	m_screenHeight = 500;
	//creates raylib screen
	InitWindow(m_screenWidth, m_screenHeight, "Button");
	//sets fps to lock at 60
	SetTargetFPS(60);
}

//happens right before project finishs use for clean up
void GameApp::Shutdown()
{
	CloseWindow();
}

//Game loop
void GameApp::Run()
{
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		//functionality every frame
		Update();
		//drawing every frame
		Draw();
	}
}

//use to update functionality every frame
void GameApp::Update()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && button->MouseOver() == true)
	{
		button->m_buttonColourOnClick = Color(GREEN);
	}

	if (button->MouseOver() == true)
	{
		button->m_buttonColourOnMouseOver = Color(PURPLE);		
	}
	else
	{
		button->m_buttonColourOnMouseOver = Color(WHITE);
	}
}
//use to draw to screen every frame
void GameApp::Draw()
{
	BeginDrawing();

	button->DrawButton();

	ClearBackground(BLACK);

	EndDrawing();
}

