#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

int buscarLibre(int [], int);
float calcularPromedio(int, int);
void mostrarAlumos(int[], char[][20], int[], int[], float[], int); // MATRIZ PASAR LAS CANTIDAD DE COLUMAS
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
int modificarAlumo(int [], int, int);
int BuscarAlumo(int [], int, int);




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

    int legajo[TAM]= {10,11,14};
    char nombre[TAM][20] = {"Maria", "Mercedes", "Valeria"};
    int nota1[TAM] = {10,8,9};
    int nota2[TAM]= {7,6,9};
    float promedio[TAM] = {8.5, 7, 9};
    int opcion;
    int index;
    int modificar;
    int dato;
    int posicion;
    int len;


    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. Modificar\n4. Baja\n9. SALIR\nElija una opcion: ");
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


        case 3:
        //Buscar alumno por nro de legajo
        printf("Buscar alumno por Legajo:\n");
        scanf("%d", &dato);

        posicion = BuscarAlumo(legajo, dato, TAM);

        while(posicion == -1)
        {
            printf("Legajo no encontrado, reingresar:\n");
            fflush(stdin);
            scanf("%d", &dato);
            posicion = BuscarAlumo(legajo, dato, TAM);

        }

        printf("Modificar:\n1-legajo\n2-Nombre(no disp)\n3-Nota1\n4-Nota2\nElija campo a modificar: ");
        scanf("%d", &modificar);

        //campo a modificar
         switch(modificar)
         {
              case 1:
                //legajo
                printf("Modificar legajo de\n: ");
                scanf("%d", &legajo[posicion]);
                break;
            case 2:
               // nombre
                printf("Modificar nombre de\n: ");
                fflush(stdin);
                gets(nombre[posicion]);
                break;
            case 3:
                //Nota1
                printf("Modificar Nota 1 de\n: ");
                scanf("%d", &nota1[posicion]);
                promedio[posicion] = calcularPromedio(nota1[posicion], nota2[posicion]);
                break;

            case 4:
                //Nota2
                printf("Modificar Nota 2 de\n: ");
                scanf("%d", &nota2[posicion]);
                promedio[posicion] = calcularPromedio(nota1[posicion], nota2[posicion]);
                break;


         }
           break;


            case 4:
                //baja
                //Buscar alumno por nro de legajo
                printf("Buscar alumno por Legajo");
                scanf("%d", &dato);

                posicion = BuscarAlumo(legajo, dato, TAM);

                legajo[posicion] = 0;
                len = strlen(nombre[posicion]);
                for (int i=0; i<len; i++)
                {
                    nombre[posicion][i] = 0;
                }
                nota1[posicion] = 0;
                nota2[posicion] = 0;
                promedio[posicion] = 0;
                break;
        }


    printf("\n\n");
    system("pause");
    system("cls");

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

int BuscarAlumo(int vector[], int dato, int tam)
{
     int i;
     int posicion = -1;

     for(i=0; i<tam; i++)
            {
                if(vector[i] == dato)
                {

                   posicion = i;

                }

            }

            return posicion;
}

int modificarAlumo(int vector[], int dato, int tam)
{
     int i;

     for(i=0; i<tam; i++)
            {
                if(vector[i] == dato)
                {

                    printf("Ingresar nuevo dato: ");
                    fflush(stdin);
                    scanf("%d", &vector[i]);
                    break;
                }
            }

            return vector[i];
}


