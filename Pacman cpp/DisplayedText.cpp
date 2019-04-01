#include "DisplayedText.h"



DisplayedText::DisplayedText(sf::Font& font, sf::Color color, float textSize, sf::Vector2f position, std::string tekst, float thickness, sf::Color outlineColor)
{
	
	textBody.setFont(font);
	textBody.setCharacterSize(textSize);
	textBody.setPosition(position);
	textBody.setFillColor(color);
	textBody.setString(tekst);
	textBody.setOutlineThickness(thickness);
	textBody.setOrigin(textBody.getGlobalBounds().width / 2.0, textBody.getGlobalBounds().height / 2.0);
	textBody.setOutlineColor(outlineColor);

}
void DisplayedText::Draw(sf::RenderWindow& window)
{
	window.draw(textBody);
}


DisplayedText::~DisplayedText()
{
}
