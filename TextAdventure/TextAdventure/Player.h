#pragma once
#include <vector>
#include "CustomString.h"

class CustomString;

class Player
{

public:
	Player();
	~Player();

	//returns true if its found the entered spell in the vector using a binary search
	bool FindSpell(CustomString& spell);

private:
	//vector for spells
	std::vector<CustomString> spells;

};

