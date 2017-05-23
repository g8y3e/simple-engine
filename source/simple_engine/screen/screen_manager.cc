#include "screen_manager.h"

#include "../helper/helper_function.h"
#include "../helper/log/log.h"

namespace simple_engine {
	void ScreenManager::setCurrentScreen(const std::string& name) {
		if (screens_map_.count(name) == 0) {
			std::string error = helper::StrConcat("Screen '", name, "' was not found!");
			helper::Logger::getInstance().error(error);

			throw std::exception(error.c_str());
		}

		current_screen_ = screens_map_[name].get();
	}

	Screen& ScreenManager::getCurrentScreen() const {
		if (current_screen_ == nullptr) {
			std::string error = helper::StrConcat("Please set currrent screen!");
			helper::Logger::getInstance().error(error);

			throw std::exception(error.c_str());
		}

		return *current_screen_;
	}

	void ScreenManager::addScreen(const std::string& name, Screen* screen) {
		screens_map_[name] = std::unique_ptr<Screen>(screen);
	}

	Screen& ScreenManager::getScreen(const std::string& name) {
		if (screens_map_.count(name) == 0) {
			std::string error = helper::StrConcat("Screen '", name, "' was not found!");
			helper::Logger::getInstance().error(error);

			throw std::exception(error.c_str());
		}

		return *screens_map_[name];
	}
}