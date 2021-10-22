#pragma once
#include "Utilities.h"
#include "Board.h"
#include "Sounds.h"

class GameManager
{
public:
	GameManager();
	void run();

private:
	void setWindow(const sf::Vector2f size);
	void welcomeWindow();
	void setMessage(sf::Text& msg, const char* str);
	void setTextPosition(sf::Text& txt, int i);
	void handleWin(sf::Text& countMsg, sf::Text& tapCount, sf::Text& timeMsg, sf::Text& time, sf::RectangleShape& background);
	//void setBackgroundMusic();

	sf::RenderWindow m_window;
	Board m_board;

	sf::Event m_event;
	sf::Vector2f m_MousePos;
	int m_tapCount;
	
	sf::Clock m_clock;
	sf::Time m_time;

	bool m_correct = false;
	bool m_solved = false;
	int m_level;
	/*sf::Music m_music;*/
};
