#include "GameManager.h"

GameManager::GameManager() : m_MousePos(0, 0), m_tapCount(0), m_event(sf::Event()), m_level(1) { }
//----------------------------------------------
void GameManager::run()
{
	welcomeWindow();
	try {
		m_board.openFile();
		setWindow(m_board.getSize());
		m_board.allocateBoard();
	}
	catch (Exception& e) {
		cerr << e.what();
		throw; // rethrow
	}
	sf::RectangleShape background;
	const auto backTexture = Image::instance().getTexture(BLUE_BACK);
	background.setTexture(&backTexture);
	background.setSize(sf::Vector2f(m_board.getSize().x * OBJECT_SIZE, m_board.getSize().y * OBJECT_SIZE));

	const auto font = Image::instance().getFont();
	sf::Text countMsg, tapCount, timeMsg, time;
	countMsg.setFont(font); tapCount.setFont(font); timeMsg.setFont(font); time.setFont(font);
	setMessage(countMsg, "Tap count: "); setMessage(tapCount, "0"); setMessage(timeMsg, "Time"); setMessage(time, "0");
	setTextPosition(countMsg, 1); setTextPosition(tapCount, 2); setTextPosition(timeMsg, 3); setTextPosition(time, 4);

	m_board.update();
	m_clock.restart();
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(background);
		m_board.draw(m_window);
		m_window.draw(countMsg); m_window.draw(tapCount);
		m_window.draw(timeMsg); m_window.draw(time);
		if (m_solved)
			handleWin(countMsg, tapCount, timeMsg, time, background);
		m_window.display();

		while (m_window.pollEvent(m_event))
		{
			switch (m_event.type) {
			case sf::Event::Closed:
				m_window.close(); break;
			case sf::Event::MouseButtonReleased:
				m_MousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
				if (m_board.getObjectInPos(m_MousePos) && !m_board.getObjectInPos(m_MousePos)->isTarget()) {
					m_board.getObjectInPos(m_MousePos)->rotate();
					++m_tapCount;
				}
				else if (m_board.getObjectInPos(m_MousePos) && m_board.getObjectInPos(m_MousePos)->isTarget()) {
					m_board.getObjectInPos(m_MousePos)->setSprite(Image::instance().getSprite(TARGET_OPEN));
					Sounds::instance().makeSound(SINK_SOUND);
				}
				if (m_board.update()) {
					Sounds::instance().makeSound(WATER_SOUND);
					m_solved = true;
				}
				break;
			}
		}
		m_time = m_clock.getElapsedTime();
		time.setString(to_string((int)m_time.asSeconds()));
		tapCount.setString(to_string(m_tapCount));
	}
}
//----------------------------------------------------
void GameManager::setWindow(const sf::Vector2f size)
{
	m_window.create(sf::VideoMode((int)(size.x * OBJECT_SIZE), (int)(size.y * OBJECT_SIZE)),
		"PIPE", sf::Style::Close | sf::Style::Titlebar);
}
//------------------------------------------------
void GameManager::setMessage(sf::Text& msg, const char* str)
{
	msg.setCharacterSize(CHARACTER_SIZE_TEXT);
	msg.setFillColor(sf::Color::Black);
	msg.setPosition(m_board.getSize().x * OBJECT_SIZE, (OBJECT_SIZE));
	msg.setOutlineThickness(OUTLINE_THIKNESS);
	msg.setOutlineColor(sf::Color::Green);
	msg.setString(str);
}
//---------------------------------------------------------
void GameManager::setTextPosition(sf::Text& txt, int i)
{
	switch (i)
	{
	case 1: txt.setPosition((m_board.getSize().x - 3) * OBJECT_SIZE + OBJECT_SIZE / 2, OBJECT_SIZE); break;
	case 2: txt.setPosition((m_board.getSize().x - 3) * OBJECT_SIZE + OBJECT_SIZE + OBJECT_SIZE / 4, OBJECT_SIZE + OBJECT_SIZE / 2); break;
	case 3: txt.setPosition((m_board.getSize().x - 3) * OBJECT_SIZE + OBJECT_SIZE / 2 + OBJECT_SIZE / 2, OBJECT_SIZE + OBJECT_SIZE / 2 + OBJECT_SIZE); break;
	case 4: txt.setPosition((m_board.getSize().x - 3) * OBJECT_SIZE + OBJECT_SIZE + OBJECT_SIZE / 4, OBJECT_SIZE + OBJECT_SIZE / 2 + OBJECT_SIZE + OBJECT_SIZE / 2); break;
	}
}
//-----------------------------------------------------------------------------------------------------
void GameManager::handleWin(sf::Text& countMsg, sf::Text& tapCount, sf::Text& timeMsg, sf::Text& time, sf::RectangleShape& background)
{
	sf::Sprite solved;
	++m_level;
	if (m_level == 4) { // win whole game
		solved = Image::instance().getSprite(YOU_WON);
		solved.setPosition(m_window.getView().getCenter().y / 2, m_window.getView().getCenter().x / 2);
		m_window.draw(solved);
		m_window.display(); cout << "You Won!" << endl;
		Sleep(SEVEN);
		exit(EXIT_SUCCESS);
	}
	solved = Image::instance().getSprite(SOLVED);
	solved.setPosition(m_window.getView().getCenter().y / 2, m_window.getView().getCenter().x / 2);
	m_window.draw(solved);
	m_window.display();
	Sleep(THREE);
	m_tapCount = 0;
	m_clock.restart();
	m_board.setUnsolved(); m_solved = false;

	try {
		m_board.readLevel();
		setWindow(m_board.getSize());
		m_board.allocateBoard();
	}
	catch (Exception& e) { cerr << e.what();
		throw;
	}
	setTextPosition(countMsg, 1); setTextPosition(tapCount, 2); setTextPosition(timeMsg, 3); setTextPosition(time, 4);
	background.setSize(sf::Vector2f(m_board.getSize().x * OBJECT_SIZE, m_board.getSize().y * OBJECT_SIZE));
	Sounds::instance().stopSound(WATER_SOUND);
	m_board.update();
}
//----------------------------------------------------------
//----------------------------------------------------------
void GameManager::welcomeWindow()
{ /* a welcome window for start game (or exit)*/
	sf::RenderWindow welcomeWindow(sf::VideoMode(1571, 800), "WELCOME TO PIPE", sf::Style::Default);
	Sounds::instance().makeSound(WATER_SOUND);

	const auto backTexture = Image::instance().getTexture(WELCOME);
	sf::RectangleShape background;
	background.setTexture(&backTexture);
	background.setSize(sf::Vector2f(welcomeWindow.getSize().x, welcomeWindow.getSize().y));

	sf::Sprite logo = Image::instance().getSprite(LOGO_PIPE);
	logo.setPosition(500, 100);
	sf::Sprite mr = Image::instance().getSprite(MR);
	mr.setPosition(1100, 350);
	sf::Sprite playButton = Image::instance().getSprite(PLAY_BUTTON);
	playButton.setPosition(100, 400);
	sf::Sprite quitButton = Image::instance().getSprite(QUIT_BUTTON);
	quitButton.setPosition(100, 500);

	while (welcomeWindow.isOpen())
	{
		welcomeWindow.clear();
		welcomeWindow.draw(background);
		welcomeWindow.draw(logo);
		welcomeWindow.draw(playButton);
		welcomeWindow.draw(quitButton);
		welcomeWindow.draw(mr);
		welcomeWindow.display();

		while (welcomeWindow.pollEvent(m_event))
		{
			switch (m_event.type)
			{
			case sf::Event::Closed:
				Sounds::instance().stopSound(WATER_SOUND);
				welcomeWindow.close(); 	break;
			case sf::Event::KeyReleased: {
				if (m_event.key.code == sf::Keyboard::Escape)
					exit(EXIT_SUCCESS);
				if (m_event.key.code == sf::Keyboard::Enter || (m_event.key.code == sf::Keyboard::Space)) {
					Sounds::instance().stopSound(WATER_SOUND);
					welcomeWindow.close();
				}
				break;
			}
			case sf::Event::MouseButtonReleased: {
				m_MousePos = welcomeWindow.mapPixelToCoords(sf::Mouse::getPosition(welcomeWindow));
				if (playButton.getGlobalBounds().contains(m_MousePos)) {
					Sounds::instance().stopSound(WATER_SOUND);
					welcomeWindow.close();
				}
				if (quitButton.getGlobalBounds().contains(m_MousePos))
					exit(EXIT_SUCCESS);
				break;
			}
			}
		}
	}
}
//--------------------------------------------------


