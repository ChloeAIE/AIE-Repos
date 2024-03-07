#pragma once

class Item;
class CustomString;

class Room
{
public:

	Room();
	~Room();
	void SetUp(int i);
	void Description() const;

public:
	Item* item;

private:
	CustomString* m_description;
	

};

