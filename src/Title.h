#pragma once
#include "lib\framework.hpp"
#include "Common.h"
#include "Map.h"
#include "Common.h"


class Title{

private:
	Vec2f pos;
	Vec2f size;
	Vec2f cutsize;
	Texture picture;
public:

	Title();

	void setup();
	void update();
	void draw();
	SceneName shift();




};