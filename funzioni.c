#include <funzioni.h>
//funzione che muove i pezzi dello snake aggiornandoli sul playground
int moveSnake(int dir, snake *chunk,char playGround[SIZE][SIZE]){
	snakeDelete(*chunk, playGround);
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
		appleSpawn(playGround);
		return 1;
	}
	else{
		snakePrint(*chunk, playGround);
		return 0;
	}
}
//funzione che controlla se il serpente tocca un bordo
int ctrlSnake(snake *chunk){
	if(chunk->x == 1 || chunk->x == SIZE-1 || chunk->y == 1 || chunk->y == SIZE-1)
		return 1;
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
//funzione che verifica il clock
int clockF(time_t *temp){
	if(difftime(time(NULL),*temp)>SPEED){
		*temp = time(NULL);
		return 1;
	}
	else
		return 0;
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

void appleSpawn(char playGround[SIZE][SIZE]){
	int x,y;
	do{
		x = rand()%31+1;
		y = rand()%31+1;
	}while(playGround[y][x] != ' ');
	playGround[y][x] = (char)169;
	
	}