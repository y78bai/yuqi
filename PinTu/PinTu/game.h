#pragma once
#include "common.h"
#include "map.h"
class Game {
public:
	Game();
	void run();
	~Game();

protected:
	Map* map_ptr;;
};