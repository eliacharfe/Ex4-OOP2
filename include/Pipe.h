#pragma once
#include "GameObject.h"

class Pipe : public GameObject
{
public:
	Pipe(const sf::Sprite sprite, const int angle);

	void waterOn() override;
	void waterOff() override;

private:
};
