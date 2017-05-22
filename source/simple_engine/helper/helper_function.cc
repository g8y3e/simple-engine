#include "helper_function.h"

#include <third_party/sdl2/SDL.h>

namespace simple_engine {
	namespace helper {
		const std::string& StrConcat(const std::string& value) {
			return value;
		}

		ulong GetCurrentTime() {
			return SDL_GetTicks();
		}
	}
}