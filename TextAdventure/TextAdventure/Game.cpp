#include "Game.h"
#include "CustomString.h"
#include "Room.h"
#include "StrangePotion.h"
#include "Chest.h"
#include "Key.h"
#include "Figure.h"
#include "Player.h"
#include <iostream>

Game::Game()
{
		m_userInput = new CustomString();
		m_player = new Player();
		m_rooms = new Room * [m_rows];



		int numbers[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 }; //setting up room count

		int r = 0;

		for (int i = 0; i < m_columns; i++) //setting up the rooms with the room data
		{
			m_rooms[i] = new Room[m_columns];
		}

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				std::cout << r << std::endl;
				m_rooms[i][j].SetUp(r, this);
				r++;
			}
		}

		m_posX = 2;  //setting player pos
		m_posY = 4;

		m_enemyPosX = 0; //monster spawn pos
		m_enemyPosY = 0;
}

Game::~Game()
{
	delete m_userInput;
	delete m_player;

	for (int i = 0; i < m_columns; i++)  //destructs the rooms in the ** then deletes the rooms[] itself
	{
		delete[] m_rooms[i];
	}
	delete[] m_rooms;
}

void Game::RunGame()
{
	
		Player player;

		//sets the rooms descriptions to match .Description()
		m_rooms[m_posY][m_posX].Description();

		//This is checking if player pos is the same as one of the trap rooms, if so game over
		if ((m_posX == 3 && m_posY == 0) || (m_posX == 1 && m_posY == 2))
		{
			system("pause");
			exit(1);
		}
		//sets bool for the figure to give an extra life
		if (m_posX == 4 && m_posY == 4)
		{
			if (foundStatue == false)
			{
				statueLife = true;
				foundStatue = true;
			}
		}
		//commands to move, use or inspect items and rooms
		std::cout << "Please enter a command: Move <up/down/left/right>  /   Use <Item*>   /   Inspect <Item*>" << std::endl;

		m_userInput->ReadConsole();

		m_userInput->ToLower();

		switch (m_userInput->CharacterAt(0))
		{
		case 'm': //if move entered it looks for the direction
			if (m_userInput->Find("move") != -1)
			{
				if (m_userInput->Find("up") != -1)
				{ //Player moves up
					tryToMove('u');
				}
				else if (m_userInput->Find("down") != -1)
				{ //Player moves down
					tryToMove('d');
				}
				else if (m_userInput->Find("left") != -1)
				{ //Player moves left
					tryToMove('l');
				}
				else if (m_userInput->Find("right") != -1)
				{ //Player moves right
					tryToMove('r');
				}
				else
				{
					std::cout << "Input not regonised, try again please.." << std::endl;
				}
			}
			break;
		case 'u': //if use entered it looks for an item in the same room, if it finds it it uses it.
			if (m_userInput->Find("use") != -1)
				if (m_userInput->Find("potion") != -1)
				{
					tryToUse('p');
				}
				else if (m_userInput->Find("chest") != -1)
				{
					tryToUse('c');
				}
				else if (m_userInput->Find("figure") != -1)
				{
					tryToUse('f');
				}
				else if (m_userInput->Find("key") != -1)
				{
					tryToUse('k');
				}
				else
				{
					std::cout << "Unsure what item you were trying to use sorry!" << std::endl;
				}
			break;
		case 'i': //same as use but with inspect
			if (m_userInput->Find("inspect") != -1)
				if (m_userInput->Find("potion") != -1)
				{
					tryToInspect('p');
				}
				else if (m_userInput->Find("chest") != -1)
				{
					tryToInspect('c');
				}
				else if (m_userInput->Find("figure") != -1)
				{
					tryToInspect('f');
				}
				else if (m_userInput->Find("key") != -1)
				{
					tryToInspect('k');
				}
				else
				{
					std::cout << "Unsure what item you were trying to inspect sorry!" << std::endl;
				}
			break;
		case 's': 
			if (m_userInput->Find("spell") != -1) //search for the entered spell using a binary search
			{
				std::cout << "Enter a spell to search for: ";
				m_userInput->ReadConsole();
				m_userInput->ToLower();
				if (player.FindSpell(*m_userInput) == true) //if spell is found
				{
					std::cout << "Spell: " << m_userInput->CStr() << " has been found!" << std::endl;
				}
				else                                        //if it is not found
				{
					std::cout << "Spell: " << m_userInput->CStr() << " has not been found.." << std::endl;
				}
			}
			break;
		default:
			//if it doesnt recognise any of the previous inputs
			std::cout << "Not sure what you were trying to do there sorry!" << std::endl;
			break;
		}
		system("pause");
	
}

