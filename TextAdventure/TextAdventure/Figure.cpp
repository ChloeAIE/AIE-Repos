#include "Figure.h"
#include <iostream>

Figure::Figure()
{
	hasVanished = false;
}

Figure::~Figure()
{

}

void Figure::Description() const
{
	//figure description changes if its been used
	if (hasVanished == false)
	{
		std::cout << "A strange stone cat figure rests on a podium in the center of the room.. its eyes seem to be watching you.." << std::endl;
	}
	else
	{
		std::cout << "All that remains is the figures podium.. " << std::endl;
	}
}

void Figure::Use()
{
	//figure use changes if its been used
	if (hasVanished == true)
	{
		std::cout << "You have already taken the figure.. it won't be coming back.." << std::endl;
	}
	else
	{
		std::cout << "You take the strange figure.. holding it makes you feel at ease.. maybe it can protect you in here.." << std::endl;
		hasVanished = true;
	}
}
