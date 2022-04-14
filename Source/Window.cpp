#include "Window.h"

Window::Window() { Setup("Pong", sf::Vector2u(1920, 1080)); }
Window::Window(const std::string& title, const sf::Vector2u& size) { Setup(title, size); }
Window::~Window() { Destroy(); }

void Window::Setup(const std::string title, const sf::Vector2u& size) {
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void Window::Create() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen
		: sf::Style::Default);
	m_window.create({ m_windowSize.x,m_windowSize.y, 32 },
		m_windowTitle, style);
}

void Window::Destroy() {
	m_window.close();
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::EndDraw() { m_window.display(); }

bool Window::isDone() { return m_isDone; }
bool Window::isFullscreen() { return m_isFullscreen; }

sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void Window::Update() {
	if (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed) { 
			m_isDone = true; 
		}
		else if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::Escape)
		{
			m_isDone = true;
		}
		else if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}