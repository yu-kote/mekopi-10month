
#include "lib/framework.hpp"
#include "Common.h"
#include "Scene.h"
// 
// メインプログラム
// 
int main() {
	App::get();

	Scene scene;

	scene.setup();

  while (App::get().isOpen()) {

	  scene.shift();
	  scene.update();

	  App::get().begin();

	  scene.draw();

	  App::get().end();
  }
}
