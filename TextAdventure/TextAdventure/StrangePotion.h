#pragma once
#include "Item.h"
class StrangePotion : public Item
{
public:
	StrangePotion();
	~StrangePotion();

	void Description() const override;
	void Use() override;


public:

	bool m_drink = false;
};

