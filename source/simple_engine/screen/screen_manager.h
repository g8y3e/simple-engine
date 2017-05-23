#pragma once

#include <string>
#include <map>
#include <memory>

#include "screen.h"

namespace simple_engine {
	class ScreenManager {
	public:
		void setCurrentScreen(const std::string& name);

		Screen& getCurrentScreen() const;

	protected:
		void addScreen(const std::string& name, Screen* screen);

		Screen& getScreen(const std::string& name);

	protected:
		std::map<std::string, std::unique_ptr<Screen>> screens_map_;

		Screen* current_screen_;
	};
}