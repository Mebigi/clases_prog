#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>


/*

1 Trabajo práctico Nº 1
1.1 Descripción

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)

• Documentar todas las funciones

*/
/** \brief leer un numero ingresado flotante
 * \return numero ingresado flotante
 *
 */

float leerNumero();

/** \brief leer un numero ingresado de opciones del menu valida que sea entre minimo y maximo
 *
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero comprendido entre el minimo valor y el maximo valor
 *
 */

int elegirOpciones(int min, int max);


int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    float resultado;
    int flag1 = 0;
    int flag2 = 0;
    double resultadofactorizar;





    while(seguir=='s')
    {

        if (flag1 == 1)
        {
            printf("1- Ingresar 1er operando (A=%f)\n", numeroUno);

        }
        else
        {
            printf("1- Ingresar 1er operando (A=X)\n");
        }

         if (flag2 == 1)
        {
            printf("2- Ingresar 2do operando (B=%f)\n", numeroDos);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=Y\n");
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        opcion = elegirOpciones(1, 9);



        switch(opcion)
        {
            case 1:

                printf("Ingresar 1er operando:\n");
                numeroUno = leerNumero();
                flag1 = 1;
                continue;


            case 2:
                printf("Ingresar 2do operando:\n");
                numeroDos = leerNumero();
                flag2 = 1;
                continue;


            case 3:

                printf("La suma (A+B): %f y %f", numeroUno, numeroDos);
                resultado = sumar(numeroUno, numeroDos);
                printf("\nResultado %f\n", resultado);
                continue;



            case 4:
                printf("La resta (A-B):\n");
                resultado = restar(numeroUno, numeroDos);
                printf("\nResultado %f\n", resultado);
                continue;

            case 5:
                printf("La division (A/B):\n");
                 while (numeroDos == 0)
                    {
                        printf("Elegir denominador distinto de cero\n");
                        scanf("%f", &numeroDos);
                    }

                resultado = dividir(numeroUno, numeroDos);
                printf("\nResultado %f\n", resultado);
                continue;
            case 6:
                printf("La multiplicacion (A*B)\n");
                resultado = multiplicar(numeroUno, numeroDos);
                printf("\nResultado %f\n", resultado);
                continue;
            case 7:
                printf("El factorial (A!):\n");
                resultadofactorizar = factorizar((int)numeroUno);
                printf("\nResultado %d %e\n", (int)numeroUno, resultadofactorizar);
                continue;

            case 8:
                printf("Calcular todas las operaciones\n");

                resultado = sumar(numeroUno, numeroDos);

                printf("\nRESULTADOS:\nSuma (A+B): %f", resultado);
                resultado = restar(numeroUno, numeroDos);

                printf("\nResta (A-B): %f", resultado);

                if (numeroDos < 0)
                {
                    printf("\n No es posible realizar esta operación");
                }

                else {
                resultado = dividir(numeroUno, numeroDos);
                printf("\nDivision (A/B): %f", resultado);

                }
                resultado = multiplicar(numeroUno, numeroDos);
                printf("\nMultiplicacion (A*B): %f", resultado);

                resultadofactorizar = factorizar((int)numeroUno);
                printf("\nFactorizacion (A!): %e", resultadofactorizar);


                continue;

            case 9:
                printf("Salir\n");
                seguir = 'n';
                break;
        }


    return 0;


    }

}


float leerNumero()
{
    float numero;

    scanf("%f", &numero);

    return numero;
}

int elegirOpciones(int min, int max)
{
        int opcion;

        printf("Elegir opcion del 1 al 9\n");

        scanf("%d",&opcion);

        while (opcion<min || opcion>max)
        {
           printf("Elegir opcion Válida (del %d al %d)\n", min, max);

           scanf("%d",&opcion);
        }

        return opcion;
}






