// GameExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void RunGame() {
	//game.Run();
	//game.menu();
	int difficulty =2;

	Menu menu;
	while (1) {
		Game game(difficulty);
	//	game.SetDifficulty(difficulty);

		menu.Print_Array();
		menu.GetClick();
		int selecteditem = menu.GetSelectedItem();
		if (selecteditem == 0) {			
			game.Run(); //game.DeleteArrays();
			difficulty = game.GetDifficulty();
			difficulty++;
		}
		else if (selecteditem == 1) {/*rulse*/ }
		else { exit(0); }
		if (difficulty > 5) { difficulty = 5; }
	}
}

int main()
{	
	RunGame();
	
	system("pause");
    return 0;
}

