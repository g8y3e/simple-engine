#pragma once

#include <third_party/sdl2/SDL.h>

namespace simple_engine {
	class EventManager {
	public:
		EventManager();

	public:
		void handleEvent(void);


	private:
		SDL_Event event_;

	};
}