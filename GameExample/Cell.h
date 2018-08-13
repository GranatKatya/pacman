#pragma once
#include "stdafx.h"


class Cell {

	COORD _coord; // logical coords of cell
	int _x_shift =10; // shift of logical structure from console margin
	int _y_shift = 10;
	int _width = 20; // size of cell in pixels
	int _height = 20;
	COLORREF _color;
	int _contains;


	Cell * _right_cell = nullptr;
	Cell * _left_cell = nullptr;
	Cell * _up_cell = nullptr;
	Cell * _down_cell = nullptr;

	

public:



	void SetR(Cell *right_cell) { _right_cell =right_cell; }
	void SetL(Cell *left_cell) { _left_cell = left_cell; }
	void SetU(Cell *up_cell) { _up_cell = up_cell; }
	void SetD(Cell *down_cell) { _down_cell = down_cell; }

	Cell *GetR() { return _right_cell; }
	Cell *GetL() { return _left_cell; }
	Cell *GetU() { return _up_cell; }
	Cell *GetD() { return _down_cell; }


	Cell() = default;
	Cell(int x, int y, int x_shift = 10, int y_shift = 10, int width = 20, int hight = 20) {
		_coord.X = x;
		_coord.Y = y;

		_x_shift = x_shift;
		_y_shift = y_shift;
		_width = width;
		_height = hight;
	}

	void TransformCoord(COORD &coord) { // Transform logical coords into pixels

		coord.X = _x_shift + (this->_width*this->_coord.X);
		coord.Y = _y_shift + (this->_height*this->_coord.Y);
	}


	void Print(COLORREF color, int shape, int direction = 1) {

		HWND myconsole = GetConsoleWindow();
		HDC mydc = GetDC(myconsole);

		COORD coord;
		TransformCoord(coord);

		if (shape == 1) { // food
			for (int i = 8; i < 13; ++i)
			{
				for (int j = 8; j < 13; ++j)
				{
					if ((i + j >18 && i + j <22) && (i - j <2 && j - i <2)) {
						SetPixel(mydc, coord.X + i, coord.Y + j, color);
					}

				}
			}

		}
		else if (shape == 2) {

			for (int i = 4; i < 16; ++i)
			{
				for (int j = 4; j < 16; ++j)
				{
					if ((i + j >14 && i + j <26) && (i - j <6 && j - i <6)) {
						SetPixel(mydc, coord.X + i, coord.Y + j, color);
					}

				}
			}
		}

		else if (shape == 3) {// wall
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					SetPixel(mydc, coord.X + i, coord.Y + j, color);
				}
			}


		}
		else if (shape == 4) // close
		{
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					if (((10 - i) * (10 - i) + (10 - j) * (10 - j)) <= 81) {
						SetPixel(mydc, coord.X + i, coord.Y + j, color);
					}
				}
			}
		}
		else if (shape == 5) // open
		{

			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{


					if (((10 - i) * (10 - i) + (10 - j) * (10 - j)) <= 81) {

						if (direction == 1) {
							if ( i > 10 && (abs(10 - j) < abs(10 - i))) { continue; }

						}
						else if (direction == 2) {
						if (j > 10 && (abs(10 - i) < abs(10 - j))) { continue; }
						}
						else if (direction == 3) {
							if (i < 10 && (abs(10 - j) < abs(10 - i))) { continue; }

						}
						else if (direction == 4) {
							if (j < 10 && (abs(10 - i) < abs(10 - j))) { continue; }
						}

						SetPixel(mydc, coord.X + i, coord.Y + j, color);

					}
				}
			}

		}
		else if (shape == 6) // enemy ghost
		{
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					if ((((10 - i) * (10 - i) + (7 - j) * (7 - j)) <= 36) ||( ( i >=5 && i <=15)  && (j >= 7 && j<=18))  )
					{
						SetPixel(mydc, coord.X + i, coord.Y + j, color);
					}
					if (((7 - i) * (7 - i) + (7 - j) * (7 - j)) <= 6) {
						SetPixel(mydc, coord.X + i, coord.Y + j, RGB(255,255,255));
					}
					if (((13 - i) * (13 - i) + (7 - j) * (7 - j)) <= 6) {
						SetPixel(mydc, coord.X + i, coord.Y + j, RGB(255, 255, 255));
					}
				}
			}

		}
		else if (shape == 7) { // KILL MODE // 8 
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					if (((5 - i) * (5 - i) + (5 - j) * (5 - j)) <= 16) {
						SetPixel(mydc, coord.X + i, coord.Y + j, RGB(255, 255, 255));
					}
					if (((15 - i) * (15 - i) + (5 - j) * (5 - j)) <= 16) {
						SetPixel(mydc, coord.X + i, coord.Y + j, RGB(255, 255, 255));
					}
				}
			}
		}
		else if (shape == 11) {
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					if (((7 - i) * (7 - i) + (7 - j) * (7 - j)) <= 25) {
						SetPixel(mydc, coord.X + i, coord.Y + j, color);
					}
					if (((13 - i) * (13 - i) + (7 - j) * (7 - j)) <= 25) {
						SetPixel(mydc, coord.X + i, coord.Y + j,color);
					}
				}
			}
			for (int i = 2; i < 18; ++i)
			{
				for (int j = 10; j < 18; ++j)
				{
					if ((i + j > 12 && i + j < 28) && (i - j < 8 && j - i < 8)) {
						SetPixel(mydc, coord.X + i, coord.Y + j, color);
					}
					
				}
			}

		}


		ReleaseDC(myconsole, mydc);
	}
	void PrintByTemplate(COLORREF color,bool templates[20][20]) {

		HWND myconsole = GetConsoleWindow();
		HDC mydc = GetDC(myconsole);

		COORD coord;
		TransformCoord(coord);

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				if (templates[j][i]) {
					SetPixel(mydc, coord.X + i, coord.Y + j, color);
				}
			}
		}
		ReleaseDC(myconsole, mydc);
	}



	virtual COLORREF GetColor() { return _color; }
	virtual int GetContains() { return _contains; }

	void SetColor(COLORREF color) { _color = color; }
	void SetContains(int contains) { _contains = contains; }
	void SetCoord(int x, int y) {
		_coord.X = x; _coord.Y = y;
	}
	COORD GetCoord() { return _coord; }

	void Clear() {}

};
