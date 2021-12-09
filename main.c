#include <funzioni.h>


int main(int argc, char **argv)
{	
	int direzione = 4;
	int direzionePre = 4;
	int dimensione = 1;
	//variabili del tempo di avanzamento del gioco
	//time_t tempo;
	struct timespec start2;
    struct timespec end2;
	clock_gettime(CLOCK_REALTIME, &start2);
	//matrice del campo di gioco
	char playGround[SIZE][SIZE];
	//inizializzo il campo di gioco
	playGroundInit(SIZE, playGround);
	//dichiaro e inizializzo il serpente
	snake pezzo[64];
	for(int i = 0 ;i <64;i++){
	pezzo[i].x = SIZE/2;
	pezzo[i].y = SIZE/2;
	}
	snakePrint(pezzo[0], playGround);
	//dichiaro una mela
	//apple mela;
	appleSpawn(playGround);
	//aggiorno la schermata
	stampaSchermata(SIZE, playGround);
	//ciclo infinito
	while(1){
		//verifico se c'è un input
		if(kbhit()){
			direzionePre = direzione;
			direzione = input();
			direzione = dirVrfy(direzione, direzionePre);
		}
		//verifico se è passato un determinato lasso di tempo
		if(time_diff(&start2, &end2) >= SPEED){
			clock_gettime(CLOCK_REALTIME, &start2);
			//la funzione moveSnakeHead restituisce 1 se è stata mangiata una mela
			//zero se non è accaduto nulla, -999 se ' stato colpito il corpo o una parete
			dimensione += moveSnakeHead(direzione, pezzo,playGround, dimensione);
			//Se la dimensione è minore di zero vuol dire che il serpente ha toccato il bordo o il suo corpo
			//AKA fine del gioco, se la dimensione è maggiore di 64 hai vinto
			if(dimensione < 0){
				endgame(1);
				return 0;
			}
			if(dimensione > 64){
				endgame(0);
				return 0;
			}
			//se la dimensione è maggiore di 1 devo movimentare anche il corpo del serpente oltre la testa
			if(dimensione > 1){
				moveSnakeBody(pezzo,playGround,dimensione);
			}
			//Refresh della schermata del campo di gioco
			stampaSchermata(SIZE, playGround);
		}
		clock_gettime(CLOCK_REALTIME, &end2);
	}
	return 0;
}



