#include "render.h"

#include "../helper/log/log.h"
#include "../config.h"

namespace simple_engine {
	Render::Render() {
	}

	void Render::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::string error_msg = "Unable to initialize SDL: ";
			helper::Logger::getInstance().error(error_msg.append(SDL_GetError()));
			throw std::exception(error_msg.c_str());
		}

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_STEREO, 0);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 0);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 0);
		SDL_GL_SetAttribute(SDL_GL_RETAINED_BACKING, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

		std::string name = Config::getInstance().getStr("name");
		int width = Config::getInstance().getInt("width");
		int height = Config::getInstance().getInt("height");
		 
		#if defined(MOBILE_OS)
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);

			window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				0, 0, SDL_WINDOW_OPENGL);
		#else  
			window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							width, height, SDL_WINDOW_OPENGL);
		#endif

		if (window_ == nullptr) {
			std::string error_msg = "Error: can't create SDL window: ";
			helper::Logger::getInstance().error(error_msg.append(SDL_GetError()));
			throw std::exception(error_msg.c_str());
		}

		context_ = SDL_GL_CreateContext(window_);

		SDL_GL_MakeCurrent(window_, context_);
	}

	void Render::draw(Screen& screen) {
		screen.draw();

		SDL_GL_SwapWindow(window_);
	}

}
