#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo{
   	long long int valor;
    struct tipoNo *esq, *dir, *pai;
}TNo;

TNo *raiz;

TNo *inicializaArvore(){
    return NULL;
}
//funcao para instanciar o TAluno
TNo *criaNo(long long int valor){
	
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

//funcao recursiva
TNo *insereArvore(TNo **nodo, long long int valorNovo){
	//se ainda nao há raiz, entao o novo elemento sera o proprio no raiz
    if((*nodo) == NULL){
        (*nodo) = criaNo(valorNovo);
    }
    //se caso tiver um nó raiz, entao compara o novo elemento com o nó raiz
    //se este elemento inserido for menor que no raiz, ele e inserido na sub-arvore da esquerda
	else if(valorNovo < (*nodo)->valor ){
        (*nodo)->esq = insereArvore(&(*nodo)->esq, valorNovo);
    }//se nao, ele e inserido na bub-arvore da direita
	else{
        (*nodo)->dir = insereArvore(&(*nodo)->dir, valorNovo);
    }
    return (*nodo);
}

void busca(TNo *nodo, long long int valor){
	//se a arvore estiver vazia
    if (nodo == NULL){
        printf("\n<<VALOR INEXISTENTE NA ARVORE>>\n\n\n");
    //se nó estiver apotando para o valor buscado
    }else if (nodo->valor == valor){
        printf("\n<<ENCONTRADO>>\n");
		printf("Valor: %lld \n\n\n", nodo->valor );
    //se nao, se o valor for menor que valor do no raiz, chama a fucao de novo, porem buscando pelo nodo da esquerda
    } else if (valor < nodo->valor){
        printf("\nPROCURADO: %d\tVISITADO: %d", valor, nodo->valor);
        printf("\n\n... Descendo pela Sub-Arvore ESQUERDA.");
        busca (nodo->esq, valor);
	//se nao, chama a funao de novo mas bucando pela direito do no
    } else {
        printf("\nPROCURADO: %d\t VISITADO: %d");
        printf("\n\n... Descendo pela Sub-Arvore DIREITA.");
        busca (nodo->dir, valor);
    }
}

void buscaValor (TNo *nodo, long long int buscado){

    if(nodo== NULL){
        printf("\n\n\tNenhum registro encontrado.\n\n");
    }else{
        printf("\n\n\tIniciando BUSCA pelo valor %lld", buscado);
        printf("\n\n\tVisitando a RAIZ (%d). \n", nodo->valor);
        busca (nodo, buscado);
    }

    system("PAUSE");
}

TNo *removeArvore(TNo *nodo, long long int valorNovo) {
	printf("teste: %s\n", nodo);
	system("PAUSE");
	
	if(nodo == NULL) {
		// interrompe
		return NULL;
	} else if (  nodo->valor != valorNovo) {
		// desce pela esquerda
		nodo->esq = removeArvore(nodo->esq, valorNovo);
	} else if ( nodo->valor != valorNovo) {
		// desce pela direita
		nodo->dir = removeArvore(nodo->dir, valorNovo);
	} else {
		// Encontrou No a ser removido
		if(nodo->dir == NULL && nodo->esq == NULL) {
			// No a ser removido nao tem filhos.
			free(nodo);
			nodo = NULL;
		} else if (nodo->esq == NULL) {
			// No a ser removido tem apenas filho a direita.
			TNo *temporario = nodo;
			nodo = nodo->dir;
			free(temporario);
		} else if (nodo->dir == NULL) {
			// No a ser removido tem apenas filho a esquerda.
			TNo *temporario = nodo;
			nodo = nodo->esq;
			free(temporario);
		} else {
			// NÃ³ tem dois filhos
			TNo *prov = nodo->esq;
			while (prov->dir != NULL) {
				prov = prov->dir;
			} // while
			// Trocando os dados entre os nodos
            nodo->valor =  prov->valor;
            prov->valor = valorNovo;
			nodo->esq = removeArvore(nodo->esq, valorNovo);
		}
	}
	
	return nodo;
}


void mostrarArvoreEmOrdem(TNo *raiz){
  if(raiz==NULL)
    return;
  //percorre a subarvore esquerda em ordem
  mostrarArvoreEmOrdem(raiz->esq);
  //printa a raiz
  printf(" %lld \n", raiz->valor);
  //percorre a sua arvore direita em ordem
  mostrarArvoreEmOrdem(raiz->dir);
}

void mostrarArvorePreOrdem(TNo *raiz){
  
    if(raiz != NULL){
    	//visita a raiz
        printf("%lld \n", raiz->valor);
        //percorre a sua subarvore a esquerda em pre-ordem
        mostrarArvorePreOrdem(raiz->esq);
         //percorre a sua subarvore a direita em pre-ordem
        mostrarArvorePreOrdem(raiz->dir);
    }
}
void mostrarArvorePosOrdem(TNo *raiz){
  if(raiz != NULL){
  		//percorre a sua subarvore esquerda em pos-ordem
        mostrarArvorePosOrdem(raiz->esq);
        //percorre a sua subarvore direita em pos-ordem
        mostrarArvorePosOrdem(raiz->dir);
        //visita a raiz
        printf("%lld \n", raiz->valor);
    }
}
