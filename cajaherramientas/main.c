#include <stdio.h>
#include <stdlib.h>
#include "herramientas.h"

int main()
{

    float numeroflotante;

    int entero;

    char* datoflot="12345.10";

    numeroflotante = atof(datoflot);

    printf("%0.2f\n", numeroflotante);







    printf("FUNCION INGRESAR FLOTANTE\n");

    numeroflotante=IngresarFlotante("Ingresar valor", 1, 14);

    printf("FUNCION INGRESAR ENTERO\n");

    entero = IngresarEntero(1, 14000);





    return 0;
}
