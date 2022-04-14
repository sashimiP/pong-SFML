#include "Game.h"
Game::Game() : m_window("Pong", sf::Vector2u(1920, 1080)),
	m_bat(1920 / 2, 1080 - 20),m_ball(1920 / 2, 0), m_textbox(72,20,20)
{
	m_textbox.setMessage(m_bat);
}
Game::~Game() {}


Window* Game::GetWindow() { return &m_window; }
void Game::RestartClock() { 
	dt= m_clock.restart();
	
}
void Game::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_bat.moveLeft();
	}
	else
	{
		m_bat.stopLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_bat.moveRight();
	}
	else
	{
		m_bat.stopRight();
	}

}
void Game::Update() {
	m_window.Update();
	

	if (m_ball.getPosition().top > m_window.GetWindowSize().y)
	{
		//reverse the ball direction
		m_ball.reboundBottom();

		//Remove a life
		m_bat.takeLives();
		m_textbox.setMessage(m_bat);
		//Check for zero lives
		if (m_bat.getLives() < 1) {
			//reset the score
			m_bat.setScore(0);
			//reset the lives
			m_bat.setLives(3);
			m_ball.restartSpeed(1000.0f);
			m_textbox.setMessage(m_bat);
		}
	}
	//Handle ball hitting top
	if (m_ball.getPosition().top < 0)
	{
		m_ball.reboundTop(m_bat);
		//Add a point to the players score
		m_textbox.setMessage(m_bat);
	}
	//Handle ball hitting sides
	if (m_ball.getPosition().left < 0 ||
		m_ball.getPosition().left + m_ball.getPosition().width>m_window.GetWindowSize().x)
	{
		m_ball.reboundSides();
	}
	//has the ball hit the bat?
	if (m_ball.getPosition().intersects(m_bat.getPosition()))
	{
		//Hit detected so reverse the ball and score a point
		m_ball.reboundBat();
		m_ball.setSpeed();
		if (!m_bat.getScored())
		{
			m_bat.addScore();
			m_bat.hasScored(true);
		}
		std::cout << "Ball speed: " << m_ball.getSpeed() << std::endl;
		m_textbox.setMessage(m_bat);

	}
	
	m_bat.update(dt);
	m_ball.update(dt);
	
}

void Game::Render()
{
	m_window.BeginDraw();
	m_bat.Render(*m_window.GetRenderWindow());
	m_ball.Render(*m_window.GetRenderWindow());
	m_textbox.Display(*m_window.GetRenderWindow());

	m_window.EndDraw();
}