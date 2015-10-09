#pragma once
#include "lib/framework.hpp"
#include "Common.h"


struct PlayerCar : TextureObject{
	int speed;
	float direction_change_speed;
	bool can_direction_change;
	bool isdirection_changing;

};


class Player{
private:

	enum Direction{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	PlayerCar Car;
	Direction direction;
	void DirectionChange();

public:
	Player();

	void setup();
	void update();
	void draw();
};
