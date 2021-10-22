#include "Tap.h"

Tap::Tap(const sf::Sprite sprite, const int angle)
	: GameObject::GameObject(sprite, angle)
{
}
//---------------------------------
void Tap::waterOn()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(TAP_FULL);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
//-----------------------------
void Tap::waterOff()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(SOURCE);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
