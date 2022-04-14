#pragma once
#include<SFML/Graphics.hpp>

class Bat
{
private:
	sf::Vector2f m_Position;

	// A rectangle shape object
	sf::RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;
	int m_score = 0;
	int m_lives = 3;

public:
	Bat(float startX, float startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	int getScore();

	void setScore(int score);
	
	void addScore();

	int getLives();

	void setLives(int lives);

	void takeLives();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void update(sf::Time dt);

	void Render(sf::RenderWindow& l_window);
};

