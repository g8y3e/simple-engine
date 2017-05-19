#include "config.h"

#include <memory>

#include "helper/log/log.h"
#include "helper/helper_function.h"

namespace simple_engine {
	Config &Config::getInstance(Config* config) {
		static std::unique_ptr<Config> config_instance;
		if (config != nullptr) {
			config_instance.reset(config);
		}

		return *config_instance;
	}

	void Config::addBool(const std::string& key, bool value) {
		bool_values_[key] = value;
	}

	void Config::addInt(const std::string& key, int value) {
		int_values_[key] = value;
	}

	void Config::addStr(const std::string& key, const std::string& value) {
		str_values_[key] = value;
	}

	const bool Config::getBool(const std::string& key) {
		if (bool_values_.count(key) == 0) {
			std::string error = helper::StrConcat("Config not have key: ", key);
			helper::Logger::getInstance().error(error);
		}

		return bool_values_[key];
	}

	const std::string& Config::getStr(const std::string& key) {
		if (str_values_.count(key) == 0) {
			std::string error = helper::StrConcat("Config not have key: ", key);
			helper::Logger::getInstance().error(error);
		}

		return str_values_[key];
	}

	int Config::getInt(const std::string& key) {
		if (int_values_.count(key) == 0) {
			std::string error = helper::StrConcat("Config not have key: ", key);
			helper::Logger::getInstance().error(error);
		}

		return int_values_[key];
	}

}