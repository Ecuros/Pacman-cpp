#include "Food.h"



Food::Food()
{

	
}
void Food::SetPosition()
{
	foodBody.setPosition(-100.0f, -100.0f);
}
void Food::foodDefinition(sf::Vector2f position)
{
	sf::Vector2f size(10.0f, 10.0f);
	foodBody.setSize(size);
	foodBody.setPosition(position);

}
Food::~Food()
{
}


void Food::Draw(sf::RenderWindow&window)
{
	window.draw(foodBody);
}
