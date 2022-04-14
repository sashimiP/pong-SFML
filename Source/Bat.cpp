#include "Bat.h"

// This is the constructor and it is called when we create an object

Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(200, 5));
	m_Shape.setPosition(m_Position);
}
sf::FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}
sf::RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_MovingLeft = true;
}

void Bat::moveRight()
{
	m_MovingRight = true;
}

void Bat::stopLeft()
{
	m_MovingLeft = false;
}

void Bat::stopRight()
{
	m_MovingRight = false;
}

void Bat::update(sf::Time dt)
{
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}
	if (m_Position.x <= -200)
	{
		m_Position.x = 1930;
	}
	if (m_Position.x >= 1950)
	{
		m_Position.x = -10;
	}
	m_Shape.setPosition(m_Position);
}

int Bat::getScore(){return m_score;}

void Bat::setScore(int score) { m_score = score; }

int Bat::getLives() { return m_lives; }

void Bat::setLives(int lives) { m_lives = lives; }

void Bat::addScore()
{
	m_score++;
}

void Bat::takeLives()
{
	m_lives--;
}

void Bat::Render(sf::RenderWindow& l_window)
{
	l_window.draw(m_Shape);
}

void Bat::hasScored(bool hasScored)
{
	m_scored = hasScored;
}
//return true/false depending on whether you got a score point
bool Bat::getScored() {
	return m_scored;
}
