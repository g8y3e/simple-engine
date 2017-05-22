#include "event_manager.h"

#include "../game.h"

namespace simple_engine {
	EventManager::EventManager() {
	}

	
	void EventManager::handleEvent() {
		while(SDL_PollEvent(&event_)) {
			switch (event_.type) {
			case SDL_QUIT:
				Game::getInstance().setRunning(false);
			}
		}
	}
}