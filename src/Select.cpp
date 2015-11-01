#include "Select.h"


void Select::setup(){

	coin = 0;
	App::get().flushInput();

}

void Select::update(){

	coinup();


}
void Select::coinup(){
	if (App::get().isPushKey('5')){
		coin += 1;
	}
	if (coin > 9){
		coin = 9;
	}
}
Select::Select(){
	picture = Texture("res/Texture/select.png");
	pos = Vec2f(-WIDTH / 2, -HEIGHT / 2);
	size = Vec2f(WIDTH, HEIGHT);
	cutsize = Vec2f(1024, 768);
	blackpos = Vec2f(0, -150);
	blacksize = Vec2f(100, 100);
}
void Select::draw(){
	
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), 0, 0, cutsize.x(), cutsize.y(), picture, Color::white);
	drawFillBox(blackpos.x(), blackpos.y(), blacksize.x(), blacksize.y(), Color::black);
	coindraw();

}
void Select::coindraw(){
	std::string text;
	int fontsize = 30;
	font.size(fontsize);
	text = std::to_string(coin);
	font.draw(text,Vec2f(blackpos.x(),blackpos.y()+50), Color::white);
}
SceneName Select::shift(){
	return GAME;
}