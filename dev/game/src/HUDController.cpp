#include <HUDController.h>
#include <PlayerProgress.h>
#include <GameObject.h>

void HUDController::Start()
{
	scoreTextRenderer = gameObject->GetComponent<TextRenderer>();
}

void HUDController::Update() //вызывается каждый кадр игры
{
	scoreTextRenderer->textObject->setString("Score:" + std::to_string(CurrentPlayerProgress.Score));
}

HUDController::~HUDController()
{
	delete scoreTextRenderer;
}
