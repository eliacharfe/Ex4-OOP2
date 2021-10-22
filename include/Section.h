#pragma once
#include "GameObject.h"

class Section : public GameObject
{
public:
	Section(const sf::Sprite sprite, const int angle);

	void waterOn() override;
	void waterOff() override;
private:

};