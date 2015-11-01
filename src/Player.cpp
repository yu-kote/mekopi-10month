#include "Player.h"


Player::Player(){
	Car.picture = Texture("res/Texture/player_macine.png");

}

void Player::setup(){
	Car.pos = Car.start_pos;
	Car.size = Vec2f(100, 128);
	Car.cut_pos = Vec2f(0, 0);
	Car.cut_size = Vec2f(64, 64);
	Car.angle = 0;
	Car.zoom = Vec2f(1, 1);
	Car.center = Vec2f(Car.size.x() / 2, Car.size.y() / 2);
	Car.fuel = 1;
	Car.fuel_count = 0;
	Car.direction_speed = Vec2i(0, 0);
	Car.speed = Vec2f(Car.direction_speed.x()*(Car.fuel - Car.fuel_count), Car.direction_speed.y()*(Car.fuel - Car.fuel_count));
	Car.can_direction_change = true;
	Car.isdirection_changing = false;
	Car.angle_count = 0;
	Car.setangler = 0;
	Car.direction_change_speed = M_PI / 16;
	direction = UP;
	Car.can_up_flag = true;
	Car.can_down_flag = true;
	Car.can_left_flag = true;
	Car.can_right_flag = true;
	Car.can_up_flag2 = true;
	Car.can_down_flag2 = true;
	Car.can_left_flag2 = true;
	Car.can_right_flag2 = true;
	Car.advance.x() = 0;
	Car.advance.y() = 0;
}

void Player::update(){
	Move();
	Direction_Flag_Change();
	DirectionChange();
	Angle_Change();
	SpeedDown();

}
void Player::draw(){

	drawTextureBox(0, 0,
				   Car.size.x(), Car.size.y(),
				   Car.cut_pos.x(), Car.cut_pos.y(),
				   Car.cut_size.x(), Car.cut_size.y(),
				   Car.picture, Color::white,
				   Car.angle, Car.zoom, Car.center);
	drawBox(0, 0,
			Car.size.x(), Car.size.y(), 5, Color::white,
			Car.angle, Car.zoom, Car.center);
	Test_direction();
}

void Player::Move(){
	Car.pos += Car.speed;
}

void Player::SpeedDown(){
	Car.speed = Vec2f(Car.direction_speed.x()*(Car.fuel - Car.fuel_count), Car.direction_speed.y()*(Car.fuel - Car.fuel_count));
	Car.fuel_count += 0.0001;
}
void Player::Direction_Flag_Change(){
	if (Car.can_direction_change == true && (App::get().isPressKey(GLFW_KEY_RIGHT) || App::get().isPressKey(GLFW_KEY_LEFT) || App::get().isPressKey(GLFW_KEY_UP) || App::get().isPressKey(GLFW_KEY_DOWN))){
		Car.isdirection_changing = true;
	}

}

Vec2f Player::getSpeed(){
	return Car.speed;
}
Vec2f Player::getPos(){
	return Car.pos;
}
Vec2f Player::getSize(){
	return Car.size;
}
int Player::getDirection(){
	return direction;
}

void Player::setStartPos(Vec2f pos){
	Car.start_pos = pos;
}

void Player::setUpFlag(bool up_flag){
	Car.can_up_flag = up_flag;
}
void Player::setDownFlag(bool down_flag){
	Car.can_down_flag = down_flag;
}
void Player::setRightFlag(bool right_flag){
	Car.can_right_flag = right_flag;
}
void Player::setLeftFlag(bool left_flag){
	Car.can_left_flag = left_flag;
}
void Player::setUp2Flag(bool up_flag){
	Car.can_up_flag2 = up_flag;
}
void Player::setDown2Flag(bool down_flag){
	Car.can_down_flag2 = down_flag;
}
void Player::setRight2Flag(bool right_flag){
	Car.can_right_flag2 = right_flag;
}
void Player::setLeft2Flag(bool left_flag){
	Car.can_left_flag2 = left_flag;
}

