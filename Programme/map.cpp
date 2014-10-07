#include <string.h>
#include "map.h"

#define CACHE_SIZE 5000

SDL_Surface* LoadImage32(const char* fichier_image)
{
	SDL_Surface* image_result;
	SDL_Surface* image_ram = SDL_LoadBMP(fichier_image);	// charge l'image dans image_ram en RAM
	if (image_ram==NULL)
	{
		printf("Image %s introuvable !! \n",fichier_image);
		SDL_Quit();
		system("pause");
		exit(-1);
	}
	image_result = SDL_DisplayFormat(image_ram);
	SDL_FreeSurface(image_ram);
	return image_result;
}

void ChargerMap_tileset(FILE* F,Map* m)
{
	int numtile,i,j;
	char buf[CACHE_SIZE];  // un buffer, petite mémoire cache
	char buf2[CACHE_SIZE];  // un buffer, petite mémoire cache
	fscanf(F,"%s",buf); // nom du fichier
	m->tileset = LoadImage32(buf);
	fscanf(F,"%d %d",&m->nbtilesX,&m->nbtilesY);
	m->LARGEUR_TILE = m->tileset->w/m->nbtilesX;
	m->HAUTEUR_TILE = m->tileset->h/m->nbtilesY;
	m->props = (TileProp *) malloc(m->nbtilesX*m->nbtilesY*sizeof(TileProp));
	for(j=0,numtile=0;j<m->nbtilesY;j++)
	{
		for(i=0;i<m->nbtilesX;i++,numtile++)
		{
			m->props[numtile].R.w = m->LARGEUR_TILE;
			m->props[numtile].R.h = m->HAUTEUR_TILE;
			m->props[numtile].R.x = i*m->LARGEUR_TILE;
			m->props[numtile].R.y = j*m->HAUTEUR_TILE;
			fscanf(F,"%s %s",buf,buf2);
			m->props[numtile].plein = 0;
			if (strcmp(buf2,"plein")==0)
				m->props[numtile].plein = 1;
		}
	}
}

void ErrorQuit(const char* error)
{
	puts(error);
	SDL_Quit();
	system("pause");
	exit(-1);
}

void ChargerMap_level(FILE* F,Map* m)
{
	int i,j;
	fscanf(F,"%d %d",&m->nbtiles_largeur_monde,&m->nbtiles_hauteur_monde);
	m->schema = (unsigned char **) malloc(m->nbtiles_largeur_monde*sizeof(tileindex*));
	for(i=0;i<m->nbtiles_largeur_monde;i++)
		m->schema[i] = (unsigned char *) malloc(m->nbtiles_hauteur_monde*sizeof(tileindex));
	for(j=0;j<m->nbtiles_hauteur_monde;j++)
	{
		for(i=0;i<m->nbtiles_largeur_monde;i++)
		{
			int tmp;
			fscanf(F,"%d",&tmp);
			if (tmp>=m->nbtilesX*m->nbtilesY)
				ErrorQuit("level tile hors limite\n");
			m->schema[i][j] = tmp;
		}
	}
}

Map* ChargerMap(const char* level)
{
	FILE* F;
	Map* m;
	char buf[CACHE_SIZE];
	F = fopen(level,"r");
	if (!F)
		ErrorQuit("fichier level introuvale\n");
	fgets(buf,CACHE_SIZE,F);
	if (strstr(buf,"Tilemapping Version 1.0")==NULL)
		ErrorQuit("Mauvaise version du fichier level. Ce programme attend la version 1.0\n");
	m = (Map *) malloc(sizeof(Map));
	do 
	{
		fgets(buf,CACHE_SIZE,F);
		if (strstr(buf,"#tileset"))
			ChargerMap_tileset(F,m);
		if (strstr(buf,"#level"))
			ChargerMap_level(F,m);
	} while (strstr(buf,"#fin")==NULL);
	fclose(F);
	return m;
}

int AfficherMap(Map* m,SDL_Surface* screen)
{
	int i,j;
	SDL_Rect Rect_dest;
	int numero_tile;
	for(i=0;i<m->nbtiles_largeur_monde;i++)
	{
		for(j=0;j<m->nbtiles_hauteur_monde;j++)
		{
			Rect_dest.x = i*m->LARGEUR_TILE;
			Rect_dest.y = j*m->HAUTEUR_TILE;
			numero_tile = m->schema[i][j];
			SDL_BlitSurface(m->tileset,&(m->props[numero_tile].R),screen,&Rect_dest);
		}
	}
	return 0;
}

int LibererMap(Map* m)
{
	int i;
	SDL_FreeSurface(m->tileset);
	for(i=0;i<m->nbtiles_hauteur_monde;i++)
		free(m->schema[i]);
	free(m->schema);
	free(m->props);
	free(m);
	return 0;
}
