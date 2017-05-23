#pragma once

#include <memory>

#include "render/render.h"
#include "event/event_manager.h"
#include "screen/screen_manager.h"

namespace simple_engine {
	class Game {
	public:
		static Game& initInstance(
				ScreenManager* screen_manager = nullptr,
				Render* render = nullptr, 
				EventManager* event_manager = nullptr
			);

		static Game& getInstance();

	public:
		Game(ScreenManager* screen_manager, Render* render, EventManager* event_manager);

	public:
		void init();
		int run();

	public:
		void setRunning(bool is_running);

	protected:
		std::unique_ptr<Render> render_;
		std::unique_ptr<EventManager> event_manager_;
		std::unique_ptr<ScreenManager> screen_manager_;

	private:
		static std::unique_ptr<Game> game_instance_;

		bool is_running_;
	};
}