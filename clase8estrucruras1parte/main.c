#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20
#define CANTA 3

typedef struct
{
  char nombre[TAM];
  int legajo;
  int nota1;
  int nota2;
  float promedio;
  char email[TAM];
} eAlumno;

int main()
{
    eAlumno miAlumno;
    miAlumno.legajo=1;
    strcpy(miAlumno.nombre,"Juan");
    miAlumno.nota1=1;
    miAlumno.nota2=2;
    miAlumno.promedio=((float)miAlumno.nota1+(float)miAlumno.nota2)/2;
    strcpy(miAlumno.email,"juan@server.com");

    //Otra forma de cargar una estructura.

    eAlumno miAlumno2={"Ignacio",2,3,4,(((float)3+(float)4)/2),"ignacio@server.com"};

    printf("Legajo: %d - Nombre: %s - Nota 1: %d - Nota 2: %d - Promedio: %.2f - E-Mail: %s\n",miAlumno.legajo,miAlumno.nombre,miAlumno.nota1,miAlumno.nota2,miAlumno.promedio,miAlumno.email);
    printf("Legajo: %d - Nombre: %s - Nota 1: %d - Nota 2: %d - Promedio: %.2f - E-Mail: %s\n",miAlumno2.legajo,miAlumno2.nombre,miAlumno2.nota1,miAlumno2.nota2,miAlumno2.promedio,miAlumno2.email);

    //Cargar estructura por pantalla
    eAlumno miAlumno3;

    printf("Ingrese legajo: ");
    scanf("%d",&miAlumno3.legajo);

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miAlumno3.nombre);

    printf("\nIngrese Nota 1: ");
    fflush(stdin);
    scanf("%d",&miAlumno3.nota1);

    printf("\nIngrese Nota 2: ");
    fflush(stdin);
    scanf("%d",&miAlumno3.nota2);

    miAlumno3.promedio=(((float)miAlumno3.nota1+(float)miAlumno3.nota2)/2);

    printf("\nIngrese E-Mail: ");
    fflush(stdin);
    gets(miAlumno3.email);

    //Cargar un arreglo de una estructura por pantalla

    eAlumno miAlumno4[CANTA];

    for(int i=0;i<CANTA;i++){
        printf("\nIngrese legajo: ");
        scanf("%d",&miAlumno4[i].legajo);

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(miAlumno4[i].nombre);

        printf("\nIngrese Nota 1: ");
        fflush(stdin);
        scanf("%d",&miAlumno4[i].nota1);

        printf("\nIngrese Nota 2: ");
        fflush(stdin);
        scanf("%d",&miAlumno4[i].nota2);

        miAlumno4[i].promedio=(((float)miAlumno3.nota1+(float)miAlumno3.nota2)/2);

        printf("\nIngrese E-Mail: ");
        fflush(stdin);
        gets(miAlumno4[i].email);
    }

    return 0;


}
