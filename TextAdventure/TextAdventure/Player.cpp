#include "Player.h"
//#include "CustomString.h"
#include <algorithm>
#include <iostream>

Player::Player()
{
	//CustomString* test1 = new CustomString("Fireball");
	spells.push_back(CustomString("lightningbolt"));
	spells.push_back(CustomString("fireblast"));
	spells.push_back(CustomString("freezebeam"));
	spells.push_back(CustomString("aircannon"));
	spells.push_back(CustomString("stonespikes"));
	spells.push_back(CustomString("blizzard"));
	spells.push_back(CustomString("poisonspray"));
}

Player::~Player()
{
}

bool Player::FindSpell(CustomString& spell)
{
	std::sort (spells.begin(), spells.end());
	int l = 0;
	int r = spells.size() -1;

	while (l <= r)
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
