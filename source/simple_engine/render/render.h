#pragma once

#include <string>

#include <third_party/sdl2/SDL.h>

#include "../screen/screen.h"

namespace simple_engine {
	class Render {
	public:
		Render();

	public:
		void init();

		void draw(Screen& screen);

	private:
		SDL_Window *window_;

		SDL_GLContext context_;
	};
}