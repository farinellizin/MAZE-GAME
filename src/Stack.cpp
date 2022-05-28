#include "Stack.hpp"
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
	Pilha coluna, linha;
	SItem c, l;
	FPVazia(&coluna);
	FPVazia(&linha);

	int checker = 0, i = 0, j = 0, cont = 0, k;
    char matrix[matrix_tam_stack][matrix_tam_stack], vet_aux[matrix_tam_stack*matrix_tam_stack];
    char matrix_aux[matrix_tam_stack][matrix_tam_stack];
	get_matrix_values_stack(vet_aux);
    k = 0;
	
    for (i = 0; i < matrix_tam_stack; i++) {
        for (j = 0; j < matrix_tam_stack; j++) {
            matrix[i][j] = vet_aux[k];
			
            k++;       
        }
    }

    for (i = 0; i < matrix_tam_stack; i++){
    	for (j = 0; j < matrix_tam_stack; j++){
    		matrix_aux[i][j] = matrix[i][j];
    	}
    }

    cout << "\t\t\t    ~ This is the matrix read from the file ~" << endl << endl;

    for (i = 0; i < matrix_tam_stack; i++) {
        cout << "\t\t\t";
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

	while(checker != 1){
		
		//Na primeira coluna
		if(j == 0){
			//Anda pra baixo
			if(matrix[i+1][j] != 'P' && (i+1 < matrix_tam_stack)){
				matrix_aux[i][j] = 'x';
				i++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra direita
			else if(matrix[i][j+1] != 'P'){
				matrix_aux[i][j] = 'x';
				j++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Volta pra cima
			else if((matrix[i][j+1] == 'P') && ((matrix[i+1][j] == 'P') || i+1 >= matrix_tam_stack)){
				matrix_aux[i][j] = 'x';
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				i--;
			}
		}

		//No meio
		else if(j > 0 && j < (matrix_tam_stack - 1) && (i < matrix_tam_stack)){
			//Anda pra baixo
			if(matrix[i+1][j] != 'P' && i < (matrix_tam_stack-1)){
				matrix_aux[i][j] = 'x';
				i++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra direita
			else if(matrix[i][j+1] != 'P'){
				matrix_aux[i][j] = 'x';
				j++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra cima
			else if((matrix[i][j+1] == 'P') && (matrix[i+1][j] == 'P' || i == (matrix_tam_stack-1)) && (matrix[i-1][j] != 'P')){
				matrix_aux[i][j] = 'x';
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				i--;
			}
			//Anda pra esquerda
			else if((matrix[i][j+1] == 'P') && (matrix[i+1][j] == 'P' || i == matrix_tam_stack-1) && matrix[i-1][j] == 'P'){
				matrix_aux[i][j] = 'x';
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				j--;
			}
		}

		//Na última coluna
		else if(j == (matrix_tam_stack - 1)){
			if(i == (matrix_tam_stack - 1)){
				checker = 1;
				matrix_aux[i][j] = 'x';
			}

			//Anda pra baixo
			else if(matrix[i+1][j] != 'P' && i < matrix_tam_stack){
				matrix_aux[i][j] = 'x';
				i++;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra esquerda  * ATENÇÃO *
			else if((i == 0) && matrix[i+1][j] == 'P'){
				matrix_aux[i][j] = 'x';
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				j--;
			}
			//Anda pra esquerda
			else if(matrix[i+1][j] == 'P'){
				matrix_aux[i][j] = 'x';
				j--;
				l.val = i;
				c.val = j;
				Push(&linha, l);
				Push(&coluna, c);
			}
			//Anda pra cima
			else if((matrix[i+1][j] == 'P') && (matrix[j-1][i] == 'P')){
				matrix_aux[i][j] = 'x';
				matrix[i][j] = 'P';
				Pop(&linha, &l);
				Pop(&coluna, &c);
				i--;
			}
		}
		cont++;
	}

	cout << endl << "\t\t\tAfter completing the process of roaming throughout " << endl;
    cout << "\t\tthe entire matrix by the DFS method, we could count " << cont << " iterations.";
    cout << endl << endl << "\t\t   ~ This is the path used to make it to the final position ~" << endl << endl;

	matrix_aux[0][0] = 'S'; matrix_aux[matrix_tam_stack - 1][matrix_tam_stack - 1] = 'F';	

	for (i = 0; i < matrix_tam_stack; i++) {
    	cout << "\t\t\t";
		for (j = 0; j < matrix_tam_stack; j++) {
            cout << matrix_aux[i][j] << "\t"; 	      
        }
        cout << endl;
    }

    cout << endl << "\t\t    'S' corresponds to the initial position, it stands for 'Start'." << endl;
    cout << "\t\t    'F' corresponds to the final position, it stands for 'Finish'." << endl;
    cout << "\t\t    All the 'x' corresponds to the move made in the previous position." << endl;
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