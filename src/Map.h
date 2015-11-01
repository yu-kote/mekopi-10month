#pragma once
#include "lib\framework.hpp"
#include "Common.h"




class Map{

private:

	enum DefaultBlockNum{
		MAP_X = 32,
		MAP_Y = 56,
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
		BLOCK = 'b',
		U_BLOCK = 'c',
		D_BLOCK = 'd',
		L_BLOCK = 'e',
		R_BLOCK = 'f',
		U_L_BLOCK = 'g',
		D_L_BLOCK = 'h',
		U_R_BLOCK = 'j',
		D_R_BLOCK = 'i',
		U_L_R_BLOCK = 'k',
		D_L_R_BLOCK = 'l',
		U_L_D_BLOCK = 'm',
		U_R_D_BLOCK = 'n',
		U_L_R_D_BLOCK = 'o',
		U_D_BLOCK = 'p',
		L_R_BLOCK = 'q',
		PLAYER_START_POS = 'P',
	};

	enum TextureBlock{
		NO_SIDE_BLOCK,
		ONE_SIDE_BLOCK,
		TWO_SIDE_BLOCK,
		THREE_SIDE_BLOCK,
		FOUR_SIDE_BLOCK,
		TWO_PAIR_SIDE_BLOCK,

		BLOCK_TEXTURE_MAX,

	};


	struct MapData : TextureObject
	{
		char status;
	};
	//MapData map[MAP_Y][MAP_X];
	char map_data[MAP_Y][MAP_X];
	int map_wall_data[MAP_Y][MAP_X];

	std::ifstream* map_type[STAGE_MAX];
	std::vector <std::vector< MapData >> map;

	Texture texture_type[BLOCK_TEXTURE_MAX];
	
	const int draw_range = 100;
	Vec2f player_start_pos;
	Vec2f player_pos;
	Vec2f player_size;
	bool player_up_flag;
	bool player_down_flag;
	bool player_left_flag;
	bool player_right_flag;
	bool player_up_flag2;
	bool player_down_flag2;
	bool player_left_flag2;
	bool player_right_flag2;

	enum Direction{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	int player_direction;

	void hit_wall();
	bool boxCollision(Vec2f box_pos, Vec2f box_size,
				 Vec2f box1_pos, Vec2f box1_size);
	bool pointCollision(Vec2f point_pos, Vec2f box_pos, Vec2f box_size);
public:

	Vec2f getStartPos();
	bool getUpFlag();
	bool getDownFlag();
	bool getLeftFlag();
	bool getRightFlag();
	bool getUp2Flag();
	bool getDown2Flag();
	bool getLeft2Flag();
	bool getRight2Flag();


	void setPlayerPos(Vec2f pos);
	void setPlayerSize(Vec2f size);
	void setPlayerDirection(int direction);

	Map();

	void setup();
	void update();
	void draw();


	
};