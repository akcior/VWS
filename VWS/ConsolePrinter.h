#pragma once
#include<cstdio>
#include<exception>
#include<Windows.h>
#include"World.h"
#include<conio.h>

class vec2d;

enum theme {
	WHITE_ON_BLACK = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE,
	RED_ON_BLUE = FOREGROUND_RED|BACKGROUND_BLUE
};

class ConsolePrinter
{
public:
	static void goToXY(int x, int y)
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(output, pos);
	}
	
	static int writeChar(char c) {
		DWORD count;
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		if (WriteConsole(output, &c, 1, &count, NULL)) return c;
		else return EOF;

	}
	static int writeString(const char* str)
	{
		DWORD count;
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		if (WriteConsoleA(output, str, strlen(str), &count, NULL)) return count;
		else return EOF;
	}

	static int printFrame(char symbol, int x, int y, int width, int height) {
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		vec2d consolesize;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(output, &info);
		consolesize.x = info.dwSize.X;
		consolesize.y = info.dwSize.Y;
		if (x + width >= consolesize.x || y + height >= consolesize.y ||
			x + width < 0 || y + height < 0); 
		else {
			int c, v;
			if (width > 0) c = 1;
			else c = -1;
			if (height > 0) v = 1;
			else v = -1;

			goToXY(x, y);
			for (int k = 0; k < 2; k++) {
				for (int i = x; i != x + width; i += c)
				{
					writeChar(symbol);
				}
				goToXY(x, y + height - 1);
			}
			for (int j = y+v; j != y + height - 1; j += v)
			{
				goToXY(x, j);
				writeChar(symbol);
				goToXY(x + width - 1,j);
				writeChar(symbol);
			}
		}
		return 1;
	}
	
	static char getConsoleChar(int x, int y)
	{
		CHAR_INFO *i = (CHAR_INFO*)malloc(sizeof(CHAR_INFO));
		char c;
		COORD size, pos;
		SMALL_RECT rec;
		size.X = size.Y = 1;
		pos.X = 0, pos.Y = 0;
		rec.Left = rec.Right = x;
		rec.Top = rec.Bottom = y;
		ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), i, size, pos, &rec);
		c = i[0].Char.AsciiChar;
		free(i);
		return c;
	}

	static void showCursor(bool t)
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = t;
		SetConsoleCursorInfo(output, &info);
	}

	static void setTitle(const char* s)
	{
		SetConsoleTitle(s);
	}

	static vec2d GetConsoleSize()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		return vec2d(info.dwSize.X, info.dwSize.Y);
	}

	static void setTheme(theme th)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), th);
	}
};