#pragma once
#include "GameObject.h"

class Sink : public GameObject
{
public:
	Sink(const sf::Sprite sprite);

	void waterOn() override;
	void waterOff() override {};
private:

};