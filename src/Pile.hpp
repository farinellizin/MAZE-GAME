#ifndef PILE_HPP
#define PILE_HPP
#include <iostream>

#define MAXTAM_STACK 10

typedef struct Item_Stack{
	int val;
}Item_Stack;

typedef struct Pilha{
	Item_Stack vet[MAXTAM_STACK];
	int top;
	int base;
}Pilha;

void FPVazia(Pilha *p);
void PUSH(Pilha *p, Item_Stack d);
void POP(Pilha *p, Item_Stack *d);
void PRemove(Pilha *p, Item_Stack d);
void PImprime(Pilha *p);

#endif