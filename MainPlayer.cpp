#include "MainPlayer.h"

MainPlayer::MainPlayer(float newX, float newY)
{
	// player directions
	UP = false, DOWN = false, LEFT = false, RIGHT = false, WALKED_DOWN = false, WALKED_UP = false, WALKED_LEFT = false, WALKED_RIGHT = false, runMode = false;

	mPlayerPosition.x = newX;
	mPlayerPosition.y = newY;
	mMapSize.x = 20;
	mMapSize.y = 20;
	mBlockSpacing = 16;
	movementSpeed = 10;
	// load sprites
	mPlayerTexture.loadFromFile("Sprites_and_Textures/faceForward.png");
	mPlayerSprite.setTexture(mPlayerTexture);

}

void MainPlayer::updateMap(Map & map)
{
	if (getPlayerPosition().x >= 19 && RIGHT == true)
	{
		map.setCurrentMap("Area2.txt", 19, 0);
	}
	else if (getPlayerPosition().x <= 19 && LEFT == true)
	{
		map.setCurrentMap("Area1.txt", 0, 0);
	}
}

void MainPlayer::updatePlayer(sf::Event &Event, sf::RenderWindow & Window, Map & map, sf::View & View, MainCamera & mainCamera)
{		
	// to avoid polling
	isMoving = true;
	do 
	{
		// automatically shift map according to player position
		updateMap(map);
		//
		updatePlayerPosition(Event);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Event.key.code = sf::Keyboard::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Event.key.code = sf::Keyboard::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Event.key.code = sf::Keyboard::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Event.key.code = sf::Keyboard::Down;
		}
		else
		{
			Event.key.code = sf::Keyboard::Unknown;
		}
		drawPlayer(Window, map, View, mainCamera);
		//system("Cls");
	} while (isMoving == true && Event.key.code == sf::Keyboard::Right || Event.key.code == sf::Keyboard::Left || Event.key.code == sf::Keyboard::Up || Event.key.code == sf::Keyboard::Down);
}


sf::Vector2i MainPlayer::getPlayerPosition() const
{
	return mPlayerPosition;
}

void MainPlayer::setPlayerPosition(const sf::Vector2i newPosition)
{
	mPlayerPosition = newPosition;
}

void MainPlayer::setPlayerSprite(const sf::Sprite newSprite)
{
	mPlayerSprite = newSprite;
}

void MainPlayer::setPlayerTexture(const sf::Texture newTexture)
{
	mPlayerTexture = newTexture;
}

void MainPlayer::setRunMode()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		runMode = !runMode;
		if (runMode)
		{
			//mStep = 2;
			movementSpeed = 1;
		}
		else
		{
			//mStep = 1;
			movementSpeed = 10;
		}
	}
}

void MainPlayer::updatePlayerPosition(sf::Event &Event)
{
	UP = false, DOWN = false, LEFT = false, RIGHT = false;
	switch (Event.key.code)
	{
	case sf::Keyboard::Up:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			mPlayerPosition.y -= 1;
			UP = true;
			//system("cls");
			//std::cout << "Player Coord: " << "(" << mPlayerPosition.x << ", " << mPlayerPosition.y << ")" << std::endl;
		}
		break;
	case sf::Keyboard::Down:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			mPlayerPosition.y += 1;
			DOWN = true;
			//system("cls");
			//std::cout << "Player Coord: " << "(" << mPlayerPosition.x << ", " << mPlayerPosition.y << ")" << std::endl;
		}
		break;
	case sf::Keyboard::Left:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			mPlayerPosition.x -= 1;
			LEFT = true;
			//system("cls");
			//std::cout << "Player Coord: " << "(" << mPlayerPosition.x << ", " << mPlayerPosition.y << ")" << std::endl;
		}
		break;
	case sf::Keyboard::Right:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			mPlayerPosition.x += 1;
			RIGHT = true;
			//system("cls");
			//std::cout << "Player Coord: " << "(" << mPlayerPosition.x << ", " << mPlayerPosition.y << ")" << std::endl;
		}
		break;
	}

}

