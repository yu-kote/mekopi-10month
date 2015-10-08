#include "Scene.h"
Scene::Scene(){
	scene_move = TITLE;

}


void Scene::setup(){

	title.setup();
	select.setup();
	game.setup();
}


void Scene::draw(){

	switch (scene_move){
	case TITLE:
		title.draw();

		break;
	case SELECT:
		select.draw();

		break;
	case GAME:
		game.draw();

		break;
	}


};


void Scene::update(){
	
	switch (scene_move){
	case TITLE:
		title.update();

		break;
	case SELECT:
		select.update();

		break;
	case GAME:
		game.update();

		break;
	}
}


void Scene::shift(){


	switch (scene_move){
	case TITLE:
		if (App::get().isPushKey(GLFW_KEY_5)){
			scene_move = title.shift();
		}

		break;
	case SELECT:
		if (App::get().isPushKey(GLFW_KEY_1)){
			scene_move = select.shift();

		}

		break;
	case GAME:
		if (App::get().isPushKey(GLFW_KEY_1)){
			scene_move = game.shift();

		}

		break;
	}


}
