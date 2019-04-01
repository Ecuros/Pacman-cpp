#include "Wall.h"




Wall::Wall(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	wall.setSize(size);
	wall.setOrigin(size / 2.0f);
	wall.setPosition(position);
	wall.setTexture(texture);
	
	
}


Wall::~Wall()
{
}


void Wall::Draw(sf::RenderWindow& window)
{
	window.draw(wall);
}