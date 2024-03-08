#pragma once

class Item;
class CustomString;
class Game;

class Room
{
public:

	Room();
	~Room();
	//function to set up the room taking an int and a pointer to Game as well as the rooms description
	void SetUp(int i, Game* game);
	void Description() const;

public:
	//pointer to items so they can be set up in the rooms
	Item* item;

private:
	// description for the rooms
	CustomString* m_description;
	Game* m_game;

};

