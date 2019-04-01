#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Enemy.h"
#include "Collision.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Death();
	void Respawn();
	//void CheckCollision(sf::RectangleShape& enemyRed);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollider() { return Collision(body); }


private:
	sf::RectangleShape body;
	Animation animation;
	float speed;
	
	
	


};

