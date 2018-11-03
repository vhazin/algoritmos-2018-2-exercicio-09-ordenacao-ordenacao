#include <stdio.h>

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
    for(int i=0; i< n; i++){
        printf("%d ", lista[i]);
    }
}

int main(){
    int lista[] = {9, 15, 98, 76, 68};
    int n = sizeof(lista)/sizeof(lista[0]);

    bubble(lista, n);
    imprimir(lista, n);

    return 0;
}
