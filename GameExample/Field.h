#pragma once
#include "stdafx.h"

class Game;

class Wall :public Cell {
	//COLORREF _color = RGB(0,0,255);
	//ForegroundColor _color = ForegroundColor::White;
	//int _contains = 3;

public:
	Wall() = default;
	Wall(int x, int y) :Cell(x,y) {
		SetColor(RGB(0,0, 255));
		SetContains(3);
	}
	//void Print(COLORREF color, int shape) {}

	/*virtual COLORREF GetColor() {
		return _color; }
	virtual int GetContais() {
		return _contains; }*/



};

class EmptyCell : public Cell {
	//COLORREF _color =RGB (255, 0, 0);
	//ForegroundColor _color = ForegroundColor::Black;
	//int _contains;

public:
	EmptyCell() = default;
	EmptyCell(int x, int y, int contains) :Cell(x, y) {
	//	_contains = contains;
		SetColor(RGB(255, 0, 0));
		SetContains(contains);
	}

//	void Print(COLORREF color, int shape) {}
	//Character *characters;
	
	//virtual COLORREF GetColor() { 
	//	return _color; }
	//virtual int GetContais() {
	//	return _contains; }
 
};
//class Cell;


class Feild {

	vector <Cell*> _array;
	PAC_MAN _pac_man;
	vector <Enemy*>	 _ghosts;


	int food_count;
	//ForegroundColor _color = ForegroundColor::Yellow;

public:

	/*void DeleteArray() {
		cout << _array.size();
		for (int i = 0; i < _array.size() + 1; i++) {
			_array.pop_back();
		}cout << _array.size();

		cout << _ghosts.size();
		for (int i = 0; i < _ghosts.size() + 1; i++) {
			_ghosts.pop_back();
		}cout << _ghosts.size();

		_pac_man.SetCoord(9, 9);
	}*/

	Feild();// = default;
	Feild(int dificulty); /*{
		for (int i = 0; i < dificulty; i++) {
			Enemy *gh = new Enemy;
			_ghosts.push_back(gh);
		}
	}*/

//	~Feild() { delete _pac_man; }

	Cell * GetCellByCoord(int x, int y) {
		return _array[(x - 1) * 25 + (y-1)];
	}

	//bool CheckGates(int direction, Enemy &enemy);


	bool CheckGates(int direction, Enemy &enemy) {

		COORD  coord = enemy.GetCoord();
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

		if (GetCellByCoord(coord.X, coord.Y)->GetContains() == 8) {
			if (!enemy.Get_Is_Dead() && !enemy.Get_Is_In_Room()) {// живой не зайдет в ворота 
				return true;
			}
		}
		return false;
	}

	bool CheckGatesPacMan(int direction, PAC_MAN &enemy) {

		COORD  coord = enemy.GetCoord();
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
		if (coord.X !=0 && coord.X != 31){
			if (GetCellByCoord(coord.X, coord.Y)->GetContains() == 8) {
				//if (!enemy.Get_Is_Dead() && !enemy.Get_Is_In_Room()) {// живой не зайдет в ворота 
				return true;
			}
		}
		return false;
	}


	vector <Cell*> &GetArray();// {	return _array;	}
	vector <Enemy*> &GetGhosts() { return _ghosts; }
	PAC_MAN& GetPacMan();// { return _pac_man; }
	void InitializeField();// {
	//	srand(time(NULL));

	//	for (int i = 1; i <= 30; i++) {
	//		for (int j = 1; j <= 25; j++) {

	//			if (((i == 1 || i == 30) && j != 13) ||  // frame
	//				(j == 1 || j == 25) ||

	//				((j >= 3 && j <= 4) && ((i >= 3 && i <= 6) || (i >= 8 && i <= 13) || (i >= 18 && i <= 23) || (i >= 25 && i <= 28))) || // top line
	//				(j == 6 && ((i >= 3 && i <= 6) || (i >= 25 && i <= 28) || (i >= 11 && i <= 19))) || // second line
	//				(j == 8 && (i != 7 && i != 14 && i != 17 && i != 24)) ||
	//				((j == 10 ) &&  (i >= 10 && i <= 21 && i != 15 && i != 16)) || 
	//				(j==12  && (i <= 6 || i >= 25 ))||
	//				((j == 14) && (i <= 6 || i >= 25 || (i >= 10 && i <= 21 ))) ||
	//				// center
	//				(j == 16 && (i <= 6 || i >= 25 || (i >= 11 && i <= 19))) ||
	//				(j == 18 && ((i >= 3 && i <= 6) || (i >= 8 && i <= 13) || (i >= 18 && i <= 23) || (i >= 25 && i <= 28))) ||
	//				(j == 20 && (i <= 3 || (i >= 11 && i <= 19) || i >= 28)) ||
	//				(j == 22 && ((i >= 3 && i <= 13) || (i >= 18 && i <= 28))) ||



	//				((i == 6 || i == 25) && ((j >= 8 && j <= 12) || (j >= 14 && j <= 16) || (j >= 18 && j <= 20))) ||
	//				((i == 8 || i == 23) && ((j>= 6 && j <= 12 ) || ( j >= 14 && j<= 16 ) || (j >=20 && j <= 22) )) ||
	//				((i == 15 || i ==16) && (j<= 4 || (j<= 6 && j >= 8) || (j >=16 && j <=18  )  || ( j >=20 && j <=23))) ||
	//				((i ==10 || i==21  )  && (j >= 10 && j <= 14))){
	//				Wall *ptr_wall = new Wall(i, j);
	//				_array.push_back(ptr_wall);
	//			}
	//			else {
	//			
	//				int random = rand() % 50;

