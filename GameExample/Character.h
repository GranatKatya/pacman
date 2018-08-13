#pragma once
#include "stdafx.h"

//
//class Character
//{
//	char _simbol = 2;
//
//	short _xPos = 20;
//	short _yPos = 12;
//
//	ForegroundColor _color = ForegroundColor::Yellow;
//
//public:
//	Character() = default;
//	Character(short x, short y, ForegroundColor color)
//	{
//		_xPos = x;
//		_yPos = y;
//		_color = color;
//	}
//	
//	void Draw()
//	{
//		Console::SetColor(_color, BackgroundColor::Black);
//		Console::SetCoord(_xPos, _yPos);
//		cout << _simbol;
//	}
//
//	void Clear()
//	{
//		Console::SetColor(_color, BackgroundColor::Black);
//		Console::SetCoord(_xPos, _yPos);
//		cout << " ";
//	}
//
//	void MoveUp()
//	{
//		Clear();
//		_yPos--;
//		Draw();
//	}
//
//	void MoveDown()
//	{
//		Clear();
//		_yPos++;
//		Draw();
//	}
//
//	void MoveLeft()
//	{
//		Clear();
//		_xPos--;
//		Draw();
//	}
//
//	void MoveRight()
//	{
//		Clear();
//		_xPos++;
//		Draw();
//	}
//};
