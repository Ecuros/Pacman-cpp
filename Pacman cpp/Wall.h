#pragma once
#include <SFML\Graphics.hpp>
#include "Collision.h"
class Wall
{
public:
	Wall(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);


	~Wall();

	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return wall.getPosition(); }
	Collision GetCollider () { return (Collision(wall)); }


private: 

	sf::RectangleShape wall;
	

};

