#include "Textbox.h"

Textbox::Textbox() {
	Setup(75, 20, 20);
}
Textbox::Textbox(int l_size, int positionX, int positionY)
{
	Setup(l_size, positionX, positionY);
}
Textbox::~Textbox(){
}

void Textbox::Setup(int l_size, float positionX, float positionY)
{
	m_Position.x = positionX;
	m_Position.y = positionY;
	m_font.loadFromFile("font/DS-DIGI.ttf");
	m_hud.setFont(m_font);
	m_hud.setCharacterSize(l_size);
	m_hud.setFillColor(sf::Color::White);
	m_hud.setPosition(m_Position);
}

void Textbox::setMessage(Bat& bat)
{
	std::stringstream m_message;
	m_message << "Score:" << bat.getScore() << "\tLives:" << bat.getLives();
	m_hud.setString(m_message.str());
}

void Textbox::Display(sf::RenderWindow& l_wind)
{
	l_wind.draw(m_hud);
	
}
