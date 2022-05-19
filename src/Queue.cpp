#include "Queue.hpp"
using namespace std;

void FFVazia(Fila *f){
	f -> first = (Block*) malloc (sizeof(Block));
	f -> last  = f -> first;
	f -> first -> prox = NULL;
}

void Enfileira(Fila *f, Item d){
	f -> last -> prox = (Block*) malloc (sizeof(Block));
	f -> last = f -> last -> prox;
	f -> last -> data = d;
	f -> last -> prox = NULL;
}

void Desenfileira(Fila *f, Item *d){
	Block *aux;

	if(f -> first == f -> last || f == NULL || f -> first -> prox == NULL){
		//printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f -> first -> prox;
	f -> first -> prox = aux -> prox;
    if (f -> first -> prox == NULL) {
        f -> last = f -> first;
    }
	d -> val = aux -> data.val;
	free(aux);
}

void FImprime(Fila *f){
	Block *aux;

	aux = f -> first -> prox;
	while(aux != NULL){
		cout << aux -> data.val << " ";
		aux = aux -> prox;
	}
}

bool queue_is_empty(Fila *f) {
    if (f -> first == f -> last || f -> first -> prox == NULL || f == NULL) {
        return true; 
    } else {
        return false;
    }
}

int return_matrix_size() {
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

int matrix_tam = return_matrix_size();

void get_matrix_values(char *vet_aux) {
	char letter;
    int k = 0;
    ifstream file;
    file.open("matrix_read.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            for (int i = 0; i < matrix_tam; i++) {
                for (int j = 0; j < matrix_tam; j++) {
                    file.get(letter);
                    if (letter == 'A' || letter == 'P') {
                        vet_aux[k] = letter;
                        k++;
                    } 
                }
            }
        }
    }
  
    file.close();
}

void solve() {
	int matrix_tam = return_matrix_size(), k = 0, i, j;
    char matrix[matrix_tam][matrix_tam], vet_aux[matrix_tam*matrix_tam];
    get_matrix_values(vet_aux);
    
    k = 0;

    for (i = 0; i < matrix_tam; i++) {
        for (j = 0; j < matrix_tam; j++) {
            matrix[i][j] = vet_aux[k];
            k++;       
        }
    }

    for (i = 0; i < matrix_tam; i++) {
        for (j = 0; j < matrix_tam; j++) {
            cout << matrix[i][j] << "\t";       
        }
        cout << endl;
    }

    Fila linha, coluna; 
    Item l, c;
    int cont = 0;
    FFVazia(&linha); 
    FFVazia(&coluna);
    l.val = 0;
    c.val = 0;
    cout << endl << endl;
    while (i != matrix_tam - 1 || j != matrix_tam - 1) {
        i = l.val;
        j = c.val;

        if (matrix[i + 1][j] == 'A' && (i < (matrix_tam - 1))){ 
            l.val = i + 1;
            c.val = j;
            matrix[i + 1][j] = 'v';
            Enfileira(&linha, l);
            Enfileira(&coluna, c);
        }

        if (matrix[i][j + 1] == 'A' && (j < (matrix_tam - 1))) { 
            l.val = i;
            c.val = j + 1;
            matrix[i][j + 1] = '>';
            Enfileira(&linha, l);
            Enfileira(&coluna, c);
        }

        Desenfileira(&linha, &l);
        Desenfileira(&coluna, &c);
        if (i != matrix_tam-1 || j != matrix_tam-1) {
            cont++;
        }
    }

    cout << endl << endl << "ITERACOES: " << cont << endl << endl;

    for (i = 0; i < matrix_tam; i++) {
        for(j = 0; j < matrix_tam; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}