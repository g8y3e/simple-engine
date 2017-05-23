#pragma once

#include <vector>
#include <memory>

#include "scene/scene.h"


namespace simple_engine {
	class Screen {
	public:
		void draw();
		void update(double dt);

	protected:
		void clearDraw();

		void addScene(Scene* scene);
		

	private:
		std::vector<std::unique_ptr<Scene>> scenes_map_;
	};
}