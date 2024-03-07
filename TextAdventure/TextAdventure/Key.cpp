#include "Key.h"
#include <iostream>

Key::Key()
{
	haveKey = false;
}

Key::~Key()
{

}

void Key::Description() const
{
	if(haveKey == false)
	{
		std::cout << "A dark black key with a ruby on the end of it sits on the floor.." << std::endl;
	}
	else
	{
		std::cout << "All that remains is a key shape in the dust on the floor.." << std::endl;
	}
}

void Key::Use()
{
	if (haveKey == false)
	{
		std::cout << "You cautiously pick up the key.. it is freezing to touch.. what could it unlock?" << std::endl;
		haveKey = true;
	}
	else
	{
		std::cout << "You have already picked up the key.. just holding it makes you feel lightheaded.." << std::endl;
	}
}
