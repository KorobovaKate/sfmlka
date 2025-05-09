#include <SFML/System/Vector2.hpp>
#include <components/Behaviour.h>

class PlayerMovement : public Behaviour
{
public:
	void Update(); //вызывается каждый кадр игры
	void Died(int score);
	void OnCollision(RectCollider* other);
	sf::Vector2f startPosition;
private:
	sf::Vector2f speed;
	float rotationSpeedFactor = 2;
	float movementSpeed = 300;
	float rotationSpeed = 600;
	float jumpSpeed = 750;
	bool isRespawned = false;
	float respawnTimer = 0;
};