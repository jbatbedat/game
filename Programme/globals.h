#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED



#endif // GLOBALS_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Player.h"
#include "Input.h"
#include <string>
using namespace std;



extern SDL_Surface *ecran;
extern SDL_Surface *background;
extern SDL_Surface *backgroundClean;
extern SDL_Surface *sprite;
extern SDL_Event event;
extern void init();
extern void load();
extern void touches();
extern bool done;
extern void drawback();
extern void drawsprites(SDL_Surface *sprite, int destX, int destY, int srcX, int srcY);
extern SDL_Rect dstrect;
extern int timer;
extern void pause(void);


//Timers et status pour la course
extern int const tCourse1;
extern int const tCourse2;
extern int const tCourse3;
extern int const tCourse4;
extern int const tCourse5;
extern int const tInterval;
extern int rtCourse;
extern int rtInterval;


