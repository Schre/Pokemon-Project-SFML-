#include "Opponent.h"

Opponent::Opponent(std::string newName)
{
	Name = newName;
}

std::string Opponent::getName() const
{
	return Name;
}
