#include <PlayerMovement.h>
#include <Game.h>
#include <PlayerProgress.h>


void PlayerMovement::OnCollision(RectCollider* other)
{
	if (other->gameObject->tag == "Enemy")
	{
		std::cout << gameObject->getPosition().y - other->gameObject->getPosition().y << std::endl;
		if (gameObject->getPosition().y - other->gameObject->getPosition().y < -55)
		{
			//other->gameObject->GetComponent<RectCollider>()->enabled = false;
			//other->gameObject->GetComponent<SpriteRenderer>()->enabled = false;
			gameObject->scene->RemoveObject(other->gameObject);
			CurrentPlayerProgress.Score += 15;
			CurrentPlayerProgress.WriteToFile();
		}
		else
		{
			isRespawned = true;
			gameObject->GetComponent<RectCollider>()->enabled = false;
			gameObject->GetComponent<SpriteRenderer>()->enabled = false;
			CurrentPlayerProgress.Score -= 20;
			//gameObject->setPosition(startPosition);
			//gameObject->GetComponent<RectCollider>()->SyncTransform(); //без этой строчки события onCollision срабатывает дважды
		}
	}
	else if (other->gameObject->tag == "Spikes")
	{
		isRespawned = true;
		gameObject->GetComponent<RectCollider>()->enabled = false;
		gameObject->GetComponent<SpriteRenderer>()->enabled = false;
		CurrentPlayerProgress.Score -= 5;
	}
	
}

void PlayerMovement::Update() //вызывается каждый кадр игры
{
	if (isRespawned == true)
	{
		respawnTimer += Game::deltaTime;
		if (respawnTimer > 0.5)
		{
			gameObject->GetComponent<RectCollider>()->enabled = true;
			gameObject->GetComponent<SpriteRenderer>()->enabled = true;
			gameObject->setPosition(startPosition);
			gameObject->GetComponent<RectCollider>()->SyncTransform(); //без этой строчки события onCollision срабатывает дважды
			isRespawned = false;
			respawnTimer = 0;
		}
		return;
	}

	//падение
	if (gameObject->getPosition().y > 1900)
	{
		isRespawned = true;
		gameObject->GetComponent<RectCollider>()->enabled = false;
		gameObject->GetComponent<SpriteRenderer>()->enabled = false;
		CurrentPlayerProgress.Score -= 40;
	}


	//гравитация
	speed.y = speed.y + 20;
	sf::FloatRect rectBottom(gameObject->getPosition().x - 10, gameObject->getPosition().y + 31, 20, 1);
	if (gameObject->scene->BoxCast(rectBottom) == 1)
	{
		speed.y = 0;
	}

	//гравитация при столкновении
	FloatRect rectTop(gameObject->getPosition().x - 10, gameObject->getPosition().y - 31, 20, 1);
	if (gameObject->scene->BoxCast(rectTop) == 1)
	{
		speed.y = 50;
	}

	//прыжок
	if (speed.y == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		speed.y = -jumpSpeed;
	}

	//движение вправо
	speed.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		FloatRect rectBottom(gameObject->getPosition().x + 28, gameObject->getPosition().y - 20, 1, 40);
		if (gameObject->scene->BoxCast(rectBottom) == 0)
		{
			speed.x = movementSpeed;
		}

	}

	//движение влево
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		FloatRect rectBottom(gameObject->getPosition().x - 30, gameObject->getPosition().y - 20, 1, 40);
		if (gameObject->scene->BoxCast(rectBottom) == 0)
		{
			speed.x = -movementSpeed;
		}
	}

	//движение/вращение/камера
	gameObject->setPosition(gameObject->getPosition() + speed * Game::deltaTime);
	gameObject->GetComponent<SpriteRenderer>()->sprite.rotate(speed.x * Game::deltaTime * rotationSpeedFactor);
	Game::mainCamera->setCenter(gameObject->getPosition());

}

