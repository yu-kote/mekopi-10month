#include "Game.h"


void Game::setup(){
	
	map.setup();
	player.setup();
}

void Game::update(){

	map.update();
	player.update();
}


void Game::draw(){
	
	map.draw();
	player.draw();
}

SceneName Game::shift(){
	return TITLE;
}