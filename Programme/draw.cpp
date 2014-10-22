#include "draw.h"

#include "Player.h"
extern Player Player1;
void drawback()
{
        // clear screen
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_Rect rect;
        rect.x=Player1.get_m_posX()-20;
	rect.y=5;
	rect.h=600;
	rect.w=640;
        // draw background
        SDL_BlitSurface(background, &rect, ecran, &dstrect);
        SDL_BlitSurface(backgroundClean, &rect, background, &rect);

}


