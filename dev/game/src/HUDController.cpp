#include <HUDController.h>
#include <PlayerProgress.h>
#include <GameObject.h>
#include <PlayerList.h>
//��� ����������� ���������� �� ������

HUDController::HUDController(TextRenderer* scoreTextRenderer, TextRenderer* levelTextRenderer)
{
	this->scoreTextRenderer = scoreTextRenderer;
	this->levelTextRenderer = levelTextRenderer;
}

void HUDController::Start()
{
}

void HUDController::Update() //���������� ������ ���� ����
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
