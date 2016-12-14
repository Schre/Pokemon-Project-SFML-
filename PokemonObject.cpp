#include "PokemonObject.h"

PokemonObject::PokemonObject(unsigned int newAttack, unsigned int newDefense, unsigned int newHitpoints, std::string newName, std::string move1, std::string move2, std::string move3, std::string move4)
{
	mStats.Attack = newAttack;
	mStats.Defense = newDefense;
	mStats.Hitpoints = newHitpoints;
	mName = newName;
	mpNext = nullptr;
	mFainted = false;
	mMove1 = new PokemonMove(move1);
	mMove2 = new PokemonMove(move2);
	mMove3 = new PokemonMove(move3);
	mMove4 = new PokemonMove(move4);
	
}

std::string PokemonObject::getName() const
{
	return mName;
}


unsigned int PokemonObject::getAttack() const
{
	return mStats.Attack;
}

unsigned int PokemonObject::getDefense() const
{
	return mStats.Defense;
}

unsigned int PokemonObject::getHitpoints() const
{
	return mStats.Hitpoints;
}

unsigned int PokemonObject::getSpeed() const
{
	return mStats.Speed;
}

PokemonObject * PokemonObject::getNextPtr() const
{
	return mpNext;
}

bool PokemonObject::hasFainted() const
{
	return mFainted;
}

void PokemonObject::setName(const std::string newName)
{
	mName = newName;
}


void PokemonObject::setAttack(const unsigned int newAttack)
{
	mStats.Attack = newAttack;
}

void PokemonObject::setDefense(const unsigned int newDefense)
{
	mStats.Defense = newDefense;
}

void PokemonObject::setHitpoints(const unsigned int newHitpoints)
{
	mStats.Hitpoints = newHitpoints;
}

void PokemonObject::setNextPtr(PokemonObject * const newPtr)
{
	mpNext = newPtr;
}

void PokemonObject::Fainted(const bool hasFainted)
{
	mFainted = hasFainted;
}

void PokemonObject::setSpeed(const unsigned int newSpeed)
{
	mStats.Speed = newSpeed;
}
