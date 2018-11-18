#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int particionar(int lista[], int esq, int dir){
    int pivo = rand() % sizeof(lista);
    int i = (esq-1);

    for (int j = esq; j <= dir-1; j++){
        if (lista[j] <= pivo){
            i++;
            trocar(&lista[i], &lista[j]);
        }
    }
    trocar(&lista[i+1], &lista[dir]);
    return (i+1);
}

void quickSort(int lista[], int esq, int dir){
    if (esq < dir){
        int divisao = particionar(lista, esq, dir);
        quickSort(lista, esq, divisao-1);
        quickSort(lista, divisao+1, dir);
    }
}

void imprimir(int lista[], int size){
    for(int i=0; i<size; i++)
        printf("%d ", lista[i]);
}

int main(){
    clock_t begin = clock();
    int lista[1000], i;
    srand(0);
    for(i=0; i<1000; i++)
        lista[i] = rand();

    int n = sizeof(lista)/sizeof(lista[0]);
    quickSort(lista, 0, n-1);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Tempo de execucao: %f", time_spent);

    return 0;
}
