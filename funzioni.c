#include <funzioni.h>

//funzione utile a scandire il tempo calcolando la differenza tra due tempi
float time_diff(struct timespec *start, struct timespec *end){
    return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_nsec - start->tv_nsec);
}

//funzione che muove i pezzi dello snake aggiornandoli sul playground
int moveSnakeHead(int dir, snake *chunk,char playGround[SIZE][SIZE],int dim){
	snakeDelete(*chunk, playGround);
	chunk->preX = chunk->x;
	chunk->preY = chunk->y;
	switch(dir){
		case 1:
			chunk->x-=1;
			break;
		case 2:
			chunk->y+=1;
			break;
		case 3:
			chunk->x+=1;
			break;
		case 4:
			chunk->y-=1;
			break;
	}
	if(playGround[chunk->y][chunk->x] == (char)169){
		snakePrint(*chunk, playGround);
		chunk[dim].x = chunk[dim-1].preX;
		chunk[dim].y = chunk[dim-1].preY;
		appleSpawn(playGround);
		return 1;
	}
	if(ctrlSnake(chunk,playGround))
		return -999;
	snakePrint(*chunk, playGround);
	return 0;

}

//funzione che muove il corpo del serpente
void moveSnakeBody(snake *chunk,char playGround[SIZE][SIZE],int dim){
	 for(int i = 0; i<dim-1;i++){
		 //AKA SnakeDelete
		playGround[chunk[i+1].y][chunk[i+1].x] = ' ';
		chunk[i+1].preX = chunk[i+1].x;
		chunk[i+1].preY = chunk[i+1].y;
		chunk[i+1].x = chunk[i].preX;
		chunk[i+1].y = chunk[i].preY;
		//AKA SnakePrint
		playGround[chunk[i+1].y][chunk[i+1].x] = (char)001;
	 }
}

//funzione che controlla se il serpente tocca un bordo
int ctrlSnake(snake *chunk, char playGround[SIZE][SIZE]){
	if(playGround[chunk->y][chunk->x] != ' ' && playGround[chunk->y][chunk->x] != (char)169){
			endgame(1);
			return 1;
	}
	else 
		return 0;
}
//funzione che stampa sul playground un chunk del serpente
void snakePrint(snake chunk, char playGround[SIZE][SIZE]){
	playGround[chunk.y][chunk.x] = (char)001;
}
//funzione che cancella dal playground un chunk del serpente
void snakeDelete(snake chunk, char playGround[SIZE][SIZE]){
	playGround[chunk.y][chunk.x] = ' ';
}
//funzione che crea il campo di gioco
void playGroundInit(int n, char playGround[SIZE][SIZE]){
	for(int i = 0; i<n;i++)
		for(int k=0;k<n;k++)
			playGround[i][k] = ' ';
	//ciclo per creare i bordi della matrice del campo di gioco
	for(int i = 0; i < n; i++){
		if(i==0 || i == n-1){
			for(int j = 0 ; j<n ; j++)
				playGround[i][j] = (char)205;
		}
		else
			for(int j = 0 ; j<n ; j+=n-1)
				playGround[i][j] = (char)186;
		
	}
	playGround[0][0] = (char)201;
	playGround[0][SIZE-1] =	(char)187;
	playGround[SIZE-1][0] = (char)200;
	playGround[SIZE-1][SIZE-1] = (char)188;
}
//funzione che stampa il campo di gioco a video
void stampaSchermata(int n, char schermata[SIZE][SIZE]){
	system("cls");
	for(int i = 0; i<n; i++){
		for(int j = 0; j < n; j++)
			putchar(schermata[i][j]);
		putchar('\n');
	}
}

//funzione che gestisce gli input da tastiera
int input()
{
        switch (getch()){
		case 'a':
			return 1;
		case 's':
			return 2;
		case 'd':
			return 3;
		case 'w':
			return 4;
		default:
			return 5;
		}
}

//funzione che verifica l'ortogonalità dei movimenti del serpente
int dirVrfy(int dir, int prevDir){
	switch(dir){
		case 1:
			if(prevDir == 3)
				return prevDir;
			break;
		case 2:
			if(prevDir == 4)
				return prevDir;
			break;
		case 3:
			if(prevDir == 1)
				return prevDir;
			break;
		case 4:
			if(prevDir == 2)
				return prevDir;
			break;
	}
	return dir;
}
//funzione che spawna casualmente le mele in giro per la mappa
void appleSpawn(char playGround[SIZE][SIZE]){
	int x,y;
	do{
		x = rand()%31+1;
		y = rand()%31+1;
	}while(playGround[y][x] != ' ');
	playGround[y][x] = (char)169;
	
	}
//funzione che gestisce la fine del gioco in base al parametro in ingresso
void endgame(int c){
		system("cls");
		if(c)
			printf("hai perso\n");
		else
			printf("hai vinto, il serpente e' lunghissimo!!!!!\n");
	}