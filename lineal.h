#include<stdio.h>


void linealsearch (int arreglo[], int n, int x, int *iteracion){
    int imprimir=-1,flag=0;
    for (int i=0;i < n ;i++){

        (*iteracion)++;
        if(arreglo[i]==x){
            imprimir=i;
            flag=1;
        }
        if(flag==1){
            i=n;
        }
    }

    printf("el valor se encuentra en la posicion: %d \n",imprimir);

}