#include <prefabs.h>
#include <PlayerMovement.h>
#include <FinishTrigger.h>
#include <EnemyMovement.h>
#include <HUDController.h>


GameObject* GetPlayer(sf::Vector2f position)
{
	GameObject* player = new GameObject("Player");
	player->tag = "Player";
	player->AddComponent(new PlayerMovement());
	player->AddComponent(new SpriteRenderer("resources\\sprites\\hero.png"));
	player->AddComponent(new RectCollider(sf::FloatRect(4, 4, 56, 56)));
	player->setOrigin(32, 32);
	player->GetComponent<PlayerMovement>()->startPosition = position;
	player->setPosition(position);

	return player;
}

GameObject* GetBox(sf::Vector2f position)
{
	GameObject* box = new GameObject("Box");
	box->AddComponent(new SpriteRenderer("resources\\sprites\\box.png"));
	box->AddComponent(new RectCollider(sf::FloatRect(2, 3, 176, 169)));
	box->setPosition(position);

	return box;
}

GameObject* GetFinishFlag(sf::Vector2f position, int nextLevel)
{
	GameObject* flag = new GameObject("Flag");
	flag->AddComponent(new SpriteRenderer("resources\\sprites\\flag.png"));
	flag->AddComponent(new RectCollider(sf::FloatRect(42, 3, 4, 95)));
	flag->AddComponent(new FinishTrigger(nextLevel));
	flag->setPosition(position);

	return flag;
}

GameObject* GetGround1(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_1.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(27, 130, 539, 548)));
	ground->AddComponent(new RectCollider(sf::FloatRect(567, 389, 1150, 290)));
	ground->AddComponent(new RectCollider(sf::FloatRect(1717, 553, 648, 126)));
	ground->AddComponent(new RectCollider(sf::FloatRect(1915, 389, 253, 291)));
	ground->AddComponent(new RectCollider(sf::FloatRect(2366, 390, 1150, 289)));
	ground->AddComponent(new RectCollider(sf::FloatRect(3516, 131, 537, 548)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetGround2(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_2.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(9, 114, 488, 628)));
	ground->AddComponent(new RectCollider(sf::FloatRect(498, 333, 643, 413)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetGround3(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_3.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(20, 96, 654, 138)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetGround4(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_4.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(30, 139, 1572, 361)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetGround5(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_5.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(0, 187, 425, 542)));
	ground->AddComponent(new RectCollider(sf::FloatRect(424, 545, 954, 185)));
	ground->AddComponent(new RectCollider(sf::FloatRect(1378, 107, 661, 622)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetGround6(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_6.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(10, 385, 884, 364)));
	ground->AddComponent(new RectCollider(sf::FloatRect(894, 618, 899, 131)));
	ground->AddComponent(new RectCollider(sf::FloatRect(1794, 102, 245, 647)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetGround7(sf::Vector2f position)
{
	GameObject* ground = new GameObject("Ground");
	ground->AddComponent(new SpriteRenderer("resources\\sprites\\ground_7.png"));
	ground->AddComponent(new RectCollider(sf::FloatRect(34, 116, 599, 533)));
	ground->setPosition(position);

	return ground;
}

GameObject* GetWood1(sf::Vector2f position)
{
	GameObject* wood1 = new GameObject("Wood");
	wood1->AddComponent(new SpriteRenderer("resources\\sprites\\wood.png"));
	wood1->AddComponent(new RectCollider(sf::FloatRect(2, 2, 145, 12)));
	wood1->setPosition(position);

	return wood1;
}

GameObject* GetWood2(sf::Vector2f position)
{
	GameObject* wood2 = new GameObject("Wood");
	wood2->AddComponent(new SpriteRenderer("resources\\sprites\\wood_2.png"));
	wood2->AddComponent(new RectCollider(sf::FloatRect(1, 5, 317, 26)));
	wood2->setPosition(position);

	return wood2;
}

GameObject* GetWood3(sf::Vector2f position)
{
	GameObject* wood3 = new GameObject("Wood");
	wood3->AddComponent(new SpriteRenderer("resources\\sprites\\wood_3.png"));
	wood3->AddComponent(new RectCollider(sf::FloatRect(1, 5, 317, 26)));
	wood3->setPosition(position);

	return wood3;
}

GameObject* GetSpikes(sf::Vector2f position)
{
	GameObject* spikes = new GameObject("Spikes");
	spikes->AddComponent(new SpriteRenderer("resources\\sprites\\spikes.png"));
	spikes->AddComponent(new RectCollider(sf::FloatRect(0, 0, 155, 29)));
	spikes->setPosition(position);
	spikes->tag = "Spikes";

	return spikes;
}

GameObject* GetStar(sf::Vector2f position)
{
	GameObject* star = new GameObject("Star");
	star->AddComponent(new SpriteRenderer("resources\\sprites\\star.png"));
	star->AddComponent(new RectCollider(sf::FloatRect(0, 0, 58, 58)));
	star->setPosition(position);
	star->tag = "Star";
	return star;
}

GameObject* GetEnemy(sf::Vector2f position, float movementSpeed, sf::Vector2f movementPoint1, sf::Vector2f movementPoint2)
{
	GameObject* enemy = new GameObject("Enemy");
	enemy->AddComponent(new SpriteRenderer("resources\\sprites\\enemy_1.png"));
	enemy->AddComponent(new RectCollider(sf::FloatRect(0, 0, 63, 63)));
	enemy->AddComponent(new EnemyMovement(movementSpeed, movementPoint1, movementPoint2));
	enemy->setOrigin(32, 32);
	enemy->setPosition(position);
	enemy->tag = "Enemy";

	return enemy;
}

GameObject* GetHUD()
{
	GameObject* hud = new GameObject("HUD");
	TextRenderer* str = new TextRenderer("resources\\fonts\\comic.ttf", { 0, 0 }, "");
	TextRenderer* ltr = new TextRenderer("resources\\fonts\\comic.ttf", { 0, 35 }, "");

	hud->AddComponent(new HUDController(str, ltr));
	hud->AddComponent(str);
	hud->AddComponent(ltr);
	return hud;
}
