#include <HUDController.h>
#include <PlayerProgress.h>
#include <GameObject.h>
#include <PlayerList.h>
//Для отображения информации на экране

HUDController::HUDController(TextRenderer* scoreTextRenderer, TextRenderer* levelTextRenderer)
{
	this->scoreTextRenderer = scoreTextRenderer;
	this->levelTextRenderer = levelTextRenderer;
}

void HUDController::Start()
{
}

void HUDController::Update() //вызывается каждый кадр игры
{
	scoreTextRenderer->textObject->setString("Score:" + std::to_string(CurrentPlayerProgress.Score));
	levelTextRenderer->textObject->setString("Level:" + std::to_string(CurrentPlayerProgress.CurrentLevel));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		CurrentPlayerList.GetAllPlayerProgress();
	}
}

HUDController::~HUDController()
{
	delete scoreTextRenderer;
	delete levelTextRenderer;
}
