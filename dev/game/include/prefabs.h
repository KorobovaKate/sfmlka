#pragma once
#include <GameObject.h>
#include <components/TextRenderer.h>

GameObject* GetPlayer(sf::Vector2f position);
GameObject* GetBox(sf::Vector2f position);
GameObject* GetFinishFlag(sf::Vector2f position, int nextLevel);
GameObject* GetGround1(sf::Vector2f position);
GameObject* GetGround2(sf::Vector2f position);
GameObject* GetGround3(sf::Vector2f position);
GameObject* GetGround4(sf::Vector2f position);
GameObject* GetGround5(sf::Vector2f position);
GameObject* GetGround6(sf::Vector2f position);
GameObject* GetGround7(sf::Vector2f position);
GameObject* GetWood1(sf::Vector2f position);
GameObject* GetWood2(sf::Vector2f position);
GameObject* GetWood3(sf::Vector2f position);
GameObject* GetSpikes(sf::Vector2f position);
GameObject* GetStar(sf::Vector2f position);
GameObject* GetEnemy(sf::Vector2f position, float movementSpeed, sf::Vector2f movementPoint1, sf::Vector2f movementPoint2);
GameObject* GetHUD();