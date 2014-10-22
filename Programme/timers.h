#ifndef TIMERS_H_INCLUDED
#define TIMERS_H_INCLUDED



#endif // TIMERS_H_INCLUDED

//durée de chaque étape de l'accélération lors de la course
int const tCourse1=3*16;
int const tCourse2=15*16;
int const tCourse3=39*16;
int const tCourse4=71*16;
int const tCourse5=123*16;
//durée d'un interval entre 2 changements de tiles du sprite
int const tInterval=1*16;
//temps écoulée depuis le début de la course et depuis le début de l'interval (dernier changement de tile)
int rtCourse;
int rtInterval;

int rtSaut;
int rtIntSaut;
