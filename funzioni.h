#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define SIZE 33
#define SPEED 0.5
//funzione che scandisce il clock passato in ingresso un indirizzo con il tempo
int clockF(time_t *temp);
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
		int h;
	}snake;
/*
typedef struct{
		int x;
		int y;
	}apple; */
//funzione che stampa la posizione del serpente nel campo di gioco
void snakePrint(snake chunk, char playGround[SIZE][SIZE]);
//funzione che rimuove la parte del serpente nel campo di gioco
void snakeDelete(snake chunk, char playGround[SIZE][SIZE]);
//funzione che controlla se il serpente tocca il bordo
int ctrlSnake(snake *chunk);
//funzione che calcola il movimento del serpente
int moveSnake(int dir, snake *chunk,char playGround[SIZE][SIZE]);
//funzione che verifica che il movimento del serpente avvenga ortogonalmente
int dirVrfy(int dir, int prevDir);
//funzione che spawna le mele nel campo di gioco
void appleSpawn(char playGround[SIZE][SIZE]);