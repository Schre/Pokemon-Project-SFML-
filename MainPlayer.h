#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include  "GameMap.h"
#include "MainCamera.h"
#include "PokemonList.h"


class MainPlayer
{
public:
	PokemonList Party;

	MainPlayer(float newX = 2, float newY = 3);
	bool UP, DOWN, LEFT, RIGHT, WALKED_UP, WALKED_DOWN, WALKED_LEFT, WALKED_RIGHT;

	// draw map in appropriate spot
	void updateMap(Map &map);
	// Wraps player functinos
	void updatePlayer(sf::Event &Event, sf::RenderWindow &Window, Map &map, sf::View & View, MainCamera & mainCamera);
	// getters
	sf::Vector2i getPlayerPosition() const;

	// setters
	void setPlayerPosition(const sf::Vector2i newPosition);
	void setPlayerSprite(const sf::Sprite newSprite);
	void setPlayerTexture(const sf::Texture newTexture);
	void setRunMode();
private:
	int movementSpeed;
	int mStep = 1;
	bool isMoving = false;
	bool runMode;
	sf::Vector2i mMapSize;
	int mBlockSpacing;
	sf::Vector2i mPlayerPosition;
	sf::Sprite mPlayerSprite;
	sf::Texture mPlayerTexture;
	// Player functions
	void updatePlayerPosition(sf::Event &Event);
	void drawPlayer(sf::RenderWindow &Window, Map &map, sf::View & View, MainCamera & mainCamera);
	


	// Pokemon linked list and functions
};
