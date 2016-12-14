#pragma once

#include <iostream>
#include <string>

class PokemonMove
{
public:
	PokemonMove(std::string newMove);

	// getters
	bool doesDamage() const;
	bool affectsDefense() const;
	bool affectsAttack() const;
	unsigned int getAttackPower() const;
	unsigned int getLowerDefense() const;
	unsigned int getLowerAttack() const;
	unsigned int getAccuracy() const;
	unsigned int getPP() const;
	std::string getMoveName() const;
	std::string getType() const;
	// setters
	
private:
	bool mDoesDamage;
	bool mAffectsDefense;
	bool mAffectsAttack;
	unsigned int mAttackPower;
	unsigned int mLowerDefense;
	unsigned int mLowerAttack;
	unsigned int mAccuracy;
	unsigned int mPP;
	std::string mMove;
	std::string mType;
	void initiateMove();

	/*bool mPoisons;
	bool mBurns;*/
};