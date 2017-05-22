#include "game.h"

#include <third_party/sdl2/SDL.h>

#include "config.h"

#include "helper/log/log.h"
#include "helper/helper_function.h"

#include "define/system_define.h"

namespace simple_engine {
	std::unique_ptr<Game> Game::game_instance_(nullptr);
	
	Game &Game::initInstance(Render* render, EventManager* event_manager) {
		if (render == nullptr) {
			render = new Render();
		}

		if (event_manager == nullptr) {
			event_manager = new EventManager();
		}

		Game *game = new Game(render, event_manager);

		game_instance_.reset(game);

		return *game_instance_;
	}

	Game &Game::getInstance() {
		if (game_instance_ == nullptr) {
			helper::Logger::getInstance().error("Please init game before!");
		}

		return *game_instance_;
	}

	Game::Game(Render* render, EventManager* event_manager)
		: is_running_(true) {

		render_.reset(render);
		event_manager_.reset(event_manager);
	}

	void Game::init() {
		render_->init();
	}

	int Game::run() {
		int static_frame_rate = Config::getInstance().getInt("static_frame_rate");
		ulong delta_time = 1000 / (static_frame_rate - 1);
		ulong current_time;
		ulong elapsed;
		ulong prev_time = helper::GetCurrentTime();

		ulong lag = 0;

		double static_dt = delta_time / 1000.0;
		double dt = 0.0;

		while(is_running_) {
			event_manager_->handleEvent();

			current_time = helper::GetCurrentTime();

			elapsed = current_time - prev_time;
			prev_time = current_time;

			lag += elapsed;
			dt = elapsed / 1000.0;

			while(lag >= delta_time) {
				// run static callback

				lag -= delta_time;
			}
		}

		return SE_EXIT_SUCCESS;
	}

	void Game::setRunning(bool is_running) {
		is_running_ = is_running;
	}

}