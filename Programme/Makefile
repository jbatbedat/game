#LDFLAGS = `-lSDL -lSDL_gfx -lSDL_image -lSDL_ttf`
LDFLAGS = `sdl-config -libs`
LDFLAGS = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -lSDL_image -lpthread 
CC = g++
DEST = ./bin
OBJ = ./obj


# Création de l'exécutable 'Game'
 
all: create boucle.o draw.o event.o init.o Input.o main.o Player.o map.o
	$(CC) $(OBJ)/*.o -o $(DEST)/Game $(LDFLAGS)
 
# Création du dossier bin (à condition que ce dernier n'existe pas déjà)
 
create:
	mkdir -p bin
	mkdir -p obj
 
 
############ Compilation de l'ensemble des fichiers ############
main.o: ./main.cpp ./main.h ./map.h ./globals.h
	$(CC) -c main.cpp -o $(OBJ)/main.o `sdl-config --cflags`
 
boucle.o: ./boucle.cpp ./boucle.h
	$(CC) -c boucle.cpp -o $(OBJ)/boucle.o
 
draw.o: ./draw.cpp ./draw.h ./globals.h
	$(CC) -c draw.cpp -o $(OBJ)/draw.o
 
event.o: ./event.cpp ./event.h ./globals.h
	$(CC) -c event.cpp -o $(OBJ)/event.o
 
init.o: ./init.cpp ./init.h ./globals.h
	$(CC) -c init.cpp -o $(OBJ)/init.o

Input.o: ./Input.cpp ./Input.h ./globals.h
	$(CC) -c Input.cpp -o $(OBJ)/Input.o

Player.o: ./Player.cpp ./Player.h ./globals.h
	$(CC) -c Player.cpp -o $(OBJ)/Player.o

map.o: ./map.cpp ./map.h
	$(CC) -c map.cpp -o $(OBJ)/map.o
 
# Suppression des fichiers temporaires
clean:
	rm -rf $(OBJ)/*.o
 
# Suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
very-clean: clean
	rm -rf bin
	rm -rf Game
	rm -rf obj