void Player::Angle_Change(){
	float change_speed = 0.15;

	if (direction == DOWN){
		if (Car.setangler < 0){
			Car.setangler += change_speed*(-M_PI - Car.setangler);
			if (Car.setangler < -M_PI + 0.1){
				Car.setangler = M_PI;
			}
		}
		else{
			Car.setangler += change_speed*(M_PI - Car.setangler);
		}
		if (Car.setangler < (-M_PI + 0.3)){
			Car.setangler += 2 * M_PI;
		}
	}
	if (direction == UP){
		if (Car.setangler > M_PI){
			Car.setangler += change_speed*(2 * M_PI - Car.setangler);
			if (Car.setangler > 2 * M_PI - 0.1){
				Car.setangler = 0;
			}
		}
		else{
			Car.setangler += change_speed*(-Car.setangler);
		}
		if (Car.setangler > (3 * M_PI / 2)){
			Car.setangler -= 2 * M_PI;
		}
	}
	if (direction == LEFT){
		if (Car.setangler < -M_PI / 2){
			Car.setangler += change_speed*(-3 * M_PI / 2 - Car.setangler);
			if (Car.setangler < -3 * M_PI / 2 + 0.1){
				Car.setangler = M_PI / 2;
			}
		}
		else{
			Car.setangler += change_speed*(M_PI / 2 - Car.setangler);
		}
		if (Car.setangler < (-M_PI + 0.3)){
			Car.setangler += 2 * M_PI;
		}
	}
	if (direction == RIGHT){
		if (Car.setangler < M_PI / 2){
			Car.setangler += change_speed*((-M_PI / 2) - Car.setangler);
			if (Car.setangler > 2 * M_PI - 0.1){
				Car.setangler = 3 * M_PI / 2;
			}
		}
		else{
			Car.setangler += change_speed*((3 * M_PI / 2) - Car.setangler);
		}
	}

	if (Car.setangler >= (-19 * M_PI / 16) && Car.setangler < (-17 * M_PI / 16)){
		Car.angle = -18 * M_PI / 16;
	}


	if (Car.setangler >= (-17 * M_PI / 16) && Car.setangler < (-15 * M_PI / 16)){
		Car.angle = -16 * M_PI / 16;
	}
	if (Car.setangler >= (-15 * M_PI / 16) && Car.setangler < (-13 * M_PI / 16)){
		Car.angle = -14 * M_PI / 16;
	}
	if (Car.setangler >= (-13 * M_PI / 16) && Car.setangler < (-11 * M_PI / 16)){
		Car.angle = -12 * M_PI / 16;
	}
	if (Car.setangler >= (-11 * M_PI / 16) && Car.setangler < (-9 * M_PI / 16)){
		Car.angle = -10 * M_PI / 16;
	}
	if (Car.setangler >= (-9 * M_PI / 16) && Car.setangler < (-7 * M_PI / 16)){
		Car.angle = -8 * M_PI / 16;
	}
	if (Car.setangler >= (-7 * M_PI / 16) && Car.setangler < (-5 * M_PI / 16)){
		Car.angle = -6 * M_PI / 16;
	}
	if (Car.setangler >= (-5 * M_PI / 16) && Car.setangler < (-3 * M_PI / 16)){
		Car.angle = -4 * M_PI / 16;
	}
	if (Car.setangler >= (-3 * M_PI / 16) && Car.setangler < (-1 * M_PI / 16)){
		Car.angle = -2 * M_PI / 16;
	}
	if (Car.setangler >= -M_PI / 16 && Car.setangler < M_PI / 16){
		Car.angle = 0;
	}
	if (Car.setangler >= M_PI / 16 && Car.setangler < (3 * M_PI / 16)){
		Car.angle = 2 * M_PI / 16;
	}
	if (Car.setangler >= (3 * M_PI / 16) && Car.setangler < (5 * M_PI / 16)){
		Car.angle = 4 * M_PI / 16;
	}
	if (Car.setangler >= (5 * M_PI / 16) && Car.setangler < (7 * M_PI / 16)){
		Car.angle = 6 * M_PI / 16;
	}
	if (Car.setangler >= (7 * M_PI / 16) && Car.setangler < (9 * M_PI / 16)){
		Car.angle = 8 * M_PI / 16;
	}
	if (Car.setangler >= (9 * M_PI / 16) && Car.setangler < (11 * M_PI / 16)){
		Car.angle = 10 * M_PI / 16;
	}
	if (Car.setangler >= (11 * M_PI / 16) && Car.setangler < (13 * M_PI / 16)){
		Car.angle = 12 * M_PI / 16;
	}
	if (Car.setangler >= (13 * M_PI / 16) && Car.setangler < (15 * M_PI / 16)){
		Car.angle = 14 * M_PI / 16;
	}
	if (Car.setangler >= (15 * M_PI / 16) && Car.setangler < (17 * M_PI / 16)){
		Car.angle = 16 * M_PI / 16;
	}
	if (Car.setangler >= (17 * M_PI / 16) && Car.setangler < (19 * M_PI / 16)){
		Car.angle = 18 * M_PI / 16;
	}
	if (Car.setangler >= (19 * M_PI / 16) && Car.setangler < (21 * M_PI / 16)){
		Car.angle = 20 * M_PI / 16;
	}
	if (Car.setangler >= (21 * M_PI / 16) && Car.setangler < (23 * M_PI / 16)){
		Car.angle = 22 * M_PI / 16;
	}
	if (Car.setangler >= (23 * M_PI / 16) && Car.setangler < (25 * M_PI / 16)){
		Car.angle = 24 * M_PI / 16;
	}
	if (Car.setangler >= (25 * M_PI / 16) && Car.setangler < (27 * M_PI / 16)){
		Car.angle = 26 * M_PI / 16;
	}
	if (Car.setangler >= (27 * M_PI / 16) && Car.setangler < (29 * M_PI / 16)){
		Car.angle = 28 * M_PI / 16;
	}
	if (Car.setangler >= (29 * M_PI / 16) && Car.setangler < (31 * M_PI / 16)){
		Car.angle = 30 * M_PI / 16;
	}
	if (Car.setangler >= (31 * M_PI / 16) && Car.setangler < (33 * M_PI / 16)){
		Car.angle = 32 * M_PI / 16;
	}
	if (Car.setangler >= (33 * M_PI / 16) && Car.setangler < (35 * M_PI / 16)){
		Car.angle = 34 * M_PI / 16;
	}
	if (Car.setangler >= (35 * M_PI / 16) && Car.setangler < (37 * M_PI / 16)){
		Car.angle = 36 * M_PI / 16;
	}
	if (Car.setangler >= (37 * M_PI / 16) && Car.setangler < (39 * M_PI / 16)){
		Car.angle = 38 * M_PI / 16;
	}
	if (Car.setangler >= (39 * M_PI / 16) && Car.setangler < (41 * M_PI / 16)){
		Car.angle = 40 * M_PI / 16;
	}
}
void Player::DirectionChange(){
	if (App::get().isPressKey(GLFW_KEY_UP)){
		if (Car.can_up_flag == true && Car.can_up_flag2 == true){
			direction = UP;
			Car.direction_speed = Vec2i(0, 1);
		}
	}
	if (App::get().isPressKey(GLFW_KEY_DOWN)){
		if (Car.can_down_flag == true && Car.can_down_flag2 == true){
			direction = DOWN;
			Car.direction_speed = Vec2i(0, -1);
		}
	}
	if (App::get().isPressKey(GLFW_KEY_RIGHT)){
		if (Car.can_right_flag == true && Car.can_right_flag2 == true){
			direction = RIGHT;
			Car.direction_speed = Vec2i(1, 0);
		}
	}
	if (App::get().isPressKey(GLFW_KEY_LEFT)){
		if (Car.can_left_flag == true && Car.can_left_flag2 == true){
			direction = LEFT;
			Car.direction_speed = Vec2i(-1, 0);
		}
	}
	//std::cout << "up    " << Car.can_up_flag << std::endl;
	//std::cout << "down  " << Car.can_down_flag << std::endl;
	//std::cout << "left  " << Car.can_left_flag << std::endl;
	//std::cout << "right " << Car.can_right_flag << std::endl;

}
void Player::Test_direction(){
	std::string text;
	if (direction == UP){
		text = "UP";
	}
	if (direction == DOWN){
		text = "DOWN";
	}
	if (direction == LEFT){
		text = "LEFT";
	}
	if (direction == RIGHT){
		text = "RIGHT";
	}
	font.size(40);
	font.draw(text, Vec2f(200, 300), Color::white);
	text = std::to_string(Car.speed.x());
	font.draw(text, Vec2f(300, 200), Color::white);
	text = std::to_string(Car.speed.y());
	font.draw(text, Vec2f(300, 100), Color::white);
}
