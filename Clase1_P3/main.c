#include <stdio.h>
#include <stdlib.h>



/*4) Escribir un programa que realice las siguientes acciones:

Solicite al usuario 10 números
Calcule cuántos son negativos y cuantos son positivos
Muestre por pantalla la cantidad de negativos y la cantidad de positivos */

int main()
{
    int numero;
    int cont=0;
    int contpos=0;
    int contneg=0;

    while(cont < 10)
    {
    cont++;
    printf("Ingrese %d numero: ", cont);
    scanf("%d", &numero);


    if(numero > 0 )
    {
         contpos++;
    }
    else if(numero < 0)
    {
         contneg++;
    }
    }

printf("Negativos %d\n", contneg);
printf("Positivos %d\n", contpos);




    return 0;
}
