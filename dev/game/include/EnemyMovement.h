#pragma once
#include <SFML/System/Vector2.hpp>
#include <components/Behaviour.h>

class EnemyMovement : public Behaviour
{
public:
	EnemyMovement(float movementSpeed, sf::Vector2f movementPoint1, sf::Vector2f movementPoint2);
	void Update(); //вызывается каждый кадр игры
private:
	float movementSpeed;
	float rotationSpeed;
	sf::Vector2f movementTarget;
	float rotationSpeedFactor = 2;
	sf::Vector2f movementPoint1;
	sf::Vector2f movementPoint2;
};