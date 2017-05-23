#include "test_game_screen.h"

#include "scene/test_game_scene.h"

namespace test_game {
	TestGameScreen::TestGameScreen() {
		addScene(new TestGameScene());
	}
}