#include "Room.h"
#include "StrangePotion.h"
#include "Figure.h"
#include "Chest.h"
#include "Key.h"
#include "CustomString.h"

Room::Room()
{
	item = nullptr;
	m_description = nullptr;
}

Room::~Room()
{
	delete item;
	delete m_description;
}

void Room::SetUp(int i)
{
	switch (i)
	{
	case 0: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. sounds like wind whistling somewhere nearby..");
		break;
	case 1: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. vines cover every wall..");
		break;
	case 2: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. you feel uneasy.. proceed with caution..");
		break;
	case 3: //Trap room
		this->item = new Key();
		this->m_description = new CustomString("The floor of this room collapsed beneath you and you have fallen into the dark void below.. Game Over!");
		break;
	case 4: //Key
		this->item = new Key();
		this->m_description = new CustomString("The room is extremely dark and dusty, on the floor is a small piece of cloth with a key* on it..");
		break;
	case 5: //Escape
		this->item = nullptr;
		this->m_description = new CustomString("There is a large door on the left in this room, it looks like the way out.. but its locked..");
		break;
	case 6: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room empty.. you can hear a strange noise like something shifting.. better be on guard");
		break;
	case 7: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, there is a chill in the air, must be something cold closeby..");
		break;
	case 8: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. something doesn't feel right.. be careful..");
		break;
	case 9: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, the door above you has a seal on it.. maybe a spell could remove it?");
		break;
	case 10: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. you feel paranoid.. could it be in your head? Be careful..");
		break;
	case 11: //Trap Room
		this->item = nullptr;
		this->m_description = new CustomString("The door has vanished behind you and the room starts to get smaller.. you are lost in the temple forever.. Game Over!");
		break;
	case 12: //Chest
		this->item = new Chest();
		this->m_description = new CustomString("The room is cold, a lone chest* waits in the center.. it seems to be drawing you in..");
		break;
	case 13: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, better keep moving..");
		break;
	case 14: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. much like your stomach.. should have packed a snack..");
		break;
	case 15: //Potion 
		this->item = new StrangePotion();
		this->m_description = new CustomString("The room contains a lone desk with a strange potion* sitting in the center..");
		break;
	case 16: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty.. it has an uncomfortable feel to it.. watch your step..");
		break;
	case 17: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, it looks like the roof could colapse any moment");
		break;
	case 18: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, there are claw marks on the walls.. were these done recently?");
		break;
	case 19: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, there are webs everywhere..");
		break;
	case 20: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, a sticky substance oozes from the walls.. what is it?");
		break;
	case 21: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, a red liquid is on the floor leading further in.. could it be?..");
		break;
	case 22: //Start Point
		this->item = nullptr;
		this->m_description = new CustomString("This room is the enterance.. the door has vanished behind you.. nowhere to go but deeper..");
		break;
	case 23: //EmptyRoom
		this->item = nullptr;
		this->m_description = new CustomString("The room is empty, torches line the walls so you can see just how empty it is");
		break;
	case 24: //Figure
		this->item = new Figure();
		this->m_description = new CustomString("A strange light is emitting from the ceiling of this room, it is pointing at a mysterious stone figure*.. it feels confortable in here..");
		break;

	default: //Shouldnt be here
		this->item = nullptr;
		this->m_description = new CustomString("You have transcended the mortal plane.. how did you do that? (out of bounds)");
		break;
	}
}

void Room::Description()const
{
	m_description->WriteConsole();
}