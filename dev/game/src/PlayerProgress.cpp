#include <PlayerProgress.h>

PlayerProgress CurrentPlayerProgress;


bool PlayerProgress::ReadFromFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName + ".txt");
	if (file.is_open() == false)
	{
		std::cout << "не удалось открыть файл" << std::endl;
		return false;
	}
	file >> Name;
	file >> Score;
	file >> CurrentLevel;
	file.close();
	return true;
}

bool PlayerProgress::WriteToFile()
{
	std::ofstream file; //создаю переменную "указывающюю" на файл
	file.open(Name + ".txt");
	if (file.is_open() == false)
		return false;

	file << Name << std::endl;
	file << Score << std::endl;
	file << CurrentLevel << std::endl;
	file.close();
	return true;
}
