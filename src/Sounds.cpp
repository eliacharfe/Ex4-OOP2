#include "Sounds.h"

Sounds::Sounds()
{
	loadSounds();
}
//----------------------------
void Sounds::loadSounds() 
{
	m_soundBuffer.resize(8);
	m_soundBuffer[0].loadFromFile("rotate.ogg"/*"metal_hit.ogg"*/);
	m_soundBuffer[1].loadFromFile("sink_sound.ogg");
	m_soundBuffer[2].loadFromFile("winLevel.wav");
	m_soundBuffer[3].loadFromFile("water_sound.ogg");

	m_soundBuffer[4].loadFromFile("badPresentSound.ogg");
	m_soundBuffer[5].loadFromFile("GameOverSound.ogg");
	m_soundBuffer[6].loadFromFile("soundWinGame.ogg");
	m_soundBuffer[7].loadFromFile("soundDig.ogg");

	m_sounds.resize(8);
	m_sounds[0].setBuffer(m_soundBuffer[0]);
	m_sounds[1].setBuffer(m_soundBuffer[1]);
	m_sounds[2].setBuffer(m_soundBuffer[2]);
	m_sounds[2].setVolume(50);
    m_sounds[3].setBuffer(m_soundBuffer[3]);

	m_sounds[4].setBuffer(m_soundBuffer[4]);
	m_sounds[5].setBuffer(m_soundBuffer[5]);
	m_sounds[6].setBuffer(m_soundBuffer[6]);
	m_sounds[7].setBuffer(m_soundBuffer[7]);
}
//-----------------------------
Sounds& Sounds::instance() 
{
	static Sounds inst;
	return inst;
}
//----------------------------------
void Sounds::makeSound(const char c)
{
	switch (c)
	{
	case ROTATE_SOUND: m_sounds[0].play(); break;
	case SINK_SOUND:      m_sounds[1].play(); break;
	case WIN:             m_sounds[2].play(); break;
	case WATER_SOUND:     m_sounds[3].play(); break;

	}
	//return m_sounds[4].play();
}
//--------------------------------------
void Sounds::stopSound(const char c)
{
	switch (c)
	{
	case WATER_SOUND:     m_sounds[3].stop(); break;
	}
}
//-------------------------------------
