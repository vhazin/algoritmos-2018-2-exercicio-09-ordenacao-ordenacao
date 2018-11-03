#include <stdio.h>

void troca(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selectionSort(int lista[], int n){
    int i,j, minimo;

    for(i=0; i < n-1; i++){
    minimo = i;
    for (j=i+1; j < n; j++)
        if (lista[j] < lista[minimo])
            minimo = j;

    troca(&lista[minimo], &lista[i]);
    }
}

void imprimir(int lista[], int tamanho){
    int i;
    for (i=0; i < tamanho; i++)
        printf("%d ", lista[i]);
    printf("\n");
}

int main(){
    int lista[] = {70, 69, 87, 92, 102};
    int n = sizeof(lista)/sizeof(lista[0]);
    selectionSort(lista, n);
    imprimir(lista, n);
    return 0;
}
