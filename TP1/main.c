#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>

/*

1 Trabajo pr�ctico N� 1
1.1 Descripci�n

Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir

� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.

� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)

� Deber�n contemplarse los casos de error (divisi�n por cero, etc)

� Documentar todas las funciones

*/

int leerNumero();
int elegirOpciones();


int main()
{
    char seguir='s';
    int opcion=0;
    int numeroUno;
    int numeroDos;
    int resultado;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        opcion = elegirOpciones();



        switch(opcion)
        {
            case 1:

                printf("Ingresar 1er operando (A=x):\n");
                numeroUno = leerNumero();
                opcion = elegirOpciones();

            case 2:
                printf("Ingresar 2do operando (B=y):\n");
                numeroDos = leerNumero();
                opcion = elegirOpciones();
                /* */




            case 3:

                printf("La suma (A+B): %d y %d", numeroUno, numeroDos);
                resultado = sumar(numeroUno, numeroDos);
                printf("\nResultado %d ", resultado);
                opcion = elegirOpciones();



            case 4:
                printf("La resta (A-B):\n");
                resultado = restar(numeroUno, numeroDos);
                printf("\nResultado %d ", resultado);
                break;
            case 5:
                printf("La division (A/B):\n");
                resultado = dividir(numeroUno, numeroDos);
                printf("\nResultado %d ", resultado);
                break;
            case 6:
                 printf("La multiplicacion (A*B)\n");
                  resultado = multiplicar(numeroUno, numeroDos);
                  printf("\nResultado %d ", resultado);
                break;
            case 7:
                printf("El factorial (A!):\n");
                resultado = factorizar(numeroUno);
                printf("\nResultado %d ", resultado);
                break;
            case 8:
                printf("Calcular todas las operacione\n");

                break;

            case 9:
                printf("Salir\n");
                seguir = 'n';
                break;
        }


    return 0;


    }


int leerNumero()
{
    int numero;

    scanf("%d", &numero);
    while (numero == 0)
    {
        scanf("%d", &numero);
    }

    return numero;
}

int elegirOpciones()
{
        int opcion;
        printf("Elegir opcion del 1 al 9\n");
        scanf("%d",&opcion);

        while (opcion<=0 || opcion>9)
        {
           printf("Elegir opcion V�lida (del 1 al 9)\n");
           scanf("%d",&opcion);
        }

        return opcion;
}






