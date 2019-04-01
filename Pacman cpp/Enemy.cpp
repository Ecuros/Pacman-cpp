#include "Enemy.h"
#include <iostream>


Enemy::Enemy()
{
	sf::Vector2f size(60.5f, 65.0f);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	
}

void EnemyYellow::move(float deltaTime)
{
	
	sf::Vector2f movement(0.0f, 0.0f);

	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}
EnemyYellow::EnemyYellow(sf::Texture *texture, sf::Vector2f position, float x, float y)
{
	this->x = x;
	this->y = y;
	body.setTexture(texture);
	body.setPosition(position);
}


EnemyBlue::EnemyBlue(sf::Texture* Texture, sf::Vector2f position, float x, float y)
{
	this->x = x;
	this->y = y;
	body.setTexture(Texture);
	body.setPosition(position);
}
void EnemyBlue::move(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}
void EnemyRed::setTexturePosition(sf::Texture *texture,sf::Vector2f position)
{
	body.setTexture(texture);
	body.setPosition(position);
}
EnemyRed::EnemyRed(sf::Texture *texture, sf::Vector2f position, float x, float y)
{
	body.setTexture(texture);
	body.setPosition(position);
	this->x = x;
	this->y = y;
}
Enemy::~Enemy()
{


}
void EnemyRed::move(float deltaTime)
{

	sf::Vector2f movement(0.0f, 0.0f);
	
	movement.x += deltaTime*x;
	movement.y += deltaTime *y;
	body.move(movement);
}
void EnemyRed::redMove(float deltaTime, float x, float y)
{
	sf::Vector2f movement(0.0f, 0.0f);

	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}


void EnemyYellow::VerticalWallCollision(float deltaTime)
{
	
	sf::Vector2f movement(0.0f, 0.0f);
	srand(time(NULL));
	int k = 0;
	k = (rand() % 10) - 5;
	
	if (k<=0)
	{
		y = -y;
	}
	x = -x;
	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}
void EnemyBlue::VerticalWallCollision(float deltaTime)
{

	sf::Vector2f movement(0.0f, 0.0f);
	srand(time(NULL));
	int k = 0;
	k = (rand() % 10) - 5;

	if (k <= 0)
	{
		y = -y;
	}
	x = -x;
	
	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}
void EnemyYellow::HorizontalWallCollision(float deltaTime)
{
	
	sf::Vector2f movement(0.0f, 0.0f);
	srand(time(NULL));
	int k = 0;
	int j = 0;
	j = (rand() % 2) - 1;
	
	k = (rand() % 10) - 5;
	x = (rand() % 200) - 1;
	if (k <= 0)
	{
		x = -x;		
	}
	y = -y;
	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}

void EnemyBlue::HorizontalWallCollision(float deltaTime)
{
	y = 100;
	sf::Vector2f movement(0.0f, 0.0f);
	srand(time(NULL));
	int k = 0;
	int j = 0;
	j = (rand() % 2) - 1;

	k = (rand() % 10) - 5;
	x = (rand() % 200) - 1;
	if (k <= 0)
	{
		x = -x;
	}
	y = -y;
	movement.x += deltaTime * x;
	movement.y += deltaTime * y;
	body.move(movement);
}
void Enemy::Stop()
{
	sf::Vector2f movement(0.0f, 0.0f);
	body.move(movement);
}
void EnemyRed::Replace()
{
	body.setPosition(sf::Vector2f(1000.0f, 50.0f));
}
void EnemyYellow::Replace()
{
	body.setPosition(sf::Vector2f(300.0f, 300.0f));
}
void EnemyBlue::Replace()
{
	body.setPosition(sf::Vector2f(500.0f, 500.0f));
}
void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void EnemyRed::VerticalWallCollision(float deltaTime)
{
	;
}
void EnemyRed::HorizontalWallCollision(float deltaTime)
{
	;
}
void EnemyBlue::redMove(float deltaTime, float x, float y)
{
	;
}
void EnemyYellow::redMove(float deltaTime, float x, float y)
{
	;
}