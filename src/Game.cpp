#include "Game.h"


void Game::setup(){
	
	map.setup();
	player.setStartPos(map.getStartPos());
	player.setup();
}

void Game::update(){

	map.setPlayerPos(player.getPos());
	map.setPlayerSize(player.getSize());
	map.setPlayerDirection(player.getDirection());
	player.setUpFlag(map.getUpFlag());
	player.setDownFlag(map.getDownFlag());
	player.setLeftFlag(map.getLeftFlag());
	player.setRightFlag(map.getRightFlag());
	player.setUp2Flag(map.getUp2Flag());
	player.setDown2Flag(map.getDown2Flag());
	player.setLeft2Flag(map.getLeft2Flag());
	player.setRight2Flag(map.getRight2Flag());

	map.update();
	player.update();
}


void Game::draw(){



	glPushMatrix();
	glTranslated(-player.getPos().x(), -player.getPos().y(), 0);
	App::get().bgColor(Color::lime);
	map.draw();
	glPopMatrix();
	player.draw();
}

SceneName Game::shift(){
	return TITLE;
}