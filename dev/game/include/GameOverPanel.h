#pragma once
#include <SFML/System/Vector2.hpp>
#include <components/Behaviour.h>
#include <components/TextRenderer.h>
#include <iostream>

class GameOverPanel : public Behaviour
{
public:
	void Start();
	void Update(); //вызывается каждый кадр игры

};
