#include "Map.h"

Map::Map(){

	map = std::vector <std::vector< MapData >>((MAP_Y), std::vector<MapData>(MAP_X));

	//ファイルをchar型のポインタで指す
	const char* map_name[STAGE_MAX] = {
		"res/MapTextData/Stage1.txt",
	};
	//ifstream型のポインタの箱にnewする？・・・わからね！
	for (int index = 0; index < STAGE_MAX; index++){
		map_type[index] = new std::ifstream(map_name[index]);
	}

	map.resize(MAP_X * 2);
	for (int i = 0; i < MAP_Y; i++)
		map[i].resize(MAP_Y * 2);

	for (int y = 0; y < MAP_Y; y++){
		for (int x = 0; x < MAP_X; x++){
			*map_type[STAGE1] >> map_data[y][x];
			map[y][x].status = map_data[y][x];
			map[y][x].size = Vec2f(100, 100);
			map[y][x].pos.x() = map[y][x].size.x() * x;
			map[y][x].pos.y() = -map[y][x].size.y() * y;
			map[y][x].cut_pos = Vec2f(0, 0);
			map[y][x].cut_size = Vec2f(31.6, 31.6);
			map[y][x].angle = 0;
			map[y][x].center = Vec2f(map[y][x].size.x() / 2, map[y][x].size.y() / 2);
			map[y][x].zoom = Vec2f(1.0f, 1.0f);
			if (map[y][x].status == PLAYER_START_POS)
				player_start_pos = map[y][x].pos;

			map_wall_data[y][x] = 0;
			switch (map[y][x].status){
			case BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case D_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case L_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case R_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_L_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case D_L_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_R_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case D_R_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_L_R_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case D_L_R_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_L_D_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_R_D_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_L_R_D_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case U_D_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			case L_R_BLOCK:
				map_wall_data[y][x] = 1;
				break;
			}
			//std::cout << x << map_wall_data[y][x] << std::endl;
		}
	}
	player_up_flag = true;
	player_down_flag = true;
	player_left_flag = true;
	player_right_flag = true;
	player_up_flag2 = true;
	player_down_flag2 = true;
	player_left_flag2 = true;
	player_right_flag2 = true;
}

Vec2f Map::getStartPos(){
	return player_start_pos;
}

bool Map::getUpFlag(){
	return player_up_flag;
}
bool Map::getDownFlag(){
	return player_down_flag;
}
bool Map::getLeftFlag(){
	return player_left_flag;
}
bool Map::getRightFlag(){
	return player_right_flag;
}
bool Map::getUp2Flag(){
	return player_up_flag2;
}
bool Map::getDown2Flag(){
	return player_down_flag2;
}
bool Map::getLeft2Flag(){
	return player_left_flag2;
}
bool Map::getRight2Flag(){
	return player_right_flag2;
}

void Map::setPlayerPos(Vec2f pos){
	player_pos = pos;
}
void Map::setPlayerSize(Vec2f size){
	player_size = size;
}
void Map::setPlayerDirection(int direction){
	player_direction = direction;
}

void Map::setup(){
	//player_speed = Vec2f(0, 0);



	const char* texture_name[BLOCK_TEXTURE_MAX] = {
		"res/Texture/no_side_block.png",
		"res/Texture/one_side_block.png",
		"res/Texture/two_side_block.png",
		"res/Texture/three_side_block.png",
		"res/Texture/four_side_block.png",
		"res/Texture/two_pair_side_block.png",

	};

	for (int index = 0; index < BLOCK_TEXTURE_MAX; index++){
		texture_type[index] = Texture(texture_name[index]);
	}

}

void Map::update(){


	//std::cout << map[0][0].pos.x() << std::endl;

}


void Map::draw(){


	drawFillBox(map[0][0].pos.x() - map[0][0].size.x() / 2, map[0][0].pos.y() + map[0][0].size.y() / 2,
				map[0][0].size.x() * MAP_X, -map[0][0].size.y() * MAP_Y, color256(250, 145, 0));
	for (int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			switch (map[y][x].status){
			case AIR_BLOCK:

				break;
			case BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[NO_SIDE_BLOCK], Color::white,
							   map[y][x].angle,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[ONE_SIDE_BLOCK], Color::white,
							   map[y][x].angle,
							   map[y][x].zoom, map[y][x].center);
				break;
			case D_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[ONE_SIDE_BLOCK], Color::white,
							   map[y][x].angle + M_PI,
							   map[y][x].zoom, map[y][x].center);

				break;
			case L_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[ONE_SIDE_BLOCK], Color::white,
							   map[y][x].angle + M_PI / 2,
							   map[y][x].zoom, map[y][x].center);

				break;
			case R_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[ONE_SIDE_BLOCK], Color::white,
							   map[y][x].angle - M_PI / 2,
							   map[y][x].zoom, map[y][x].center);

				break;
			case U_L_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[TWO_SIDE_BLOCK], Color::white,
							   map[y][x].angle,
							   map[y][x].zoom, map[y][x].center);
				break;
			case D_L_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[TWO_SIDE_BLOCK], Color::white,
							   map[y][x].angle + M_PI / 2,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_R_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[TWO_SIDE_BLOCK], Color::white,
							   map[y][x].angle - M_PI / 2,
							   map[y][x].zoom, map[y][x].center);
				break;
			case D_R_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[TWO_SIDE_BLOCK], Color::white,
							   map[y][x].angle + M_PI,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_L_R_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[THREE_SIDE_BLOCK], Color::white,
							   map[y][x].angle - M_PI / 2,
							   map[y][x].zoom, map[y][x].center);

				break;
			case D_L_R_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[THREE_SIDE_BLOCK], Color::white,
							   map[y][x].angle + M_PI / 2,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_L_D_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[THREE_SIDE_BLOCK], Color::white,
							   map[y][x].angle,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_R_D_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[THREE_SIDE_BLOCK], Color::white,
							   map[y][x].angle - M_PI,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_L_R_D_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[FOUR_SIDE_BLOCK], Color::white,
							   map[y][x].angle,
							   map[y][x].zoom, map[y][x].center);
				break;
			case U_D_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[TWO_PAIR_SIDE_BLOCK], Color::white,
							   map[y][x].angle,
							   map[y][x].zoom, map[y][x].center);
				break;
			case L_R_BLOCK:
				drawTextureBox(map[y][x].pos.x(), map[y][x].pos.y(),
							   map[y][x].size.x(), map[y][x].size.y(),
							   map[y][x].cut_pos.x(), map[y][x].cut_pos.y(),
							   map[y][x].cut_size.x(), map[y][x].cut_size.y(),
							   texture_type[TWO_PAIR_SIDE_BLOCK], Color::white,
							   map[y][x].angle + M_PI / 2,
							   map[y][x].zoom, map[y][x].center);
				break;
			case PLAYER_START_POS:

				break;
			}

		}
	}

	hit_wall();
}

