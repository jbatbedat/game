#include "event.h"
extern Player Player1;

void touches()
{

        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // On fait correspondre les actions disponibles aux inputs. On switch en On les input correspondants aux touches enfoncées
                    if (event.key.keysym.sym == SDLK_x)
                        {
                        Player1.setm_input(1, 1);}
                    if (event.key.keysym.sym == SDLK_SPACE)
                        {
                        Player1.setm_input(1, 2);}
                    if (event.key.keysym.sym == SDLK_UP)
                        {
                        Player1.setm_input(1, 3);}
                    if (event.key.keysym.sym == SDLK_DOWN)
                        {
                        Player1.setm_input(1, 4);}
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        {
                        Player1.setm_input(1, 5);}
                    if (event.key.keysym.sym == SDLK_LEFT)
                        {
                        Player1.setm_input(1, 6);}
                    break;

            //On switch les input en off si les touches correspondantes ne sont pas enfoncées
            case SDL_KEYUP:
                {
                    if (event.key.keysym.sym == SDLK_SPACE)
                        Player1.setm_input(0, 2);
                    if (event.key.keysym.sym == SDLK_UP)
                        Player1.setm_input(0, 3);
                    if (event.key.keysym.sym == SDLK_DOWN)
                        Player1.setm_input(0, 4);
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        Player1.setm_input(0, 5);
                    if (event.key.keysym.sym == SDLK_LEFT)
                        Player1.setm_input(0, 6);
                    break;
                }
            }
        }
    }
}

