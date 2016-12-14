#include "GameMap.h"

Map::Map(std::string mapName)
{
	mMapSize.x = 20;
	mMapSize.y = 20;
	mReadMap.open(mapName);
	mShift.x = 0;
	mShift.y = 0;
	// initiate sprites
	tGrassBlock1.loadFromFile("Sprites_and_Textures/Grass.png");
	sGrassBlock1.setTexture(tGrassBlock1);
	tTreeTop1.loadFromFile("Sprites_and_Textures/treeTop.png");
	sTreeTop1.setTexture(tTreeTop1); sTreeTop1.setScale(.5, .5);
	tTreeBottom1.loadFromFile("Sprites_and_Textures/treeBottom.png");
	sTreeBottom1.setTexture(tTreeBottom1); sTreeBottom1.setScale(.5, .5);
	tPokeGrass1.loadFromFile("Sprites_and_Textures/pokeGrass1.png");
	sPokeGrass1.setTexture(tPokeGrass1);
	// house sprites
	tBottomLeftHouseWall.loadFromFile("Sprites_and_Textures/House/bottomLeftHouseWall.png");
	sBottomLeftHouseWall.setTexture(tBottomLeftHouseWall);
	tBottomRightHouseWall.loadFromFile("Sprites_and_Textures/House/bottomRightHouseWall.png");
	sBottomRightHouseWall.setTexture(tBottomRightHouseWall);
	tRedRoof.loadFromFile("Sprites_and_Textures/House/redRoof.png");
	sRedRoof.setTexture(tRedRoof);
	tRedRoofBorderBottom.loadFromFile("Sprites_and_Textures/House/redRoofBorderBottom.png");
	sRedRoofBorderBottom.setTexture(tRedRoofBorderBottom);
	tRedLeftRoofBorder.loadFromFile("Sprites_and_Textures/House/redLeftRoofBorder.png");
	sRedLeftRoofBorder.setTexture(tRedLeftRoofBorder);
	tHouseDoor.loadFromFile("Sprites_and_Textures/House/houseDoor.png");
	sHouseDoor.setTexture(tHouseDoor);

	tRedRoofBottom.loadFromFile("Sprites_and_Textures/House/redRoofBottom.png");
	sRedRoofBottom.setTexture(tRedRoofBottom);
	tRightWindow.loadFromFile("Sprites_and_Textures/House/houseRightWindow.png");
	sRightWindow.setTexture(tRightWindow);
	tLeftWindow.loadFromFile("Sprites_and_Textures/House/houseLeftWindow.png");
	sLeftWindow.setTexture(tLeftWindow);
	//

}

void Map::loadCurrentMap()
{
	int col = 0, row = 0;
	char buffer[10];
	if (mReadMap.is_open())
	{
		// read from file and initiate 2 dimensional array
			for (row = 0; row < mMapSize.y; row++)
			{
				for (col = 0; col < mMapSize.x; col++)
				{
					mReadMap >> buffer;
					mCurrentMap[col][row] = buffer[0];
				}
			}
	}
	else
	{
		std::cout << "ERROR: Failed to load map";
	}
}

void Map::drawCurrentMap(sf::RenderWindow &Window)
{
	sf::Sprite sTemp;
	/*sf::Texture tTemp;
	tTemp.loadFromFile("Sprites_and_Textures/Chunks/Chunk1.png");
	sTemp.setTexture(tTemp);
	sTemp.setPosition(mShift.x*mBlockSpacing, mShift.y*mBlockSpacing);
	Window.draw(sTemp);*/
	for (int row = 0; row < mMapSize.y; row++) // implement shift
	{
		for (int col = 0; col < mMapSize.x; col++)
		{
			switch (mCurrentMap[row][col])
			{
			case 'G': // grass 
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing+mShift.x*16, col*mBlockSpacing+mShift.y*16);
				Window.draw(sTemp);
				break;
			case 't': // tree top
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sTreeTop1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case 'T': // tree bottom
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sTreeBottom1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case 'X': // poke grass
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sPokeGrass1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
				/////////// house
			case '!': // left roof border
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sRedLeftRoofBorder;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '@': // red roof
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sRedRoof;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '#': // red roof border bottom
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sRedRoofBorderBottom;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '%': // house left wall
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sBottomLeftHouseWall;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '^': // house right wall
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sBottomRightHouseWall;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '&': // house door
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sHouseDoor;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '$': // red roof bottom
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sRedRoofBottom;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
				/////////////////////
			case '(': // left window
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sLeftWindow;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			case '*': // right window
				sTemp = sGrassBlock1;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				sTemp = sRightWindow;
				sTemp.setPosition(row*mBlockSpacing + mShift.x * 16, col*mBlockSpacing + mShift.y * 16);
				Window.draw(sTemp);
				break;
			}
		}
	}
}

char Map::getCurrentMapItem(const int row, const int col)
{
	return mCurrentMap[row][col];
}

sf::Vector2u Map::getShift() const
{
	return mShift;
}

void Map::setCurrentMap(std::string newMap, int xShift, int yShift)
{
	mReadMap.close();
	mReadMap.open(newMap);
	loadCurrentMap();
	mShift.x = xShift;
	mShift.y = yShift;
}

