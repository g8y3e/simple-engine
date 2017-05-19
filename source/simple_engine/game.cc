#include "game.h"

#include <iostream>

#include <third_party/sdl2/SDL.h>

#include "helper/log/log.h"

namespace simple_engine {
	void Game::init() {
		render_->init();
	}


	int Game::run() {
		helper::Logger::getInstance().info("Game initialized!");
		SDL_Delay(3000);

		return 0;
	}
}