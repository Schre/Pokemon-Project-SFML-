#pragma once
#include "PokemonObject.h"

class PokemonList
{
public:
	PokemonList();

	// getters
	PokemonObject *getHeadPtr();
	unsigned int getTotalPokemonAlive();

	// setters
	void setHeadPtr(PokemonObject * const newPtr);

	// linked list functions
	PokemonObject *makeNode(unsigned int newAttack, unsigned int newDefense, unsigned int newHitpoints
		, std::string newName = "", std::string move1 = "", std::string move2 = "", std::string move3 = "", std::string move4 = "");

	void insertAtFront(unsigned int newAttack, unsigned int newDefense, unsigned int newHitpoints
		, std::string newName = "", std::string move1 = "", std::string move2 = "", std::string move3 = "", std::string move4 = "");

private:
	PokemonObject *mpHead;
	unsigned int totalPokemonAlive;
};