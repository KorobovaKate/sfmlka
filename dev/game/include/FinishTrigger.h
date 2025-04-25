#pragma once
#include <SFML/System/Vector2.hpp>
#include <components/Behaviour.h>

class FinishTrigger : public Behaviour
{
public:
	FinishTrigger(int nextScene);
	void OnCollision(RectCollider* other); 
private:
	int nextNumberScene;
};