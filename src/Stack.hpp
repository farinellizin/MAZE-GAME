#ifndef STACK_HPP 
#define STACK_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<fstream>
#include<string>
#include<iostream>

typedef struct SItem SItem;
typedef struct SBlock SBlock;
typedef struct Pilha Pilha;

struct SItem{
	int val;
};

struct SBlock{
	SItem data;
	SBlock *prox;
};

struct Pilha{
	SBlock *base;
	SBlock *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, SItem d);
void Pop(Pilha *p, SItem *d);
int return_matrix_size_stack();
void get_matrix_values_stack(char *vet);
void runMatrix();
void PImprime(Pilha *p);

#endif