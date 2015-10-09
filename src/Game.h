#pragma once
#include "lib\framework.hpp"
#include "Common.h"
#include "Map.h"


class Game{

private:
	Map map;


public:


	void setup();
	void update();
	void draw();
	SceneName shift();




};