#include <iostream>

#include "third_party/sdl2/SDL.h";

int main(int argc, char** argv) {

	SDL_Delay(2000);

	std::cout << "Engine initiated!" << std::endl;
	std::cin.get();

	return 0;
}