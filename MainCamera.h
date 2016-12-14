#pragma once
#include <SFML/Graphics.hpp>

class MainCamera
{
public:
	MainCamera();
	void playerCamera(sf::View &View, sf::Vector2i playerCoor, bool isMoving);
private:
	sf::Vector2i screenDimension;
	int camX;
	int camY;
};