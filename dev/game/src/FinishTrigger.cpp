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
		if (nextNumberScene == -1)
		{
			LoadScene(CreateGameOver());
			CurrentPlayerProgress.CurrentLevel = 1;
		}
		else
		{
			LoadScene(CreateSceneByNumber(nextNumberScene));
			CurrentPlayerProgress.CurrentLevel = nextNumberScene;
		}
		
		CurrentPlayerProgress.Score += 50;
		CurrentPlayerProgress.WriteToFile();
	}
}