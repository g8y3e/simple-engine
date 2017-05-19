#pragma once

#include <string>
#include <memory>

#include "render/render.h"

namespace simple_engine {
	class Game {
	public:
		void init();
		int run();

	protected:
		std::unique_ptr<Render> render_;
	};
}