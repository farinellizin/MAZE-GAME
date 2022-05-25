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

void swap(Block *a, Block *b){
	Item aux;
	aux = a -> data;
	a -> data = b -> data;
	b -> data = aux;
}

// void Desenfileira(Fila *f, Item *d){
// 	Block *aux;

// 	if(f -> first == f -> last || f == NULL || f -> first -> prox == NULL){
// 		//printf("FILA VAZIA!\n");
// 		return;
// 	}
	
// 	aux = f -> first -> prox;
// 	f -> first -> prox = aux -> prox;
//     if (f -> first -> prox == NULL) {
//         f -> last = f -> first;
//     }
// 	d -> val = aux -> data.val;
// 	free(aux);
// }

void manhattan_dequeue(Fila *f, Item *aux) {
    Block *tmp;

    if (f -> first == f -> last || f == NULL || f -> first -> prox == NULL) {
        return;
    }

    tmp = f -> first -> prox;
    f -> first -> prox = tmp -> prox;
    if (f -> first -> prox == NULL) {
        f -> last = f -> first;
    }

    aux -> manhattan_distance = tmp -> data.manhattan_distance;
    aux -> pos_i = tmp -> data.pos_i;
    aux -> pos_j = tmp -> data.pos_j;
}


void euclidean_dequeue(Fila *f, Item *aux) {
    Block *tmp;

    if (f -> first == f -> last || f == NULL || f -> first -> prox == NULL) {
        return;
    }

    tmp = f -> first -> prox;
    f -> first -> prox = tmp -> prox;
    if (f -> first -> prox == NULL) {
        f -> last = f -> first;
    }

    aux -> euclidean_distance = tmp -> data.euclidean_distance;
    aux -> pos_i = tmp -> data.pos_i;
    aux -> pos_j = tmp -> data.pos_j;
}

// void FImprime(Fila *f){
// 	Block *aux;

// 	aux = f -> first -> prox;
// 	while(aux != NULL){
// 		cout << aux -> data.val << " ";
// 		aux = aux -> prox;
// 	}
// }



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

void manhattan_sort(Fila *manhattan_queue) {
    Block *i, *j;

    i = manhattan_queue -> first -> prox;

    while (i != NULL) {
        j = i -> prox;
        while (j != NULL) {
            if (j -> data.manhattan_distance < i -> data.manhattan_distance) {
                swap(i, j);
            }
            j = j -> prox;
        }
        i = i -> prox; 
    }
}

void euclidean_sort(Fila *euclidean_queue) {
    Block *i, *j;

    i = euclidean_queue -> first -> prox;

    while (i != NULL) {
        j = i -> prox;
        while (j != NULL) {
            if (j -> data.euclidean_distance < i -> data.euclidean_distance) {
                swap(i, j);
            }
            j = j -> prox;
        }
        i = i -> prox;
    }
}

void manhattan_heuristic_calc(Fila *manhattan_queue, int i, int j) {
    int distance;
    Item aux;

    distance = abs(matrix_tam - i - 1) + abs(matrix_tam - j - 1);
    aux.manhattan_distance = distance;
    aux.pos_i = i;
    aux.pos_j = j;

    Enfileira(manhattan_queue, aux);
    manhattan_sort(manhattan_queue);
}

void euclidean_heuristic_calc(Fila *euclidean_queue, int i, int j) {
    float distance;
    Item aux;

    distance = sqrt(pow(abs((matrix_tam - 1) - i), 2) + pow(abs((matrix_tam - 1) - j), 2));
    aux.euclidean_distance = distance;
    aux.pos_i = i;
    aux.pos_j = j;

    Enfileira(euclidean_queue, aux);
    euclidean_sort(euclidean_queue);
}

void manhattan_print(Fila *f){
	Block *aux;

	aux = f -> first -> prox;
	
	while (aux != NULL) {
        cout << "\t\t@@\t   " << aux -> data.manhattan_distance;
        cout << "\t\t      " << aux -> data.pos_i;
        cout << "\t\t\t    " << aux -> data.pos_j << "\t\t@@" << endl;
        aux = aux -> prox;
    }
}

