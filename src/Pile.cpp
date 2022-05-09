#include "Pile.hpp"

void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha *p, Item_Stack d){
	if (p->top >= MAXTAM_STACK){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Item_Stack *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
		*d = p->vet[p->top];
	}
}

void PRemove(Pilha *p, Item_Stack d){
	Pilha aux;
	Item_Stack rem;

	FPVazia(&aux);

	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		while(p->top > p->base){
			POP(p, &rem);
			if(rem.val != d.val)
				PUSH(&aux, rem);
		}

		while(aux.top > aux.base){
			POP(&aux, &rem);
			PUSH(p, rem);
		}
	}
}

void PImprime(Pilha *p){
	for(int i=p->top-1; i>=p->base; i--)
		printf("%d\n", p->vet[i].val);
	printf("\n");
}