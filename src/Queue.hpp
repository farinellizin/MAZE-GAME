#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <fstream>
#include <cmath>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	//int val;

	// solving using Manhattan Euristic

	int manhattan_distance;
	int pos_i;
	int pos_j;
	float euclidean_distance;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void FImprime(Fila *f);
void swap(Block *a, Block *b);
bool queue_is_empty(Fila *f);

int return_matrix_size();
void get_matrix_values(char *vet);


void solve();

void manhattan_heuristic_calc(Fila *manhattan_queue, int i, int j);
void manhattan_print(Fila *manhattan_queue);
void manhattan_dequeue(Fila *manhattan_queue, Item *aux);
void manhattan_sort(Fila *manhattan_queue);

void euclidean_heuristic_calc(Fila *euclidean_queue, int i, int j);
void euclidean_print(Fila *euclidean_queue);
void euclidean_dequeue(Fila *euclidean_queue, Item *aux);
void euclidean_sort(Fila *euclidean_queue);


#endif