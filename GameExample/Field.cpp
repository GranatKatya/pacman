#include "stdafx.h"
//class Cell;



Feild::Feild() = default;
Feild::Feild(int dificulty) {
	

	for (int i = 1; i < dificulty +1; i++) {
		Enemy *gh = new Enemy();
		gh->SetCoord( 10+ i*2 , 12);
		//gh->SetTarget(10 + i * 2 , 9);
		gh->SetTarget(15,9);
		_ghosts.push_back(gh);

	}
}

PAC_MAN& Feild::GetPacMan() { return _pac_man; }


void Feild::InitializeField() {
	srand(time(NULL));

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 25; j++) {

			if (((i == 1 || i == 30) && j != 13) ||  // frame
				(j == 1 || j == 25) ||

				((j >= 3 && j <= 4) && ((i >= 3 && i <= 6) || (i >= 8 && i <= 13) || (i >= 18 && i <= 23) || (i >= 25 && i <= 28))) || // top line
				(j == 6 && ((i >= 3 && i <= 6) || (i >= 25 && i <= 28) || (i >= 11 && i <= 19))) || // second line
				(j == 8 && (i != 7 && i != 14 && i != 17 && i != 24)) ||
				((j == 10) && (i >= 10 && i <= 21 && i != 15 && i != 16)) ||
				(j == 12 && (i <= 6 || i >= 25)) ||
				((j == 14) && (i <= 6 || i >= 25 || (i >= 10 && i <= 21))) ||
				// center
				(j == 16 && (i <= 6 || i >= 25 || (i >= 11 && i <= 19))) ||
				(j == 18 && ((i >= 3 && i <= 6) || (i >= 8 && i <= 13) || (i >= 18 && i <= 23) || (i >= 25 && i <= 28))) ||
				(j == 20 && (i <= 3 || (i >= 11 && i <= 19) || i >= 28)) ||
				(j == 22 && ((i >= 3 && i <= 13) || (i >= 18 && i <= 28))) ||



				((i == 6 || i == 25) && ((j >= 8 && j <= 12) || (j >= 14 && j <= 16) || (j >= 18 && j <= 20))) ||
				((i == 8 || i == 23) && ((j >= 6 && j <= 12) || (j >= 14 && j <= 16) || (j >= 20 && j <= 22))) ||
				((i == 15 || i == 16) && (j <= 4 || (j <= 6 && j >= 8) || (j >= 16 && j <= 18) || (j >= 20 && j <= 23))) ||
				((i == 10 || i == 21) && (j >= 10 && j <= 14))) {
				Wall *ptr_wall = new Wall(i, j);
				_array.push_back(ptr_wall);
				//delete ptr_wall;
			}
			else {

				int random = rand() % 50;

				int contains = 1;
				if (random == 0) {
					contains = 2;
				}
				if (((j == 15) || (j >= 9 && j <= 11)) && ((i >= 2 && i <= 5) || (i >= 26 && i <= 29)) ||// НЕ ЗАПОЛНЯЕМ ЕДУ
					((i >= 9 && i <= 22) && (j >= 9 && j <= 15))) {
					//continue;
					EmptyCell *ptr_wall = new EmptyCell(i, j, 0);
					_array.push_back(ptr_wall);
				}
				else {//ЗАПОЛНЯЕМ ЕДУ
					EmptyCell *ptr_wall = new EmptyCell(i, j, contains);
					_array.push_back(ptr_wall);
					food_count++;
				}

			}

			if (i != 1) {// по ходу заполнения массива 
				//Cell & w = _array[_array.size - 26];
				_array[_array.size() - 1]->SetL(&(*_array[_array.size() - 26]));
				_array[_array.size() - 26]->SetR(&(*_array[_array.size() - 1]));// устанавливаем начение правой клетки для предыдущей левой
			}
			if (j != 1) {// по ходу заполнения массива //ВЫСОТА
				_array[_array.size() - 1]->SetU(&(* _array[_array.size() - 2]));//---?????????????????????????????????????????????????????????????????????????????????/
				_array[_array.size() - 2]->SetD(&(*_array[_array.size() - 1]));// устанавливаем начение НИЖНЕЙ клетки для предыдущей ВЕРХНЕЙ

			}
						
		}//
	}
	GetCellByCoord(15, 10)->SetContains(8);//ворота
	GetCellByCoord(16, 10)->SetContains(8);



	_array[12]->SetL(&(*_array[737]));
	_array[737]->SetR(&(*_array[12]));


	GetPacMan().Set_Current_Position(&(*_array[208]));// = _array[233];

	for (int i = 0; i < _ghosts.size(); i++) {
		_ghosts[i]->Set_Current_Position(&(*_array[236 + (i+1) * 50]));
			
		
	}

}

void Feild::Print() {
	for (int i = 0; i <= _array.size() - 1; i++) {
		_array[i]->Print(_array[i]->GetColor(), _array[i]->GetContains());
	}
	_pac_man.Print(_pac_man.GetColor(), _pac_man.GetContains(), _pac_man.GetRotation());

	for (int i = 0; i <= _ghosts.size() - 1; i++) {
		_ghosts[i]->Print(_ghosts[i]->GetColor(), _ghosts[i]->GetContains());
	}

}



//void Clear() {}


bool Feild::CheckWalls(int direction, Character &character) {

	//COORD  coord = character.GetCoord();
	Cell *current_position  = character.Get_Current_Position();
	Cell * next_position = NULL;
	switch (direction) {
	case 1:
		next_position = current_position->GetR();
		//coord.X++;
		break;
	case 2:
		next_position = current_position->GetD();
		//coord.Y++;
		break;
	case 3:
		next_position = current_position->GetL();
		//coord.X--;
		break;
	case 4:
		next_position = current_position->GetU();
		//coord.Y--;
		break;
	}
	//for (int i = 0; i < _array.size() - 1; i++) {
	//	if (coord.X == _array[i]->GetCoord().X  &&  coord.Y == _array[i]->GetCoord().Y) {
			if (next_position->GetContains() == 3) return true;
			else return false;
		//}
	//}
	return false;

}

bool Feild::CheckEdge(int direction, Character &character) {

	COORD  coord = character.GetCoord();
	switch (direction) {
	case 1:
		coord.X++;
		break;
	case 2:
		coord.Y++;
		break;
	case 3:
		coord.X--;
		break;
	case 4:
		coord.Y--;
		break;
	}


	if (coord.X < 1 || coord.X >30 || coord.Y < 1 || coord.Y >25) {
		return true;
	}
	
	else return false;

}


int Feild::CheckFood(Character &character) {

	for (int i = 0; i <= _array.size() - 1; i++) {
		if (_array[i]->GetCoord().X == character.GetCoord().X  &&
			_array[i]->GetCoord().Y == character.GetCoord().Y) {
			if (_array[i]->GetContains() == 1) {

				_array[i]->SetContains(0);// убрали еду
				food_count--;
				if (food_count == 0)
					return 10; //Game::victory();

				return 1;
			}
			else if (_array[i]->GetContains() == 2) {

				_array[i]->SetContains(0);// убрали ништяк
				food_count--;
				if (food_count == 0)
					return 10; //Game::victory();

				return 2;

			}

		}
	}
	return 0;
}

vector <Cell*> & Feild::GetArray() {	return _array;	}