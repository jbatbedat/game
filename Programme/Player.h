#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Input.h"


class Player
{
public:

Player();
Player(int posX, int posY);
Player(int posX, int posY, int width, int height);

void load();
void draw();
void freeSurface();
void courir();
void immobile();
void saut();
void vitesse();
int get_m_posX();
void setm_input(bool a, int b);
bool getm_input(std::string touche);


private:

int m_vie;
int m_posX;
int m_posXo;
int m_preposX;
int m_posY;
int m_posYo;
int m_vitesse;
int m_tileX;
int m_tileY;
int m_hauteurTile;
int m_largeurTile;
std::string m_adresseSprite;
SDL_Surface *m_sprite;

Input m_input;
//attributs d'états du personnage
int m_sens;
bool m_courseOn;
bool m_sautOn;

};


#endif // PLAYER_H
