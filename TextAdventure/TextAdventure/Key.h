#pragma once
#include "Item.h"
class Key : public Item
{
public:
	Key();
	~Key();
	//description and use overrides
	void Description() const override;
	void Use() override;


private:
	//checks if you have the key 
	bool haveKey;

};