void euclidean_print(Fila *f) {
    Block *aux;

    aux = f -> first -> prox;

    while (aux != NULL) {
        cout << "\t\t\t   " << aux -> data.euclidean_distance;
        cout << "\t\t      " << aux -> data.pos_i;
        cout << "\t\t\t    " << aux -> data.pos_j << "\t\t" << endl;
        aux = aux -> prox;
    }
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

    cout << "\t\t\t    ~ This is the matrix read from the file ~" << endl << endl;

    for (i = 0; i < matrix_tam; i++) {
        cout << "\t\t\t";
        for (j = 0; j < matrix_tam; j++) {
            cout << matrix[i][j] << "\t";       
        }
        cout << endl;
    }

    Fila manhattan_queue, euclidean_queue; 
    Item aux;
    int cont = 0;
    FFVazia(&manhattan_queue);
    FFVazia(&euclidean_queue);
    aux.pos_i = 0;
    aux.pos_j = 0;
    cout << endl << endl;
    while (i != matrix_tam - 1 || j != matrix_tam - 1) {
        i = aux.pos_i;
        j = aux.pos_j;

        if (matrix[i + 1][j] == 'A' && (i < (matrix_tam - 1))){ 
            aux.pos_i = i + 1;
            aux.pos_j = j;
            matrix[i + 1][j] = 'v';
            // manhattan_heuristic_calc(&manhattan_queue, i + 1, j);
            euclidean_heuristic_calc(&euclidean_queue, i + 1, j);
        }

        if (matrix[i][j + 1] == 'A' && (j < (matrix_tam - 1))) { 
            aux.pos_i = i;
            aux.pos_j = j + 1;
            matrix[i][j + 1] = '>';
            // manhattan_heuristic_calc(&manhattan_queue, i, j + 1);
            euclidean_heuristic_calc(&euclidean_queue, i, j + 1);
        }

        if (queue_is_empty(&manhattan_queue) && matrix[i - 1][j] == 'A' && (i > 0)) {
            aux.pos_i = i - 1;
            aux.pos_j = j;
            matrix[i - 1][j] = '^';
            // manhattan_heuristic_calc(&manhattan_queue, i - 1, j);
            euclidean_heuristic_calc(&euclidean_queue, i - 1, j);
        }

        // manhattan_dequeue(&manhattan_queue, &aux);
        euclidean_dequeue(&euclidean_queue, &aux);
        if (i != matrix_tam-1 || j != matrix_tam-1) {
            cont++;
        }
        // cont++;
    }

    matrix[0][0] = 'S'; matrix[matrix_tam - 1][matrix_tam - 1] = 'F';

    cout << "\t\t\tAfter completing the process of roaming throughout " << endl;
    cout << "\t\tthe entire matrix by the BFS method, we could count " << cont << " iterations.";
    cout << endl << endl << "\t\t   ~ This is the path used to make it to the final position ~" << endl << endl;

    for (i = 0; i < matrix_tam; i++) {
        cout << "\t\t\t";
        for(j = 0; j < matrix_tam; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << "\t\t    'S' corresponds to the initial position, it stands for 'Start'." << endl;
    cout << "\t\t    'F' corresponds to the final position, it stands for 'Finish'." << endl;
    cout << "\t\t    All the arrows corresponds to the move made in the previous position." << endl;

    cout << endl << endl << "\t\t\t      After Manhattan Heuristic being applied" << endl;
    cout << "\t\t\t\t    here's the intel gathered" << endl << endl << endl;
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << "\t\t@@\t\t\t\t\t\t\t\t@@" << endl;
    cout << "\t\t@@      Distance        Poisition in I        Position in J\t@@" << endl << "\t\t@@\t\t\t\t\t\t\t\t@@" << endl;
    // manhattan_print(&manhattan_queue);
    cout << "\t\t@@\t\t\t\t\t\t\t\t@@" << endl;
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}