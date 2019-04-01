#pragma once
#include <SFML\Graphics.hpp>
#include"Collision.h"
#include <ctime>
#include <cstdlib>
class Enemy
{
public:
	Enemy();

	
	void Draw(sf::RenderWindow& window);
	virtual void VerticalWallCollision(float deltaTime) = 0;
	virtual void HorizontalWallCollision(float deltaTime) = 0;;

	void Stop();
	virtual void move(float deltaTime) = 0;
	virtual void redMove(float deltaTime, float x, float y) = 0;
	
	
	
	virtual void Replace()=0;
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollider() { return Collision(body); }

	
	
	
	~Enemy();
	
	sf::RectangleShape body;
	
private:
	
	float speed;
	
	sf::Vector2f position;
	
};
class EnemyRed :public Enemy {
public:
	EnemyRed(sf::Texture *texture, sf::Vector2f position, float x, float y);
	void VerticalWallCollision(float deltaTime);
	void HorizontalWallCollision(float deltaTime);
	void move(float deltaTime);
	void setTexturePosition(sf::Texture* Texture, sf::Vector2f position);
	void Replace();
	void redMove(float deltaTime, float x, float y);
	float x; float y;
	
	
};
class EnemyYellow :public Enemy {
public:
	EnemyYellow(sf::Texture *texture, sf::Vector2f position, float x, float y);
	void move(float deltaTime);
	void Replace();
	void VerticalWallCollision(float deltaTime);
	void HorizontalWallCollision(float deltaTime);
	void redMove(float deltaTime, float x, float y) ;
	float x; float y;
};

class EnemyBlue :public Enemy {
public:
	EnemyBlue(sf::Texture* Texture, sf::Vector2f position,float x, float y);
	void move(float deltaTime);
	
	void VerticalWallCollision(float deltaTime);
	void HorizontalWallCollision(float deltaTime);
	void Replace();
	void redMove(float deltaTime, float x, float y);
	float x, y;
};

