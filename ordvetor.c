#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD *VETORD_create(int n, COMP *compara){ //criar um vetorord
    VETORORD *vetorord = malloc(sizeof(VETORORD)); //aloca o tamanho do ponteiro na memoria
    vetorord->comparador = compara; //a valor comparador recebe a funcao de compara
    vetorord->N = n; // recebe o tamanho do vetor
    vetorord->P = 0; // o valor P recebe ovalor 0
    vetorord->elems = malloc(n * sizeof(void *)); //aloca memoria para os elementos
    for(int i=0; i<n; i++) vetorord->elems[i] = NULL; //atribui o valor null para os vetores do elems
    
    return vetorord; // retorna um ponteiro para uma estrutura VETORORD
}

void VETORD_add(VETORORD *vetor, void *newelem){ //adicionar no vetorord
    if(vetor->P < vetor->N){ //se o valor p for menor q N ele faz o if
        if(vetor->P==0) vetor->elems[0] = newelem; //se P for 0, ele adiciona na primeira casa
        else if(vetor->comparador(newelem, vetor->elems[vetor->P - 1])==-1 ||
                vetor->comparador(newelem, vetor->elems[vetor->P - 1]) == 0) vetor->elems[vetor->P] = newelem; //verifica se o ultimo elemento é maior ou igual para adicionr
        else{//se newelem for menor
            for(int i = vetor->P - 1; i > -1; i--){//vai repetir até entcontrar
                if(vetor->comparador(newelem, vetor->elems[i]) == 1){//se o elemnto for menor que newelem
                    vetor->elems[i + 1] = vetor->elems[i];//ele anda o elems uma casa
                    vetor->elems[i] = newelem;//e o elemento é adicionado no lugar
                }else break;//quebra
            }
        }
        vetor->P++; //valor p do vetorord adiciona mais um
    }
}

void *VETORD_remove(VETORORD *vetor){
    void *aux = vetor->elems[0];//um auxiliar pra entcontrar o endereço
    for(int i=0; i<vetor->P; i++) vetor->elems[i] = vetor->elems[i + 1]; //Remove o menor elemento do vetor
    vetor->P--;//valor p do vetorord remove um
    
    return aux; //retorna um ponteiro para o elemento que foi removido do vetor
}