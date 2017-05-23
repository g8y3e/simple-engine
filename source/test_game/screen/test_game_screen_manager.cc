#include "test_game_screen_manager.h"

#include "test_screen/test_game_screen.h"

namespace test_game {
	TestGameScreenManager::TestGameScreenManager() {
		addScreen("test_screen", new TestGameScreen());

		setCurrentScreen("test_screen");
	}
}