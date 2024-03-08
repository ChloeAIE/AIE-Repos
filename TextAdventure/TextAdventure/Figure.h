#pragma once
#include "Item.h"
class Figure : public Item
{
public:
	Figure();
	~Figure();

	//use and description overrides
	void Description() const override;
	void Use() override;

private:
	//checks if you have picked it up
	bool hasVanished;

};

