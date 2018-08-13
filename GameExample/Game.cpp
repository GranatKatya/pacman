#include "stdafx.h"
//
//class Field;
//extern Field field;

void  Game::victory() {
	system("cls");/* cout << "victory" << endl;  _dificulty += 1;*/
	GotoXY(40, 12);
	cout << "You win" << endl;
	_getch();
	system("cls");
}


HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// обращение к  консоли.дескрипторы
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

void SetColor(int text, int background) // устанавливаем цвет
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y) // перемещение консоли по координата  
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}


int Game::GetScore() { return _score; }

void Game::PacMenGhostIntersection() {
	vector<Enemy*> &ghosts = field.GetGhosts();

	if (field.PacManGhostIntersection()) {//пересечение PacMan и Ghost
		if (!_killmode) {
			// gameover -1life
			//_life--;

			RemoveLife();
			field.GetPacMan().Get_Current_Position()->Print(RGB(0, 0, 0), 4);// square
			field.GetPacMan().SetCoord(9,9);//PacMan
			field.GetPacMan().Set_Current_Position(&(*field.GetArray()[208]));  //208//25 *8 +9  Current_Position поставили в начальную позицию
			field.GetPacMan().Print(RGB(255, 255, 0), 5);//print pacman after death
			
			for (int i = 0; i < field.GetGhosts().size(); i++) {
				ghosts[i]->Set_Is_Dead(false);//чтобы остались не только глаза на поле
				ghosts[i]->SetContains(6);//чтобы остались не только глаза на поле
				ghosts[i]->Get_Current_Position()->Print(RGB(0, 0, 0), 3); //квадрат
				ghosts[i]->Get_Current_Position()->Print(RGB(255, 0, 0), ghosts[i]->Get_Current_Position()->GetContains());// закрасить тела приведений которые умерли 
				ghosts[i]->SetCoord(12+i*2, 12);// вернуть в начало Ghost 
				//ghosts[i]->SetTarget(12 + i * 2, 9); // цели изначальные
				ghosts[i]->SetTarget(15, 9);
				ghosts[i]->Set_Current_Position(&(*field.GetArray()[236 + (i+1) * 50])); //  Current_Position поставили в начальную позицию
				ghosts[i]->Set_Is_In_Room(true);
			}
		}
		else {
			// Ghost на базу
			
			for (int i = 0; i < field.GetGhosts().size(); i++) {
				if (field.GetPacMan().GetCoord().X == field.GetGhosts()[i]->GetCoord().X  &&
					field.GetPacMan().GetCoord().Y == field.GetGhosts()[i]->GetCoord().Y) {
					field.GetGhosts()[i]->Set_Is_Dead(true);

					//if (ghosts[i]->Get_Is_Dead()) {
					ghosts[i]->SetTarget(15, 10);/////
												 
					ghosts[i]->SetContains(7);// глаза 

				}
			}

		}
	}

}


