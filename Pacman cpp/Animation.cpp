#include "Animation.h"
#include "Player.h"


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this-> imageCount = imageCount;
	this-> switchTime = switchTime;
	time = 0.0f;
	currentImage.x = 0;


	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
	


}


Animation::~Animation()
{
}

void Animation::Update(float deltaTime)
{
	currentImage.y = 1;
	time += deltaTime;

	if (time >= switchTime) 
	{
		time -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 1;
		}
		uvRect.left = currentImage.x * uvRect.width;
	}
	
}