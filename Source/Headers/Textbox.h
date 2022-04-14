#pragma once
#include<SFML/Graphics.hpp>
#include"Bat.h"
#include<string>
#include<sstream>
#include<cstdlib>
#include<iostream>
class Textbox
{
public:
	Textbox();
	Textbox(int l_size, int positionX, int positionY);
	~Textbox();
	void Setup(int l_size, float positionX, float positionY);

	void Display(sf::RenderWindow& l_wind);
	void setMessage(Bat& bat);


private:
	sf::Vector2f m_Position;
	sf::Text m_hud;
	sf::Font m_font;
};

