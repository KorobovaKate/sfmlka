#pragma once
#include <SFML/System/Vector2.hpp>
#include <components/Behaviour.h>
#include <components/TextRenderer.h>
#include <iostream>

class HUDController : public Behaviour
{
public:
	HUDController(TextRenderer* scoreTextRenderer, TextRenderer* levelTextRenderer);
	void Start();
	void Update(); //���������� ������ ���� ����
	~HUDController();
private:
	TextRenderer* scoreTextRenderer;
	TextRenderer* levelTextRenderer;
};