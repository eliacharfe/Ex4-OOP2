#include "GameObject.h"

GameObject::GameObject(const sf::Sprite sprite, const int angle)
	: m_sprite(sprite), m_angle(angle)
{
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
}
//-------------------------------------------------
void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//------------------------------------
void GameObject::rotate()
{
	m_sprite.rotate(ROTATE);
	m_angle == LEFT_ANGLE ? m_angle = UP_ANGLE : m_angle += ROTATE;
	Sounds::instance().makeSound(ROTATE_SOUND);
}
//-------------------------------------------------
void GameObject::setSprite(const sf::Sprite sprite)
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = sprite;
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
}

