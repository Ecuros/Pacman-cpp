#include "Player.h"
#include <iostream>




Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	
	body.setSize(sf::Vector2f(65.0f, 65.0f));
	body.setPosition(312.0f, 500.0f);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);	

}
void Player::Death()
{
	body.setPosition(-200.0f, -200.0f);
}


Player::~Player()
{
	
}

void Player::Update(float deltaTime)
{

	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime;
		body.setRotation(180);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime;
		body.setRotation(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= speed * deltaTime;
		body.setRotation(270);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += speed * deltaTime;
		body.setRotation(90);
	}


	animation.Update(deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

	

}
void Player::Respawn()
{
	body.setPosition(312.0f, 512.0f);
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}