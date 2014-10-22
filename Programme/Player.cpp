#ifndef PLAYER_CPP_INCLUDED
#define PLAYER_CPP_INCLUDED



#endif // PLAYER_CPP_INCLUDED

#include <math.h>
#include "Player.h"
#include "Input.h"
#include "timers.h"
extern SDL_Surface *background;
extern SDL_Surface *ecran;

Player::Player():  m_vie(100), m_posX(0), m_posXo(0), m_posY(500), m_posYo(500), m_tileX(1),
m_tileY(1), m_hauteurTile(75), m_largeurTile(38), m_adresseSprite("images/sprite.png"),
m_sprite(0), m_sens(1), m_courseOn(0), m_sautOn(0), m_preposX(0), m_vitesse(0), m_input()

{
}

Player::Player(int posX, int posY):  m_vie(100), m_posX(posX), m_posXo(0), m_posY(posY), m_posYo(posY), m_tileX(1),
m_tileY(1), m_hauteurTile(75), m_largeurTile(38), m_adresseSprite("images/sprite.png"),
m_sprite(0), m_sens(1), m_courseOn(0), m_sautOn(0), m_preposX(0), m_vitesse(0), m_input()
{
}



Player::Player(int posX, int posY, int width, int height):  m_vie(100), m_posX(posX), m_posXo(0), m_posY(posY), m_posYo(posY), m_tileX(1),
m_tileY(1), m_hauteurTile(height), m_largeurTile(width), m_adresseSprite("images/dahu.png"),
m_sprite(0), m_sens(1), m_courseOn(0), m_sautOn(0), m_preposX(0), m_vitesse(0), m_input()
{

}

void Player::freeSurface()
{
    SDL_FreeSurface(m_sprite);
}

void Player::load()
{
    m_sprite = IMG_Load("images/dahu.png");

    if (!m_sprite)
    {
        printf("Unable to load sprite: %s\n", SDL_GetError());
        exit(1);
    }

}

int Player::get_m_posX()
{
    return m_posX;
}

void Player::draw()
{
    SDL_Rect dest;
    dest.x=m_posX;
    dest.y=m_posY;

    SDL_Rect src;
    src.x=(m_tileX-1)*m_largeurTile;
    src.y=(m_tileY-1)*m_hauteurTile;
    src.w=m_largeurTile;
    src.h=m_hauteurTile;
    // draw sprite
    SDL_BlitSurface(m_sprite, &src, background, &dest);

}


//Vérifie qu'aucune action n'est en cours et affiche la tile correspondante à l'inaction
void Player::immobile()
{
    if(m_courseOn==0 && m_sens==1)
    {
        m_tileY=1;
        m_tileX=1;
    }

    if(m_courseOn==0 && m_sens==2)
    {
        m_tileY=2;
        m_tileX=1;
    }
}

//Peut courir vers la droite ou la gauche
void Player::courir()
{
    //Réinitialise le status de course en Off si aucune touche directionnelle n'est enfoncée alors que le status est encore en On
    if(m_courseOn && !this->getm_input("right") && !this->getm_input("left") || (this->getm_input("right") && this->getm_input("left")))
    {
        m_courseOn=0;

    }

    if(this->getm_input("right") && !m_sautOn)
       {
           //On vérifie qu'on commence à courir et on initialise les status et timers
           if(!m_courseOn)
           {
               m_tileY=1;
               m_sens=1;
               m_courseOn=1;
               rtCourse=SDL_GetTicks();
               rtInterval=SDL_GetTicks();
           }

           //On affiche la tile suivante à chaque boucle
           if(m_tileX<6)
           m_tileX++;
           //Si on est à la dernière tile on revient à la première
           else
            m_tileX=1;
            //Première étape d'accélèration
           if(SDL_GetTicks()-rtCourse<tCourse1)
           m_posX=m_posX+3;
           //Seconde étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse1 && SDL_GetTicks()-rtCourse<tCourse2)
           m_posX=m_posX+5;
           //Troisième étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse2 && SDL_GetTicks()-rtCourse<tCourse3)
           m_posX=m_posX+9;
           //4ème étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse3 && SDL_GetTicks()-rtCourse<tCourse4)
           m_posX=m_posX+13;
           //5ème étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse4 && SDL_GetTicks()-rtCourse<tCourse5)
           m_posX=m_posX+19;
           //Vitesse max
           if(SDL_GetTicks()-rtCourse>=tCourse5)
            m_posX=m_posX+23;


       }

    if(this->getm_input("left"))
       {
           if(!m_courseOn)
           {
               m_tileY=2;
               m_sens=2;
               m_courseOn=1;
               rtCourse=SDL_GetTicks();
               rtInterval=SDL_GetTicks();
           }
           if(m_tileX<6)
           m_tileX++;
           else
            m_tileX=1;
           if(SDL_GetTicks()-rtCourse<tCourse1)
           m_posX=m_posX-3;
           if(SDL_GetTicks()-rtCourse>=tCourse1 && SDL_GetTicks()-rtCourse<tCourse2)
           m_posX=m_posX-5;
           if(SDL_GetTicks()-rtCourse>=tCourse2 && SDL_GetTicks()-rtCourse<tCourse3)
           m_posX=m_posX-9;
           if(SDL_GetTicks()-rtCourse>=tCourse3 && SDL_GetTicks()-rtCourse<tCourse4)
           m_posX=m_posX-13;
           if(SDL_GetTicks()-rtCourse>=tCourse4 && SDL_GetTicks()-rtCourse<tCourse5)
           m_posX=m_posX-19;
           if(SDL_GetTicks()-rtCourse>=tCourse5)
            m_posX=m_posX-23;


       }
}


void Player::saut()
{
    if(!m_sautOn && this->getm_input("space"))
    {
        m_posYo=m_posY;
        m_posXo=m_posX;
        m_sautOn=1;
        rtSaut=SDL_GetTicks();
        rtIntSaut=SDL_GetTicks();
    }
    if(m_sautOn)
    {
        int t= SDL_GetTicks()-rtSaut;
        m_posY=m_posYo - 500*t/1000 + 0.5*1000*t/1000*t/1000;
        m_posX=m_posXo + m_vitesse*t/50;
    }
    if(m_sautOn && SDL_GetTicks()-rtSaut>1000 && m_posY>m_posYo)
    {
        m_posY=m_posYo;
        m_sautOn=0;
    }
}

void Player::vitesse()
{
    if(!m_sautOn)
    {
        m_vitesse=m_posX - m_preposX;
        m_preposX=m_posX;
    }
}

void Player::setm_input(bool a, int touche)
{
    if(touche==1)
        m_input.setm_quit(a);
    if(touche==2)
        m_input.setm_space(a);
    if(touche==3)
        m_input.setm_up(a);
    if(touche==4)
        m_input.setm_down(a);
    if(touche==5)
        m_input.setm_right(a);
    if(touche==6)
    m_input.setm_left(a);


}

bool Player::getm_input(std::string touche)
{
    if(touche=="quit")
    return m_input.getm_quit();
    if(touche=="space")
    return m_input.getm_space();
    if(touche=="up")
    return m_input.getm_up();
    if(touche=="down")
    return m_input.getm_down();
    if(touche=="quit")
    return m_input.getm_quit();
    if(touche=="left")
    return m_input.getm_left();
    if(touche=="right")
    return m_input.getm_right();


}
