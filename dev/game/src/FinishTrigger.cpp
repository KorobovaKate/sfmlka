#include <FinishTrigger.h>
#include <Game.h>
#include <SceneList.h>
#include <PlayerProgress.h>

FinishTrigger::FinishTrigger(int nextScene)
{
	nextNumberScene = nextScene;
}

void FinishTrigger::OnCollision(RectCollider* other)
{
	if (other->gameObject->tag == "Player")
	{
		LoadScene(CreateSceneByNumber(nextNumberScene));

		CurrentPlayerProgress.Score += 50;
		CurrentPlayerProgress.CurrentLevel = nextNumberScene;

		CurrentPlayerProgress.WriteToFile();

		
	}
}