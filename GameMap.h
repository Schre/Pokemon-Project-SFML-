#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
class Map
{
public:
	Map(std::string mapName = "Area1.txt");

	void loadCurrentMap();
	void drawCurrentMap(sf::RenderWindow &Window);
	char getCurrentMapItem(const int row, const int col);

	sf::Vector2u getShift() const;
	void setCurrentMap(std::string newMap, int xShift, int yShift);
private:
	// 20x20 map
	char mCurrentMap[20][20];
	sf::Vector2i mMapSize;
	int mBlockSpacing = 16;
	std::ifstream mReadMap;
	sf::Vector2u mShift;

	// block textures
	sf::Texture tGrassBlock1;
	sf::Texture tTreeTop1;
	sf::Texture tTreeBottom1;
	sf::Texture tPokeGrass1;
	// house
	sf::Texture tRedLeftRoofBorder;
	sf::Texture tRedRoof;
	sf::Texture tRedRoofBorderBottom;
	sf::Texture tBottomLeftHouseWall;
	sf::Texture tBottomRightHouseWall;
	sf::Texture tHouseDoor;
	sf::Texture tRedRoofBottom;
	sf::Texture tRightWindow;
	sf::Texture tLeftWindow;


	// block sprites
	sf::Sprite sGrassBlock1;
	sf::Sprite sTreeTop1;
	sf::Sprite sTreeBottom1;
	sf::Sprite sPokeGrass1;

	// house
	sf::Sprite sRedLeftRoofBorder;
	sf::Sprite sRedRoof;
	sf::Sprite sRedRoofBorderBottom;
	sf::Sprite sBottomLeftHouseWall;
	sf::Sprite sBottomRightHouseWall;
	sf::Sprite sHouseDoor;
	sf::Sprite sRedRoofBottom;
	sf::Sprite sRightWindow;
	sf::Sprite sLeftWindow;



};