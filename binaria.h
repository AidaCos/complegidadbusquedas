#include <stdio.h>

// Función de búsqueda binaria
int binarySearch(int arr[], int left, int right, int x, int *iteracion) {
    while (left <= right) {
        (*iteracion)++;
        int mid = left + (right - left) / 2;

        // Si el elemento está en el medio
        if (arr[mid] == x)
            return mid;

        // Si el elemento es mayor, buscar en la mitad izquierda
        if (arr[mid] < x)
            left = mid + 1;
        // Si el elemento es menor, buscar en la mitad derecha
        else
            right = mid - 1;
    }

    // Si el elemento no se encuentra en el arreglo
    return -1;
}

void binaria(int arr[], int n, int x, int *iteracion) {


    int result = binarySearch(arr, 0, n - 1, x, iteracion);
    printf("el valor se encuentra en la posicion: %d \n",result);
}


void Mainexpo(int arr[], int n, int x, int *iteracion){
    int imprimir=0;

        imprimir = exponentialSearch(arr, n, x, iteracion);

        printf("el valor se encuentra en la posicion: %d \n",imprimir);
}



int exponentialSearch(int arr[], int n, int x, int *iteracion) {
    // Si el elemento está presente en la primera posición
    if (arr[0] == x)
        return 0;

    // Encontrar el rango para la búsqueda binaria
    int i = 1;
    while (i < n && arr[i] <= x){
        (*iteracion)++;
        i *= 2;
    }
    // Realizar la búsqueda binaria en el rango encontrado
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, x, iteracion);
}
