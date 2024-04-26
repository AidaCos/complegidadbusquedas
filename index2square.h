//busqueda indexada
#include<stdio.h>
#include<math.h>
#include<time.h>

typedef struct tabla{

    int index;
    int contenido;

}seccion;

int square(int n);
void incializarSeccion (seccion tabla[], int arreglo[], int fragmentos, int n, int *tamfrag);

int square(int n){
    //partiendo de n obtiene el cuadrado y lo trunca a techo.
    double raiz = sqrt(n);
    int retorno = (int)raiz + 1;
    return retorno;
}


void incializarSeccion (seccion tabla[], int arreglo[], int fragmentos, int n, int *tamfrag){//rellena el arreglo de indices
    int incremento;
    int k=0;
    double comparativo;
    comparativo= sqrt(n);

    if(comparativo == fragmentos) //si es raiz cerrada
        incremento = fragmentos;
    else
        incremento = fragmentos-1;//si es raiz irracional


        (*tamfrag) = incremento;

    for(int i=0;i<n;i=i+incremento){
        tabla[k].index     =        i;
        tabla[k].contenido =        arreglo[i];
        k++;
    }

}

int IndexSearch(seccion tabla[], int fragmento, int x, int *iteracion) {
    int retorno = 0;
    for (int i = fragmento - 1; i >= 0; i--) {
        (*iteracion)++;
        if (tabla[i].contenido <= x) {
            retorno = tabla[i].index;
            return retorno;
        }
    }
    return retorno;
}



int linealIsearch (int arreglo[], int n, int seccionDiv, int x, int *iteracion, int tamfrag){//busqueda lineal recortada

    for (int i=seccionDiv; i<n; i++){
        (*iteracion)++;
        if(arreglo[i]==x)
            return i;
    }

    return -1;
}


int PropuestaIndex (int arreglo, int n,int x, int *iteraciones){
    int tamanio_fragmento;
    int ptamanio_frag = &tamanio_fragmento;


    int fragmentaciones = square(n);
    seccion tabla[fragmentaciones];
    int division;
    int indice;

    incializarSeccion (tabla,arreglo,fragmentaciones,n,ptamanio_frag);

    division = IndexSearch (tabla,fragmentaciones,x,iteraciones);
    indice = linealIsearch (arreglo,n,division,x,iteraciones, tamanio_fragmento);
    //busca el valor y devuelve por estructura.

    printf("el valor se encuentra en la posicion: %d \n",indice);
    return 0;
}
