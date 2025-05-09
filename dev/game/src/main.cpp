#include <SFML/Graphics.hpp>
#include <Game.h>

#include <components/Behaviour.h>
#include <components/RectCollider.h>

#include <prefabs.h>
#include <SceneList.h>
#include <PlayerProgress.h>
#include <locale.h>


int main()
{
	setlocale(0, "RUS");
	std::string playerName;
	std::cout << "Добро пожаловать в игру! ";
	std::cout << "Введите ваше имя: ";
	//std::cin >> playerName;
	playerName = "Kate";
	
	if (CurrentPlayerProgress.ReadFromFile(playerName) == false)
	{
		std::cout << "Такой игрок не найден" << std::endl;
		CurrentPlayerProgress.Name = playerName;
		CurrentPlayerProgress.Score = 0;
		CurrentPlayerProgress.WriteToFile();
	}


	std::cout<< CurrentPlayerProgress.Name;
	std::cout<< CurrentPlayerProgress.Score;

	Game* game = new Game({ 800, 600 }, "RedBall");
	game->StartGame(CreateSceneByNumber(1));

	
}
