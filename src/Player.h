#pragma once
#include "lib/framework.hpp"
#include "Common.h"


struct PlayerCar : TextureObject{
	Vec2f speed;
	float fuel;
	float fuel_count;
	float direction_change_speed;
	bool can_direction_change;
	bool isdirection_changing;
	bool upComond_flag;
	bool downComond_flag;
	bool rightComond_flag;
	bool leftComond_flag;
	int angle_count;
	Vec2f advance;
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
	void Direction_Flag_Change();
	void Angle_Change();
	void SpeedDown();
public:
	Player();
	void setup();
	void update();
	void draw();
	Vec2f getSpeed();
	bool getMove_flag();
};
