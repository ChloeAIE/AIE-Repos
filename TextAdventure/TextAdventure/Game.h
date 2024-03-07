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


private:

	Room** m_rooms;
	Player* m_player;

	int m_rows = 5;
	int m_columns = 5;

	void tryToMove(char c);
	void tryToUse(char c);
	void tryToInspect(char c);

	int m_posX, m_posY;

	CustomString* m_userInput;
	

	bool hasSpell = false;
	bool hasKey = true;
	bool escaped = false;
};

