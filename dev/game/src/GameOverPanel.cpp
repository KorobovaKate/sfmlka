#include "GameOverPanel.h"
#include <PlayerList.h>
#include <Game.h>
#include <SceneList.h>


void GameOverPanel::Start()
{
	std::string result = "";
	std::vector<PlayerProgress> players = CurrentPlayerList.GetAllPlayerProgress();
	for (int i = 0; i < players.size(); i++)
	{
		result += players[i].Name + ":   " + std::to_string(players[i].Score) + "\n";
	}

	TextRenderer* textRenderer = gameObject->GetComponent<TextRenderer>();
	textRenderer->textObject->setString(result);
}

void GameOverPanel::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) 
	{
		CurrentPlayerProgress.CurrentLevel = 1;
		LoadScene(CreateSceneByNumber(1));
	}
}
