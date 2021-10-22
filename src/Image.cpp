#include "Image.h"

Image::Image()
{
	loadImages();
}
//---------------------------------
void Image::loadImages()
{
	m_texture.resize(22);
	m_texture[0].loadFromFile("play.jpg");
	m_texture[1].loadFromFile("quit.jpg");
	m_texture[2].loadFromFile("background_pipe.jpg");
	m_texture[3].loadFromFile("blue_back.jpg");
	m_texture[4].loadFromFile("start.png");
	m_texture[5].loadFromFile("tap_full.png");
	m_texture[6].loadFromFile("pipe.png");
	m_texture[7].loadFromFile("corner.png"); 
	m_texture[8].loadFromFile("sink.png"); 
	m_texture[9].loadFromFile("section.png");
	m_texture[10].loadFromFile("main_section.png"); 
	m_texture[11].loadFromFile("pipe_full.png");
	m_texture[12].loadFromFile("logo_pipe.png");
	m_texture[13].loadFromFile("sink_open.png"); 
	m_texture[14].loadFromFile("corner_full.png");
	m_texture[15].loadFromFile("section_full.png");
	m_texture[16].loadFromFile("main_section_full.png");
	m_texture[17].loadFromFile("sink_full.png"); 
	m_texture[18].loadFromFile("mr.png");
	m_texture[19].loadFromFile("solved.png");
	m_texture[20].loadFromFile("you_won.png");
	m_texture[21].loadFromFile("empty.png");

	m_sprites.resize(22);
	m_sprites[0].setTexture(m_texture[0]);
	m_sprites[1].setTexture(m_texture[1]);
	m_sprites[2].setTexture(m_texture[2]);
	m_sprites[3].setTexture(m_texture[3]);
	m_sprites[4].setTexture(m_texture[4]);
	m_sprites[5].setTexture(m_texture[5]);
	m_sprites[6].setTexture(m_texture[6]);
	m_sprites[7].setTexture(m_texture[7]);
	m_sprites[8].setTexture(m_texture[8]);
	m_sprites[9].setTexture(m_texture[9]);
	m_sprites[10].setTexture(m_texture[10]);
	m_sprites[11].setTexture(m_texture[11]);
	m_sprites[12].setTexture(m_texture[12]);
	m_sprites[13].setTexture(m_texture[13]);
	m_sprites[14].setTexture(m_texture[14]);
	m_sprites[15].setTexture(m_texture[15]);
	m_sprites[16].setTexture(m_texture[16]);
	m_sprites[17].setTexture(m_texture[17]);
	m_sprites[18].setTexture(m_texture[18]);
	m_sprites[19].setTexture(m_texture[19]);
	m_sprites[20].setTexture(m_texture[20]);
	m_sprites[21].setTexture(m_texture[21]);

	m_font.loadFromFile("resources/sansation.ttf");
}
//------------------------------------
Image& Image::instance()
{
	static Image inst;
	return inst;
}
//-----------------------------------------
const sf::Sprite Image::getSprite(const char c) const
{
	switch (c)
	{
	case PLAY_BUTTON:       return m_sprites[0];  break;
	case QUIT_BUTTON:       return m_sprites[1];  break;
	case SOURCE:            return m_sprites[4];  break;
	case TAP_FULL:          return m_sprites[5];  break;
	case PIPE:              return m_sprites[6];  break;
	case CORNER:            return m_sprites[7];  break;
	case TARGET:            return m_sprites[8];  break;
	case SECTION:           return m_sprites[9];  break;
	case MAIN_SECTION:      return m_sprites[10]; break;
	case PIPE_FULL:         return m_sprites[11]; break;
	case LOGO_PIPE:         return m_sprites[12]; break;
	case TARGET_OPEN:       return m_sprites[13]; break;
	case CORNER_FULL:       return m_sprites[14]; break;
	case SECTION_FULL:      return m_sprites[15]; break;
	case MAIN_SECTION_FULL: return m_sprites[16]; break;
	case SINK_FULL:         return m_sprites[17]; break;
	case MR:                return m_sprites[18]; break;
	case SOLVED:            return m_sprites[19]; break;
	case YOU_WON:           return m_sprites[20]; break;
	case EMPTY:             return m_sprites[21]; break;
	}
	return m_sprites[21];
}
//--------------------------------------------
const sf::Texture Image::getTexture(const char c) const
{
	switch (c)
	{
	case WELCOME:   return m_texture[2]; break;
	case BLUE_BACK: return m_texture[3]; break;
	}
	return m_texture[0];
}
//--------------------------------------
const sf::Font Image::getFont() const
{
	return m_font;
}
//--------------------------------------------------------------



























