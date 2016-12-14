#include "PokemonList.h"

PokemonList::PokemonList()
{
	mpHead = nullptr;
}

PokemonObject * PokemonList::getHeadPtr()
{
	return mpHead;
}

unsigned int PokemonList::getTotalPokemonAlive()
{
	PokemonObject *pIndex = mpHead;
	unsigned int totalAlive = 0;
	while (pIndex != nullptr)
	{
		if (!pIndex->hasFainted())
		{
			totalAlive += 1;
		}
		pIndex = pIndex->getNextPtr();
	}
	return totalAlive;
}

void PokemonList::setHeadPtr(PokemonObject * const newPtr)
{
	mpHead = newPtr;
}

PokemonObject * PokemonList::makeNode(unsigned int newAttack, unsigned int newDefense, unsigned int newHitpoints, std::string newName, std::string move1, std::string move2, std::string move3, std::string move4)
{
	PokemonObject *pMem = new PokemonObject(newAttack, newDefense, newHitpoints, newName, move1, move2, move3, move4);
	return pMem;
}

void PokemonList::insertAtFront(unsigned int newAttack, unsigned int newDefense, unsigned int newHitpoints, std::string newName, std::string move1, std::string move2, std::string move3, std::string move4)
{
	PokemonObject *pMem = makeNode(newAttack, newDefense, newHitpoints, newName, move1, move2, move3);
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
}
