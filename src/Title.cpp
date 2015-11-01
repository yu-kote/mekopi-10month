#include "Title.h"



void Title::setup(){




}

void Title::update(){




}
Title::Title(){
	picture=Texture("res/Texture/title.png");
	pos = Vec2f(-WIDTH/2, -HEIGHT/2);
	size = Vec2f(WIDTH, HEIGHT);
	cutsize = Vec2f(1024,768);
}

void Title::draw(){

	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), 0, 0, cutsize.x(),cutsize.y(), picture, Color::white);


}


SceneName Title::shift(){
	return SELECT;
}