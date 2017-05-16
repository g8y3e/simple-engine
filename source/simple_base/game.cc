#include "game.h"

#include <iostream>

#include <third_party/sdl2/SDL.h>

#include "helper/log/log.h";

namespace simple_engine {
	Game::Game(const std::string& name) 
		: name_(name) {
	}

	int Game::run() {
		helper::Logger::getInstance().info("Game initialized!");
		SDL_Delay(3000);

		return 0;
	}
}