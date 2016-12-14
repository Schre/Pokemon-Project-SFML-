#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainPlayer.h"
#include "GameMap.h"
#include "MainCamera.h"
#include "Opponent.h"
class Application
{
public:
	Application();
	void runApp();
	void updatePlayer(Map & mainMap, sf::Event &Event, MainPlayer &player);
private:
	sf::RenderWindow mainPage;
	sf::View View;
	sf::Event Event;
	MainCamera mainCamera;

	// battle functions
	bool startBattle(MainPlayer &player, Opponent &opponent);
	void playerTurn(PokemonObject *&playerPokemon, PokemonObject *& opponentPokemon);
	void opponentTurn(PokemonObject *&playerPokemon, PokemonObject *& opponentPokemon);

};