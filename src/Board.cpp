#include "Board.h"

Board::Board() : m_startLevelOnTextBoard('\n')
{ }
//---------------------------------------------------------
void Board::openFile()
{
	m_BoardFile.open("Board.txt");
	if (!m_BoardFile.is_open()) 
		throw Exception("Cannot open file...\n");
	readLevel();
}
//----------------------------------------
void Board::readLevel()
{
	m_startLevelOnTextBoard = m_BoardFile.tellg();
	m_BoardFile >> m_sizeBoard.y >> m_sizeBoard.x;
	m_BoardFile.get(); m_charBoard.clear();
	for (unsigned int row = 0; row < m_sizeBoard.y; row++) {
		string str;
		getline(m_BoardFile, str);
		if (str.size() != m_sizeBoard.x)
			throw Exception("Error at file, num of columns at the line don't match...\n");
		m_charBoard.push_back(str); // save the line in a vector of strings
	}
	if (m_charBoard.size() != m_sizeBoard.y)
		throw Exception("Error at file, num of rows don't match...\n");
}
//-----------------------------------------------------
void Board::allocateBoard()
{ // allocate according to the board level 
	m_objects.clear();
	m_objects.resize(m_sizeBoard.y);
	sf::Vector2f location(OBJECT_SIZE / 2, OBJECT_SIZE / 2);
	for (unsigned int row = 0; row < m_sizeBoard.y; row++, location.y += OBJECT_SIZE) {
		for (unsigned int col = 0; col < m_sizeBoard.x; col++, location.x += OBJECT_SIZE)
		{
			m_sprite = Image::instance().getSprite(m_charBoard[row][col]); // get the accurate sprite
			m_sprite.setPosition(location);
			createObjects(row, m_charBoard[row][col], m_sprite); // create object
			if (m_charBoard[row][col] == SOURCE)
				m_objects[row][col]->setSource();
			if (m_charBoard[row][col] == TARGET)
				m_objects[row][col]->setTarget();
		}
		location.x = OBJECT_SIZE / 2;
	}
}
//--------------------------------------------
void Board::draw(sf::RenderWindow& window) const
{
	for (auto& row : m_objects) 
		for (auto& object : row) 
			object->draw(window); // m_objects[i][j]->draw(window)
}
//-----------------------------------------------------
GameObject* Board::getObjectInPos(const sf::Vector2f mousePos) const
{
	for (auto& row : m_objects)
		for (auto& object : row)
			if (object->getSprite().getGlobalBounds().contains(mousePos))
				return object.get();
	return nullptr;
}
//-----------------------------
bool Board::update()
{
	shared_ptr < GameObject > source;
	for (auto& row : m_objects)
		for (auto& object : row)
			if (object->isSource())
				source = object;
	resetWaterFlow();
	fillWater(getVertexObject(source), DOWN); // call recursive func that fill the water from the source
	return m_solved ? true : false;
}
//---------------------------------------
void Board::fillWater(const sf::Vector2i vertex, int direction)
{ // recursive function. go in path from the source
	if (vertex.x < 0 || vertex.y < 0 || vertex.x >= m_sizeBoard.y-2 || vertex.y >= m_sizeBoard.x-3)
		return;
	shared_ptr < GameObject > object = m_objects[vertex.x][vertex.y];
	sf::Vector2i VertexUp (vertex.x - 1, vertex.y);
	sf::Vector2i VertexDown (vertex.x + 1, vertex.y);
	sf::Vector2i VertexRight (vertex.x , vertex.y + 1);
	sf::Vector2i VertexLeft (vertex.x , vertex.y - 1);

	if (typeid(*object) == typeid(Tap)) {
		object->waterOn(); // fill with water
		if (object->getAngle() == UP_ANGLE) 
			fillWater(VertexDown, DOWN);
		else if (object->getAngle() == DOWN_ANGLE) 
			fillWater(VertexUp, UP);
		else if (object->getAngle() == RIGHT_ANGLE) 
			fillWater(VertexLeft, LEFT);
		else if (object->getAngle() == LEFT_ANGLE) 
			fillWater(VertexRight, RIGHT);
	}

	switch (direction)
	{ /* Up *///------------------------------------------
	case UP:  // if direction up
		if (typeid(*object) == typeid(Pipe)) {
			if (object->getAngle() == DOWN_ANGLE || object->getAngle() == UP_ANGLE) {
				object->waterOn(); // fill with water
				fillWater(VertexUp, UP);
			}
			else return;
		}
		if (typeid(*object) == typeid(Corner)) {
			if ((object->getAngle() == DOWN_ANGLE || object->getAngle() == LEFT_ANGLE)) {
				object->waterOn();// fill with water
				(object->getAngle() == DOWN_ANGLE) ? fillWater(VertexRight, RIGHT) : fillWater(VertexLeft, LEFT);
			}
			else return;
		}
		if (typeid(*object) == typeid(Section)) {
			if (object->getAngle() != UP_ANGLE) {
				object->waterOn(); // fill with water
				if (object->getAngle() == DOWN_ANGLE) {
					fillWater(VertexRight, RIGHT);
					fillWater(VertexLeft, LEFT);
				}
				else if (object->getAngle() == RIGHT_ANGLE) {
					fillWater(VertexRight, RIGHT);
					fillWater(VertexUp, UP);
				}
				else if (object->getAngle() == LEFT_ANGLE) {
					fillWater(VertexUp, UP);
					fillWater(VertexLeft, LEFT);
				}
			}
			else return;
		}
		if (typeid(*object) == typeid(MainSection)) {
			object->waterOn();// fill with water
			fillWater(VertexUp, UP);
			fillWater(VertexLeft, LEFT);
			fillWater(VertexRight, RIGHT);
		}
	    break;
		/* Down *///------------------------------------------
	case DOWN: // if direction down
		if (typeid(*object) == typeid(Pipe)) {
			if ((object->getAngle() == DOWN_ANGLE || object->getAngle() == UP_ANGLE)) {
				object->waterOn(); // fill with water
				fillWater(VertexDown, DOWN);
			}
			else return;
		}
		if (typeid(*object) == typeid(Corner)) {
			if ((object->getAngle() == RIGHT_ANGLE || object->getAngle() == UP_ANGLE)) {
				object->waterOn();// fill with water
				(object->getAngle() == UP_ANGLE) ? fillWater(VertexLeft, LEFT) : fillWater(VertexRight, RIGHT);
			}
			else return;
		}
		if (typeid(*object) == typeid(Section)) {
			if (object->getAngle() != DOWN_ANGLE) {
				object->waterOn(); // fill with water
				if (object->getAngle() == UP_ANGLE) {
					fillWater(VertexRight, RIGHT);
					fillWater(VertexLeft, LEFT);
				}
				else if (object->getAngle() == RIGHT_ANGLE) {
					fillWater(VertexRight, RIGHT);
					fillWater(VertexDown, DOWN);
				}
				else if (object->getAngle() == LEFT_ANGLE) {
					fillWater(VertexDown, DOWN);
					fillWater(VertexLeft, LEFT);
				}
			}
			else return;
		}
		if (typeid(*object) == typeid(MainSection)) {
			object->waterOn(); // fill with water
			fillWater(VertexLeft, LEFT);
			fillWater(VertexDown, DOWN);
			fillWater(VertexRight, RIGHT);
		}			
		break;
		/* Right *///------------------------------------------
	case RIGHT: // if direction right
		if (typeid(*object) == typeid(Pipe)) {
			if ((object->getAngle() == RIGHT_ANGLE || object->getAngle() == LEFT_ANGLE)) {
				object->waterOn();
				fillWater(VertexRight, RIGHT);
			}
			else return;
		}
		if (typeid(*object) == typeid(Corner)) {
			if (object->getAngle() == UP_ANGLE || object->getAngle() == LEFT_ANGLE) {
				object->waterOn(); // fill with water
				(object->getAngle() == UP_ANGLE) ? fillWater(VertexUp, UP) : fillWater(VertexDown, DOWN);
			}
			else return;
		}
		if (typeid(*object) == typeid(Section)) {
			if (object->getAngle() != RIGHT_ANGLE) {
				object->waterOn(); // fill with water
				if (object->getAngle() == UP_ANGLE) {
					fillWater(VertexUp, UP);
					fillWater(VertexRight, RIGHT);
				}
				else if (object->getAngle() == DOWN_ANGLE) {
					fillWater(VertexRight, RIGHT);
					fillWater(VertexDown, DOWN);
				}
				else if (object->getAngle() == LEFT_ANGLE) {
					fillWater(VertexDown, DOWN);
					fillWater(VertexUp, UP);
				}
			}
			else return;
		}
		if (typeid(*object) == typeid(MainSection)) {
			object->waterOn(); // fill with water
			fillWater(VertexUp, UP);
			fillWater(VertexDown, DOWN);
			fillWater(VertexRight, RIGHT);
		}
		if (typeid(*object) == typeid(Sink)) {
			object->waterOn(); // fill with water
			m_solved = true; // end level --> will go next level
		}
		break;
      /* Left *///------------------------------------------
	case LEFT:  // if direction left
		if (typeid(*object) == typeid(Pipe)) {
			if ((object->getAngle() == RIGHT_ANGLE || object->getAngle() == LEFT_ANGLE)) {
				object->waterOn(); // fill with water
				fillWater(VertexLeft, LEFT);
			}
			else return;
		}
		if (typeid(*object) == typeid(Corner))
		{
			if (object->getAngle() == DOWN_ANGLE || object->getAngle() == RIGHT_ANGLE) {
				object->waterOn(); // fill with water
				(object->getAngle() == DOWN_ANGLE) ? fillWater(VertexDown, DOWN) : fillWater(VertexUp, UP);
			}
			else return;
		}
		if (typeid(*object) == typeid(Section))
		{
			if (object->getAngle() != LEFT_ANGLE) {
				object->waterOn(); // fill with water
				if (object->getAngle() == UP_ANGLE) {
					fillWater(VertexUp, UP);
					fillWater(VertexLeft, LEFT);
				}
				else if (object->getAngle() == DOWN_ANGLE) {
					fillWater(VertexLeft, LEFT);
					fillWater(VertexDown, DOWN);
				}
				else if (object->getAngle() == RIGHT_ANGLE) {
					fillWater(VertexDown, DOWN);
					fillWater(VertexUp, UP);
				}
			}
			else return;
		}
		if (typeid(*object) == typeid(MainSection)) {
			object->waterOn(); // fill with water
			fillWater(VertexUp, UP);
			fillWater(VertexDown, DOWN);
			fillWater(VertexLeft, LEFT);
		}
		break;
	}
}
//------------------------------
void Board::resetWaterFlow()
{
	for (auto& row : m_objects)
		for (auto& object : row)
			object->waterOff();
}
//-----------------------------------------
sf::Vector2i Board::getVertexObject(shared_ptr < GameObject > obj) const
{
	return sf::Vector2i(obj->getSprite().getPosition().y / OBJECT_SIZE, obj->getSprite().getPosition().x / OBJECT_SIZE);
}
//----------------------------------------------------
void Board::createObjects(const int row, const char c, const sf::Sprite sprite)
{
	shared_ptr < GameObject > object = createObject(c, sprite);
	if (object) 
		m_objects[row].push_back(move(object)); 
}
//------------------------------------------------------------------------------------------
shared_ptr < GameObject > Board::createObject(const char c, const sf::Sprite sprite)
{
	switch (c) {
	case SOURCE:       return  make_shared < Tap >(sprite, UP_ANGLE);     break;
	case TARGET:       return  make_shared < Sink >(sprite);              break;
	case MAIN_SECTION: return  make_shared < MainSection >(sprite);       break;
	case PIPE:         return  make_shared < Pipe >(sprite, UP_ANGLE);    break;
	case CORNER:       return  make_shared < Corner >(sprite, UP_ANGLE);  break;
	case SECTION:      return  make_shared < Section >(sprite, UP_ANGLE); break;
	case EMPTY:        return  make_shared < Empty >(sprite);             break;
	}
	return nullptr;
}
//-------------------------------------------------------






