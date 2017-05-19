#pragma once

#include <string>
#include <map>

namespace simple_engine {
	class Config {
	public:
		static Config &getInstance(Config *config = nullptr);

	public:
		void addInt(const std::string& key, int value);
		void addBool(const std::string& key, bool value);
		void addStr(const std::string& key, const std::string& value);
		
		const std::string& getStr(const std::string& key);
		const bool getBool(const std::string& key);
		int getInt(const std::string& key);

	private:
		std::map<std::string, int> int_values_;
		std::map<std::string, bool> bool_values_;
		std::map<std::string, std::string> str_values_;
	};
}