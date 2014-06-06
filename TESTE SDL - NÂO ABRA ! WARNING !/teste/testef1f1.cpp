/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>


int main( ){

	SDL_Init(SDL_INIT_VIDEO);

SDL_CreateWindow( "Vermelho", 0, 0, 640, 480, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	return 0;
}
