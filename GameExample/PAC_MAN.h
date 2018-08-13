#pragma once
#include "stdafx.h"

//class Cell;
class Field;

class Character  :public Cell {
	

	int _rotation ;
protected:
	Cell * _current_position = nullptr;//

	public:
		//virtual bool Get_Is_Dead() = 0;// {  }
		//virtual bool Get_Is_In_Room() = 0;// { return _is_in_room; }
		Character() = default;
		void Set_Current_Position(Cell * current_position) { _current_position = current_position;	}
		Cell * Get_Current_Position() { return _current_position; }
		
	/*	Character(short x, short y, ForegroundColor color)
		{
			_xPos = x;
			_yPos = y;
			_color = color;
		}*/
		
		/*void Draw()
		{
			Console::SetColor(_color, BackgroundColor::Black);
			Console::SetCoord(_xPos, _yPos);
			cout << _simbol;
		}
	*/
	/*	void Clear()
		{
			Console::SetColor(_color, BackgroundColor::Black);
			Console::SetCoord(_xPos, _yPos);
			cout << " ";
		}
	*/
		int GetRotation() { return _rotation; }
		void SetRotation(int rotation) { _rotation = rotation; }

		//bool IsFood();
		//	Field::GetArray();
		

		void MoveUp(bool is_edge , vector <Cell*> &array)
		{
			//CheckWall();
			//CheckEdge();
		//	Clear();

			Print(RGB(0,0,0), 3, GetRotation());
			if (GetContains() == 6 || GetContains() == 7) {
			
						_current_position->Print(RGB(255, 0, 0), _current_position->GetContains());
						
			}
		
			//_yPos--;

			COORD coord = GetCoord();
			SetCoord(coord.X, --coord.Y);
			_current_position = _current_position->GetU();

			_rotation = 4;

			if(is_edge) 	SetCoord(coord.X, 25);
			
			//SetRotation();
			//Draw();
			Print(GetColor(),GetContains(), GetRotation());

		}
	
		void MoveDown(bool is_edge, vector <Cell*> &array)
		{
			//Clear();
			Print(RGB(0, 0, 0), 3, GetRotation());

			if (GetContains() == 6 || GetContains() == 7) {
			//	for (int i = 0; i < array.size(); i++) {
					//if (array[i]->GetCoord().X == GetCoord().X  && array[i]->GetCoord().Y == GetCoord().Y) {
						//Print(RGB(0, 0, 0), 3, GetRotation());
					/*	array[i]->Print(RGB(255, 0, 0), array[i]->GetContains());*/
						_current_position->Print(RGB(255, 0, 0), _current_position->GetContains());
					//	break;
					//}
			//	}
			}

			//_yPos++;
			COORD coord = GetCoord();
			SetCoord(coord.X, ++coord.Y);
			_current_position = _current_position->GetD();
			_rotation = 2;

			if (is_edge) 	SetCoord(coord.X, 0);
			//Draw();
			Print(GetColor(), GetContains(), GetRotation());
		}
	
		void MoveLeft(bool is_edge, vector <Cell*> &array)
		{
			//Clear();
			Print(RGB(0, 0, 0), 3, GetRotation());

			if (GetContains() == 6 || GetContains() == 7) {
				_current_position->Print(RGB(255, 0, 0), _current_position->GetContains());
			}

			COORD coord = GetCoord();
			SetCoord(--coord.X, coord.Y);
			_current_position = _current_position->GetL();
			_rotation = 3;

			if (is_edge) 	SetCoord(30, coord.Y);
			//Draw();
			Print(GetColor(), GetContains(), GetRotation());
		}
	
		void MoveRight(bool is_edge, vector <Cell*> &array)
		{
			//Clear();
			Print(RGB(0, 0, 0), 3, GetRotation());

			if (GetContains() == 6 || GetContains() == 7) {
				_current_position->Print(RGB(255, 0, 0), _current_position->GetContains());
			}

			COORD coord = GetCoord();
			SetCoord(++coord.X, coord.Y);
			_current_position = _current_position->GetR();
			_rotation = 1;

			if (is_edge) 	SetCoord(1, coord.Y);
			//Draw();
			Print(GetColor(), GetContains(), GetRotation());
		}


};

class PAC_MAN : public Character{

	

public:
	//virtual COLORREF GetColor() { return _color; }
	//virtual int GetContais() { return _contains; }

	//virtual bool Get_Is_Dead() { return false; }
	//virtual bool Get_Is_In_Room() { return false; }

	//PAC_MAN() = default;
	PAC_MAN() {

		SetColor(RGB(255, 255, 0));
		SetContains(4);
		SetCoord(9,9);

		SetRotation(1);


		
	
	}


	//void SetContains(int contains) { _contains = _contains; }
//	void SetRotation(int direction) { _rotation = direction; }
	void Death() {}//print

};

class Enemy : public Character {
	bool _is_dead = false;
	COORD _target;
	bool _is_in_room = true;

public:

	//Enemy() = default;

	Enemy() {
		Set_Random_Color();
		
		SetContains(6);
		SetCoord(11, 11);
		SetRotation(4);

	}

	void Set_Random_Color() {
		int color = rand() % 7 + 1;
		switch (color) {
		case 1:
			SetColor(RGB(30, 144, 255));
			break;
		case 2:
			SetColor(RGB(255, 255, 0));
			break;
		case 3:
			SetColor(RGB(255, 0, 255));
			break;
		case 4:
			SetColor(RGB(138, 43, 226));
			break;
		case 5:
			SetColor(RGB(165, 42, 42));
			break;
		case 6:
			SetColor(RGB(250, 128, 114));
			break;
		case 7:
			SetColor(RGB(205, 92, 92));
			break;
		}
	
	}

	

	void Set_Is_In_Room(bool is_in_room) { _is_in_room = is_in_room; }
	 bool Get_Is_In_Room() { return _is_in_room; }

	void Set_Is_Dead(bool is_dead) {_is_dead = is_dead;	}
	 bool Get_Is_Dead() { return _is_dead; }

	COORD GetTarget() { return _target; }
	void SetTarget(int x , int y ) { _target.X = x;  _target.Y = y;}


	bool CheckTarget() {
		if (GetCoord().X == _target.X && GetCoord().Y == _target.Y) {
			return true;
		}return false;
	}

};