	//				int contains = 1;
	//				if (random == 0) {
	//					contains = 2;
	//				}
	//				if (((j == 15) || (j >= 9 && j <= 11)) && ((i >= 2 && i <= 5) || (i >= 26 && i <= 29)) ||
	//					((i >= 9 && i <= 22) && (j >= 9 && j <= 15))) {
	//					continue;
	//				}else {
	//					EmptyCell *ptr_wall = new EmptyCell(i, j, contains);
	//					_array.push_back(ptr_wall);
	//					food_count++;
	//				}
	//				
	//			}
	//			 
	//	
	//			 
	//		}//
	//	}
	//}

	void Print(); /*{
		for (int i = 0; i <= _array.size()-1; i++) {
			_array[i]->Print(_array[i]->GetColor(), _array[i]->GetContains());
		}
		_pac_man.Print(_pac_man.GetColor(), _pac_man.GetContains(), _pac_man.GetRotation());
		
		for (int i = 0; i <= _ghosts.size() - 1; i++) {
			_ghosts[i]->Print(_ghosts[i]->GetColor(), _ghosts[i]->GetContains());
		}

	}*/
	
	

	//void Clear() {}


	bool CheckWalls(int direction, Character &character);/* {

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
		for (int i = 0; i < _array.size() - 1; i++) {
			if (coord.X == _array[i]->GetCoord().X  &&  coord.Y == _array[i]->GetCoord().Y) {
				if (_array[i]->GetContains() == 3) return true;
				else return false;
			}
		}
		return false;

	}*/

	bool CheckEdge(int direction, Character &character);// {
	/*
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
		} else return false;
			
	}
*/

	int CheckFood(Character &character);// {

	//	for (int i = 0; i <= _array.size() - 1; i++) {
	//		if (_array[i]->GetCoord().X == character.GetCoord().X  &&
	//			_array[i]->GetCoord().Y == character.GetCoord().Y) {
	//			if (_array[i]->GetContains() == 1) {

	//				_array[i]->SetContains(0);// убрали еду
	//				food_count--;
	//				if (food_count == 0) 
	//					return 10; //Game::victory();

	//				return 1;
	//			}
	//			else if (_array[i]->GetContains() == 2) {

	//				_array[i]->SetContains(0);// убрали ништяк
	//				food_count--;
	//				if (food_count == 0)
	//					return 10; //Game::victory();

	//				return 2;

	//			}
	//			
	//		}
	//	}
	//	return 0;
	//}

	int GetNextMoveToTarget(Enemy &ghost) {
		int random = rand() % 2;
		int countwals = 0;
		int direction = 1;
		int current_direction = ghost.GetRotation();

		while (countwals < 2) {
			if (random == 0 && ghost.GetCoord().X < ghost.GetTarget().X) { direction = 1; }// direction 1; }
			else if (random == 0 && ghost.GetCoord().X > ghost.GetTarget().X) { direction = 3; }
			else if (random == 1 && ghost.GetCoord().Y < ghost.GetTarget().Y) { direction = 2; }
			else if (random == 1 && ghost.GetCoord().Y > ghost.GetTarget().Y) { direction = 4; }
			if (CheckWalls(direction, ghost) ||  
				((current_direction + 2) % 4 == direction%4)
				|| CheckEdge(direction, ghost) || CheckGates(direction, ghost)
				/*(current_direction== 1 && direction ==3) ||
				(current_direction == 2 && direction == 4) ||
				(current_direction == 3 && direction == 1) ||
				(current_direction == 4 && direction == 2) */
				) {
				countwals++; random++; random %= 2; continue; }
			else return direction;
		}
		direction = current_direction;
		if (!CheckWalls(direction, ghost) && !CheckEdge(direction, ghost) && !CheckGates(direction, ghost)) {
			return direction;
		}
		direction = (current_direction + 3) %4;
		if (direction == 0) { direction = 4; }
		if (!CheckWalls(direction, ghost) && !CheckEdge(direction, ghost) && !CheckGates(direction, ghost)) {
			return direction;
		}
		direction = (current_direction +1) % 4;
		if (direction == 0) { direction = 4; }
		if (!CheckWalls(direction, ghost) && !CheckEdge(direction, ghost) && !CheckGates(direction, ghost)) {
			return direction;
		}
		direction = (current_direction + 2) % 4;
		if (direction == 0) { direction = 4; }
		return direction;

		//while (1) { // если мы не можем идти в нужном направлении , то идем в случайном 
		//	direction = rand() % 4 +1;
		//	if (!CheckWalls(direction, ghost) && ((current_direction+2) %4 != direction %4) && !CheckEdge(direction, ghost)) {
		//		return direction; }

		//}

	}

	bool PacManGhostIntersection() { // проверкп на пересечение 
		COORD coord_pacman = _pac_man.GetCoord();

		for (int i = 0; i < _ghosts.size(); i++) {
			if (coord_pacman.X == _ghosts[i]->GetCoord().X  &&   coord_pacman.Y == _ghosts[i]->GetCoord().Y ) {
				if (!_ghosts[i]->Get_Is_Dead()) {// глаза без привилоса
					return true;
				}
			}
		}
		return false;
	}
};