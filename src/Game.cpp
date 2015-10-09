#include "Game.h"


void Game::setup(){
	
	map.setup();
}

void Game::update(){

	map.update();
}


void Game::draw(){
	
	map.draw();
}

SceneName Game::shift(){
	return TITLE;
}