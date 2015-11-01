#pragma once
#include "lib/framework.hpp"
#include "Common.h"


struct PlayerCar : TextureObject{
	Vec2f start_pos;
	Vec2f speed;
	Vec2i direction_speed;
	float fuel;
	float fuel_count;
	float direction_change_speed;
	bool can_direction_change;
	bool isdirection_changing;
	bool can_up_flag;
	bool can_down_flag;
	bool can_right_flag;
	bool can_left_flag;
	bool can_up_flag2;
	bool can_down_flag2;
	bool can_right_flag2;
	bool can_left_flag2;
	float setangler;
	int angle_count;
	Vec2f advance;
};


class Player{
private:
	Font font = Font("res/meiryo.ttc");
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
	void Move();
	void SpeedDown();
	void Test_direction();
public:
	Player();
	void setup();
	void update();
	void draw();

	Vec2f getSpeed();
	Vec2f getPos();
	Vec2f getSize();
	int getDirection();

	void setStartPos(Vec2f pos);
	void setUpFlag(bool up_flag);
	void setDownFlag(bool down_flag);
	void setRightFlag(bool right_flag);
	void setLeftFlag(bool left_flag);
	void setUp2Flag(bool up_flag);
	void setDown2Flag(bool down_flag);
	void setRight2Flag(bool right_flag);
	void setLeft2Flag(bool left_flag);

};
