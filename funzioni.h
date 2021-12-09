#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/time.h>
#include <time.h>
//dimensione del campo di gioco
#define SIZE 33
//velocità di aggiornamento del gioco in secondi
#define SPEED 0.2

float time_diff(struct timespec *start, struct timespec *end);
//funzione che inizializza il campo di gioco
void playGroundInit(int n, char playGround[SIZE][SIZE]);
//funzione che stampa il campo di gioco
void stampaSchermata(int n, char schermata[SIZE][SIZE]);
//funzione che legge l'input da tastiera
int input();
//tipo di variabile serpente
typedef struct{
		int x;
		int y;
		int preX;
		int preY;
	}snake;
//funzione che stampa la posizione del serpente nel campo di gioco
void snakePrint(snake chunk, char playGround[SIZE][SIZE]);
//funzione che rimuove la parte del serpente nel campo di gioco
void snakeDelete(snake chunk, char playGround[SIZE][SIZE]);
//funzione che controlla se il serpente tocca il bordo
int ctrlSnake(snake *chunk, char playGround[SIZE][SIZE]);
//funzioni che calcolano il movimento del serpente
//TESTA
int moveSnakeHead(int dir, snake *chunk,char playGround[SIZE][SIZE],int dim);
//CORPO
void moveSnakeBody(snake *chunk,char playGround[SIZE][SIZE], int dim);
//funzione che verifica che il movimento del serpente avvenga ortogonalmente
int dirVrfy(int dir, int prevDir);
//funzione che spawna le mele nel campo di gioco
void appleSpawn(char playGround[SIZE][SIZE]);
//funzione che termina il gioco
void endgame(int c);