void Map::hit_wall(){
	int offset = 5;

	for (int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{

			if (player_direction == UP || player_direction == DOWN)
			{

				if (pointCollision(Vec2f(player_pos.x() - map[y][x].size.x(), player_pos.y() + map[y][x].size.y() / 2 - offset),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_left_flag = false;
					}
					else
					{
						player_left_flag = true;
					}
				}
				else if (pointCollision(Vec2f(player_pos.x() - map[y][x].size.x(), player_pos.y() - map[y][x].size.y() / 2 + offset),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_left_flag2 = false;
					}
					else
					{
						player_left_flag2 = true;
					}
				}
				

				if (pointCollision(Vec2f(player_pos.x() + map[y][x].size.x(), player_pos.y() + map[y][x].size.y() / 2 - offset),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_right_flag = false;
					}
					else
					{
						player_right_flag = true;
					}
				}
				else if (pointCollision(Vec2f(player_pos.x() + map[y][x].size.x(), player_pos.y() - map[y][x].size.y() / 2 + offset),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))	//右の当り判定
				{
					if (map_wall_data[y][x] == 1)
					{
						player_right_flag2 = false;
					}
					else
					{
						player_right_flag2 = true;
					}
				}
			}
			else
			{
				player_left_flag = true;
				player_left_flag2 = true;
				player_right_flag = true;
				player_right_flag2 = true;
			}

			if (player_direction == LEFT || player_direction == RIGHT)
			{
				if (pointCollision(Vec2f(player_pos.x() + map[y][x].size.x() / 2 - offset, player_pos.y() + map[y][x].size.y()),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_up_flag = false;
					}
					else
					{
						player_up_flag = true;
					}
				}
				else if (pointCollision(Vec2f(player_pos.x() - map[y][x].size.x() / 2 + offset, player_pos.y() + map[y][x].size.y()),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_up_flag2 = false;
					}
					else
					{
						player_up_flag2 = true;
					}
				}
				

				if (pointCollision(Vec2f(player_pos.x() + map[y][x].size.x() / 2 - offset, player_pos.y() - map[y][x].size.y()),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_down_flag = false;
					}
					else
					{
						player_down_flag = true;
					}
				}
				else if (pointCollision(Vec2f(player_pos.x() - map[y][x].size.x() / 2 + offset, player_pos.y() - map[y][x].size.y()),
					Vec2f(map[y][x].pos.x() - map[y][x].size.x() / 2, map[y][x].pos.y() - map[y][x].size.y() / 2), map[y][x].size))
				{
					if (map_wall_data[y][x] == 1)
					{
						player_down_flag2 = false;
					}
					else
					{
						player_down_flag2 = true;
					}
				}
			}
			else
			{
				player_up_flag = true;
				player_up_flag2 = true;
				player_down_flag = true;
				player_down_flag2 = true;
			}
		}
	}
}






	//四角と四角の当たり判定
	bool Map::boxCollision(Vec2f box_pos, Vec2f box_size,
						   Vec2f box1_pos, Vec2f box1_size) {



		//drawBox(box1_pos.x(), box1_pos.y(), box1_size.x(), box1_size.y(), 5, Color::white);
		return (
			box_pos.x() < box1_pos.x() + box1_size.x() &&
			box_pos.x() + box_size.x() > box1_pos.x() &&
			box_pos.y() < box1_pos.y() + box1_size.y() &&
			box_pos.y() + box_size.y() > box1_pos.y());
	}

	//点と四角の当り判定
	bool Map::pointCollision(Vec2f point_pos, Vec2f box_pos, Vec2f box_size){

		drawPoint(point_pos.x(), point_pos.y(), 10, Color::yellow);

		return (point_pos.x() > box_pos.x() &&
				point_pos.x() < box_pos.x() + box_size.x() &&
				point_pos.y() > box_pos.y() &&
				point_pos.y() < box_pos.y() + box_size.y());

	}