#pragma once
#include "lib\framework.hpp"
#include "Common.h"


class Select{

private:
	Font font = Font("res/meiryo.ttc");
	Vec2f pos;
	Vec2f size;
	Vec2f cutsize;
	Texture picture;
	Vec2f blackpos;
	Vec2f blacksize;
	int coin;
	void coinup();
public:

	Select::Select();
	void setup();
	void update();
	void draw();
	void coindraw();
	SceneName shift();




};