void MainPlayer::drawPlayer(sf::RenderWindow &Window, Map &map, sf::View & View, MainCamera & mainCamera)
{
	sf::Sprite sTemp;
	sf::Vector2i tempPos;

	if (UP == false && DOWN == false && LEFT == false && RIGHT == false)
	{
		sTemp.setTexture(mPlayerTexture);
		sTemp.setScale(.5, .3337);

		sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y*mBlockSpacing);
		Window.draw(sTemp);
	
	}
	else
	{
		//bool display = false;
		if (RIGHT == true) 
		{
			if (map.getCurrentMapItem(mPlayerPosition.x-map.getShift().x, mPlayerPosition.y-map.getShift().y) != 'G' && map.getCurrentMapItem(mPlayerPosition.x, mPlayerPosition.y) != 'X') // HIT A BORDER
			{
				isMoving = false;
				mPlayerPosition.x -= 1;
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					if (i > mBlockSpacing / 2)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/faceRight.png");
					}
					else if (WALKED_RIGHT)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/rightWalk1.png");
					}
					else if (!WALKED_RIGHT)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/rightWalk2.png");
					}
					sTemp.setTexture(mPlayerTexture);
					sTemp.setScale(.5, .3337);

					sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y*mBlockSpacing);
					Window.draw(sTemp);
					//
					Window.clear();
					//
					map.drawCurrentMap(Window);
					Window.draw(sTemp);
					Window.display();
					sf::sleep(sf::milliseconds(movementSpeed));

				}
				WALKED_RIGHT = !WALKED_RIGHT;

			}
			else
			{
				if (WALKED_RIGHT)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/rightWalk1.png");
					sTemp.setTexture(mPlayerTexture);
				}
				else if (!WALKED_RIGHT)
				{
				mPlayerTexture.loadFromFile("Sprites_and_Textures/rightWalk2.png");
				sTemp.setTexture(mPlayerTexture);
				}
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					//display = !display;
					//if (display == true)
					//{
						if (i > mBlockSpacing / 2)
						{
							mPlayerTexture.loadFromFile("Sprites_and_Textures/faceRight.png");
							sTemp.setTexture(mPlayerTexture);
						}
						sTemp.setScale(.5, .3337);
						//
						Window.clear();
						//
						sTemp.setPosition((mPlayerPosition.x - 1)* mBlockSpacing + i, mPlayerPosition.y * mBlockSpacing);
						map.drawCurrentMap(Window);
						Window.draw(sTemp);
						//// set camera
						tempPos.x = sTemp.getPosition().x + 1;
						tempPos.y = sTemp.getPosition().y;
						mainCamera.playerCamera(View, tempPos, true);
						Window.setView(View);
						///////
						Window.display();
						sf::sleep(sf::milliseconds(movementSpeed));

				}

				}
				Window.clear();
				//
				sTemp.setTexture(mPlayerTexture);
				sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y * mBlockSpacing);
				map.drawCurrentMap(Window);
				Window.draw(sTemp);
				Window.display();
				WALKED_RIGHT = !WALKED_RIGHT;
				//
			//}
		}
		else if (LEFT == true)
		{
			if (map.getCurrentMapItem(mPlayerPosition.x - map.getShift().x, mPlayerPosition.y - map.getShift().y) != 'G' && map.getCurrentMapItem(mPlayerPosition.x, mPlayerPosition.y) != 'X') // HIT A BORDER
			{
				isMoving = false;
				mPlayerPosition.x += 1;
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					if (i > mBlockSpacing / 2)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/faceLeft.png");
					}
					else if (WALKED_LEFT)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/leftWalk1.png");
					}
					else if (!WALKED_LEFT)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/leftWalk2.png");
					}
					sTemp.setTexture(mPlayerTexture);
					sTemp.setScale(.5, .3337);

					sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y*mBlockSpacing);
					Window.draw(sTemp);
					//
					Window.clear();
					//
					map.drawCurrentMap(Window);
					Window.draw(sTemp);
					Window.display();
					sf::sleep(sf::milliseconds(movementSpeed));

				}
				//
				WALKED_LEFT = !WALKED_LEFT;

				//

			}
			else
			{
				if (WALKED_LEFT)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/leftWalk1.png");
					sTemp.setTexture(mPlayerTexture);
				}
				else if (!WALKED_LEFT)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/leftWalk2.png");
					sTemp.setTexture(mPlayerTexture);
				}
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					//display = !display;
					//if (display == true)
					//{
						if (i > mBlockSpacing / 2)
						{
							mPlayerTexture.loadFromFile("Sprites_and_Textures/faceLeft.png");
						}
						sTemp.setScale(.5, .3337);
						//
						Window.clear();
						//
						sTemp.setPosition(mPlayerPosition.x * mBlockSpacing + (mBlockSpacing - i), mPlayerPosition.y * mBlockSpacing);
						map.drawCurrentMap(Window);
						Window.draw(sTemp);
						//// set camera
						tempPos.x = sTemp.getPosition().x - 1;
						tempPos.y = sTemp.getPosition().y;
						mainCamera.playerCamera(View, tempPos, true);
						Window.setView(View);
						///////

						Window.display();
					//}
					sf::sleep(sf::milliseconds(movementSpeed));

				}
				Window.clear();
				//
				sTemp.setTexture(mPlayerTexture);
				sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y * mBlockSpacing);
				map.drawCurrentMap(Window);
				Window.draw(sTemp);
				Window.display();
				//
				WALKED_LEFT = !WALKED_LEFT;
			}
		}
		else if (UP == true)
		{
			if (map.getCurrentMapItem(mPlayerPosition.x - map.getShift().x, (mPlayerPosition.y) - map.getShift().y) != 'G' && map.getCurrentMapItem(mPlayerPosition.x, mPlayerPosition.y) != 'X') // HIT A BORDER
			{
				isMoving = false;
				mPlayerPosition.y += 1;
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					if (i > mBlockSpacing / 2)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/faceBack.png");
					}
					else if (WALKED_UP)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/walkUp1.png");
					}
					else if (!WALKED_UP)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/walkUp2.png");
					}
					sTemp.setTexture(mPlayerTexture);
					sTemp.setScale(.5, .3337);

					sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y*mBlockSpacing);
					Window.draw(sTemp);
					//
					Window.clear();
					//
					map.drawCurrentMap(Window);
					Window.draw(sTemp);
					Window.display();
					sf::sleep(sf::milliseconds(movementSpeed));

				}
				WALKED_UP = !WALKED_UP;

			}
			else
			{
				if (WALKED_UP)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/walkUp1.png");
					sTemp.setTexture(mPlayerTexture);
				}
				else if (!WALKED_UP)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/walkUp2.png");
					sTemp.setTexture(mPlayerTexture);
				}

				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					//display = !display;
					//if (display == true)
					//{
						if (i > mBlockSpacing / 2)
						{
							mPlayerTexture.loadFromFile("Sprites_and_Textures/faceBack.png");
							sTemp.setTexture(mPlayerTexture);
						}

						sTemp.setScale(.5, .3337);
						//
						Window.clear();
						//
						sTemp.setPosition(mPlayerPosition.x * mBlockSpacing, mPlayerPosition.y * mBlockSpacing + (mBlockSpacing - i));
						map.drawCurrentMap(Window);
						Window.draw(sTemp);
						//// set camera
						tempPos.x = sTemp.getPosition().x - 1;
						tempPos.y = sTemp.getPosition().y - 1;
						mainCamera.playerCamera(View, tempPos, true);
						Window.setView(View);
						///////
						Window.display();
					//}
					sf::sleep(sf::milliseconds(movementSpeed));
				}
				Window.clear();
				//
				sTemp.setTexture(mPlayerTexture);
				sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y * mBlockSpacing);
				map.drawCurrentMap(Window);
				Window.draw(sTemp);
				Window.display();
				//
				WALKED_UP = !WALKED_UP;
			}
		}
		else if (DOWN == true)
		{
			if (map.getCurrentMapItem(mPlayerPosition.x - map.getShift().x, mPlayerPosition.y - map.getShift().y) != 'G' && map.getCurrentMapItem(mPlayerPosition.x, mPlayerPosition.y) != 'X') // HIT A BORDER
			{
				isMoving = false;
				mPlayerPosition.y -= 1;
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					if (i > mBlockSpacing / 2)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/faceForward.png");
					}
					else if (WALKED_DOWN)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/downWalk1.png");
					}
					else if (!WALKED_DOWN)
					{
						mPlayerTexture.loadFromFile("Sprites_and_Textures/downWalk2.png");
					}
					sTemp.setTexture(mPlayerTexture);
					sTemp.setScale(.5, .3337);

					sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y*mBlockSpacing);
					Window.draw(sTemp);
					//
					Window.clear();
					//
					map.drawCurrentMap(Window);
					Window.draw(sTemp);
					Window.display();
					sf::sleep(sf::milliseconds(movementSpeed));

				}
				WALKED_DOWN = !WALKED_DOWN;

			}
			else
			{
				if (WALKED_DOWN)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/downWalk1.png");
					sTemp.setTexture(mPlayerTexture);
				}
				else if (!WALKED_DOWN)
				{
					mPlayerTexture.loadFromFile("Sprites_and_Textures/downWalk2.png");
					sTemp.setTexture(mPlayerTexture);
				}
				for (int i = 0; i < mBlockSpacing; i += mStep)
				{
					//display = !display;
					//if (display == true)
					//{
						if (i > mBlockSpacing / 2)
						{
							mPlayerTexture.loadFromFile("Sprites_and_Textures/faceForward.png");
							sTemp.setTexture(mPlayerTexture);
						}
						sTemp.setScale(.5, .3337);
						//
						Window.clear();
						//
						sTemp.setPosition(mPlayerPosition.x * mBlockSpacing, mPlayerPosition.y * mBlockSpacing - (mBlockSpacing - i));
						map.drawCurrentMap(Window);
						Window.draw(sTemp);
						//// set camera
						tempPos.x = sTemp.getPosition().x - 1;
						tempPos.y = sTemp.getPosition().y + 1;
						mainCamera.playerCamera(View, tempPos, true);
						Window.setView(View);
						///////
						Window.display();
					//}
						sf::sleep(sf::milliseconds(movementSpeed));
					//if (i % mStep * 2 == 0)
					//	//Window;
				}
				Window.clear();
				//
				sTemp.setTexture(mPlayerTexture);
				sTemp.setPosition(mPlayerPosition.x*mBlockSpacing, mPlayerPosition.y * mBlockSpacing);
				map.drawCurrentMap(Window);
				Window.draw(sTemp);
				Window.display();
				//
				WALKED_DOWN = !WALKED_DOWN;
			}
		}
	}
}
