#pragma once
#include <iostream>
#include <ctime>
#include <string>
class DeckCreator
{
public:
	void DeckCreation(int c[], std::string a[]);
	std::string FaceCard(int a);
	void ReadArray(std::string c[], int v[]);
	int ChooseSuit(int cardNum);
};

