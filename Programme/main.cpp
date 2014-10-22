#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "SDL.h"
#include "SDL_image.h"

#include "main.h"

int main ( int argc, char** argv )
{

//initialise la SDL
init();

//Charge les surfaces (le background et les 2 sprites)
load();
Player1.load();



// program main loop

while (!Player1.getm_input("quit"))
{
    //Gère les évènements (claviers et souris)
    touches();

    //Affiche le background et les 2 sprites

    drawback();

    Player1.immobile();
    Player1.vitesse();
    Player1.courir();
    Player1.saut();
    Player1.draw();
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
