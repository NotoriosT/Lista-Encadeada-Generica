//Arquivo ListaDinEncad.h

/* llist.h
 * Generic Linked List
 */
/* llist.h
 * Generic Linked List
 */

struct node {
	int chave;
    void *objeto;
    struct node *proximo;
};

typedef struct node * Lista;

//cria a lista
Lista *criaLista(void *data);

//esvazia lista
void esvaziaLista(Lista *list);

//adciona chaves aleatorias colocando em ordem,(compare) pode adciona em ordem cresente ou decresente
int adcionaLista(void *data, Lista *lista, int (*compare)(int a, int b), int chave);

//adiciona em ordem de cima para baixo
void listaAdcionaCabeca(Lista *list, void *data);

/* llist_pop: remove and return head of linked list */


//printa a lista
void listaPrint(Lista *list, void (*print)(void *data));

//deleta apartir de uma chave
int listaDelete(Lista *listaTotal,int chave);

void listaBuscaChave(Lista*list, void (*print)(void *), int chave);

int vazia(Lista *lista);
