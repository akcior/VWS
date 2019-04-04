#pragma once
#include<cstdio>
#include<exception>
#include<Windows.h>

class vec2d;

class OutOfConsoleException : public std::exception
{
	const char* what() const override
	{
		return "Unable to print out of a console!";
	}
};
class ConsolePrinter
{
public:
	/*static void initConsole() {
		CONSOLE_SCREEN_BUFFER_INFO info;
		output = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(output, &info);
		consolesize.x = info.dwSize.X;
		consolesize.y = info.dwSize.Y;
		SetConsoleMode(output, ENABLE_PROCESSED_OUTPUT);
	}*/
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
	static int writeString(char* str)
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
			x + width < 0 || y + height < 0) throw OutOfConsoleException();
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
			for (int j = y+v; j != y + height - v; j += v)
			{
				goToXY(x, j);
				writeChar(symbol);
				goToXY(x + width - 1,j);
				writeChar(symbol);
			}
		}
	}

	static void hideCursor()
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(output, &info);
	}
};