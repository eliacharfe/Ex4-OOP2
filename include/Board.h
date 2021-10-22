#pragma once
#include "Utilities.h"
#include "Tap.h"
#include "Pipe.h"
#include "Corner.h"
#include "Sink.h"
#include "Section.h"
#include "MainSection.h"
#include "Empty.h"
#include "Exception.h"

#include "Image.h"
#include "Sounds.h"

class Board
{
public:
	Board(); // c-tor
	void openFile();
	void readLevel();
	void allocateBoard();

	void draw(sf::RenderWindow& window) const;
	GameObject* getObjectInPos(const sf::Vector2f mouse) const;

    bool update();
	sf::Vector2f getSize() { return m_sizeBoard; }
    bool isSolved() const { return m_solved; }
    void setUnsolved() { m_solved = false; }

private:
	void createObjects(const int row, const char c, const sf::Sprite sprite);
    shared_ptr < GameObject > createObject(const char c, const sf::Sprite sprite);

    void fillWater(const sf::Vector2i vertex, int direction);
    void resetWaterFlow();
    sf::Vector2i getVertexObject(shared_ptr < GameObject > obj) const;

	vector < string > m_charBoard;
    vector < vector < shared_ptr < GameObject >>> m_objects;

	ifstream m_BoardFile;
	streamoff m_startLevelOnTextBoard;
	sf::Sprite m_sprite;
	sf::Vector2f m_sizeBoard;

    bool m_solved = false;
	bool m_correct = true;
};




