#include "Pile.hpp"
using namespace std;

void FPVazia(Pilha *p){
	p->base = (SBlock*) malloc (sizeof(SBlock));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, SItem d){
	SBlock *aux = (SBlock*) malloc (sizeof(SBlock));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, SItem *d){
	SBlock *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}

int return_matrix_size_stack() {
	string letter;
    int matrix_tam;
    ifstream file;
    file.open("matrix_read.txt");

    if (file.is_open()) {
        getline(file, letter);
		matrix_tam = stoi(letter);
    }

    file.close();
    return matrix_tam;
}

int matrix_tam_stack = return_matrix_size_stack();

void get_matrix_values_stack(char *vet) {
	char letter;
	int k = 0;
	ifstream file;
	file.open("matrix_read.txt");

	if (file.is_open()) {
		while(!file.eof()) { 
			file.get(letter);
			if (letter == 'A' || letter == 'P') {
				vet[k] = letter;
				k++;
			}
		}
	}
	file.close();
}

void runMatrix(){
	//cout << matrix_tam_stack;
	Pilha coluna, linha;
	SItem c, l;
	FPVazia(&coluna);
	FPVazia(&linha);

	int checker = 0, i = 0, j = 0, cont = 0, k;
    char matrix[matrix_tam_stack][matrix_tam_stack], vet_aux[matrix_tam_stack*matrix_tam_stack];
	get_matrix_values_stack(vet_aux);
    k = 0;
	
    for (i = 0; i < matrix_tam_stack; i++) {
        for (j = 0; j < matrix_tam_stack; j++) {
            matrix[i][j] = vet_aux[k];
			
            k++;       
        }
    }

    for (i = 0; i < matrix_tam_stack; i++) {
        for (j = 0; j < matrix_tam_stack; j++) {
            cout << matrix[i][j] << "\t"; 	      
        }
        cout << endl;
    }

	i = 0; j = 0;
	l.val = i;
	c.val = j;
	Push(&linha, l);
	Push(&coluna, c);

	printf("Caminho percorrido em [i][j]:\t");

	while(checker != 1){
		
		//Na primeira coluna
		if(j == 0){
			//Anda pra baixo
			if(matrix[i+1][j] != 'P' && (i+1 < matrix_tam_stack)){
				printf("[%d][%d]\t", i, j);
				i++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra direita
			else if(matrix[i][j+1] != 'P'){
				printf("[%d][%d]\t", i, j);
				j++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Volta pra cima
			else if((matrix[i][j+1] == 'P') && ((matrix[i+1][j] == 'P') || i+1 >= matrix_tam_stack)){
				printf("[%d][%d]\t", i, j);
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				i--;
			}
			else{
				//printf("Obstáculos mal posicionados.\n\n");
			}
		}

		//No meio
		else if(j > 0 && j < (matrix_tam_stack - 1) && (i < matrix_tam_stack)){
			//Anda pra baixo
			if(matrix[i+1][j] != 'P' && i < (matrix_tam_stack-1)){
				printf("[%d][%d]\t", i, j);
				i++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra direita
			else if(matrix[i][j+1] != 'P'){
				printf("[%d][%d]\t", i, j);
				j++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra cima
			else if((matrix[i][j+1] == 'P') && (matrix[i+1][j] == 'P' || i == (matrix_tam_stack-1)) && (matrix[i-1][j] != 'P')){
				printf("[%d][%d]\t", i, j);
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				i--;
			}
			//Anda pra esquerda
			else if((matrix[i][j+1] == 'P') && (matrix[i+1][j] == 'P' || i == matrix_tam_stack-1) && matrix[i-1][j] == 'P'){
				printf("[%d][%d]\t", i, j);
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				j--;
			}
			else{
				//printf("Obstáculos mal posicionados.\n\n");
			}
		}

		//Na última coluna
		else if(j == (matrix_tam_stack - 1)){
			if(i == (matrix_tam_stack - 1)){
				checker = 1;
				printf("[%d][%d]\t", i, j);
				printf("FIM!!\n\n");
			}

			//Anda pra baixo
			else if(matrix[i+1][j] != 'P' && i < matrix_tam_stack){
				printf("[%d][%d]\t", i, j);
				i++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra esquerda  *** ATENÇÃO ***
			else if((i == 0) && matrix[i+1][j] == 'P'){
				printf("[%d][%d]\t", i, j);
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				j--;
			}
			//Anda pra esquerda
			else if(matrix[i+1][j] == 'P'){
				printf("[%d][%d]\t", i, j);
				// printf("i: %d, j: %d\n\n", i, j);
				j--;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra cima
			else if((matrix[i+1][j] == 'P') && (matrix[j-1][i] == 'P')){
				printf("[%d][%d]\t", i, j);
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				i--;
			}
			else{
				//printf("Obstáculos mal posicionados.\n\n");
			}
		}
		cont++;
	}

	printf("Posições empilhadas de linha:\t");
	PImprime(&linha);
	printf("Posições empilhadas de coluna:\t");
	PImprime(&coluna);

	printf("Número de posições testadas: %d\n\n", cont);
}


void PImprime(Pilha *p){
	SBlock *aux;

	aux = p->top;
	while(aux != p->base){
		printf("%d\t", aux->data.val);
		aux = aux->prox;
	}
	printf("\n");
}