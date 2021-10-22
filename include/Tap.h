#pragma once
#include "GameObject.h"

class Tap : public GameObject
{
public:
	Tap(const sf::Sprite sprite, const int angle);

	void waterOn() override;
	void waterOff() override;
private:

};