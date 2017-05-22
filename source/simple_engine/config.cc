#include "config.h"


#include "helper/log/log.h"
#include "helper/helper_function.h"

namespace simple_engine {
	std::unique_ptr<Config> Config::config_instance_(nullptr);
	
	Config& Config::initInstance(Config* config) {
		config_instance_.reset(config);

		return *config_instance_;
	}

	Config& Config::getInstance() {
		if (config_instance_ == nullptr) {
			helper::Logger::getInstance().error("Please init game before!");
		}

		return *config_instance_;
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