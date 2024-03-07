#pragma once
#include "Item.h"
class Key : public Item
{
public:
	Key();
	~Key();
	void Description() const override;
	void Use() override;


private:
	bool haveKey;

};

