#include "Player.h"


Player::Player(){
	Car.picture = Texture("res/Texture/player_macine.png");

}

void Player::setup(){
	Car.pos = Vec2f(0, 0);
	Car.size = Vec2f(128, 128);
	Car.cut_pos = Vec2f(0, 0);
	Car.cut_size = Vec2f(128, 128);
	Car.angle = 0;
	Car.zoom = Vec2f(1, 1);
	Car.center = Vec2f(Car.size.x()/2, Car.size.y()/2);
	Car.direction_change_speed=M_PI/20;
}

void Player::update(){
	DirectionChange();
}
void Player::draw(){

	drawTextureBox(Car.pos.x(), Car.pos.y(), 
		Car.size.x(), Car.size.y(),
		Car.cut_pos.x(),Car.cut_pos.y(),
		Car.cut_size.x(),Car.cut_size.y(),
		Car.picture,Color::white,
		Car.angle,Car.zoom,Car.center);

}
void Player::DirectionChange(){
	if (Car.can_direction_change){

		switch (direction){


		case UP:
			if (App::get().isPushKey(GLFW_KEY_RIGHT)){

			}

			break;
		}
	}
	if (App::get().isPushKey(GLFW_KEY_UP)){
		Car.angle = M_PI;
	}





}