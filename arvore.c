// Priscila Fabrete Candido
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int menu(){
    int opcao;
    system("CLS");
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir Valor.\n");
    printf("2 - Mostrar Arvore em Pre Ordem.\n");
    printf("3 - Mostrar Arvore em In-ordem ou Ordem Simetrica\n");
    printf("4 - Mostrar Arvore em Pos Ordem\n");
    printf("5 - Buscar Valor .\n");
    printf("6 - Remover Valor.\n");
    printf("\tInforme OPCAO desejada: ");

    scanf(" %d", &opcao);

    if ((opcao > 5) || (opcao < 0))
    {
        printf("\n\n\n");
        printf("\t+-------------------------------------------------+");
        printf("\t|   ERRO:                                         |");
        printf("\t|                                                 |");
        printf("\t|   OPCAO INVALIDA!!!                             |");
        printf("\t|                                                 |");
        printf("\t|   Tente outra vez.                              |");
        printf("\t+-------------------------------------------------+\n\n");
        system("PAUSE");
    }
    return opcao;
}

int main(){
	TNo * raiz;
	raiz = inicializaArvore();

	int opcao = 10;
	long long int valor;

	while (opcao != 0) {
		opcao = menu();
		switch (opcao)
		{
		case 1:
			printf("\tInforme um valor: ");
			scanf("%lld", &valor);
			insereArvore(&raiz, valor);
			break;
		case 2:
			mostrarArvorePreOrdem(raiz);
			system("PAUSE");
			break;
		case 3:
			mostrarArvoreEmOrdem(raiz);
			system("PAUSE");
			break;
		case 4:
			mostrarArvorePosOrdem(raiz);
			system("PAUSE");
			break;
		case 5:
			printf("\n\n\t=====| Buscar ALUNO |=====\n\n");
			printf("\tInforme NOME a ser PROCURADO: ");
			scanf("%lld", &valor);
			buscaValor(raiz, valor);
			break;
		case 6:
			printf("\tInforme um valor: ");
			scanf("%lld", &valor);
			removeArvore(raiz, valor);
			system("PAUSE");
			break;
		
		default:
			break;
		}
	}
    
    return 0;
}
