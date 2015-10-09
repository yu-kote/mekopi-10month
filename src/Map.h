#pragma once
#include "lib\framework.hpp"
#include "Common.h"




class Map{

private:

	enum{
		MAP_X = 32,
		MAP_Y = 64,
	};

	enum TextMap{
		STAGE1,
		//STAGE2,
		//STAGE3,
		//STAGE4,


		STAGE_MAX,
	};
	enum BlockNum{
		AIR_BLOCK = '0',
		BLOCK = '1',
		PLAYER_START_POS = 'P',
	};


	struct Mapdate : TextureObject
	{
		char status;
	};

	Mapdate map[MAP_Y][MAP_X];
	std::ifstream* map_type[STAGE_MAX];
	

	const int draw_range = 300;


public:

	Map();


	void setup();
	void update();
	void draw();


};