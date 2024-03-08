#pragma once
#include "Item.h"
class StrangePotion : public Item
{
public:
	StrangePotion();
	~StrangePotion();

	//use and description overrides
	void Description() const override;
	void Use() override;


public:
	//checks if you have drank the potion
	bool m_drink = false;
};

