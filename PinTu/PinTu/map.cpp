#include "map.h"

Map::Map(string whitePath, string picturePath) {
	this->hwnd = initgraph(WIDTH, HEIGHT);
	loadimage(&white, whitePath.c_str(), IMGW, IMGH);
	loadimage(&picture, picturePath.c_str(), WIDTH, HEIGHT);
	srand((unsigned int)time(nullptr));
	array<int, 16> temp = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	random_shuffle(temp.begin(), temp.end() - 1);
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = temp[count++];
		}
	}
}

void Map::drawMap() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int x = j * IMGW;
			int y = i * IMGH;
			if (map[i][j] == 15) {
				putimage(x, y, &white);
			}
			else {
				int row = map[i][j] / 4;
				int col = map[i][j] % 4;
				putimage(x, y, IMGW, IMGH, &picture, col*IMGW, row*IMGH);
			}
		}
	}
}

int Map::getRow() { 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 15) {
				return i;
			}
		}
	}
	return -1;
}

int Map::getCol() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 15) {
				return j;
			}
		}
	}
	return -1;
}

void Map::swapValue(int r1, int c1, int r2, int c2) {
	swap(map[r1][c1], map[r2][c2]);
}

bool Map::isOrder(){
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != count++) return false;
		}
	}
	return (map[3][0] == 12);
}

HWND Map::getHwnd()
{
	return this->hwnd;
}
