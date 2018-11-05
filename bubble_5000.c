#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubble(int lista[], int n){
    int i, j;
    for (i=0; i<n-1; i++){
        for (j=0; j< n-i-1; j++){
            if(lista[j] > lista[j+1])
                trocar(&lista[j], &lista[j+1]);
        }
    }
}

void imprimir(int lista[], int n){
    for(int i=0; i< n; i++)
        printf("%d ", lista[i]);
}

int main(){
    clock_t begin = clock();
    int lista[5000], i;
    srand(0);

    for(i=0; i<5000; i++){
        lista[i] = rand();
    }

    int n = sizeof(lista)/sizeof(lista[0]);

    bubble(lista, n);
    imprimir(lista, n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Tempo de execucao: %f", time_spent);
    return 0;
}
