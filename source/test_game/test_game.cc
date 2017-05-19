#include "test_game.h"

#include <simple_engine/config.h>

namespace test_game {
	TestGame::TestGame() {
		simple_engine::Config *config = new simple_engine::Config();
		config->addInt("width", 1024);
		config->addInt("height", 768);

		config->addBool("fullscreen", false);

		config->addStr("name", "Test name!");

		simple_engine::Config::getInstance(config);

		render_.reset(new simple_engine::Render());
	}
}