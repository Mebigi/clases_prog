#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
#define LONG 30



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

//void ordenarListadoDeAlumnos(eAlumno[], int);

void  mostrarAlumno(eAlumno alumnito);




float calcularPromedio(int nota1, int nota2);


int main()
{

    eAlumno listadoDeAlumnos[TAM];
    eAlumno aux[TAM];
    int valorstr;






     /*int i;

   for(i=0; i<TAM; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &listadoDeAlumnos[i].legajo);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(listadoDeAlumnos[i].nombre); // es por referencia no lleva &

        printf("Ingrese Nota1: ");
        scanf("%d", &listadoDeAlumnos[i].nota1);

        printf("Ingrese Nota2: ");
        scanf("%d", &listadoDeAlumnos[i].nota2);

        printf("Ingrese mail: ");
        fflush(stdin);
        gets(listadoDeAlumnos[i].email); // es por referencia no lleva &

        listadoDeAlumnos[i].promedio = calcularPromedio(listadoDeAlumnos[i].nota1, listadoDeAlumnos[i].nota2);
    }
*/

     //Hardcodeo

    fflush(stdin);
    listadoDeAlumnos[1].legajo = 2;
    strcpy(listadoDeAlumnos[1].nombre, "daniela");
    listadoDeAlumnos[1].nota1 = 5;
    listadoDeAlumnos[1].nota2 = 5;
    strcpy(listadoDeAlumnos[1].email, "Mercedes@gamil");
    listadoDeAlumnos[1].promedio = calcularPromedio(listadoDeAlumnos[1].nota1, listadoDeAlumnos[1].nota2);


    fflush(stdin);
    listadoDeAlumnos[0].legajo = 1;
    strcpy(listadoDeAlumnos[0].nombre, "biviana");
    listadoDeAlumnos[0].nota1 = 10;
    listadoDeAlumnos[0].nota2 = 10;
    strcpy(listadoDeAlumnos[0].email, "Maria@gamil");
    listadoDeAlumnos[0].promedio = calcularPromedio(listadoDeAlumnos[0].nota1, listadoDeAlumnos[0].nota2);


    fflush(stdin);
    listadoDeAlumnos[2].legajo = 3;
    strcpy(listadoDeAlumnos[2].nombre, "celeste");
    listadoDeAlumnos[2].nota1 = 6;
    listadoDeAlumnos[2].nota2 = 6;
    strcpy(listadoDeAlumnos[2].email, "Bigi@gamil");
    listadoDeAlumnos[2].promedio = calcularPromedio(listadoDeAlumnos[0].nota1, listadoDeAlumnos[0].nota2);


    valorstr = strcmp(listadoDeAlumnos[1].nombre,listadoDeAlumnos[2].nombre);
    printf("%d", valorstr);



    //ordenar por legajo
    for(int i=0; i<TAM-1; i++)
    {
        for(int j=i+1; j<TAM; j++)
        {
            if((strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre))>0)
            //if (listadoDeAlumnos[i].nombre<listadoDeAlumnos[j].legajo) // depende como lo ordeno va mayo o menor
            {
                aux[i]= listadoDeAlumnos[i];
                listadoDeAlumnos[i]=listadoDeAlumnos[j];
                listadoDeAlumnos[j]=aux[i];
            }
        }
    }


    mostrarListadoDeAlumnos(listadoDeAlumnos, TAM);


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
   printf("%d--, %s--, %d--, %d--, %f--, %s\n",alumnito.legajo, alumnito.nombre, alumnito.nota1, alumnito.nota2, alumnito.promedio, alumnito.email );
}




float calcularPromedio(int nota1, int nota2)
{

    float promedio;

    promedio = (float)(nota1+nota2)/2;

    return promedio;

}







