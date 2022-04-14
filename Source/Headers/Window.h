#pragma once
#include <string>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
class Window
{
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void BeginDraw();
	void EndDraw();

	void Update();

	bool isDone();
	bool isFullscreen();
	sf::RenderWindow* GetRenderWindow();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen();

private:
	void Setup(const std::string title, const sf::Vector2u& size);
	void Create();
	void Destroy();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
	sf::Event m_event;
};
