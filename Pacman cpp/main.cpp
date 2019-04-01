#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include <iostream>
#include "Enemy.h"
#include "Collision.h"
#include "Wall.h"
#include"Food.h"
#include "DisplayedText.h"




static const float view_height = 1080.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(view_height *aspectRatio, view_height);
}


int main()
{
	bool GameRunning = true;
	while (GameRunning)
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
			//sf::View view(sf::Vector2f(512.0f, 512.0f), sf::Vector2f(view_height, view_height));
			
			sf::RectangleShape logo;
			logo.setSize(sf::Vector2f(500.0f, 90.0f));
			logo.setOrigin(logo.getSize().x / 2.0f, 0.0f);
			logo.setPosition(menu.getSize().x / 2.0f, 0.0f);
			sf::Texture logoTexture;
			logoTexture.loadFromFile("pacmanlogo.png");
			logo.setTexture(&logoTexture);

			DisplayedText pressToPlay(font, sf::Color(250, 210, 0), 65, sf::Vector2f((900.0f / 2.0), 150.0f), "PRESS SPACE TO PLAY", 4.0f, sf::Color(0.0, 0.0, 400.0));
			DisplayedText pressToExit(font, sf::Color(250, 210, 0), 65, sf::Vector2f((900.0f / 2.0), 370.0f), "PRESS ESC TO EXIT", 4.0f, sf::Color(0.0, 0.0, 400.0));
			DisplayedText pressToRules(font, sf::Color(250, 210, 0), 65, sf::Vector2f((900.0f / 2.0), 250.0f), "PRESS I TO READ THE RULES", 4.0f, sf::Color(0.0, 0.0, 400.0));


			while (menu.isOpen())
			{
				sf::Event evnt;
				while (menu.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						menu.close();
						GameRunning = false;
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
					GameRunning = false;
					menu.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
				{
					GameLevel = 5;
					menu.close();
				}
				menu.clear(sf::Color(140, 140, 140));
				pressToPlay.Draw(menu);
				pressToExit.Draw(menu);
				pressToRules.Draw(menu);
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

			
			Enemy *enemy = new EnemyRed (&redTexture, sf::Vector2f(600.0f, 700.0f),0.0f,0.0f);
			Enemy *enemyBlue = new EnemyBlue(&blueTexture, sf::Vector2f(650.0f, 700.0f),100.0f, 100.0f);
			Enemy *enemyYellow = new EnemyYellow(&yellowTexture, sf::Vector2f(500.0f, 200.0f) ,-100.0f, 100.0f);

			sf::Texture wallTexture;
			wallTexture.loadFromFile("PacmanWall.png");
			sf::Texture verticalWall;
			verticalWall.loadFromFile("wallVertical.png");
			
			Wall wallUp(&wallTexture, sf::Vector2f(1000.0f, 50.0f), sf::Vector2f(500.0f, 50.0f));
			Wall wallDown(&wallTexture, sf::Vector2f(1000.0f, 50.0f), sf::Vector2f(500.0f, 930.0f));
			Wall wallRight(&verticalWall, sf::Vector2f(50.0f, 900.0f), sf::Vector2f(1000.0f, 490.0f));
			Wall wallLeft(&verticalWall, sf::Vector2f(50.0f, 900.0f), sf::Vector2f(20.0f, 490.0f));
			Wall wallMiddleU(&verticalWall, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(200.0f, 300.0f));
			Wall wallMiddleD(&verticalWall, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(200.0f, 680.0f));
			Wall wallMiddle(&wallTexture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(500.0f, 500.0f));
			Wall wallMiddleR(&verticalWall, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(800.0f, 300.0f));
			Wall wallMiddleRD(&verticalWall, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(800.0f, 680.0f));

			//CREATING FOOD//
			int k = 0;
			int j = 0;
			int l = 0;
			
			Food food[300];
			for (int i = 0; i < 22; i++)
			{
				food[i].foodDefinition(sf::Vector2f((80 + i * 40), 100.0f));
				
			}
			for (int i = 22; i < 41; i++)
			{
				food[i].foodDefinition(sf::Vector2f(80.0f, (140 + j * 40)));
				j++;

			}
			for (int i = 41; i < 60; i++)
			{
				food[i].foodDefinition(sf::Vector2f(920.0f, (140 + l * 40)));
				l++;
			}
			for (int i = 60; i< 81; i++)
			{
				
				food[i].foodDefinition(sf::Vector2f((80+ k * 40),860.0f));	
				k++;
			}		
			int i = 81;
				for (int o = 0; o < 8; o++)
				{
					for (int n = 0; n < 13; n++)
					{
						food[i].foodDefinition(sf::Vector2f((260+n*40 ),(540+o*40)));
						i++;
					}
				}
				i = 185;
				for (int o = 0; o < 8; o++)
				{
					for (int n = 0; n < 13; n++)
					{
						food[i].foodDefinition(sf::Vector2f((260 + n * 40), (160 + o * 40)));
						i++;
					}
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
				//GETTING COLLIDERS//
				Collision(redCollider) = enemy->GetCollider();
				Collision(blueCollider) = enemyBlue->GetCollider();
				Collision(yellowCollider) = enemyYellow->GetCollider();
				Collision(wallUpCollider) = wallUp.GetCollider();
				Collision(wallDownCollider) = wallDown.GetCollider();
				Collision(wallLeftCollider) = wallLeft.GetCollider();
				Collision(wallRightCollider) = wallRight.GetCollider();
				Collision(wallMiddleUCollider) = wallMiddleU.GetCollider();
				Collision(wallMiddleDCollider) = wallMiddleD.GetCollider();
				Collision(wallMiddleCollider) = wallMiddle.GetCollider();
				Collision(wallMiddleRCollider) = wallMiddleR.GetCollider();
				Collision(wallMiddleRDCollider) = wallMiddleRD.GetCollider();
				
				
			

				//EATING FOOD//
				for (int x = 0; x < 300; x++)
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
					player.Respawn();
					enemyBlue->Stop();
					enemy->Stop();
					enemyYellow->Stop();
					enemyBlue->Replace();
					enemy->Replace();				
					enemyYellow->Replace();
				
					
					if (livesCount == 0)
					{
						window.close();
						GameLevel = 3;
					}
				}
				
				


				player.GetCollider().CheckCollision((wallUpCollider), 0.0f);
				player.GetCollider().CheckCollision((wallDownCollider), 0.0f);
				player.GetCollider().CheckCollision((wallLeftCollider), 0.0f);
				player.GetCollider().CheckCollision((wallRightCollider), 0.0f);
				player.GetCollider().CheckCollision((wallMiddleUCollider), 0.0f);
				player.GetCollider().CheckCollision((wallMiddleDCollider), 0.0f);
				player.GetCollider().CheckCollision((wallMiddleCollider), 0.0f);
				player.GetCollider().CheckCollision((wallMiddleRCollider), 0.0f);
				player.GetCollider().CheckCollision((wallMiddleRDCollider), 0.0f);


				DisplayedText livesRemaining(font, sf::Color(230, 230, 230), 40, sf::Vector2f(-280.0f, 140.0f), "Lives remaining:", 4.0f, sf::Color(50, 50, 50));
				DisplayedText livesCounter(font, sf::Color(230, 230, 230), 40, sf::Vector2f(-90.0f, 140.0f), std::to_string(livesCount), 4.0f, sf::Color::Red);
				DisplayedText score(font, sf::Color(230, 230, 230), 35, sf::Vector2f(-360.0f, 20.0f), "Score:", 4.0f, sf::Color(0, 0, 0));
				DisplayedText scoreCounter(font, sf::Color(230, 230, 230), 35, sf::Vector2f(-260.0f,20.0f), std::to_string(Score), 4.0f, sf::Color::Red);
				if (Score == 2000)
				{
					window.close();
					GameLevel = 2;
				}


				player.Update(deltaTime);

				if (player.GetPosition().x != enemy->GetPosition().x || player.GetPosition().y != enemy->GetPosition().y)
				{

					if (player.GetPosition().x < enemy->GetPosition().x && player.GetPosition().y > enemy->GetPosition().y)
					{
						enemy->redMove(deltaTime,-100.0f,100.0f);

					}
					else if (player.GetPosition().x < enemy->GetPosition().x && player.GetPosition().y < enemy->GetPosition().y)
					{
						enemy->redMove(deltaTime,-100.0f,-100.0f);

					}

					else if (player.GetPosition().x > enemy->GetPosition().x && player.GetPosition().y < enemy->GetPosition().y)
					{
						enemy->redMove(deltaTime,100.0f,-100.0f);

					}
					else if (player.GetPosition().x > enemy->GetPosition().x && player.GetPosition().y > enemy->GetPosition().y)
					{
						enemy->redMove(deltaTime,100.0f,100.0f);
						
					}
				}

				while (player.GetPosition().x == enemy->GetPosition().x)
				{
						enemy->redMove(deltaTime,100.0f,0.0f);			
				}
				while (player.GetPosition().y == enemy->GetPosition().y)
				{
					enemy->redMove(deltaTime,0.0f,100.0f);
				}
				enemyBlue->move(deltaTime);
				if (enemyBlue->GetCollider().CheckCollision((wallDownCollider), 0.0f) ||
					enemyBlue->GetCollider().CheckCollision((wallUpCollider), 0.0f) )

				{
					enemyBlue->HorizontalWallCollision(deltaTime);
				}
				if (enemyBlue->GetCollider().CheckCollision((wallLeftCollider), 0.0f) ||
					enemyBlue->GetCollider().CheckCollision((wallRightCollider), 0.0f) )

				{
					enemyBlue->VerticalWallCollision(deltaTime);
				}


			
				enemyYellow->move (deltaTime);
				if (enemyYellow->GetCollider().CheckCollision((wallRightCollider), 0.0f) ||
					enemyYellow->GetCollider().CheckCollision((wallLeftCollider), 0.0f)||
					enemyYellow->GetCollider().CheckCollision((wallMiddleUCollider), 0.0f)||
					enemyYellow->GetCollider().CheckCollision((wallMiddleDCollider), 0.0f)||
					enemyYellow->GetCollider().CheckCollision((wallMiddleRCollider), 0.0f)||
					enemyYellow->GetCollider().CheckCollision((wallMiddleRDCollider), 0.0f)
					)
					
				{
					enemyYellow->VerticalWallCollision(deltaTime);
				}
				if (enemyYellow->GetCollider().CheckCollision((wallDownCollider), 0.0f) ||
					enemyYellow->GetCollider().CheckCollision((wallUpCollider), 0.0f) ||
					enemyYellow->GetCollider().CheckCollision((wallMiddleCollider), 0.0f)
					)

				{
					enemyYellow->HorizontalWallCollision(deltaTime);
				}


				window.clear(sf::Color(150, 150, 150));
				window.setView(view);

				wallMiddle.Draw(window);
				wallUp.Draw(window);
				wallDown.Draw(window);
				wallRight.Draw(window);
				wallLeft.Draw(window);
				wallMiddleU.Draw(window);
				wallMiddleD.Draw(window);
				wallMiddleR.Draw(window);
				wallMiddleRD.Draw(window);
				for (int j = 0; j < 300; j++)
				{
					food[j].Draw(window);
				}
				enemy->Draw(window);
				enemyBlue->Draw(window);
				enemyYellow->Draw(window);
				livesCounter.Draw(window);
				livesRemaining.Draw(window);
				sf::String(livesCount);

				
				score.Draw(window);
				scoreCounter.Draw(window);
				
				

				player.Draw(window);
				window.display();

			}
		}
		//LEVELWON// 
		if (GameLevel == 2)
		{
			sf::RenderWindow LevelWon(sf::VideoMode(1080.0f, 800.0f), "END OF LEVEL", sf::Style::Close);
			DisplayedText Congratulations(font, sf::Color(250, 210, 0), 70, sf::Vector2f((1080.0f / 2.0f), 300.0f), "CONGRATULATIONS", 4.0f, sf::Color(0.0, 0.0, 400.0));
			DisplayedText YouWon(font, sf::Color(250, 210, 0), 70, sf::Vector2f((1080.0f / 2), 380.0f), " YOU WON!", 4.0f, sf::Color(0.0, 0.0, 400.0));
			DisplayedText pressToPlay(font, sf::Color(250, 210, 0), 50, sf::Vector2f((1080.0f / 2), 700.0f), "PRESS SPACE TO CONTINUE", 4.0f, sf::Color(0.0, 0.0, 400.0));
			

			while (LevelWon.isOpen())
			{
				sf::Event evnt;
				while (LevelWon.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						LevelWon.close();
						break;
						//case sf::Event::Resized:
						//	ResizeView(menu, view);

						//break;

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						GameLevel = 1;
						LevelWon.close();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						LevelWon.close();
						GameRunning = false;
					}
				}

				LevelWon.clear(sf::Color(150, 150, 150));
				Congratulations.Draw(LevelWon);
				YouWon.Draw(LevelWon);
				pressToPlay.Draw(LevelWon);
				LevelWon.display();

			}

		}
		if (GameLevel == 3)
		{
			sf::RenderWindow GameOver(sf::VideoMode(1080.0f, 800.0f), "END OF LEVEL", sf::Style::Close);
			DisplayedText Congratulations(font, sf::Color(250, 210, 0), 70, sf::Vector2f((1080.0f / 2.0f), 300.0f), "GAME OVER", 4.0f, sf::Color(0.0, 0.0, 400.0));
			
			DisplayedText pressToPlay(font, sf::Color(250, 210, 0), 50, sf::Vector2f((1080.0f / 2), 700.0f), "PRESS SPACE TO CONTINUE", 4.0f, sf::Color(0.0, 0.0, 400.0));


			while (GameOver.isOpen())
			{
				sf::Event evnt;
				while (GameOver.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						GameOver.close();
						break;
						//case sf::Event::Resized:
						//	ResizeView(menu, view);

						//break;

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						GameLevel = 1;
						GameOver.close();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						GameOver.close();
						GameRunning = false;
					}
				}

				GameOver.clear(sf::Color(150, 150, 150));
				Congratulations.Draw(GameOver);
				
				pressToPlay.Draw(GameOver);
				GameOver.display();

			}

		}
		//RULES//
		if (GameLevel == 5)
		{

			sf::RenderWindow Rules(sf::VideoMode(820.0f, 1000.0f), "RULES", sf::Style::Close);
			sf::RectangleShape rules;
			rules.setSize(sf::Vector2f(820.0f, 1000.0f));
			sf::Texture rulesTexture;
			rulesTexture.loadFromFile("PacmanRules.png");
			rules.setTexture(&rulesTexture);


			while (Rules.isOpen())
			{
				sf::Event evnt;
				while (Rules.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						Rules.close();
						break;
						//case sf::Event::Resized:
						//	ResizeView(menu, view);

						//break;

					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						GameLevel = 0;
						Rules.close();

					}
				}

				Rules.clear(sf::Color(150, 150, 150));
				Rules.draw(rules);
				Rules.display();

			}	
		}
	}

	return 0;
}



