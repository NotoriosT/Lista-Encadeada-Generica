#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

 typedef struct  {
    int matricula;
    char nome[40];
    float n1;
}aluno;

void imprime_aluno(void *info){
   aluno *al = info;
    printf("Matricula: %d\n",al->matricula);
    printf("Nome: %s\n",al->nome);
    printf("Notas: %f\n",al->n1);
    printf("-------------------------------\n");
}


int numcmp(int a, int b);;

int main()
{
	int chave;
	int i=0;
	 aluno *alunos;
	Lista *my_list = criaLista(NULL);
	
	int escolha;
	while (escolha!=5)
{

printf("\n\n ----------------------- ");

printf("\n 1 - Inserir aluno ");
printf("\n 2 - Buscar aluno (por matrícula)");
printf("\n 3 - Imprimir alunos");
printf("\n 4 -Retirar aluno (por matricula) ");
printf("\n 5 - Verifica se lista esta vazia ");
printf("\n\n Escolha uma opcao: ");
scanf("%d",&escolha);


// estrutura switch
switch (escolha) {

case 1:
{printf("\n\n Opcao escolhida: 1 ");
	alunos=(aluno*)malloc(sizeof(aluno));
printf("Nome do aluno ......: ");
  fflush(stdin);
  
    fgets(alunos->nome, 40, stdin);
  
  printf("Matricula ......: ");
  
  scanf("%d", &alunos->matricula);
  
  printf("Informe a 1a. nota ..: ");
  scanf("%f", &alunos->n1);
  printf("%s", alunos->nome);

adcionaLista(alunos,my_list, numcmp, alunos->matricula);




break;
}

case 2:
{
 chave=0;
printf("\n\n Opcao escolhida: 2 \n");
printf("Digite a matricula que deseja busca:");
scanf("%d",&chave);

    listaBuscaChave(my_list,imprime_aluno,chave);
break;
}

case 3:
{

printf("\n\n Opcao escolhida: 3 \n");

 listaPrint(my_list, imprime_aluno);
break;
}

case 4:
{

printf("\n\n Opcao escolhida: 4\n ");
printf("Digite a matricula que deseja busca:");
scanf("%d",&chave);
 ListaDelete(my_list,chave);

break;
}
case 5:{
if(	vazia(my_list)==0){
	printf("esta vazia");
}else{ printf("n esta vazia");
}
	break;
}

// opção padrão
default:
{


// se for escolhida a opção 5, ele pula o while utilizando continue para isso 
if( escolha==6)
{
	  esvaziaLista(my_list);
continue;
}
// caso o usuário digite um numero acima de 5, ele irá informar que nao existe essa opção
printf("\n\n Nenhuma opcao foi escolhida ");
break;
}

}

}

if( escolha==6)
printf("\n\n O Programa foi fechado");

getch(); 



  

    return 0;
}
//oredem cresente ou decrresente
int numcmp(int a, int b)
{
     if (a <b)
        return - 1;
    if (a > b)
        return 1;

    return 0;
}


