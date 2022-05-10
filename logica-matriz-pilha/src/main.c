#include "pilha.h"

int main()
{
	Pilha coluna, linha;
	Item c, l;
	int matriz[MAXTAM][MAXTAM];

	int i = 0; 
	int j = 0;

	FPVazia(&coluna);
	FPVazia(&linha);

	for(i = 0; i < MAXTAM; i++){
		for(j = 0; j < MAXTAM; j++){
			if((i == 3) && (j == 1)){
				matriz[i][j] = 1;
			}
			else if((i == 2) && (j == 2)){
				matriz[i][j] = 1;
			}
			else if((i == 1) && (j == 1)){
				matriz[i][j] = 1;
			}
			else{
				matriz[i][j] = 0;				
			}

			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

//////////////////////////////////////////////////////////

	int checker = 0;
	i = 0;
	j = 0;

	l.val = i;
	c.val = j;
	PUSH(&linha, l);
	PUSH(&coluna, c);


	printf("Coluna:\t");
	PImprime(&coluna);
	printf("\nLinha:\t");
	PImprime(&linha);

	printf("\n\n");


	while(checker != 1){
		
		//Na primeira coluna
		if(j == 0){
			//Anda pra baixo
			if(matriz[i+1][j] != 1 && (i+1 < MAXTAM)){
				printf("[%d][%d]\t", i, j);
				i++;
				l.val = i;
				c.val = j;
				PUSH(&linha, l);
				PUSH(&coluna, c);
			}
			//Anda pra direita
			else if(matriz[i][j+1] != 1){
				printf("[%d][%d]\t", i, j);
				j++;
				l.val = i;
				c.val = j;
				PUSH(&linha, l);
				PUSH(&coluna, c);
			}
			//Volta pra cima
			else if((matriz[i][j+1] == 1) && ((matriz[i+1][j] == 1) || i+1 >= MAXTAM)){
				printf("[%d][%d]\t", i, j);
				matriz[i][j] = 1;
				PRemove(&linha, l);
				PRemove(&coluna, c);
				i--;
			}
			else{
				printf("Obstáculos mal posicionados.\n\n");
			}
		}

		//No meio
		else if(j > 0 && j < (MAXTAM - 1) && (i < MAXTAM)){
			//Anda pra baixo
			if(matriz[i+1][j] != 1 && i < MAXTAM - 1){
				printf("[%d][%d]\t", i, j);
				i++;
				l.val = i;
				c.val = j;
				PUSH(&linha, l);
				PUSH(&coluna, c);
			}
			//Anda pra direita
			else if(matriz[i][j+1] != 1){
				printf("[%d][%d]\t", i, j);
				j++;
				l.val = i;
				c.val = j;
				PUSH(&linha, l);
				PUSH(&coluna, c);
			}
			//Anda pra cima
			else if((matriz[i][j+1] == 1) && (matriz[i+1][j] == 1) && (matriz[i-1][j] != 1)){
				printf("[%d][%d]\t", i, j);
				matriz[i][j] = 1;
				PRemove(&linha, l);
				PRemove(&coluna, c);
				i--;
			}
			//Anda pra esquerda
			else if((matriz[i][j+1] == 1) && (matriz[i+1][j] == 1) && matriz[i-1][j] == 1){
				printf("[%d][%d]\t", i, j);
				matriz[i][j] = 1;
				PRemove(&linha, l);
				PRemove(&coluna, c);
				j--;
			}
		}

		//Na última coluna
		else if(j == (MAXTAM - 1)){
			if(i == (MAXTAM - 1)){
				checker = 1;
				printf("[%d][%d]\t", i, j);
				printf("\tFIM!!\n\n");
			}

			//Anda pra baixo
			else if(matriz[i+1][j] != 1 && i < MAXTAM){
				printf("[%d][%d]\t", i, j);
				i++;
				l.val = i;
				c.val = j;
				PUSH(&linha, l);
				PUSH(&coluna, c);
			}
			//Anda pra esquerda
			else if((i == 0) && matriz[i+1][j] == 1){
				printf("[%d][%d]\t", i, j);
				matriz[i][j] = 1;
				PRemove(&linha, l);
				PRemove(&coluna, c);
				j--;

			}
			//Anda pra esquerda
			else if(matriz[i+1][j] == 1){
				printf("[%d][%d]\t", i, j);
				// printf("i: %d, j: %d\n\n", i, j);
				j--;
				l.val = i;
				c.val = j;
				PUSH(&linha, l);
				PUSH(&coluna, c);
			}
			//Anda pra cima
			else if((matriz[i+1][j] == 1) && (matriz[j-1][i] == 1)){
				printf("[%d][%d]\t", i, j);
				matriz[i][j] = 1;
				PRemove(&linha, l);
				PRemove(&coluna, c);
				i--;
			}
		}
	}


	printf("Linha:\t");
	PImprime(&linha);
	printf("Coluna:\t");
	PImprime(&coluna);

//ALGO ERRADO NA LINHA

	return 0;
}
