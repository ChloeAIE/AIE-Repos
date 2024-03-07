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



		int numbers[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };

		int r = 0;

		for (int i = 0; i < m_columns; i++)
		{
			m_rooms[i] = new Room[m_columns];
		}

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{//currently have an issue here, it repeats 5 numbers due to column size
				//fix this up tomorrow (Hello todays Chloe o/ do your best!!)
				std::cout << r << std::endl;
				m_rooms[i][j].SetUp(r);
				r++;
			}
		}

		m_posX = 2;
		m_posY = 4;
	
	
}

Game::~Game()
{
	delete m_userInput;
	delete m_player;

	for (int i = 0; i < m_columns; i++)
	{
		delete[] m_rooms[i];
	}
	delete[] m_rooms;
}

void Game::RunGame()
{
	if (escaped)
	{
		// put end game logic here.. if for escaped and if for died
	}
	else
	{
		Player player;

		m_rooms[m_posY][m_posX].Description();

		std::cout << "Please enter a command: Move   /   Use <Item>   /   Inspect <Item>" << std::endl;

		m_userInput->ReadConsole();

		m_userInput->ToLower();

		switch (m_userInput->CharacterAt(0))
		{
		case 'm':
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
		case 'u':
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
		case 'i':
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
			if (m_userInput->Find("spell") != -1)
			{
				std::cout << "Enter a spell to search for: ";
				m_userInput->ReadConsole();
				m_userInput->ToLower();
				if (player.FindSpell(*m_userInput) == true) //QOL changes here tomorrow~!
				{
					std::cout << "Spell: " << m_userInput->CStr() << " has been found!" << std::endl;
				}
				else
				{
					std::cout << "Spell: " << m_userInput->CStr() << " has not been found.." << std::endl;
				}
			}
		default:
			std::cout << "Not sure what you were trying to do there sorry!" << std::endl;
			break;
		}

		system("pause");
	}
}

void Game::DrawMap()
{
	system("cls");
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
			else
			{
				std::cout << "-";
			}

			std::cout << " |";

		}

		std::cout << std::endl << "\n";
	}

	std::cout << "\n\n----------------------------------------\n\n";
}

void Game::tryToMove(char c)
{
	switch (c)  //These check if there is room on the grid for the player to move
		// must be within the walls of the generated room.
	{
	case 'u':
		if (m_posY >= 1)
		{
			if(m_posX == 4 && m_posY == 1)
			{
				
				if (hasSpell == true)
				{
					std::cout << "The power you got from the potion has broken the seal! You move up!" << std::endl;
					m_posY--;
				}
				else
				{
					std::cout << "The door has a seal on it.. maybe it can be broken with a spell?" << std::endl;
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
	case 'd':
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
	case 'l':
		if (m_posX >= 1)
		{
				m_posX--;
				std::cout << "You moved left!" << std::endl;
		}
		else
		{
			if (m_posX == 0 && m_posY == 1)
			{
				if (hasKey)
				{
					std::cout << "You used the key to unlock the door to your freedom! Congratulations you escaped!" << std::endl;
					escaped = true;
				}
				else
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
	case 'r':
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

void Game::tryToUse(char c)
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

void Game::tryToInspect(char c)
{
	switch (c)
	{
	case 's':
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
