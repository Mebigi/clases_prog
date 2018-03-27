#include <stdio.h>
#include <stdlib.h>

int factorizar(int);

int main()
{
    int numero;
    int factorizado;



    numero = 5;

    factorizado = factorizar(numero);
    printf("%d", factorizado);

}


int factorizar(int numero)
{

    int factorial;

    factorial = 1;

    for (int i=1;i<=numero;i++)
    {
        factorial = factorial * i;


    }
    return factorial;

}


int factorial (int numero)
{
    int retorno
    if(numero ==0)
    {
        retorno = 1;
    }
    else
    {
    retorno = numero * factorial(numero -1);

    }
    return retorno;
    }
}
