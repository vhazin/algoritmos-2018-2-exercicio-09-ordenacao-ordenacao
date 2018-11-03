#include <stdio.h>
#include <math.h>

void insertion(int lista[], int n){
    int i, j, selecionado;
    for(i=1; i< n; i++){
        selecionado = lista[i];
        j = i-1;

        while(j>=0 && lista[j] > selecionado){
            lista[j+1] = lista[j];
            j = j-1;
        }lista[j+1] = selecionado;
    }
}

void imprimir(int lista[], int n){
    for (int i=0; i < n; i++)
       printf("%d ", lista[i]);
    printf("\n");
}

int main(){
    int lista[] = {0, 4, 6, 10, 26};
    int n = sizeof(lista)/sizeof(lista[0]);

    insertion(lista, n);
    imprimir(lista, n);

    return 0;
}
