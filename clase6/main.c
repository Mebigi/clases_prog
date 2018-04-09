#include <stdio.h>
#include <stdlib.h>

#define TAM 5

float calcularPromedio(int, int);

void mostrarVector(int [], int); // paso el vector por valor no por referencia (es una copia del dato) y
//tamaño del vector// cuando paso algo por referncia estoy pasando la direcion de memoria y no la copia)

int main()
{
    int vector[TAM] = {5,6,-3,9,4}; // {0} //


    int i; //flecha negra
    int j; //flecha roja
    int aux;
    int cantI=0;
    int cantJ=0;

    for(i=0; i<TAM-1; i++)//negra tiene cantidad de elementos menos 1 para que no desborde.
    {
        cantI++;
        for(j=i+1;j<TAM;j++)//j=i+1 para que quede desfasado y llega al final del tamaño
        {
            cantJ++;
            if(vector[i]>vector[j]) // depende si ordeno de menor a mayor pongo mayor
            {
                aux = vector[i];
                vector[i]=vector[j];
                vector[j]= aux;
            }
        }
    }


    mostrarVector(vector, TAM);
    printf("Cantidad negro %d y cantidad rojo %d", cantI, cantJ);


    return 0;
}

float calcularPromedio(int suma, int cantidad)
{
    float promedio;

    promedio = (float)suma/cantidad;


    return promedio;
}

void mostrarVector(int vector[], int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(vector[i]!=0)
            {
                    printf("%d\n", vector[i]);
            }
    }
}
