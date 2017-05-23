#include "screen.h"

#include "../opengl.h"

namespace simple_engine {
	void Screen::draw() {
		clearDraw();

		for (const auto& scene : scenes_map_) {
			scene->draw();
		}
	}

	void Screen::update(double dt) {
		for (const auto& scene : scenes_map_) {
			scene->update(dt);
		}
	}

	void Screen::clearDraw() {
		glClearColor(0.3, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Screen::addScene(Scene* scene) {
		scenes_map_.push_back(std::unique_ptr<Scene>(scene));
	}
}