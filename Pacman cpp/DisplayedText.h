#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class DisplayedText
{
public:
	DisplayedText(sf::Font& font, sf::Color color, float textSize, sf::Vector2f position, std::string text, float thickness, sf::Color outlineColor );
	~DisplayedText();

	void Draw(sf::RenderWindow& window);

private:
	sf::Text textBody;
	sf::Font font;
	
};

