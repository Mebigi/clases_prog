#include <stdio.h>
#include <stdlib.h>
#include "herramientas.h"

int main()
{

    float numeroflotante;

    int entero;


    int edad;
    float precio;
    char continuar;
    char nombre[50];
    int r; // Respuesta









    printf("FUNCION INGRESAR FLOTANTE\n");

    numeroflotante=IngresarFlotante("Ingresar valor", 1, 14);

    printf("%0.2f\n", numeroflotante);

    printf("FUNCION INGRESAR ENTERO\n");

    entero = IngresarEntero(1, 14000);


     // EJEMPLO DE USO DE getInt
    r = getInt(&edad,"�Cual es tu edad?","Rango valido [0 - 100]",1,100);
    if(r == 0)
        printf("\nLa edad es: %d\n",edad);


    // EJEMPLO DE USO DE getFloat
    r = getFloat(&precio,"�Cual es el precio?","Rango valido [0 - 10000]",1,10000);
    if(r == 0)
        printf("\nEl precio es: %0.2f\n",precio);


    // EJEMPLO DE USO DE getChar
    r = getChar(&continuar,"Ingrese Opcion [A][B][C]","Solo [A][B][C]",'A','C');
    if(r == 0)
        printf("\nContinuar: %c\n",continuar);


    // EJEMPLO DE USO DE getChar
    r = getString(nombre,"Nombre: ","El largo debe ser entre 2 y 50", 2, 50);
    if(r == 0)
        printf("\nNombre: %s\n",nombre);


    return 0;
}






    return 0;
}
