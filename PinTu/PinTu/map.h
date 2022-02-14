#pragma once
#include "common.h"
class Map {
public:
	Map(string whitePath, string picturePath);
	void drawMap();
	int getRow();
	int getCol(); 
	void swapValue(int r1, int c1, int r2, int c2);
	bool isOrder();
	HWND getHwnd();
protected:
	IMAGE white;
	IMAGE picture;
	array<array<int, 4>, 4> map;
	HWND hwnd;
};
