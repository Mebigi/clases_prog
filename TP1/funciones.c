#include "funciones.h"



float sumar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 + numero2;
    return resultado;
}

float restar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 - numero2;
    return resultado;
}


float dividir(float numero1, float numero2)
{
    float resultado;
    resultado = numero1/numero2;
    return resultado;
}


float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1*numero2;
    return resultado;
}

double factorizar(int numero)
{

    double factorial = 1;
    for (int i=1;i<=numero;i++)
    {
        factorial = factorial * i;
    }
    return factorial;

}

