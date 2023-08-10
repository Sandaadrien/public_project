#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc , char ** argv) {
	
	SDL_Surface * ecran;
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800 , 600 , 32 , SDL_HWSURFACE);
	int continuer = 1;
	SDL_Event event;
	while(continuer){
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT :
				continuer = 0;
				break;
			case SDL_KEYDOWN : 
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE : 
						continuer = 0;
						break;
						
				}
				break;
		}
	}
	SDL_Quit();
	return EXIT_SUCCESS;
}
