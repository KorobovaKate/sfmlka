#pragma once
#include <string>
#include <PlayerProgress.h>
#include <vector>

class PlayerList
{
public:
	void AddPlayer(std::string name);
	std::vector<PlayerProgress> GetAllPlayerProgress();
};


extern PlayerList CurrentPlayerList;
