#pragma once
#include "lib\framework.hpp"
#include "Common.h"
#include "Map.h"
#include "Player.h"

class Game{

private:
	Map map;
	Player player;

public:


	void setup();
	void update();
	void draw();
	SceneName shift();




};