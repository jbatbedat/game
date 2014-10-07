#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "SDL.h"
#include "SDL_image.h"
#include "map.h"

#include "main.h"

int main ( int argc, char** argv )
{
	SDL_Surface* screen;
	SDL_Event event;
	Map* m;
	SDL_Init(SDL_INIT_VIDEO);		// prepare SDL
	screen = SDL_SetVideoMode(360, 208, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	m = ChargerMap("map/lvl0.txt");
	AfficherMap(m,screen);
	SDL_Flip(screen);
	do 
	{
		SDL_WaitEvent(&event);
	} while (event.type!=SDL_KEYDOWN);
	LibererMap(m);
	SDL_Quit();
	return 0;

}

void lost(void) {

//initialise la SDL
init();

//Charge les surfaces (le background et les 2 sprites)
load();
Player1.load();



// program main loop

while (!Input1.m_quit)
{
    //Gère les évènements (claviers et souris)
    touches();

    //Affiche le background et les 2 sprites

    drawback();
    Player1.draw();
    Player1.immobile();
    Player1.courir();
    //Met l'écran à jour
    SDL_Flip(ecran);
    pause();
    } // end main loop

//Libère les images chargées en mémoire
SDL_FreeSurface(background);
SDL_FreeSurface(backgroundClean);
Player1.freeSurface();

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;

}
