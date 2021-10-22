#pragma once
#include "GameObject.h"

class Empty : public GameObject
{
public:
	Empty(const sf::Sprite sprite);

	void waterOn() override {};
	void waterOff() override {};

private:

};