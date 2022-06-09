#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

 

Lista *criaLista(void *novoObjeto)
{
    struct node *novoNode;

Lista *novaLista = (Lista *)malloc(sizeof (Lista));
    *novaLista= (struct node *)malloc(sizeof (struct node));
    
   novoNode = *novaLista;
   novoNode->objeto = novoObjeto;
   novoNode->proximo = NULL;
    return novaLista;
}
void testaUM(int um){
	printf("deu pau no um %d", um);
	
}

void esvaziaLista(Lista *lista)
{
    struct node *atual = *lista;
    struct node *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}

int adcionaLista(void *data, Lista *lista, int (*comp)(int a, int b), int chave) {  
    struct node *novoNodo;  
    struct node *atual;  
    struct node *anterior = NULL;  
//verifica se lista eh nula
	  if (lista == NULL || *lista == NULL) {  

		fprintf(stderr, "lista eh nula\n"); return 0; }  
//igyula a lista com atual
    atual = *lista;  
    //verifica se objeto da atual eh nula 
    if (atual->objeto == NULL) {  

        atual->objeto = data;  

        atual->chave=chave;  
//return 1 caso objeto seja null e n adciona
        return 1;  
    }  
//aloca memoria pro novo nodo
    novoNodo = (struct node *)malloc(sizeof (struct node));  
    novoNodo->objeto = data; 
    novoNodo->chave=chave; 
    

  
//vai coloca os objetos em ordem cresente ou decresente
    while (atual != NULL && atual->objeto != NULL && comp(chave,atual->chave ) > 0) {  
        anterior = atual;  
        atual = atual->proximo;  
    }  
    novoNodo->proximo = atual;  
//liga o nodo no proximo
    if (anterior == NULL)   
        *lista = novoNodo;  
    else   
        anterior->proximo = novoNodo;  
    return 1;  
} 
  
void listaAdcionaCabeca(Lista *lista, void *data) { 
    struct node *cabeca; 

    struct node *novoNode; 
    if (lista == NULL || *lista == NULL) { 

        fprintf(stderr, "lista eh nula\n"); 

    } 
    cabeca = *lista; 
    // Cabeca eh vazia

    if (cabeca->objeto == NULL) 
        cabeca->objeto= data; 

    // Cabeca nao esta vazia adciona na frente

    else { 
        novoNode = malloc(sizeof (struct node)); 
        novoNode->objeto = data; 
        novoNode->proximo = cabeca; 
        *lista = novoNode; 
    } 

} 



void listaPrint(Lista*list, void (*print)(void *))
{
    struct node *atual = *list;
    while (atual != NULL) {
        print(atual->objeto);
        printf(" ");
        atual = atual->proximo;
    }
    putchar('\n');
}

int ListaDelete(Lista *listaTotal,int valorProcurado){


Lista elementoAuxiliar, elementoAnterior;
int encontrou=0;
 elementoAuxiliar = *listaTotal;
 elementoAnterior = *listaTotal;
/* Percorre a lista ateh encontrar o elemento (nodo) procurado */
while (encontrou == 0 && elementoAuxiliar != NULL){
 if (elementoAuxiliar->chave == valorProcurado){
 /* Encontrou o elemento (nodo) procurado */
 encontrou = 1;
 }
 else{
 /*nao encontrou o elemento(nodo). Avança ao proximo */
 elementoAnterior = elementoAuxiliar;
 elementoAuxiliar= elementoAuxiliar->proximo;
 }
 }
if (encontrou == 1){
 /* Verifica se o elemento (nodo) encontrado eh o
 primeiro da lista */
 if (elementoAnterior == elementoAuxiliar
 && elementoAuxiliar == *listaTotal){
 *listaTotal = elementoAuxiliar->proximo;
 }
/*Caso o elemento(nodo) encontrado nao seja o primeiro da lista*/
 else{
 elementoAnterior->proximo=elementoAuxiliar->proximo;
 }
 /* Libera a memoria alocada */
 free(elementoAuxiliar);
 elementoAuxiliar = NULL;
 return 1;
 }
/*Retorna zero indicando que o elemento(no) nao foi encontrado*/
return 0;
}



void listaBuscaChave(Lista*list, void (*print)(void *), int chave)
{
    struct node *atual = *list;
    while (atual != NULL) {
    	if(atual->chave==chave)
        print(atual->objeto);
        printf(" ");
        atual = atual->proximo;
    }
    putchar('\n');
}
int vazia(Lista *lista){
if(lista==NULL){
		return 0;
	}
	return 1;
	
}



