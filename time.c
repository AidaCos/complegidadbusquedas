
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "index2square.h"
#include "lineal.h"
#include "binaria.h"
#include "interpol.h"
#include "fibo.h"


double medir_tiempo(void (*funcion)(int[], int, int, int *), int arr[], int n, int *iteracion,int x) {
    clock_t inicio, fin;
    double tiempo_ejecucion;
    inicio = clock();
    funcion(arr,n,x,iteracion);
    fin = clock();
    tiempo_ejecucion = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    return tiempo_ejecucion;
}

int main() {

    int n=10;
    int x=0;

    int iteraciones=0;
    int *iterar;

    double tiempo;
    iterar = &iteraciones;


    printf("n = %d, valor buscado = %d\n\n",n,x);

    srand(time(NULL));
        int arr[n];

        for (int i = 0; i < n ; i++) {
            arr[i] = rand() % (100);
        }
     bubbleSort(arr, n);



        printf("algoritmo propuesto, busqueda indexada mejorada \n");
                    tiempo = medir_tiempo(PropuestaIndex, arr, n, iterar,x);
        printf("Tiempo de ejecucion: %.6f segundos. iteraciones: %d \n\n", tiempo,iteraciones);
        iteraciones=0;


        printf("algoritmo busqueda lineal \n");
                    tiempo = medir_tiempo(linealsearch, arr, n, iterar,x);
        printf("Tiempo de ejecucion: %.6f segundos. iteraciones: %d \n\n", tiempo,iteraciones);
        iteraciones=0;

        printf("algoritmo busqueda binaria \n");
                tiempo = medir_tiempo(binaria, arr, n, iterar,x);
        printf("Tiempo de ejecucion: %.6f segundos. iteraciones: %d \n\n", tiempo,iteraciones);
        iteraciones=0;

        printf("algoritmo busqueda por interpolacion \n");
                    tiempo = medir_tiempo(busquedaInterpolacion, arr, n, iterar,x);
        printf("Tiempo de ejecucion: %.6f segundos. iteraciones: %d \n\n", tiempo,iteraciones);
        iteraciones=0;

        printf("algoritmo busqueda por fibonacci \n");
                tiempo = medir_tiempo(fibonacciSearch, arr, n, iterar,x);
        printf("Tiempo de ejecucion: %.6f segundos. iteraciones: %d \n\n", tiempo,iteraciones);
        iteraciones=0;

        printf("algoritmo busqueda exponencial \n");
                tiempo = medir_tiempo(  Mainexpo , arr, n, iterar,x);
        printf("Tiempo de ejecucion: %.6f segundos. iteraciones: %d \n\n", tiempo,iteraciones);
        iteraciones=0;


        printf("\n");
    return 0;
}


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

