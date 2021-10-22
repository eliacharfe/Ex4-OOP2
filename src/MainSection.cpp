#include "MainSection.h"

MainSection::MainSection(const sf::Sprite sprite)
	: GameObject::GameObject(sprite)
{
}
//----------------------------
void MainSection::waterOn()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(MAIN_SECTION_FULL);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
//-----------------------------
void MainSection::waterOff()
{
	sf::Vector2f location = m_sprite.getPosition();
	m_sprite = Image::instance().getSprite(MAIN_SECTION);
	m_sprite.setOrigin(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	m_sprite.setPosition(location);
	m_sprite.rotate(m_angle);
}
