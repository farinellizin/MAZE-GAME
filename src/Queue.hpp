#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

#define MAXTAM_QUEUE 4

typedef struct Item{
	int val;
}Item;

typedef struct Fila{
	Item vet[MAXTAM_QUEUE];
	int first;
	int last;
}Fila;

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void FRemove(Fila *f, Item d);
void FImprime(Fila *f);

#endif