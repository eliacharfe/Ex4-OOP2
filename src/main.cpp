#include "GameManager.h"

int main()
{
	srand((int)time(NULL));
	GameManager game;
	try {
		game.run();
	}
	catch (std::exception& e) {
		ofstream output;
		output.open("log.txt");
		output << e.what() << endl;
	}
	return EXIT_SUCCESS;
}

