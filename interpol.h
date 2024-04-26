#include<stdio.h>

int busquedaInterpolacion(int arr[], int n, int x, int *iteracion) {
    int lo = 0, hi = (n - 1);
    int indice=-1;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        (*iteracion)++;
        if (lo == hi) {
            if (arr[lo] == x) indice=-1;
        }

        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x) indice = pos;

        if (arr[pos] < x) lo = pos + 1;
        else hi = pos - 1;
    }
     printf("el valor se encuentra en la posicion: %d \n",indice);
}