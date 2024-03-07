#include "CustomString.h"
#include <iostream>

CustomString::CustomString()    // Default 
{
	m_string = new char[1];
	m_string[0] = '\0';
}

CustomString::CustomString(const CustomString& other) //Copy constructor
{
	m_string = new char[strlen(other.m_string) + 1];
	strcpy_s(m_string, (strlen(other.m_string)) + 1, other.m_string);
}

CustomString::CustomString(CustomString&& other)
{
	m_string = other.m_string;
	other.m_string = nullptr;
}

CustomString::CustomString(const char* c)      //Allocating the space for the string
{
	m_string = new char[strlen(c)+1];          //Sets m_string to the size of c +1

	strcpy_s(m_string, (strlen(c)) + 1, c);    //Fills the data in m_string to the same as c
};


int CustomString::Length() 
{
	return strlen(m_string);                   // Gets the Length of m_string
}

char CustomString::CharacterAt(int index)      //Finds the character that is at "index"
{
	if (index < 0 || index > Length())
	{
		return '\0';                           //Returns null if the value is 0 or too high
	}
	else
	{
		return m_string[index];                //Returns the char in string at the index
	}
}

const char* CustomString::CStr() const         //Prints m_string to the console
{
	return m_string;
}

void CustomString::Append(const CustomString& other)    //This Appends to the end of the string
{

	int newCapacity = Length() + strlen(other.m_string) + 1;

	char* toFill = new char[newCapacity];

	strcpy_s(toFill, newCapacity, m_string);             

	strcat_s(toFill, newCapacity, other.m_string);

	delete[] m_string;
	m_string = toFill;

}


void CustomString::Preppend(const CustomString& other)   //This prepends to the start of the string
{

	int newCapacity = Length() + strlen(other.m_string) + 1;

	char* toFill = new char[newCapacity];

	strcpy_s(toFill, newCapacity, other.m_string);             

	strcat_s(toFill, newCapacity, m_string);

	delete[] m_string;
	m_string = toFill;

}

void CustomString::ToUpper()    //This turns m_string into uppercase
{
	for (int i = 0; i < Length(); i++)
	{
		m_string[i] = toupper(m_string[i]);
	}
}

void CustomString::ToLower()  //This turns m_string into Lowercase
{
	for (int i = 0; i < Length(); i++)
	{
		m_string[i] = tolower(m_string[i]);
	}
}

bool CustomString::EqualTo(const CustomString& other)    //this checks if m_string is the same as the entered substring
{
	if (strcmp(m_string, other.m_string) == 0) 
	{
		return true;
	}
	else
	{	
		return false;
	}
}

int CustomString::Find(const CustomString& other)                    //Find function returns the array index where the chars in other start
{

	int searchLength = strlen(other.m_string);

	for (int i = 0; i <=  strlen(m_string) - searchLength; i++) 
	{
		bool numberMatch = true;

		for (int j = 0; j < searchLength; j++) 
		{
			if (m_string[i + j] != other.m_string[j]) 
			{
				numberMatch = false;
			}
		}

		if (numberMatch)                   //this only works if the above for loop finds the right characters in order
		{
			return i;                      // returns i which is the location in the array where the substring starts
		}
	}

	return -1;
	
}


int CustomString::FindStartPoint(const CustomString& other, int startPoint) //This searches for the substring again but starting from the input array position in startingPoint
{
	int startingPoint = startPoint;
	int searchLength = strlen(other.m_string);

	//what happens when other is longer than m_string
	if (strlen(m_string) >= strlen(other.m_string)) 
	{
		for (int i = startPoint; i <= strlen(m_string) - searchLength; i++)
		{
			bool numberMatch = true;

			for (int j = 0; j < searchLength; j++)
			{
				if (m_string[i + j] != other.m_string[j])
				{
					numberMatch = false;
				}
			}

			if (numberMatch)                   //this only works if the above for loop finds the right characters in order
			{
				return i;
			}
		}
	} //if other string is longer, return -1;

	return -1;
}

void CustomString::StartFind(const CustomString& other) // dont think this is needed, this may be a remnant from testing something but it searches and returns the substring
{
	char* newString = new char[strlen(other.m_string) + 1];
	newString[strlen(other.m_string)] = '\0';
	int count = 0;
	int indexing = 0;

	for (int i = 0; i < strlen(other.m_string); i++)
	{
		for (int b = indexing; b <= strlen(m_string); b++)
		{
			if (other.m_string[i] == m_string[b])
			{
				newString[count] = other.m_string[i];
				count++;
				i++;
				indexing = b;
				if(strcmp(newString, other.m_string) == 0)
				{
					std::cout << "The substring is: " << newString << std::endl;
					return;
				}
				else
				{
				
				}
			}
			else
			{
				for (int c = 0; c < strlen(newString); c++)
				{
					int current = 0;
					newString[current] = ' ';
					current++;
				}
			} 

			if (b >= Length())
			{
				std::cout << "There was no substring in this string." << std::endl;
				return;
			}

		}
	}
	delete[] newString;
}

