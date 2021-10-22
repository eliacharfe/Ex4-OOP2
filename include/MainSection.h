#pragma once
#include "GameObject.h"

class MainSection : public GameObject
{
public:
	MainSection(const sf::Sprite sprite);

	void waterOn() override;
	void waterOff() override;

private:

};