void Game::DrawMap()
{
	while (m_menu)
	{   //the code below will run while at the menu
		system("cls");
		std::cout << "Welcome to the temple! " << std::endl;
		std::cout << "Would you like to Play, see Instructions or Quit? ('p' / 'i' / 'q')" << std::endl;

		m_userInput->ReadConsole();
		switch (m_userInput->CharacterAt(0))
		{
		case 'p':
			m_menu = false;
			break;
		case 'i':
			system("cls");
			std::cout << "You have discovered an ancient temple hidden deep within a dark forest, your curiosity has gotten the better" << std::endl;
			std::cout << "of you as you enter the temple.." << std::endl;
			std::cout << std::endl;
			std::cout << "Your goal is to find the exit and escape the temple alive, you will need to find certain items to progress" << std::endl;
			std::cout << "through the temple.." << std::endl;
			std::cout << std::endl;
			std::cout << "Pay attention to the room descriptions as they may warn you of possible danger lurking within the temple.. good luck!" << std::endl;
			system("pause");
			break;
		case 'q':
			exit(1);
			break;
		default:
			std::cout << "I didn't recognise that command, please try again.." << std::endl;
			break;
		}
	} //once menu loop breaks it goes to the game loop and draws the map
	
	system("cls");
	if (m_posX == m_enemyPosX && m_posY == m_enemyPosY && chestUsed)
	{
		//if you enter the same room as the monster and dont have the figure you lose, if you do it moves the monster and you can continue
		if (statueLife)
		{
			std::cout << "You have entered the same room as the monster.. the statue emits a powerful light!" << std::endl;
			std::cout << std::endl;
			std::cout << "The statue has driven the monster away! But it crumbled.. it wont save you again.." << std::endl;
			statueLife = false;
			m_enemyPosX = 0;
			m_enemyPosY = 0;
		}
		else
		{
			std::cout << "You have entered the same room as the monster.. it lunges at you dragging you deep into the temple.. Game Over!" << std::endl;
			exit(1);
		}
	}
	if (chestUsed)
	{
		MoveMonster(); //monster move logic triggers here to move it with the player
	}
	if (m_posX == m_enemyPosX && m_posY == m_enemyPosY && chestUsed)
	{
		//same as above but if the monster moves into you
		if (statueLife)
		{
			std::cout << "The monster has found you! The statue emits a powerful light!" << std::endl;
			std::cout << std::endl;
			std::cout << "The statue has driven the monster away! But it crumbled.. it wont save you again.." << std::endl;
			statueLife = false;
			m_enemyPosX = 0;
			m_enemyPosY = 0;
		}
		else
		{
			std::cout << "The monster has found you.. you try to run but it is too late.. Game Over!" << std::endl;
			exit(1);
		}
	}
	if ((m_posX == m_enemyPosX||m_posX == m_enemyPosX -1 || m_posX == m_enemyPosX + 1) && (m_posY == m_enemyPosY || m_posY == m_enemyPosY - 1 || m_posY == m_enemyPosY + 1))
	{
		inDanger = true; //sets up the logic to tell if the monster is within one room of you to warn you
	}
	else
	{
		inDanger = false;
	}
	//draws map based on number of columns and rows
	std::cout << "\n\n----------------------------------------\n\n";
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			std::cout << "| ";
			if (i == m_posY && j == m_posX)
			{
				//player position
				std::cout << "X";
			}
			//else if (i == m_enemyPosY && j == m_enemyPosX && chestUsed) //enemy
			//{
			//	//std::cout << "O";   // enemy map indicator (to be removed)
			//}
			else
			{
				std::cout << "-";
			}

			std::cout << " |";

		}

		std::cout << std::endl << "\n";
	}

	std::cout << "\n\n----------------------------------------\n";
	if (inDanger) //triggers if you are within a room of the monster
	{
		std::cout << "You hear loud growing outside the room.. its very close now.." << std::endl;
	}
}


