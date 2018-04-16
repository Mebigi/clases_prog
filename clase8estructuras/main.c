#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define LONG 30

/*void func(char * p, char q)
{
    * p = 'D';
    q = 'C';

}

int main()
{
    char letra1= 'A';
    char letra2 = 'B';
    func(&letra1,letra2);

    printf("letra 1 :%s  letra2:%s", &letra1, &letra2);

    return 0;

}*/

typedef struct
{
int legajo;
char nombre[LONG];
int nota1;
int nota2;
float promedio;
char email[50];
} eAlumno;


void mostrarListadoDeAlumnos(eAlumno[], int);

void  mostrarAlumno(eAlumno alumnito);


int main()
{
    eAlumno miAlumno = {30, "Juan", 10, 6 ,8, "juan@gmail.com"};
    eAlumno listadoDeAlumnos[TAM];

    int i;

    for(i=0; i<TAM; i++)
    {
        printf("Ingrese legajo");
        scanf("%d", &listadoDeAlumnos[i].legajo);

        printf("Ingrese legajo");
        scanf("%d", &listadoDeAlumnos[i].legajo);

        printf("Ingrese nombre");
        fflush(stdin);
        gets(listadoDeAlumnos[i].nombre); // es por referencia no lleva &

        printf("Ingrese legajo");
        scanf("%d", &listadoDeAlumnos[i].nota1);

        printf("Ingrese legajo");
        scanf("%d", &listadoDeAlumnos[i].nota2);

        printf("Ingrese mail");
        fflush(stdin);
        gets(listadoDeAlumnos[i].email); // es por referencia no lleva &

        listadoDeAlumnos[i].promedio = (listadoDeAlumnos[i].nota1, listadoDeAlumnos[i].nota2);
    }

    mostrarListadoDeAlumnos(listadoDeAlumnos, TAM);

    //printf(%p %p")
    return 0;



     }

void mostrarListadoDeAlumnos(eAlumno lista[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        mostrarAlumno(lista[i]);
    }

}



void  mostrarAlumno(eAlumno alumnito)
{
   printf("%d--, %s--, %d--, %d--, %f--\n",alumnito.legajo, alumnito.nombre, alumnito.nota1, alumnito.nota2, alumnito.promedio,alumnito.email );
}


float calcularPromedio(int nota1, int nota2)
{

    float promedio;

    promedio = (float)(nota1+nota2)/2;

    return promedio;

}







