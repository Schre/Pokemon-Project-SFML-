#pragma once
#include "PokemonList.h"
#include <string>
class Opponent
{
public:
	Opponent(std::string newName = "Name");
	PokemonList Party;

	// getters
	std::string getName() const;

private:
	std::string Name;
};