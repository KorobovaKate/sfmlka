#include <SFML/Graphics.hpp>
#include <Game.h>

#include <components/Behaviour.h>
#include <components/RectCollider.h>

#include <prefabs.h>
#include <SceneList.h>


int main()
{
	Game* game = new Game({ 800, 600 }, "RedBall");

	game->StartGame(CreateSceneByNumber(2));
}
