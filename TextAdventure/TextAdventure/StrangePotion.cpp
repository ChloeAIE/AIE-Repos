#include "StrangePotion.h"
#include "Game.h"
#include <iostream>

StrangePotion::StrangePotion()
{
	m_drink = false;
}

StrangePotion::~StrangePotion()
{
	//can be empty
}

void StrangePotion::Description() const
{
	//potion description changes if its been used
	if(m_drink == false)
	{
		std::cout << "There is a round glass bottle with a glistening blue liquid inside.." << std::endl;
	}
	else
	{
		std::cout << "The bottle is empty.. you drank it all.." << std::endl;
	}
	
}

void StrangePotion::Use()
{
	//potion use changes if its been used
	if(m_drink == false)
	{
		std::cout << "You drink the strange potion.. you feel like the magic flowing through your body.." << std::endl;
		m_drink = true;
	}
	else
	{
		std::cout << "The bottle is empty, you can't drink anymore.." << std::endl;
	}
}
