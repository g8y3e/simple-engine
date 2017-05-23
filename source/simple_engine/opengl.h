#pragma once

#ifdef MOBILE_OS
#include <third_party/sdl2/SDL_opengles.h>
#else
#include <third_party/sdl2/SDL_opengl.h>
#endif