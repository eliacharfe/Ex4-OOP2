#include "Corner.h"

Corner::Corner(const sf::Sprite sprite,const int angle)
	: GameObject::GameObject(sprite, angle)
{
}
//-------------------------------
void Corner::waterOn()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(CORNER_FULL);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
//----------------------
void Corner::waterOff()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(CORNER);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
