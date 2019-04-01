#pragma once
#include <SFML\Graphics.hpp>
#include "Collision.h"
class Food
{
public:
	Food();
	
	~Food();
	

	void Draw(sf::RenderWindow& window);
	void foodDefinition(sf::Vector2f position);
	void SetPosition();

	Collision GetCollider() { return Collision(foodBody); }

	
private:
	sf::RectangleShape foodBody;
};

