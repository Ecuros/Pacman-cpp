#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include <iostream>
#include "Enemy.h"
#include "Collision.h"
#include "Wall.h"
#include"Food.h"
#include "DisplayedText.h"
#include "FirstLevel.h"



static const float view_height = 1080.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(view_height *aspectRatio, view_height);
}


FirstLevel::FirstLevel()
{
	int Score = 0;
	int livesCount = 3;
	int GameLevel = 0;
	sf::Font font;
	font.loadFromFile("Ubuntu-B.ttf");
	//STARTING MENU//
	if (GameLevel == 0)
	{
		sf::RenderWindow menu(sf::VideoMode(900.0f, 500.0f), "MENU", sf::Style::Close);
		sf::View view(sf::Vector2f(512.0f, 512.0f), sf::Vector2f(view_height, view_height));

		sf::RectangleShape logo;
		logo.setSize(sf::Vector2f(500.0f, 90.0f));
		logo.setOrigin(logo.getSize().x / 2.0f, 0.0f);
		logo.setPosition(menu.getSize().x / 2.0f, 0.0f);
		sf::Texture logoTexture;
		logoTexture.loadFromFile("pacmanlogo.png");
		logo.setTexture(&logoTexture);

		DisplayedText pressToPlay(font, sf::Color(250, 210, 0), 70, sf::Vector2f((900.0f / 2.0), 150.0f), "PRESS SPACE TO PLAY", 4.0f, sf::Color(0.0, 0.0, 400.0));
		DisplayedText pressToExit(font, sf::Color(250, 210, 0), 70, sf::Vector2f((900.0f / 2.0), 300.0f), "PRESS ESC TO EXIT", 4.0f, sf::Color(0.0, 0.0, 400.0));




		while (menu.isOpen())
		{
			sf::Event evnt;
			while (menu.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					menu.close();
					break;
					//case sf::Event::Resized:
					//	ResizeView(menu, view);

					//break;

				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				GameLevel = 1;
				menu.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				menu.close();
			}
			menu.clear(sf::Color(140, 140, 140));
			pressToPlay.Draw(menu);
			pressToExit.Draw(menu);
			menu.draw(logo);

			menu.display();

		}

	}

	//GAME//
	if (GameLevel == 1)
	{
		sf::RenderWindow window(sf::VideoMode(1920.0f, 1080.0f), "PACMAN", sf::Style::Close | sf::Style::Resize);
		sf::View view(sf::Vector2f(512.0f, 512.0f), sf::Vector2f(1920.0f, view_height));

		sf::Texture playerTexture;
		playerTexture.loadFromFile("pacman.png");

		Player player(&playerTexture, sf::Vector2u(5, 1), 0.13f, 200.0f);

		sf::Texture redTexture;
		redTexture.loadFromFile("PacmanGhostRed.png");
		sf::Texture blueTexture;
		blueTexture.loadFromFile("PacmanGhostBlue.png");
		sf::Texture yellowTexture;
		yellowTexture.loadFromFile("PacmanGhostYellow.png");

		Enemy enemyRed(&redTexture, sf::Vector2f(60.0f, 65.0f), sf::Vector2f(300.0f, 500.0f), 0.0f, 0.0f);
		Enemy enemyBlue(&blueTexture, sf::Vector2f(60.0f, 65.0f), sf::Vector2f(400.0f, 500.0f), 0.0f, 0.0f);
		Enemy enemyYellow(&yellowTexture, sf::Vector2f(60.0f, 65.0f), sf::Vector2f(600.0f, 500.0f), 100.0f, 100.0f);

		sf::Texture wallTexture;
		wallTexture.loadFromFile("PacmanWall.png");
		sf::Texture verticalWall;
		verticalWall.loadFromFile("wallVertical.png");

		Wall wallUp(&wallTexture, sf::Vector2f(1000.0f, 50.0f), sf::Vector2f(500.0f, 100.0f));
		Wall wallDown(&wallTexture, sf::Vector2f(900.0f, 50.0f), sf::Vector2f(500.0f, 800.0f));
		Wall wallRight(&verticalWall, sf::Vector2f(50.0f, 900.0f), sf::Vector2f(80.0f, 500.0f));
		Wall wallLeft(&verticalWall, sf::Vector2f(50.0f, 900.0f), sf::Vector2f(1000.0f, 500.0f));




		Food food[20];
		for (int i = 0; i < 20; i++)
		{
			food[i].foodDefinition(sf::Vector2f((200 + i * 40), 300.0f));
		}



		float deltaTime = 0.0f;
		sf::Clock clock;

		while (window.isOpen())
		{

			deltaTime = clock.restart().asSeconds();

			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					ResizeView(window, view);

					break;
				}
			}

			Collision(redCollider) = enemyRed.GetCollider();
			Collision(blueCollider) = enemyBlue.GetCollider();
			Collision(yellowCollider) = enemyYellow.GetCollider();
			Collision(wallUpCollider) = wallUp.GetCollider();
			Collision(wallDownCollider) = wallDown.GetCollider();
			Collision(wallLeftCollider) = wallLeft.GetCollider();
			Collision(wallRightCollider) = wallRight.GetCollider();

			//RED GHOST CHASING PLAYER//
			if (player.GetPosition().x < enemyRed.GetPosition().x && player.GetPosition().y > enemyRed.GetPosition().y)
			{
				enemyRed.ChasePacman(deltaTime, -100.0f, 100.0f);
				std::cout << "Pacman is on the left on the bottom" << std::endl;

			}
			else if (player.GetPosition().x < enemyRed.GetPosition().x && player.GetPosition().y < enemyRed.GetPosition().y)
			{
				enemyRed.ChasePacman(deltaTime, -100.0f, -100.0f);
				std::cout << "Pacman is on the left on top" << std::endl;

			}

			else if (player.GetPosition().x > enemyRed.GetPosition().x && player.GetPosition().y < enemyRed.GetPosition().y)
			{
				enemyRed.ChasePacman(deltaTime, 100.0f, -100.0f);
				std::cout << "Pacman is on the right on top" << std::endl;

			}
			else if (player.GetPosition().x > enemyRed.GetPosition().x && player.GetPosition().y > enemyRed.GetPosition().y)
			{
				enemyRed.ChasePacman(deltaTime, 100.0f, 100.0f);
				std::cout << "Pacman is on the right on the bottom" << std::endl;

			}

			//EATING FOOD//
			for (int x = 0; x < 25; x++)
			{

				Collision(foodCollider) = food[x].GetCollider();
				if (player.GetCollider().CheckCollision((foodCollider), 0.0f))
				{
					Score += 10;
					std::cout << "Collision with food " << Score << std::endl;
					food[x].SetPosition();
				}
			}

			bool EnemyCollision;
			if (player.GetCollider().CheckCollision((redCollider), 0.0f) ||
				player.GetCollider().CheckCollision((blueCollider), 0.0f) ||
				player.GetCollider().CheckCollision((yellowCollider), 0.0f))
			{
				std::cout << "collision with enemy" << std::endl;
				player.Death();
				livesCount--;
				std::cout << "Remaining lives:  " << livesCount << std::endl;
				EnemyCollision = true;
				//if (livesCount == 2) window.close();
			}



			player.GetCollider().CheckCollision((wallUpCollider), 0.0f);
			player.GetCollider().CheckCollision((wallDownCollider), 0.0f);
			player.GetCollider().CheckCollision((wallLeftCollider), 0.0f);



			DisplayedText livesRemaining(font, sf::Color(230, 230, 230), 70, sf::Vector2f(200.0f, 200.0f), "Lives remaining:", 4.0f, sf::Color(50, 50, 50));
			DisplayedText livesCounter(font, sf::Color(230, 230, 230), 70, sf::Vector2f(450.0f, 270.0f), std::to_string(livesCount), 4.0f, sf::Color::Red);
			DisplayedText score(font, sf::Color(230, 230, 230), 35, sf::Vector2f(20.0f, 20.0f), "Score:", 4.0f, sf::Color(0, 0, 0));
			DisplayedText scoreCounter(font, sf::Color(230, 230, 230), 35, sf::Vector2f(130.0f, 20.0f), std::to_string(Score), 4.0f, sf::Color::Red);
			if (Score == 100)
			{
				window.close();
				GameLevel = 2;
			}


			player.Update(deltaTime);


			//	enemyBlue.Update(deltaTime);
			enemyYellow.Move(deltaTime);
			if (enemyYellow.GetCollider().CheckCollision((wallDownCollider), 0.0f) ||
				enemyYellow.GetCollider().CheckCollision((wallUpCollider), 0.0f) ||
				enemyYellow.GetCollider().CheckCollision((wallRightCollider), 0.0f) ||
				enemyYellow.GetCollider().CheckCollision((wallLeftCollider), 0.0f))
			{
				enemyYellow.ChangeDirection(deltaTime);
			}
			window.clear(sf::Color(150, 150, 150));
			window.setView(view);


			wallUp.Draw(window);
			wallDown.Draw(window);
			wallRight.Draw(window);
			wallLeft.Draw(window);

			enemyRed.Draw(window);
			enemyBlue.Draw(window);
			enemyYellow.Draw(window);
			if (EnemyCollision == true)
			{
				livesCounter.Draw(window);
				livesRemaining.Draw(window);
				sf::String(livesCount);

			}
			score.Draw(window);
			scoreCounter.Draw(window);
			for (int j = 0; j < 20; j++)
			{
				food[j].Draw(window);
			}
			player.Draw(window);
			window.display();

		}
	}







