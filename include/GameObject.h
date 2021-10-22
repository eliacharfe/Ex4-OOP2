#pragma once
#include "Utilities.h"
#include "Sounds.h"
#include "Image.h"

class GameObject
{
public:
	GameObject(const sf::Sprite sprite, const int angle = UP_ANGLE);
	virtual ~GameObject() = default;

	void draw(sf::RenderWindow& window) const;
	void rotate() ;

	virtual void waterOn() = 0;
	virtual void waterOff() = 0;

	sf::Sprite getSprite() const { return m_sprite; }
	void setSprite(const sf::Sprite sprite);

	bool isSource() const { return m_isSource; }
	void setSource() { m_isSource = true; }
	bool isTarget() const { return m_isTarget; }
	void setTarget() { m_isTarget = true; }

	int getAngle() const { return m_angle; }

protected:
	sf::Sprite m_sprite;
	int m_angle;

	bool m_isSource = false;
	bool m_isTarget = false;

private:
	
};