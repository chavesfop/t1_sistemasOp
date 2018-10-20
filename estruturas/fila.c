#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MALLOC(x) ((x *) malloc (sizeof(x)))

//adicionar o lock na lista.
//
//declaração da estrutura
struct elementoFila{
   int prioridade, contador;
   struct elementoFila *proximo;
};

typedef struct elementoFila tipo_elementoFila;
tipo_elementoFila *novo;
pthread_mutex_t trancaFila = PTHREAD_MUTEX_INITIALIZER;

//declaração das funções
tipo_elementoFila *criarFila(tipo_elementoFila *lista);
tipo_elementoFila *enfileirar(tipo_elementoFila *lista, int prioridade, int contador);
tipo_elementoFila *proximo(tipo_elementoFila *lista);
int exibir(tipo_elementoFila *lista);
int qtdElementos(tipo_elementoFila *lista);

tipo_elementoFila *criarFila(tipo_elementoFila *lista){
	lista = MALLOC(tipo_elementoFila);
	return lista;
};

tipo_elementoFila *proximo(tipo_elementoFila *lista){
	pthread_mutex_lock(&trancaFila);
	tipo_elementoFila *p;
	p=lista;
	if (lista != NULL){
		lista = lista->proximo;
		free(p);
		pthread_mutex_unlock(&trancaFila);
		return lista;
	}
	pthread_mutex_unlock(&trancaFila);
	return NULL;
};

tipo_elementoFila *enfileirar(tipo_elementoFila *lista, int prioridade, int contador){
	pthread_mutex_lock(&trancaFila);
	tipo_elementoFila *aux;
	aux = lista;
	novo = MALLOC(tipo_elementoFila);
	while (aux->proximo!=NULL)
		aux=aux->proximo;
	novo->proximo = NULL;
	novo->prioridade = prioridade;
	novo->contador = contador;
	aux->proximo=novo;
	pthread_mutex_unlock(&trancaFila);
	return lista;
};

int exibir(tipo_elementoFila *lista){
	tipo_elementoFila *p;
	int k,i = 0;
	if (lista==NULL){
		printf("Lista vazia\n\n");
		return 0;
	}
	p = lista;
	do {
		printf("\n%iP%i",p->prioridade+1, p->contador);
		p = p->proximo;
		i++;
	}while(p!=NULL);
	printf("\n===================\nTem %d pessoas na fila\n\n", i);
	return 0;
};

int qtdElementos(tipo_elementoFila *lista){
	tipo_elementoFila *p;
	p=lista;
	int i=0;
	while (p!=NULL){
		p=p->proximo;
		i++;
	}
	return i;
};
