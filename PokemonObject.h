#pragma once

#include <iostream>
#include <string>
#include "PokemonMoves.h"

typedef struct stats
{
	unsigned int Attack;
	unsigned int Defense;
	unsigned int Hitpoints;
	unsigned int Speed;
}Stats;

class PokemonObject
{
public:
	PokemonObject(unsigned int newAttack, unsigned int newDefense, unsigned int newHitpoints
		, std::string newName = "", std::string move1 = "", std::string move2 = "", std::string move3 = "", std::string move4 = "");

	// getters
	std::string getName() const;
	unsigned int getAttack() const;
	unsigned int getDefense() const;
	unsigned int getHitpoints() const;
	unsigned int getSpeed() const;
	PokemonObject * getNextPtr() const;
	bool hasFainted() const;

	// setters
	
	void setName(const std::string newName);
	void setAttack(const unsigned int newAttack);
	void setDefense(const unsigned int newDefense);
	void setHitpoints(const unsigned int newHitpoints);
	void setNextPtr(PokemonObject * const newPtr);
	void Fainted(const bool hasFainted);
	void setSpeed(const unsigned int newSpeed);



private:
	std::string mName;
	Stats mStats;
	bool mFainted;
	PokemonMove *mMove1;
	PokemonMove *mMove2;
	PokemonMove *mMove3;
	PokemonMove *mMove4;
	PokemonObject *mpNext;

};