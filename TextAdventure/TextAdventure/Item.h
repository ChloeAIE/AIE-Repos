#pragma once
class Item
{
private:



public:
	//sets the virtual voids to be used as overrides in the items themselves
	virtual void Description() const = 0;
	virtual void Use() = 0;

};

