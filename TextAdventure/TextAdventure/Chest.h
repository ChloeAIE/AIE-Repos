#pragma once
#include "Item.h"
class Chest : public Item
{
public:
	Chest();
	~Chest();
	void Description() const override;
	void Use() override;

private:
	bool isOpened;


};

