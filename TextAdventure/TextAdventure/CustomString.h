#pragma once
class CustomString
{
public:
	CustomString();
	CustomString(const char* c);
	CustomString(const CustomString& other);
	CustomString(CustomString&& other);

	~CustomString();

public:

	int Length();

	char CharacterAt(int index);
	const char* CStr() const;
	void Append(const CustomString& other);
	void Preppend(const CustomString& other);
	bool EqualTo(const CustomString& other);
	
	int Find(const CustomString& other);
	int FindStartPoint(const CustomString& other, int startPoint);
	void StartFind(const CustomString& other);
	void FindReplaceSingle(const CustomString& other);
	void FindReplaceChar(const CustomString& toSearch, const CustomString& replaceWith);

	void WriteConsole();
	void ReadConsole();

	void ToUpper();
	void ToLower();

	bool operator==(CustomString& other);
	char operator[](int charAt);
	bool operator< (CustomString& other);
	CustomString& operator= (CustomString& other);
	CustomString& operator= (CustomString&& other);

private:
	char* m_string;
};

