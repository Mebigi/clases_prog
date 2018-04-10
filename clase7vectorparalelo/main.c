#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int buscarLibre(int [], int);
float calcularPromedio(int, int);
void mostrarAlumos(int[], char[][20], int[], int[], float[], int); // MATRIZ PASAR LAS CANTIDAD DE COLUMAS
int cargarAlumno(int[], char[][20], int[], int[], float[], int);




//una funcion que muerte 1 alumno llamando desde una funcion

int main()
{
    /*
       legajo  nota1 nota2 promedio nombre(matriz)
    0    10        7    4     5.5
    1    20        4    9     6.5
    2    30        10   7     8.5
    int legajo[3] int nota[3] float promedio[3]  char nombre[3][5] (fila y columna)


    son paralelos porque tenemos correspondecias del mismo subindice de todos los vectores.
    para los str las filas se correponde en este caso. cada columna un caracter */

    int legajo[TAM]= {0};
    char nombre[TAM][20];
    int nota1[TAM];
    int nota2[TAM];
    float promedio[TAM];
    int opcion;
    int index;


    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. Modificar\n4. Baja(modificacion)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            index= cargarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
            if(index == -1)
            {
                printf("no hay lugar!!!\n");
            }else
            {
             printf("Se ingreso el alumno\n");
            }

            break;
        case 2:

        mostrarAlumos(legajo, nombre, nota1, nota2, promedio, TAM);
        break;


        }

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int legajos[], int tamano)
{

    int index = -1;
    int i;


    for(i=0; i<tamano; i++)
    {
        if (legajos[i] == 0)
        {
            index = i;
            break;
        }

    }
    return index;
}

float calcularPromedio(int nota1, int nota2)
{

    float promedio;

    promedio = (float)(nota1+nota2)/2;

    return promedio;

}

void mostrarAlumos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{


     for(int i=0; i<tam; i++)
            {
                if(legajos[i] != 0)
                {
                     printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i]);
                }

            }


}


int cargarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{


           int index;

           index = buscarLibre(legajo, tam);
            if(index !=-1)
            {

            printf("Ingrese Legajo: ");
            scanf("%d", &legajo[index]);


            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(nombre[index]);// diferencia del tiempo de ejecicio scan f reconoce el espacio como un caracter de salida

            printf("Ingrese Nota 1: ");
            scanf("%d", &nota1[index]);

            printf("Ingrese Nota 2: ");
            scanf("%d", &nota2[index]);

            promedio[index] = calcularPromedio(nota1[index], nota2[index]);

            }
            return index;

}



