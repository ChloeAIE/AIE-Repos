#pragma once
#include "Item.h"
class Figure : public Item
{
public:
	Figure();
	~Figure();

	void Description() const override;
	void Use() override;

private:
	int timesTouched;
	bool hasVanished;

};

