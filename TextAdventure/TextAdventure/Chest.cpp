#include "Chest.h"
#include <iostream>

Chest::Chest()
{
	isOpened = false;
}

Chest::~Chest()
{

}

void Chest::Description() const
{
	if (isOpened == false)
	{
		std::cout << "A mysterious chest sits in the center of this room, it doesn't appear to be locked, better be careful.." << std::endl;
	}
	else
	{
		std::cout << "The chest is open and empty, what was that?" << std::endl;
	}
}

void Chest::Use()
{
	if (isOpened == false)
	{
		std::cout << "You slowly open the chest, a faint mist starts pouring out onto the floor, it quickly rises and flows through a crack in the ceiling as if it is escaping.. maybe you shouldn't have done that.." << std::endl;
		isOpened = true;
	}
	else
	{
		std::cout << "The chest is completely empty and the lid wont budge.." << std::endl;
	}
}
