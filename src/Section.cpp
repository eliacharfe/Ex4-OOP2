#include "Section.h"

Section::Section(const sf::Sprite sprite, const int angle)
	: GameObject::GameObject(sprite, angle)
{
}
//-----------------------------
void Section::waterOn()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(SECTION_FULL);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
//-------------------------------
void Section::waterOff()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(SECTION);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
