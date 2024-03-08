#include "Player.h"
//#include "CustomString.h"
#include <algorithm>
#include <iostream>

Player::Player()
{
	//setting up the spells into a vector
	spells.push_back(CustomString("thunder fall"));
	spells.push_back(CustomString("incinerate"));
	spells.push_back(CustomString("cryo blast"));
	spells.push_back(CustomString("air cannon"));
	spells.push_back(CustomString("stone spikes"));
	spells.push_back(CustomString("blizzard"));
	spells.push_back(CustomString("miasma"));
}

Player::~Player()
{
}

bool Player::FindSpell(CustomString& spell)
{
	std::sort (spells.begin(), spells.end()); //sorting the vector into order
	int l = 0;
	int r = spells.size() -1;

	while (l <= r) //binary searches for the entered spell
	{
		int startFrom = (l + r) / 2;  

		if (spells[startFrom] == spell)
		{
			return true;
		}
		else if (spells[startFrom] < spell)
		{
			l = startFrom + 1;
		}
		else
		{
			r = startFrom -1;
		}
	}
	return false;
}