void Game::tryToMove(char c)
{

	switch (c)  //These check if there is room on the grid for the player to move
		// must be within the walls of the generated room.
	{
	case 'u': //moves up
		if (m_posY >= 1)
		{
			if(m_posX == 4 && m_posY == 1)
			{
				//triggers on a specific locked room
				if (hasSpell == true)
				{
					std::cout << "The power you got from the potion has broken the seal! You move up!" << std::endl;
					m_posY--;
				}
				else
				{
					std::cout << "The door has a seal on it.. maybe it can be broken with a certain magical power?" << std::endl;
				}
			}
			else
			{
				m_posY--;
				std::cout << "You moved up!" << std::endl;
			}
		}
		else
		{
			std::cout << "There was nowhere to go! Please try again." << std::endl;
		}
		break;
	case 'd': //moves down
		if (m_posY < m_rows - 1)
		{
			m_posY++;
			std::cout << "You moved down!" << std::endl;
		}
		else
		{
			std::cout << "There was nowhere to go! Please try again." << std::endl;
		}
		break;
	case 'l': //moves left
		if (m_posX >= 1)
		{
				m_posX--;
				std::cout << "You moved left!" << std::endl;
		}
		else
		{
			if (m_posX == 0 && m_posY == 1)
			{
				if (hasKey) //if you have the key you can move left out the exit
				{
					std::cout << "You used the key to unlock the door to your freedom! Congratulations you escaped!" << std::endl;
					system("pause");
					exit(1);
				}
				else //if you dont have the key you cant go left
				{
					std::cout << "You could go through that door if you had the key.." << std::endl;
				}
			}
			else
			{
				std::cout << "There was nowhere to go! Please try again." << std::endl;
			}
		}
		break;
	case 'r': //move right
		if (m_posX < m_columns - 1)
		{
			m_posX++;
			std::cout << "You moved right!" << std::endl;
		}
		else
		{
			std::cout << "There was nowhere to go! Please try again." << std::endl;
		}
		break;
	default:
		std::cout << "There was nowhere to go! Please try again." << std::endl;
		break;
	}
}

void Game::tryToUse(char c) //checking to see if you can use an item in a room, will fail if the room does not contain that item
{
	switch (c)
	{
	case 'p':
	{
		StrangePotion* potion = dynamic_cast<StrangePotion*>(m_rooms[m_posY][m_posX].item);
		if (potion != nullptr)
		{
			potion->Use();
			hasSpell = true;
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}
		break;
	}
	case 'c':
	{
		Chest* chest = dynamic_cast<Chest*>(m_rooms[m_posY][m_posX].item);
		if (chest != nullptr)
		{
			chest->Use();
			chestUsed = true; //monster is active
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}

		break;
	}
	case 'f':
	{
		Figure* figure = dynamic_cast<Figure*>(m_rooms[m_posY][m_posX].item);
		if (figure != nullptr)
		{
			figure->Use();
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}

		break;
	}
	case 'k':
	{
		Key* key = dynamic_cast<Key*>(m_rooms[m_posY][m_posX].item);
		if (key != nullptr)
		{
			key->Use();
			hasKey = true;
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}

		break;
	}
	default:
		std::cout << "There was nothing in this room to use.." << std::endl;
		break;
	}
}

void Game::tryToInspect(char c) //inspects the room for an item, will fail if the room does not have that item
{
	switch (c)
	{
	case 'p':
	{
		StrangePotion* potion = dynamic_cast<StrangePotion*>(m_rooms[m_posY][m_posX].item);
		if (potion != nullptr)
		{
			potion->Description();
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}
		break;
	}
	case 'c':
	{
		Chest* chest = dynamic_cast<Chest*>(m_rooms[m_posY][m_posX].item);
		if (chest != nullptr)
		{
			chest->Description();
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}
		break;
	}
	case 'f':
	{
		Figure* figure = dynamic_cast<Figure*>(m_rooms[m_posY][m_posX].item);
		if (figure != nullptr)
		{
			figure->Description();
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}
		break;
	}
	case 'k':
	{
		Key* key = dynamic_cast<Key*>(m_rooms[m_posY][m_posX].item);
		if (key != nullptr)
		{
			key->Description();
		}
		else
		{
			std::cout << "That item isnt in this room.." << std::endl;
		}
		break;
	}
	default:
		std::cout << "There was nothing in this room to look at.." << std::endl;
		break;
	}
}

