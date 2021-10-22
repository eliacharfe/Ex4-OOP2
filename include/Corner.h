#pragma once
#include "GameObject.h"

class Corner : public GameObject
{
public:
	Corner(const sf::Sprite sprite, const int angle);

	void waterOn() override;
	void waterOff() override;
private:

};