void Game::Run()
{
	//CheckLose();
	field.InitializeField();
	field.Print();
	PrintLife();


	//	//smile.Draw();
	//	enemy.Draw();

	bool even_cycle = false;
	int even_cycle1 = 1;
	int hits_count = 0;// зажатие кнопки
	int kill_mode_counter = 0;
	int target_counter = 0;

	vector<Enemy*> &ghosts = field.GetGhosts();//---??????????????

	while (true)
	{

		
		

		while (!_kbhit()) //пока пользователь не нажал клавишу
		{
			



			if (_killmode) {// врем€ _killmode
				kill_mode_counter++;
				TargetGhostsAwayFromPacMan();//чтобы призраки убегали 
				if (kill_mode_counter >= 50) {
					_killmode = 0;
					for (int i = 0; i < ghosts.size(); i++) {
						ghosts[i]->Set_Random_Color();// ѕќ—Ћ≈ KILL MODE SET NEW COLORS
					}
				}
			}
			else {// не _killmode
				target_counter++;
				if (target_counter < 50) {
					TargetGhostsToCorners();//в углы бегут
				}
				else if (target_counter >= 50 && target_counter <350) {// за пекменом
					TargetGhostsToPacMan();
				}
				else { target_counter = 0; }

			}



			hits_count = 0;
			if (even_cycle1>1) {

				//ghost move
				
				for (int i = 0; i < ghosts.size(); i++) {

				
					if (ghosts[i]->Get_Is_Dead()) {// идет к воротам , мертвый
						if (ghosts[i]->CheckTarget()) { // если мы достиигли цели 
							ghosts[i]->Set_Is_Dead(false);
							ghosts[i]->SetContains(6);// глаза + ghost

							ghosts[i]->Set_Is_In_Room(true);//чтобы прив при входе  в комнаиу могли из нее выйти
							ghosts[i]->SetTarget(12,9);
						}
					}// у ворот + contais
					else if (ghosts[i]->Get_Is_In_Room()) {//in room
						if (ghosts[i]->CheckTarget()) { // если мы достиигли цели 
							ghosts[i]->Set_Is_In_Room(false);
						}
					}

						/*while (1) {


							int random = rand() % field.GetArray().size();

							if (field.GetArray()[random]->GetContains() != 3) {
								ghosts[i]->SetTarget(field.GetArray()[random]->GetCoord().X, field.GetArray()[random]->GetCoord().Y);
								break;
							}

						}*/
					// check target

					// поиск пути к цели
					//if (field.CheckWalls(ghosts[i]->GetRotation(), *ghosts[i])  || 
					//	field.CheckEdge(ghosts[i]->GetRotation(), *ghosts[i])) {
					ghosts[i]->SetRotation(field.GetNextMoveToTarget(*ghosts[i]));

					//} // if hit wall or edge0

					int direction = ghosts[i]->GetRotation();

					switch (direction) {
					case 1:
						ghosts[i]->MoveRight(0, field.GetArray());
						break;
					case 2:
						ghosts[i]->MoveDown(0, field.GetArray());
						break;
					case 3:
						ghosts[i]->MoveLeft(0, field.GetArray());
						break;
					case 4:
						ghosts[i]->MoveUp(0, field.GetArray());
						break;

					}

					PacMenGhostIntersection();




				}
				even_cycle1++;
				if (even_cycle1 > 3) { even_cycle1 = 1; }
			}
			else { even_cycle1++; }

			//enemy.MoveDown();
			Sleep(200);


			/*if (even_cycle1) {
				even_cycle1 = false;

			}
			else { even_cycle1 = true; }
*/


		}
		//	while (_kbhit()){

		

			Keys key = Console::GetKey();

			if (hits_count < 4) {
				hits_count++;

			switch (key)
			{
			case Keys::ArrowUp:
				if (!field.CheckWalls(4, field.GetPacMan()) && !field.CheckGatesPacMan(4, field.GetPacMan())) {
					//if (field.CheckEdge(4, field.GetPacMan())) {
					//	field.Edge(4, field.GetPacMan()); }
					field.GetPacMan().MoveUp(field.CheckEdge(4, field.GetPacMan()), field.GetArray());

				}

				break;

			case Keys::ArrowDown:
				if (!field.CheckWalls(2, field.GetPacMan()) && !field.CheckGatesPacMan(2, field.GetPacMan())) {
					//if (field.CheckEdge(4, field.GetPacMan())) { field.Edge(2, field.GetPacMan()); }
					field.GetPacMan().MoveDown(field.CheckEdge(2, field.GetPacMan()), field.GetArray());
				}

				break;

			case Keys::ArrowLeft:
				if (!field.CheckWalls(3, field.GetPacMan()) && !field.CheckGatesPacMan(3, field.GetPacMan())) {
					//if (field.CheckEdge(4, field.GetPacMan())) { field.Edge(3, field.GetPacMan()); }
					field.GetPacMan().MoveLeft(field.CheckEdge(3, field.GetPacMan()), field.GetArray());
				}

				break;

			case Keys::ArrowRight:
				if (!field.CheckWalls(1, field.GetPacMan()) && !field.CheckGatesPacMan(1, field.GetPacMan())) {
					//if (field.CheckEdge(4, field.GetPacMan())) { field.Edge(1, field.GetPacMan()); }
					field.GetPacMan().MoveRight(field.CheckEdge(1, field.GetPacMan()), field.GetArray());
				}

				break;

			case Keys::Space:
				Pause();
				break;
			case Keys::Enter:
				break;

			case Keys::Esc:
				exit(0);
				break;

			default:
				break;
			}

			PacMenGhostIntersection();
			if (CheckLose()) {
				_dificulty -= 1;
				return;
			}

			int checkfood = field.CheckFood(field.GetPacMan());
			if (checkfood == 1) {
				_score += 1;
				PrintScore();
			}
			else if (checkfood == 2) {
				_score += 5;
				PrintScore();
				_killmode = 1;
				kill_mode_counter = 0;

				for (int i = 0; i < ghosts.size(); i++) {
					ghosts[i]->SetColor(RGB(0,0,255));//  KILL MODE SET NEW COLORS
				}

			}
			else if (checkfood == 10) {
				victory();
				return;
			}

			//cout << _score;

			if (even_cycle) {
				even_cycle = false;
				field.GetPacMan().SetContains(4);
			}
			else { even_cycle = true; field.GetPacMan().SetContains(5); }
		}
	}
}