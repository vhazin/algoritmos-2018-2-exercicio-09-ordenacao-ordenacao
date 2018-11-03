#include <stdio.h>

void trocar(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void heapify(int lista[], int n, int i){
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*1 + 2;

    if (esq < n && lista[esq] > lista[maior])
        maior = esq;
    if(dir < n && lista[dir] > lista[maior])
        maior = dir;
    if(maior!=i){
        trocar(&lista[i], &lista[maior]);
        heapify(lista, n, maior);
    }
}

void heapSort(int lista[], int n){
    for(int i = (n/2) - 1; i>=0; i--)
        heapify(lista, n, i);
    for(int i= n-1; i>=0; i--){
        trocar(&lista[0], &lista[i]);
        heapify(lista, i, 0);
    }
}

void imprimir(int lista[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", lista[i]);
}

int main(){
    int lista[] = {98, 56, 32, 27, 42};
    int n = sizeof(lista)/sizeof(lista[0]);

    heapSort(lista, n);
    imprimir(lista, n);

    return 0;
}
