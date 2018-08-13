#pragma once
#include "stdafx.h"

enum class ForegroundColor
{
	Black = 0,
	Blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Cyan = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	DarkBlue = FOREGROUND_BLUE,
	DarkCyan = FOREGROUND_BLUE | FOREGROUND_GREEN,
	DarkGray = FOREGROUND_INTENSITY,
	DarkGreen = FOREGROUND_GREEN,
	DarkMagenta = FOREGROUND_BLUE | FOREGROUND_RED,
	DarkRed = FOREGROUND_RED,
	DarkYellow = FOREGROUND_GREEN | FOREGROUND_RED,
	Gray = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
	Green = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	Magenta = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
	Red = FOREGROUND_RED | FOREGROUND_INTENSITY,
	White = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Yellow = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
};

enum class BackgroundColor
{
	Black = 0,
	Blue = BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	Cyan = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY,
	DarkBlue = BACKGROUND_BLUE,
	DarkCyan = BACKGROUND_BLUE | BACKGROUND_GREEN,
	DarkGray = BACKGROUND_INTENSITY,
	DarkGreen = BACKGROUND_GREEN,
	DarkMagenta = BACKGROUND_BLUE | BACKGROUND_RED,
	DarkRed = BACKGROUND_RED,
	DarkYellow = BACKGROUND_GREEN | BACKGROUND_RED,
	Gray = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE,
	Green = BACKGROUND_GREEN | BACKGROUND_INTENSITY,
	Magenta = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY,
	Red = BACKGROUND_RED | BACKGROUND_INTENSITY,
	White = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	Yellow = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY
};