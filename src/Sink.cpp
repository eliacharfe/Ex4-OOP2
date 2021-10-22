#include "Sink.h"

Sink::Sink(const sf::Sprite sprite)
	: GameObject::GameObject(sprite)
{
}
//-------------------------------
void Sink::waterOn()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(SINK_FULL);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
