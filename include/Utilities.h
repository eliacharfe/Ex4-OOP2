#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <experimental/vector>
#include <Windows.h>
#include <queue>
#include <windows.h>

using std::vector;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;
using std::move;
using std::ifstream;
using std::ofstream;
using std::streamoff;
using std::to_string;
using std::cout;
using std::endl;
using std::cerr;

const int DEF_SIZE_WINDOW = 1100;
const int OUTLINE_THIKNESS = 3;
const int CHARACTER_SIZE = 55;
const int CHARACTER_SIZE_TEXT = 30;
const float MSG_X_POS = 100.f;
const float MSG_Y_POS = 80.f;

const float OBJECT_SIZE = 80.0f;
const int NUM_BUTTOMS = 10; 
const float SPEED_PLAYER = 230.0f; 
const float SPEED_ENEMY = 150.0f; 
const float SPEED_SMART_ENEMY = 190.0f; 
const int MAX_RAND = 1000;

const int MAX_MESSAGE_SIZE = 200;

const char PLAY_BUTTON = 'P';
const char QUIT_BUTTON = 'Q';
const char WELCOME = 'W';
const char BLUE_BACK = 'Y';
const char LOGO_PIPE = 'L';

const char SOURCE = 'S'; // tap open
const char TAP_FULL = 'B';
const char PIPE = '-';
const char CORNER = 'C';
const char CORNER_FULL = '#';
const char TARGET = 'T'; // sink
const char TARGET_OPEN = 'D';
const char SINK_FULL = '*';
const char SECTION = 'V';
const char SECTION_FULL = '%';
const char MAIN_SECTION = '+';
const char MAIN_SECTION_FULL = '$';
const char PIPE_FULL = 'I';
const char MR = 'M';
const char SOLVED = 'O';
const char YOU_WON = '!';
const char EMPTY = ' ';

const char ROTATE_SOUND = 'R';
const char SINK_SOUND = '@';
const char WIN = 'W';
const char WATER_SOUND = 'V';

const int UP_ANGLE = 0;
const int RIGHT_ANGLE = 90;
const int DOWN_ANGLE = 180;
const int LEFT_ANGLE = 270;

const int ROTATE = 90;

const int UP = 1;
const int DOWN = 3;
const int RIGHT = 2;
const int LEFT = 4;

const int THREE = 3000;
const int SEVEN = 7000;


//enum objects_t {
//	EMPTY = 'E',
//	WELCOME = 'W',
//	BACKGROUND1 = 'B1',
//	BLUE_BACK = 'BB',
//
//	START_OPEN = 'A',
//	START_FULL = 'B'
//
//};


//const char BACKGROUND = 'B'; 
//
//const char MENU = 'M';
//const char PLAYER = '@';
//const char ENEMY = '%';
//const char WALL = '#';
//const char FLOOR = 'F';
//const char LADDER = 'H';
//const char POLE = '-';
//const char COIN = '*';
//const char PRESENT = '+';
//const char BAD_PRESENT = 'X';
//const char EMPTY_CELL = ' ';
//const char WIN = 'W';
//const char LOOSE = 'L';
//const char WIN_GAME = 'V';
//const char PLAY_BUTTON = 'P';
//const char QUIT_BUTTON = 'Q';
//const char DIG = 'D';
