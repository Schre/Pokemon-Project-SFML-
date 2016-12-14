#include "PokemonMoves.h"

PokemonMove::PokemonMove(std::string newMove)
{
	mMove = newMove;
	mDoesDamage = false;
	mAttackPower = 0;
	mAffectsDefense = false;
	mAffectsAttack = false;
	mLowerAttack = 0;
	mLowerDefense = 0;
	mPP = 0;
	mType = "NORMAL";
	mAccuracy = 100;
}

bool PokemonMove::doesDamage() const
{
	return mDoesDamage;
}

bool PokemonMove::affectsDefense() const
{
	return mAffectsDefense;
}

bool PokemonMove::affectsAttack() const
{
	return mAffectsAttack;
}

unsigned int PokemonMove::getAttackPower() const
{
	return mAttackPower;
}

unsigned int PokemonMove::getLowerDefense() const
{
	return mLowerDefense;
}

unsigned int PokemonMove::getLowerAttack() const
{
	return mLowerAttack;
}

unsigned int PokemonMove::getAccuracy() const
{
	return mAccuracy;
}

unsigned int PokemonMove::getPP() const
{
	return mPP;
}

std::string PokemonMove::getMoveName() const
{
	return mMove;
}

std::string PokemonMove::getType() const
{
	return mType;
}

void PokemonMove::initiateMove()
{
	if (mMove == "Tackle")
	{
		mDoesDamage = true;
		mAttackPower = 40;
		mPP = 40;
	}
	else if (mMove == "Growl")
	{
		mAffectsAttack = true;
		mLowerAttack = 1;
		mPP = 40;
	}
	
}
