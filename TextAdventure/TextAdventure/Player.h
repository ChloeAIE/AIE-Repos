#pragma once
#include <vector>
#include "CustomString.h"

class CustomString;

class Player
{

public:
	Player();
	~Player();

	bool FindSpell(CustomString& spell);

private:
	std::vector<CustomString> spells;

};

