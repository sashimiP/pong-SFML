#pragma once
#include<SFML/Graphics.hpp>
#include "Bat.h"
class Ball
{
private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundTop(Bat& bat);

	void reboundBat();

	void reboundBottom();

	void update(sf::Time dt);

	float getSpeed();
	void setSpeed();
	void restartSpeed(float newSpeed);
	void Render(sf::RenderWindow& l_window);
};

