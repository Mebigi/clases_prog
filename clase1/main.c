#include <stdio.h> /* Std input ouput */
#include <conio.h> /* getche getch */
#include <stdlib.h>
#include <ctype.h> /* convertir cosas ejemplo mayus min */

int main()
/* funcion principal punto de entrada en C, int digo que devulve en este caso int un entero en () digo que recibe*/
{
    printf("Hello world mercedes Bigi!\n");
    /* salida en pantalla */

    /* de datos int (%d) float (%f) char (%c)  distinto espacio de memoria segun en tipo de dato tmabien por el sistema operativo*/

    int numero1;
    float numero2;
    float suma;
    char letra;

    /*numero1 = 8;
    numero2 = 44.258; */

    printf("Ingrese numero1: ");
    scanf("%d", &numero1);

    printf("Ingrese numero2: ");
    scanf("%f", &numero2);

    printf("Ingrese letra: ");

    /* fflush(stdin);    // standar inpunt constante del buffer de entrada, flush limpiamos buffer */
     /* scanf(" %c", &letra); poner un espacio antes de %c */

    /*Otra forma:

    letra = getche();

    letra = toupper(letra); */

   /*otra forma */

    letra = toupper(getche());



    suma = numero1 + numero2;


    /* funcion scanf es similar a prompt y a document.getElementById pero no se le asigna a una variable, recibe 2 parametros "tipo de dato (mascara de entrada)HASTA
    donde puede leer y el desde"*/
    /* & la direccion de memoria de esa variable el "DESDE" */
    printf("\nEl primer número es: %d numero y el segundo: %.2f\ny la suma es %.2f", numero1, numero2, suma); /* .2f resultado den 2 decimaales */

    printf("\n la letra ingresada es: %c ", letra);

    /* buffer entrada y salida cuando escribimos se llena y luego se descarga, el entre se representa un "enter" queda guardado en el buffer lo pasa de largo */

    return 0;
    /* lo que devuelve */
}
/* goo.gl/forms/jreuEjcALAJWjfPi1 */
