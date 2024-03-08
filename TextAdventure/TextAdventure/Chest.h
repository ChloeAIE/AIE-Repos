#pragma once
#include "Item.h"
class Chest : public Item
{
public:
	Chest();
	~Chest();
	//description and use overrides
	void Description() const override;
	void Use() override;

private:
	//checks if it is opened
	bool isOpened;


};

