#pragma once

#include <string>

#include <third_party/sdl2/SDL.h>

namespace simple_engine {
	class Render {
	public:
		Render();

	public:
		void init();

	private:
		SDL_Window *window_;
	};
}