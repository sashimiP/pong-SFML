#pragma once
#include "Window.h"
#include "Bat.h"
#include "Ball.h"
#include "Textbox.h"
class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	void RestartClock();

	Window* GetWindow();
private:
	Window m_window;
	sf::Clock m_clock;
	Bat m_bat;
	Ball m_ball;
	Textbox m_textbox;
	sf::Time dt;
};

