#pragma once
#include "lib/framework.hpp"
#include "Common.h"
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
