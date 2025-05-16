#pragma once
#include <SFML/System/Vector2.hpp>
#include <components/Behaviour.h>
#include <iostream>
#include <fstream>

class PlayerProgress
{
public:
	std::string Name;
	int Score;
	int CurrentLevel;
	bool ReadFromFile(std::string fileName);
	bool WriteToFile();
};


extern PlayerProgress CurrentPlayerProgress;