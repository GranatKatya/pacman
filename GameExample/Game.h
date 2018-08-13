#pragma once
#include "stdafx.h"

//class Field;
//extern Field field;


enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


void SetColor(int text, int background);
void GotoXY(int X, int Y);


class Game
{
	//	Character smile;
	//	Character enemy{ 5, 5, ForegroundColor::Green };
	int _dificulty ;
	int _score;

	Feild field = (_dificulty);
	bool _killmode = 0;//eat
	//int _life = 3;
	vector<int> _corners_array = { 26,48,723,701 };//����
	vector<Cell*> _lifes;
	bool templates[10][20][20] = {
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 },
			{ 0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		}
	
	};

public:

	int m_pos = 0;          // ������� ����
	int max_pos = 3;        // ������������ ������� ����

	void SetDifficulty(int dificulty) {	_dificulty = dificulty;	}
	int GetDifficulty() { return _dificulty; }

	/*void DeleteArrays() {
		cout << _lifes.size();
		for (int i = 0; i < _lifes.size()+1; i++) {
			_lifes.pop_back();
		}cout << _lifes.size();
		field.DeleteArray();

	}*/
	//Game() = default;
	Game(int dificulty):_dificulty(dificulty) {
		for (int i = 0; i < 3; i++) {
			AddLife();
		}
		//_dificulty = dificulty;
	}
	void AddLife() {
		
		Cell *life = new Cell(GetLives().size()+1,1,650,490);
		//life->SetContains(11);
		//life->SetColor(RGB(255,0,0));
		_lifes.push_back(life);
	}
	vector<Cell*> &GetLives() { return _lifes; }

	void PrintLife() {
		//clean
		/*for (int i = 0; i < GetLives().size(); i++) {
			GetLives()[i]->Print(RGB(0, 0, 0), 11);
		}*/
		for (int i = 0; i < GetLives().size(); i++) {
			_lifes[i]->Print(RGB(255, 0, 0),11);
		}
	}
	void RemoveLife() {
		for (int i = 0; i < GetLives().size(); i++) {
			_lifes[i]->Print(RGB(0, 0, 0), 11);
		}
		_lifes.pop_back();
		PrintLife();
	}

	bool CheckLose() {
		
		if (_lifes.size() == 0) {
			system("cls");
			_dificulty = 2;
			_score = 0;

			for (int i = 0; i < 3; i++) {
				AddLife();
			}
			
			GotoXY(40,12);
		 cout << "You lose" << endl; 
		 _getch();
		 system("cls");
		 return true;
		}
		return false;
	}

	void victory();

	int GetScore();// { return _score; }
	/*void menu();


	void add();
	void dif();
	void go(int x);
	void choice();*/


	void PacMenGhostIntersection();
	void Pause() {
		while (1) //���� ������������ �� ����� �������
		{
			Sleep(200);
			Keys key = Console::GetKey();
			if (key == Keys::Space) { return; }

		}
	}

	/*void PrintScore() {

	}*/


	void TargetGhostsToCorners() {

		for (int i = 0; i < field.GetGhosts().size(); i++) {
			if (field.GetGhosts()[i]->Get_Is_Dead() || field.GetGhosts()[i]->Get_Is_In_Room()) { continue; }// �� ������ ���� ��� ������� ���������

			field.GetGhosts()[i]->SetTarget( field.GetArray()[_corners_array[i%4]]->GetCoord().X , field.GetArray()[_corners_array[i%4]]->GetCoord().Y);
		//������ ���� � ����
		}
	}
	void TargetGhostsToPacMan() {
		for (int i = 0; i < field.GetGhosts().size(); i++) {
			if (field.GetGhosts()[i]->Get_Is_Dead() || field.GetGhosts()[i]->Get_Is_In_Room()) { continue; }// �� ������ ���� ��� ������� ���������

			field.GetGhosts()[i]->SetTarget(field.GetPacMan().GetCoord().X, field.GetPacMan().GetCoord().Y);//������ ���� -�������
		}
	}
	void TargetGhostsAwayFromPacMan() {
		int x = 0;
		int y = 0;
		int ghost_current_x;
		int ghost_current_y;
		for (int i = 0; i < field.GetGhosts().size(); i++) {
			if (field.GetGhosts()[i]->Get_Is_Dead() || field.GetGhosts()[i]->Get_Is_In_Room()) { continue; }// �� ������ ���� ��� ������� ���������  � ���� �  ������� 

			ghost_current_x = field.GetGhosts()[i]->GetCoord().X;
			ghost_current_y = field.GetGhosts()[i]->GetCoord().Y;
			for (;;) {
				if (field.GetPacMan().GetCoord().X < ghost_current_x) {// left PacMan
					x = (rand() % (31 - ghost_current_x)) + (ghost_current_x -1);
				}
				else { x = rand() % ghost_current_x; }


				if (field.GetPacMan().GetCoord().Y < ghost_current_y) {// up PacMan
					y = (rand() % (25 - ghost_current_y)) + ghost_current_y -1;
				}
				else { y = rand() % ghost_current_y; }

				if (field.GetCellByCoord(x+1, y+1)->GetContains() != 3) {//�������� �� ������
					break;
				}
			}
		}
	}
	void PrintScore() {
		int score = _score;
		int number;
		Cell *cell = new Cell(1, 1, 650, 20);
		for (int i = 2; i < 12;i++) {
			cell->Print(RGB(0, 0, 0), 3);
			cell->SetCoord(i,1);
		}
		cell->SetCoord(10, 1);
		while (score) {
			number = score % 10;
			score /= 10;
			cell->PrintByTemplate(RGB(255, 122, 0), templates[number]);
			cell->SetCoord(cell->GetCoord().X - 1, 1);
		}
	}
	void Run();//
	//{
	//	field.InitializeField();
	//	field.Print();
	//	
	//
	//	
	//	//	//smile.Draw();
	//	//	enemy.Draw();

	//	bool even_cycle = false;
	//	while (true)
	//	{
	//		while (!_kbhit()) //���� ������������ �� ����� �������
	//		{
	//			//enemy.MoveDown();
	//			Sleep(200);
	//		}

	//		Keys key = Console::GetKey();

	//		switch (key)
	//		{
	//		case Keys::ArrowUp:
	//			if (!field.CheckWalls(4, field.GetPacMan())) {
	//				//if (field.CheckEdge(4, field.GetPacMan())) {
	//				//	field.Edge(4, field.GetPacMan()); }
	//				field.GetPacMan().MoveUp(field.CheckEdge(4, field.GetPacMan()));

	//			}

	//			break;

	//		case Keys::ArrowDown:
	//			if (!field.CheckWalls(2, field.GetPacMan())) {
	//				//if (field.CheckEdge(4, field.GetPacMan())) { field.Edge(2, field.GetPacMan()); }
	//				field.GetPacMan().MoveDown(field.CheckEdge(2, field.GetPacMan()));
	//			}

	//			break;

	//		case Keys::ArrowLeft:
	//			if (!field.CheckWalls(3, field.GetPacMan())) {
	//				//if (field.CheckEdge(4, field.GetPacMan())) { field.Edge(3, field.GetPacMan()); }
	//				field.GetPacMan().MoveLeft(field.CheckEdge(3, field.GetPacMan()));
	//			}

	//			break;

	//		case Keys::ArrowRight:
	//			if (!field.CheckWalls(1, field.GetPacMan())) {
	//				//if (field.CheckEdge(4, field.GetPacMan())) { field.Edge(1, field.GetPacMan()); }
	//				field.GetPacMan().MoveRight(field.CheckEdge(1, field.GetPacMan()));
	//			}

	//			break;

	//		case Keys::Space:
	//			break;
	//		case Keys::Enter:
	//			break;

	//		case Keys::Esc:
	//			exit(0);
	//			break;

	//		default:
	//			break;
	//		}


	//		int checkfood = field.CheckFood(field.GetPacMan());
	//		if (checkfood ==1) {
	//			_score += 1;
	//		}
	//		else if(checkfood == 2) {
	//			_score += 5;
	//		}
	//		//cout << _score;

	//		if (even_cycle) {
	//			even_cycle = false;
	//			field.GetPacMan().SetContains(4);
	//		}
	//		else { even_cycle = true; field.GetPacMan().SetContains(5); }
	//	}
	//}
};
