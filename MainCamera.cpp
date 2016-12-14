#include "MainCamera.h"

MainCamera::MainCamera()
{
	screenDimension.x = 800;
	screenDimension.y = 600;
}

void MainCamera::playerCamera(sf::View & View, sf::Vector2i playerCoor, bool isMoving)
{
	sf::Vector2f position;
	if (isMoving)
	{
		position.x = playerCoor.x - screenDimension.x / 2;
		position.y = playerCoor.y - screenDimension.y / 2;
	}
	else
	{
		position.x = playerCoor.x*16 - screenDimension.x / 2;
		position.y = playerCoor.y *16- screenDimension.y / 2;
	}
	
	View.reset(sf::FloatRect(position.x, position.y, screenDimension.x, screenDimension.y));
	View.setViewport(sf::FloatRect(0,0,1,1));
	View.zoom(.6);
}
