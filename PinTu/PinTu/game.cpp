#include "game.h"

Game::Game() :  map_ptr(new Map("blank.png", "2.jpg")) {

}

void Game::run() {
	EASYXMSG m;
	while (1) {
		peekmessage(&m, EM_MOUSE);
		map_ptr->drawMap();
		// °×¿éµÄÐÐÁÐ
		int blank_row = map_ptr->getRow();
		int blank_col = map_ptr->getCol();

		if (m.message == WM_LBUTTONDOWN) {
			int m_row = m.y / IMGH;
			int m_col = m.x / IMGW;
			
			if (   (m_row == blank_row && m_col == blank_col - 1) || (m_row == blank_row && m_col == blank_col + 1)
				|| (m_row == blank_row - 1 && m_col == blank_col) || (m_row == blank_row + 1 && m_col == blank_col)) {

				map_ptr->swapValue(m_row, m_col, blank_row, blank_col);
			}

		}
		if (map_ptr->isOrder()) {
			MessageBox(map_ptr->getHwnd(), "11", "22", MB_OK);
			break;
		}
	}
}

Game::~Game(){
	delete map_ptr;
}
