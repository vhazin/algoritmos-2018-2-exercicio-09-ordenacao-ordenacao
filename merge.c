#include <stdio.h>
#include <stdlib.h>

void merge(int lista[], int esq, int m, int dir){
    int i, j, selecionado;
    int num1 = m - esq + 1;
    int num2 = dir - m;

    int tempesq[num1], tempdir[num2];

    for(i=0; i<num1; i++)
        tempesq[i] = lista[esq + i];
    for(j=0; j<num2; j++)
        tempdir[j] = lista[m + 1 + j];

    i, j = 0;
    selecionado= esq;

    while(i< num1 && j< num2){
        if (tempesq[i] <= tempdir[j]){
            lista[selecionado] = tempesq[i];
            i++;
        }
        else{
        lista[selecionado] = tempdir[j];
        j++;
        }
        selecionado++;
    }
    while(i<num1){
        lista[selecionado] = tempesq[i];
        i++;
        selecionado++;
    }
    while(j<num2){
        lista[selecionado] = tempdir[j];
        j++;
        selecionado++;
    }
}

void mergeSort(int lista[], int esq, int dir){
    if(esq<dir){
        int m = esq+(dir-1)/2;

        mergeSort(lista, esq, m);
        mergeSort(lista, m+1, dir);

        merge(lista, esq, m, dir);
    }
}

void imprimir(int lista[], int n){
    for(int i=0; i<=n; i++)
        printf("%d ", lista[i]);
}

int main(){
    int lista[] = {45, 77, 90, 101, 14, 2};
    int n = sizeof(lista)/sizeof(lista[0]);

    imprimir(lista, n);

    mergeSort(lista, 0, n-1);

    imprimir(lista, n);

    return 0;
}
