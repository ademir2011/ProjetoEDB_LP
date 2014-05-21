//#include<SDL.h>
#include <SDL/SDL.h> se manteve a pasta SDL */
#include<stdlib.h>
int main(int argc, char** argv) {
 SDL_Surface* screen;
 SDL_Event event;
 int quit = 0;
 atexit(SDL_Quit);
 SDL_Init(SDL_INIT_VIDEO);
 screen = SDL_SetVideoMode(640, 480, 8, 0);
 while(!quit) {
 while(SDL_PollEvent(&event))
 if(event.type == SDL_QUIT)
 quit = 1;
 SDL_Flip(screen);
 }
 SDL_Quit();
 return 0;
}
