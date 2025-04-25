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
	bool ReadFromFile(std::string fileName)
	{
		std::ifstream file;
		file.open(fileName + ".txt");
		if (file.is_open() == false)
		{
			std::cout << "�� ������� ������� ����" << std::endl;
			return false;
		}
		file >> Name;
		file >> Score;
		file.close();
		return true;
	}
	bool WriteToFile()
	{
		std::ofstream file; //������ ���������� "�����������" �� ����
		file.open(Name + ".txt");
		if (file.is_open() == false)
			return false;

		file << Name << " " << Score;
		file.close();
		return true;
	}
};


extern PlayerProgress CurrentPlayerProgress;