#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <fstream>
#include <cmath>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
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
void bfs_queue(Fila *f, Item d);
void bfs_dequeue(Fila *f, Item *aux);
void FImprime(Fila *f);
void swap(Block *a, Block *b);
bool queue_is_empty(Fila *f);

int return_matrix_size();
void get_matrix_values(char *vet);
bool all_queues_empty(Fila *bfs_queue, Fila *manhattan_queue, Fila *euclidean_queue);

void solve(int choice);

void manhattan_heuristic_calc(Fila *manhattan_queue, int i, int j);
void manhattan_dequeue(Fila *manhattan_queue, Item *aux);
void manhattan_sort(Fila *manhattan_queue);

void euclidean_heuristic_calc(Fila *euclidean_queue, int i, int j);
void euclidean_dequeue(Fila *euclidean_queue, Item *aux);
void euclidean_sort(Fila *euclidean_queue);


#endif