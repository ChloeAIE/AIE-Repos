#pragma once

class Room;
class Player;
class CustomString;

class Game
{
public:
	Game();
	~Game();

	void RunGame();    //run the game
	void DrawMap();   //draw that map

public:
	bool m_menu = true; //checks if its at the menu

private:

	Room** m_rooms; //room pointer pointer to set the X and Y values
	Player* m_player; // player

	int m_rows = 5; //X and Y values of rooms to be used
	int m_columns = 5;

	void tryToMove(char c); //try to move, use and inspect functions for the switch statements
	void tryToUse(char c);
	void tryToInspect(char c);

	void MoveMonster(); //function to move the monster around

	int m_posX, m_posY; //player pos
	int m_enemyPosX, m_enemyPosY; //monster pos
	
	CustomString* m_userInput; //input for the string

	//the below bools check things to unlock certain rooms, see if the monster should spawn and check if you have an extra life or not
	bool hasSpell = false;
	bool hasKey = false;
	bool escaped = false;
	bool chestUsed = false;
	bool statueLife = false;
	bool foundStatue = false;

	//is true if the monster is within one room
	bool inDanger;

	//bools to check monster location
	bool onTop = false;
	bool onBot = false;
	bool onLeft = false;
	bool onRight = false;
};

