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
	Car.fuel = 10;
	Car.fuel_count = 0;
	Car.speed = Vec2f(Car.fuel - Car.fuel_count, Car.fuel - Car.fuel_count);
	Car.can_direction_change = true;
	Car.isdirection_changing = false;
	Car.angle_count = 0;
	Car.direction_change_speed = M_PI/16;
	direction = UP;
	Car.upComond_flag = false;
	Car.downComond_flag = false;
	Car.rightComond_flag = false;
	Car.leftComond_flag = false;
	Car.advance.x() = 0;
	Car.advance.y() = 0;
}

void Player::update(){
	Direction_Flag_Change();
	DirectionChange();
	Angle_Change();
	SpeedDown();
}
void Player::draw(){

	drawTextureBox(Car.pos.x(), Car.pos.y(), 
		Car.size.x(), Car.size.y(),
		Car.cut_pos.x(),Car.cut_pos.y(),
		Car.cut_size.x(),Car.cut_size.y(),
		Car.picture,Color::white,
		Car.angle,Car.zoom,Car.center);

}
Vec2f Player::getSpeed(){
	return Car.speed;
}
void Player::SpeedDown(){
	Car.speed = Vec2f(Car.advance.x()*(Car.fuel - Car.fuel_count), Car.advance.y()*(Car.fuel - Car.fuel_count));
	Car.fuel_count += 0.05;
}
void Player::Direction_Flag_Change(){
	if (Car.can_direction_change==true && (App::get().isPressKey(GLFW_KEY_RIGHT) ||App::get().isPressKey(GLFW_KEY_LEFT) ||App::get().isPressKey(GLFW_KEY_UP) ||  App::get().isPressKey(GLFW_KEY_DOWN))){
		Car.isdirection_changing = true;
	}

}
void Player::Angle_Change(){
	if (Car.isdirection_changing == true){

		if (Car.rightComond_flag == true){
			direction = RIGHT;
				Car.angle = -M_PI / 2;
		}
		if (Car.leftComond_flag == true){
				Car.angle = M_PI / 2;
		}
		if (Car.upComond_flag == true){
				Car.angle = 0;
		}
		if (Car.downComond_flag == true){
				Car.angle = M_PI;
		}
	}
}
void Player::DirectionChange(){


		switch (direction){

		case UP:
			if (App::get().isPressKey(GLFW_KEY_RIGHT)){
				Car.rightComond_flag = true;
			}
			else{
				Car.rightComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_LEFT)){
				Car.leftComond_flag = true;
			}
			else{
				Car.leftComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_DOWN)){
				Car.downComond_flag = true;
			}
			else{
				Car.downComond_flag = false;
			}
			break;
		case DOWN:
			if (App::get().isPressKey(GLFW_KEY_RIGHT)){
				Car.rightComond_flag = true;
			}
			else{
				Car.rightComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_LEFT)){
				Car.leftComond_flag = true;
			}
			else{
				Car.leftComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_UP)){
				Car.upComond_flag = true;
			}
			else{
				Car.upComond_flag = false;
			}
			break;
		case RIGHT:
			if (App::get().isPressKey(GLFW_KEY_LEFT)){
				Car.leftComond_flag = true;
			}
			else{
				Car.leftComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_DOWN)){
				Car.downComond_flag = true;
			}
			else{
				Car.downComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_UP)){
				Car.upComond_flag = true;
			}
			else{
				Car.upComond_flag = false;
			}
			break;
		case LEFT:
			if (App::get().isPressKey(GLFW_KEY_RIGHT)){
				Car.rightComond_flag = true;
			}
			else{
				Car.rightComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_DOWN)){
				Car.downComond_flag = true;
			}
			else{
				Car.downComond_flag = false;
			}
			if (App::get().isPressKey(GLFW_KEY_UP)){
				Car.upComond_flag = true;
			}
			else{
				Car.upComond_flag = false;
			}
			break;
		}
	

}