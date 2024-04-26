#include<stdio.h>

int fibonacciSearch(int arr[], int n, int x, int *iteraciones) {
    int indice = -1;
    int fibM2 = 0; // (m-2)'th Fibonacci
    int fibM1 = 1; // (m-1)'th Fibonacci
    int fib = fibM1 + fibM2; // m'th Fibonacci

    // Encuentra el número de Fibonacci más grande menor o igual que n
    while (fib < n) {
        fibM2 = fibM1;
        fibM1 = fib;
        fib = fibM1 + fibM2;
    }

    // Inicializar el índice del rango de búsqueda
    int offset = -1;

    // Realizar la búsqueda comparando el elemento buscado con el elemento en la posición fibM2
    while (fib > 1) {
        (*iteraciones)++;
        // Calcular el índice de la posición a comparar
        int i = offset + fibM2 < n - 1 ? offset + fibM2 : n - 1;

        // Si el elemento buscado es menor, reduce el rango de búsqueda a la mitad izquierda
        if (arr[i] > x) {
            fib = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fib - fibM1;
        }
        // Si el elemento buscado es mayor, reduce el rango de búsqueda a la mitad derecha
        else if (arr[i] < x) {
            fib = fibM1;
            fibM1 = fibM2;
            fibM2 = fib - fibM1;
            offset = i;
        }
        // Si el elemento buscado es igual, devuelve el índice de la posición
        else {
            indice = i;
            break; // No necesitas seguir buscando una vez que hayas encontrado el elemento
        }
    }

    // Si el elemento no se encuentra en el arreglo
    printf("el valor se encuentra en la posicion: %d \n",indice);
    
    return indice;
}