void CustomString::FindReplaceSingle(const CustomString& other) //This looks through the string and changes all characters in searchFor with the character in replaceWith
{
	char replaceWith = 'i';
	char searchFor = 'o';

	for (int i = 0; i < Length(); i++)
	{
		if (m_string[i] == searchFor)
		{
			m_string[i] = replaceWith;
		}
	}
}


void CustomString::FindReplaceChar(const CustomString& toSearch, const CustomString& replaceWith) //This searches through the string for the chars entered in "toSearch" and replaces all instances of them with "toReplace"
{
	bool isTrue = true;

	int startSearchFrom = 0;

	while (isTrue)                                     //as long as the word isnt finished being looked through this will continue looping
	{		
		

		if(FindStartPoint(toSearch.m_string,startSearchFrom) != -1)
		{
			
			char* temp1 = new char[FindStartPoint(toSearch.m_string, startSearchFrom) + 1];       //creating temporary containers for parts of the string
			temp1[FindStartPoint(toSearch.m_string, startSearchFrom)] = '\0';
			
			for (int i = 0; i < FindStartPoint(toSearch.m_string, startSearchFrom); i++) //runs through everything before the string was found
			{
				//This puts the string into temp1!
				temp1[i] = m_string[i];
			}
			//temp1 full


			char* temp2 = new char[strlen(m_string) - strlen(toSearch.m_string) - strlen(temp1) + 1];
			temp2[strlen(m_string) - strlen(toSearch.m_string) - strlen(temp1)] = '\0';

			int startingPoint = FindStartPoint(toSearch.m_string, startSearchFrom) + strlen(toSearch.m_string);
			int tempValue2 = 0;
			for (int j = startingPoint; j < strlen(m_string); j++)          //temp2 holds the rest of the word
			{
				temp2[tempValue2] = m_string[j];
				tempValue2++;
			}
			//temp2 full

			int storage = strlen(temp1) + strlen(replaceWith.m_string) + strlen(temp2) + 1;
			char* newWord = new char[storage];
			


			strcpy_s(newWord, storage, temp1);            //putting temp1 - toReplace - temp2  together in that order
			strcat_s(newWord, storage, replaceWith.m_string);
			strcat_s(newWord, storage, temp2);

			


			delete[] m_string;
			m_string = newWord;
			
			startSearchFrom = strlen(temp1) + strlen(replaceWith.m_string);     //this starts the next loop from the point after toReplace was inserted so it doesnt check it again
			

			if(Find(toSearch) == -1)                                   //this i am not sure if its needed, will have to investigate that
			{
				//std::cout << "New string is: " << newWord << std::endl;  //This is in-fact printing to the console when its done, just gonna cc it for now
			}
			
			delete[] temp1;
			delete[] temp2;
		}
		else                // this will make the loop end when the word length has been reached
		{
			isTrue = false;
		}
	}
}

bool CustomString::operator==(CustomString& other)  //checking if m_string is equal to other.m_string if not it returns false
{
	if(strcmp(m_string, other.m_string) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char CustomString::operator[](int charAt)     //Checks for which character is at a specific point in the array, I am not sure how to get the std::couts out of here as i wanted to have
                                              //it say "out of range" when it was past the array size but maybe that isnt needed
{
	if (charAt >= strlen(m_string)|| charAt < 0)
	{
		std::cout << "Char at index " << charAt << " is out of range..";
	}
	else
	{
		std::cout << "Char at index " << charAt << " is: " << m_string[charAt];
	}
	
	
	return m_string[charAt];
}

bool CustomString::operator<(CustomString& other)       //checking if m_string is less than other.m_string in alphabetical order, this is case sensitive and will place capital letters
	                                                    //first before lowercase eg. Z is earlier than a
{
	
	if(strcmp(m_string, other.m_string) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

CustomString& CustomString::operator=(CustomString& other)         //this changes the data in m_string to be a deep copy of other.m_string
{
	//A shallow copy would be to make this pointer point to the others data
	//this->m_string = other.m_string (SHALLOW COPY)

	//this->m_string becomes an exact DEEP copy of other.m_string data
	//1.Do we care about our current m_string data?
	//2.Do we need to declare new memory?
	
	
	delete[] m_string;

	m_string = new char[strlen(other.m_string) + 1];
	strcpy_s(m_string, (strlen(other.m_string)) + 1, other.m_string);

	return *this;

	//operator = overload logic
	/*
	1. I want my data to be the data thats inside of other
	2. I want it to be a deep copy
	3. My m_string doesn't matter anymore => delete
	4. Make a new buffer for m_string the size of the other objects buffer
	5. Copy across string from other object into newly created buffer

	End all be all : m_string should be pointing to new data that is identical to other objects data

	*/
	
}

CustomString& CustomString::operator=(CustomString&& other)
{
	delete[] m_string;
	m_string = other.m_string;
	other.m_string = nullptr;

	return *this;
}

void CustomString::ReadConsole()
{
	std::cin.clear();

	std::cin.ignore(std::cin.rdbuf()->in_avail());

	delete[] m_string;

	m_string = new char[50];

	std::cin.get(m_string, 50, '\n');
}

void CustomString::WriteConsole()
{
	std::cout << m_string << std::endl;
}

CustomString::~CustomString()                  //Deletes the allocated "new" space
{
	delete[] m_string;
}

