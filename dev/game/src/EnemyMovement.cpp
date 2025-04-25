#include <EnemyMovement.h>
#include <Game.h>

EnemyMovement::EnemyMovement(float movementSpeed, sf::Vector2f movementPoint1, sf::Vector2f movementPoint2)
{
	this->movementSpeed = movementSpeed;
	this->movementPoint1 = movementPoint1;
	this->movementPoint2 = movementPoint2;
	this->movementTarget = movementPoint1;
}

sf::Vector2f MoveTowards(sf::Vector2f current, sf::Vector2f target, float maxDistanceDelta)
{
	sf::Vector2f moveStep = target - current;
	float distance = sqrt(moveStep.x * moveStep.x + moveStep.y + moveStep.y);
	if (maxDistanceDelta < distance)
	{
		moveStep.x = moveStep.x / distance * maxDistanceDelta;
		moveStep.y = moveStep.y / distance * maxDistanceDelta;
		return current + moveStep;
	}
	else
	{
		return target;
	}
}

void EnemyMovement::Update() //вызывается каждый кадр игры
{
	if (gameObject->getPosition() == movementTarget)
	{
		if (movementTarget == movementPoint1)
		{
			movementTarget = movementPoint2;
		}
		else
		{
			movementTarget = movementPoint1;
		}
	}
	gameObject->setPosition(  MoveTowards(gameObject->getPosition(), movementTarget, movementSpeed * Game::deltaTime)  );
}