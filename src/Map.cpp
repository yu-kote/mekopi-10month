#include "Map.h"

Map::Map(){
	//�t�@�C����char�^�̃|�C���^�Ŏw��
	const char* map_name[STAGE_MAX] = {
		"res/MapTextData/Stage1.txt",
	};
	//ifstream�^�̃|�C���^�̔���new����H�E�E�E�킩��ˁI
	for (int index = 0; index < STAGE_MAX; index++){
		map_type[index] = new std::ifstream(map_name[index]);
	}

	for (int y = 0; y < MAP_Y; y++){
		for (int x = 0; x < MAP_X; x++){

			map[y][x].size = Vec2f(10, 10);
			map[y][x].pos.x() = map[y][x].size.x() * x;
			map[y][x].pos.y() = map[y][x].size.y() * y;
			map[y][x].cut_pos = Vec2f(0, 0);
			map[y][x].cut_size = Vec2f(200, 200);

		}
	}
}

Vec2f Map::getmapPos(){
	for (int y = 0; y < MAP_Y; y++){
		for (int x = 0; x < MAP_X; x++){
			return map[y][x].pos;
		}
	}
}

Vec2f Map::getmapSize(){
	for (int y = 0; y < MAP_Y; y++){
		for (int x = 0; x < MAP_X; x++){
			return map[y][x].size;
		}
	}
}

void Map::setPos(Vec2f speed){
	player_speed = speed;
}



void Map::setup(){
	player_speed = Vec2f(0, 0);
}

void Map::update(){

	for (int y = 0; y < MAP_Y; y++){
		for (int x = 0; x < MAP_X; x++){
			*map_type[STAGE1] >> map[y][x].status;

			switch (map[y][x].status){
			case AIR_BLOCK:


				break;
			case BLOCK:

				break;
			}

		}
		

	}
	std::cout << map[0][0].pos.x() << std::endl;

}


void Map::draw(){


	glPushMatrix();
	glTranslated(-player_speed.x(), -player_speed.y(), 0);
	for (int y = 0; y < MAP_Y; y++){
		for (int x = 0; x < MAP_X; x++){
			*map_type[STAGE1] >> map[y][x].status;

			if (map[y][x].pos.x() >= -WIDTH / 2 - draw_range && map[y][x].pos.x() <= WIDTH / 2 + draw_range &&
				map[y][x].pos.y() >= -HEIGHT / 2 - draw_range && map[y][x].pos.y() <= HEIGHT / 2 + draw_range){

				switch (map[y][x].status){
				case AIR_BLOCK:
					break;

				case BLOCK:

					drawFillBox(map[y][x].pos.x(), map[y][x].pos.y(),
								map[y][x].size.x(), map[y][x].size.x(), Color::white);
					break;
				}

			}

		}
	}
	glPopMatrix();
}




