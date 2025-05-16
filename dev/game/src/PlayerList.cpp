#include <PlayerList.h>

void PlayerList::AddPlayer(std::string name)
{
	std::ofstream file; //создаю переменную "указывающюю" на файл
	file.open("PlayerList.txt", std::ios_base::app);
	if (file.is_open() == false)
		return;

	file << std::endl << name;
	file.close();
}

std::vector<PlayerProgress> PlayerList::GetAllPlayerProgress()
{
	std::vector<PlayerProgress> players;
	std::ifstream file;
	file.open("PlayerList.txt");
	if (file.is_open() == false)
	{
		std::cout << "не удалось открыть файл" << std::endl;
		return std::vector<PlayerProgress>();
	}
	while (file.eof() == false)
	{
		std::string name;
		file >> name;
		PlayerProgress p;
		p.ReadFromFile(name);
		players.push_back(p);

		//std::cout << name << std::endl;
	}
	file.close();
	return players;
}
PlayerList CurrentPlayerList;