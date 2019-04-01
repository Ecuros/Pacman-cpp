/*#include "Game.h"


int Score = 0;
int livesCount = 3;
static const float view_height = 1024.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(view_height *aspectRatio, view_height);
}

Game::Game()
{
	
		sf::RenderWindow window(sf::VideoMode(1024, 818), "PACMAN", sf::Style::Close | sf::Style::Resize);
		sf::View view(sf::Vector2f(512.0f, 512.0f), sf::Vector2f(view_height, view_height));

		sf::Texture playerTexture;
		playerTexture.loadFromFile("pacman.png");

		Player player(&playerTexture, sf::Vector2u(5, 1), 0.13f, 200.0f);

		sf::Texture redTexture;
		redTexture.loadFromFile("PacmanGhostRed.png");
		sf::Texture blueTexture;
		blueTexture.loadFromFile("PacmanGhostBlue.png");
		sf::Texture yellowTexture;
		yellowTexture.loadFromFile("PacmanGhostYellow.png");

		Enemy enemyRed(&redTexture, sf::Vector2f(65.0f, 65.0f), sf::Vector2f(300.0f, 500.0f));
		Enemy enemyBlue(&blueTexture, sf::Vector2f(65.0f, 65.0f), sf::Vector2f(400.0f, 500.0f));
		Enemy enemyYellow(&yellowTexture, sf::Vector2f(65.0f, 65.0f), sf::Vector2f(600.0f, 500.0f));

		sf::Texture wallTexture;
		wallTexture.loadFromFile("PacmanWall.png");

		Wall wall(&wallTexture, sf::Vector2f(880.0f, 300.0f), sf::Vector2f(80.0f, 50.0f));


		Food food[20];
		for (int i = 0; i < 20; i++)
		{
			food[i].foodDefinition(sf::Vector2f((200 + i * 40), 200.0f));

		}

		//sf::Texture wallTexture;
		//wallTexture.loadFromFile();

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

			player.Update(deltaTime);



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

			}
			sf::Font font;
			font.loadFromFile("Ubuntu-B.ttf");

			DisplayedText livesRemaining(font, sf::Color(230, 230, 230), 70, sf::Vector2f(200.0f, 200.0f), "Lives remaining:", 4.0f, sf::Color(50, 50, 50));
			DisplayedText livesCounter(font, sf::Color(230, 230, 230), 70, sf::Vector2f(450.0f, 270.0f), std::to_string(livesCount), 4.0f, sf::Color::Red);
			DisplayedText score(font, sf::Color(230, 230, 230), 35, sf::Vector2f(20.0f, 20.0f), "Score:", 4.0f, sf::Color(0, 0, 0));
			DisplayedText scoreCounter(font, sf::Color(230, 230, 230), 35, sf::Vector2f(130.0f, 20.0f), std::to_string(Score), 4.0f, sf::Color::Red);




			window.clear(sf::Color(30, 30, 120));
			window.setView(view);


			wall.Draw(window);

			enemyRed.Draw(window);
			enemyBlue.Draw(window);
			enemyYellow.Draw(window);
			if (EnemyCollision == true)
			{
				livesCounter.Draw(window);
				livesRemaining.Draw(window);
				sf::String(livesCount);

			}
			for (int j = 0; j < 20; j++)
			{
				food[j].Draw(window);
			}
			score.Draw(window);
			scoreCounter.Draw(window);

			player.Draw(window);
			window.display();

		}
		
	}



Game::~Game()
{
}*/
