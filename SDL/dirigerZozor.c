#include <stdio.h>
#include <SDL/SDL.h>


int main(int argc , char ** argv) {
	
	SDL_Surface * ecran , *zozor;
	SDL_Rect positionZozor;
	
	positionZozor.x = 0;
	positionZozor.y = 0;
	
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(800 , 600 , 32 , SDL_HWSURFACE);
	SDL_FillRect(ecran , NULL , SDL_MapRGB(ecran->format , 255 , 255, 255));
	
	zozor = SDL_LoadBMP("zozor.bmp");
	SDL_SetColorKey(zozor , SDL_SRCCOLORKEY , SDL_MapRGB(zozor->format , 0 , 0 , 255));
	SDL_BlitSurface(zozor , NULL , ecran , &positionZozor);
	SDL_Flip(ecran);
	int continuer = 1;
	SDL_Event event;
	while(continuer){
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT : 
				continuer =0;
				break;

			case SDL_KEYDOWN : 
				switch(event.key.keysym.sym){
					case SDLK_UP : 
						positionZozor.y-=100;
						break;
					case SDLK_DOWN : 
						positionZozor.y+=100;
						break;
					case SDLK_RIGHT : 
						positionZozor.x+=100;
						break;
					case SDLK_LEFT : 
						positionZozor.x-=100;
						break;
				}
				break;
			
			case SDL_MOUSEBUTTONUP : 
				positionZozor.x = event.button.x;
				positionZozor.y = event.button.y;
				break;
		}
		
		SDL_FillRect(ecran , NULL , SDL_MapRGB(ecran->format , 255 , 255, 255));
		SDL_BlitSurface(zozor , NULL , ecran , &positionZozor);
		SDL_Flip(ecran);
	}
	
	SDL_FreeSurface(zozor);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
