#include "Figure.h"
#include <iostream>

Figure::Figure()
{
	timesTouched = 0;
	hasVanished = false;
}

Figure::~Figure()
{

}

void Figure::Description() const
{
	if (hasVanished == false)
	{
		std::cout << "A strange stone cat figurine rests on a podium in the center of the room.. its eyes seem to be watching you.." << std::endl;
	}
	else
	{
		std::cout << "The podium is empty.. where has that figure gone?" << std::endl;
	}
}

void Figure::Use()
{
	if(timesTouched == 0)
	{
		std::cout << "You touch the stone figure and begin to feel dizzy, best not to do that again.." << std::endl;
		timesTouched++;
	}
	if(timesTouched == 1)
	{
		std::cout << "The room begins to go dark and your eyes grow heavy.. are you sure about this?" << std::endl;
		timesTouched++;
	}
	if (timesTouched == 2)
	{
		std::cout << "You awake feeling better than ever.. huh guess it was fine to touch.. but where has it gone?" << std::endl;
		timesTouched++;
		hasVanished = true;
	}
	if(timesTouched == 3)
	{
		std::cout << "There is nothing to touch.. the figure has vanished.." << std::endl;
	}
}
