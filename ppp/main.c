#include <stdio.h>
#include <stdlib.h>


int sumaarray(int [], int);

int main()
{

    char letra1 = 'A';
    char letra2 = 'B';
    char *p =&letra1;
    letra1 = 'C';
    letra2 = *p;




    printf("%c-%c", letra1, letra2);


    int resultado;
    int pisos[10]={1,2,3,4,5,6,7,8,9,10};

    resultado = sumaarray(pisos, 10);

    printf("Hello world! %d\n", resultado);
    return 0;
}
int sumaarray(int enteros[], int tam)
{
    int resultadosuma=0;

    int i;

    for(i=0;i<tam;i++)
    {
        resultadosuma=enteros[i];
    }
    return resultadosuma;
}
