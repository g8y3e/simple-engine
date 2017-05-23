#include "scene.h"

#include "../../helper/log/log.h"

namespace simple_engine {
	void Scene::draw() {
		helper::Logger::getInstance().info("Draw from scene...");
	}

	void Scene::update(double dt) {
		helper::Logger::getInstance().info("Update from scene...");
	}
}