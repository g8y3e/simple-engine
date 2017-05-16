#pragma once

#include <string>

namespace simple_engine {
	class Game {
	public:
		Game(const std::string& name);

	public:
		int run();

	private:
		std::string name_;
	};
}