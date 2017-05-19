#pragma once

#include <string>

namespace simple_engine {
	namespace helper {
		template <typename... Args>
		std::string StrConcat(const std::string& value, Args... args) {
			return value + StrConcat(args...);
		}

		const std::string& StrConcat(const std::string& value) {
			return value;
		}
	}
}