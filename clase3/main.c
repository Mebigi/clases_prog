#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*prototipo*/
// 1 declaro la funcion
int sumar(int numero1, int numero2);

void pedirNumero();

int leerNumero();

int pediryleerNumero(int minimo, int maximo);

char pedirOperador();

float Calcular(int num1, char op, int num2);



int main()
{

    int num1;
    int num2;
    char op;
    float resultado;
    int minimo = 0;
    int maximo = 100;



    /*printf("Ingrese un numero para operar:\n");*/
    //pedirNumero();
    /*scanf("%d", &num1);*/
    //num1=leerNumero();

    num1 = pediryleerNumero(minimo, maximo);
    op = pedirOperador();
    num2 = pediryleerNumero(minimo, maximo);
    resultado = Calcular(num1, op, num2);
    printf("Resultado: %.2f", resultado);



    return 0;
}

/*Implementacion de la funcion*/
//si devuleve una flotante  debe retornar un flotante

int sumar(int numero1, int numero2)
{
    int resultado;

    resultado = numero1 + numero2;

    return resultado;
}

void pedirNumero()
{
    printf("\nIngrese un numero para operar del 0 al 100\n");


}

int leerNumero()
{
    int numero1;

    scanf("%d", &numero1);

    return numero1;
}

int pediryleerNumero(int minimo, int maximo)
{
    int numero;

    pedirNumero();

    numero = leerNumero();

    while(numero < minimo || numero > maximo)
    {
        pedirNumero();
        numero = leerNumero();


    }

        return numero;


}





char pedirOperador()
{
    char operacion;

    printf("\nIngrese la operacion que desea realizar:\n");
    operacion = getche();
    while(operacion !='*' && operacion !='/' && operacion !='+' && operacion !='-' )
    {
        printf("\nError Reingrese la operacion que desea realizar:\n");
        operacion = getche();
    }

    return operacion;
}

/** \brief
 * realiza la el calculo segun la operacion
 * \param  num1 el primer numero
 * \param tipo de operador
 * \param num2 el primer numero
 * \return el resultado de la operacion dos parametros
 *
 */


float Calcular(int num1, char op, int num2)
{
    float resultado;

     switch(op)
    {
         case '+':
            resultado = sumar(num1, num2);
            //resultado = num1+num2;
            break;
         case '-':
            resultado = num1-num2;
            break;
         case '/':
            resultado = (float)num1/num2;
            break;
        case '*':
            resultado = (float)num1*num2;
            break;
    }

     return resultado;
}

