#pragma once
#include "lib\framework.hpp"
#include "Title.h"
#include "Common.h"
#include "Select.h"
#include "Game.h"


class Scene{

private:
	Title title;
	Select select;
	Game game;

	SceneName scene_move;



public:
	

	Scene();

	void setup();
	void update();
	void draw();
	void shift();


};


