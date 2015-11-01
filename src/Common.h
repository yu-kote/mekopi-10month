#pragma once
#include "lib\framework.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


enum WindowSize{
	WIDTH = 1024,
	HEIGHT = 768,
};


//êÈåæÇ∑ÇÈÇ∆Ç´Å@App::get().isPressKey~
class App{
private:

public:
	static AppEnv& get(){
		static AppEnv env(WIDTH, HEIGHT,false,true);
		return env;
	}
};

enum SceneName{
	TITLE,
	SELECT,
	GAME,
};

struct Object{
	Vec2f pos;
	Vec2f size;
};

struct TextureObject : Object{
	Vec2f cut_pos;
	Vec2f cut_size;
	Texture picture;
	float angle;
	Vec2f zoom;
	Vec2f center;
};



/*èëÇ´ï˚ÇÃó·ÉNÉâÉX


struct Map : Object{

};
class Player(){

public:

	void update();
	void draw();
	void setup();

private:


	Map map[10][20];
	TextureObject monta;


	void move();

}

void Player::update()
{

	move();

}


void Player::draw()
{
	drawTextureBox(monta.pos.x(), monta.pos.y(),
				monta.size.x(), monta.size.y(),
				monta.cut_pos.x(), monta.cut_pos.y(),
				monta.cut_size.x(), monta.cut_size.x(),
				monta.picture, Color::white);

}

void Player::move()
{

~~~
~~~
~~~

}



*/