void Game::MoveMonster()
{
	//resets the location bools then sets them again the the below statements to find out which directions it can move
	onTop = false;
	onBot = false;
	onRight = false;
	onLeft = false;

	if ((m_enemyPosX == 0 && m_enemyPosY == 0) || (m_enemyPosX == 4 && m_enemyPosY == 0) || (m_enemyPosX == 0 && m_enemyPosY == 4) || (m_enemyPosX == 4 && m_enemyPosY == 4))
	{  // monster is in the corner so it can only move depending on which corner it is in
		if (m_enemyPosX == 0)
		{
			onLeft = true;
			onRight = false;
		}
		else if (m_enemyPosX == 4)
		{
			onRight = true;
			onLeft = false;
		}

		if (m_enemyPosY == 0)
		{
			onTop = true;
			onBot = false;
		}
		else if (m_enemyPosY == 4)
		{
			onBot = true;
			onTop = false;
		}
	}
	//monster is on the far left or far right
	else if ((m_enemyPosX == 0) || (m_enemyPosX == 4))
	{  //on far left or far right, move accordingly
		if (m_enemyPosX == 0)
		{
			onLeft = true;
			onRight = false;
			onTop = false;
			onBot = false;
		}
		else if (m_enemyPosX == 4)
		{
			onRight = true;
			onLeft = false;
			onTop = false;
			onBot = false;
		}
	}
	//monster is on the top or bottom
	else if ((m_enemyPosY == 0) || (m_enemyPosY == 4))
	{ //on top or bottom
		if (m_enemyPosY == 0)
		{
			onTop = true;
			onBot = false;
			onRight = false;
			onLeft = false;
		}
		else if (m_enemyPosY == 4)
		{
			onBot = true;
			onTop = false;
			onRight = false;
			onLeft = false;
		}
	}

	//movement logic for the monster

	if (onLeft && onTop) // at pos 0 0 (top left)
	{
		//moves right or down on a random value
		int move = rand() % 1 + 1;

		if (move == 1)
		{
			m_enemyPosX++;
		}
		else
		{
			m_enemyPosY++;
		}
	}
	else if (onRight && onTop) // at 4 0 (top right)
	{
		//moves left or down on a random value
		int move = rand() % 1 + 1;

		if (move == 1)
		{
			m_enemyPosX--;
		}
		else
		{
			m_enemyPosY++;
		}
	}
	else if (onLeft && onBot) // at 0 4 (bottom left)
	{
		//moves up or right on a random value
		int move = rand() % 1 + 1;

		if (move == 1)
		{
			m_enemyPosX++;
		}
		else
		{
			m_enemyPosY--;
		}
	}
	else if (onRight && onBot) //at 4 4 (bottom right)
	{
		// moves left or up on a random value
		int move = rand() % 1 + 1;

		if (move == 1)
		{
			m_enemyPosX--;
		}
		else
		{
			m_enemyPosY--;
		}
	}
	else if (onLeft)
	{ //moves right up or down on a random value
		int move = rand() % 2 + 1;

		if (move == 1)
		{
			m_enemyPosX++;
		}
		else if (move == 2)
		{
			m_enemyPosY++;
		}
		else
		{
			m_enemyPosY--;
		}
	}
	else if (onRight)
	{// moves left up or down on a random value
		int move = rand() % 2 + 1;

		if (move == 1)
		{
			m_enemyPosX--;
		}
		else if (move == 2)
		{
			m_enemyPosY++;
		}
		else
		{
			m_enemyPosY--;
		}
	}
	else if (onTop)
	{// moves down left or right on a random value
		int move = rand() % 2 + 1;

		if (move == 1)
		{
			m_enemyPosX++;
		}
		else if (move == 2)
		{
			m_enemyPosY++;
		}
		else
		{
			m_enemyPosX--;
		}
	}
	else if (onBot)
	{//moves up left or right on a random value
		int move = rand() % 2 + 1;

		if (move == 1)
		{
			m_enemyPosX++;
		}
		else if (move == 2)
		{
			m_enemyPosY--;
		}
		else
		{
			m_enemyPosX--;
		}
	}
	else // goes here if it is not on any edges of the map
	{//moves up down left or right on a random value
		int move = rand() % 3 + 1;

		if (move == 1)
		{
			m_enemyPosX++;
		}
		else if (move == 2)
		{
			m_enemyPosY++;
		}
		else if (move == 3)
		{
			m_enemyPosX--;
		}
		else
		{
			m_enemyPosY--;
		}
	}
}

