#include <funzioni.h>


int main(int argc, char **argv)
{	
	int direzione = 4;
	int direzionePre = 4;
	int dimensione = 1;
	//variabili del tempo di avanzamento del gioco
	time_t tempo;
	//variabile della dimensione del campo di gioco
	int n = 33;
	//matrice del campo di gioco
	char playGround[SIZE][SIZE];
	//inizializzo il campo di gioco
	playGroundInit(n, playGround);
	//dichiaro e inizializzo il serpente
	snake pezzo[64];
	pezzo[0].x = n/2;
	pezzo[0].y = n/2;
	snakePrint(pezzo[0], playGround);
	//dichiaro una mela
	//apple mela;
	appleSpawn(playGround);
	//aggiorno la schermata
	stampaSchermata(n, playGround);
	//assumo inizialmente il tempo
	tempo = time(NULL);
	//ciclo infinito
	while(1){
		//verifico se c'è un input
		if(kbhit()){
			direzionePre = direzione;
			direzione = input();
			direzione = dirVrfy(direzione, direzionePre);
		}
		//verifico se è passato un determinato lasso di tempo
		if(clockF(&tempo)){
			dimensione += moveSnake(direzione, pezzo,playGround);
			if(ctrlSnake(pezzo)){
				system("cls");
				printf("hai perso\n");
				return 0;
			}
			stampaSchermata(n, playGround);
		}
		
	}
	return 0;
}



