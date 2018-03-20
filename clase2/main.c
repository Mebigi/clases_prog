#include <stdio.h> /* Std input ouput */
#include <conio.h> /* getche getch */
#include <stdlib.h>
#include <ctype.h> /* convertir cosas ejemplo mayus min */

int main()

{

    int numero;
    char respuesta = 's';
    int pares = 0;
    float promedio = 0;
    int suma = 0;
    int contador = 0;
    int maximo;
    int minimo;
    int flag = 0;



    do
    {
        printf("Ingrese numero: ");
        scanf("%d", &numero);

        while (numero <=0)
        {
            printf("Reingrese numero positivo: ");
            scanf("%d", &numero);
        }

        suma = suma + numero;
        contador= contador + 1;

        if (numero%2 == 0)
        {
            pares= pares + 1;
        }
        if (numero > maximo || flag == 0)
        {
            maximo = numero;
        }
        if (numero < minimo || flag == 0)
        {
            minimo = numero;
            flag = 1;
        }

         printf("Seguir? s/n: ");
         respuesta = tolower(getche());



    } while (respuesta != 'n');



    promedio =(float)suma/contador; // casteo flotante /entero da flotante



     printf("a - cantidad pares: %d \n b - promedio: %f \n c - suma: %d \n d - maximo %d minimo %d", pares, promedio, suma, maximo, minimo );






}
