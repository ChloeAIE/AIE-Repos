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
	//Chest description changes on if its been opened or not
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
	//chest use changes if its been opened
	if (isOpened == false)
	{
		std::cout << "You slowly open the chest, a thick black mist starts pouring out onto the floor, it quickly rushes through a crack" << std::endl;
		std::cout << "in the wall while growling, as if it is escaping..maybe you shouldn't have done that.." << std::endl;
		isOpened = true;
	}
	else
	{
		std::cout << "The chest is completely empty and the lid wont budge.." << std::endl;
	}
}
