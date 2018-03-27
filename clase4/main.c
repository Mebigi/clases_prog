#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fuciones.h"


int main()
{
    int edad;
    int legajo;
    int nota;


    edad = pedirEntero("Ingrese edad: ", 18, 60);
    legajo = pedirEntero("Ingrese Legajo: ",1, 10);
    nota = pedirEntero("Ingrese nota: ", 1, 1500);

    return 0;
}


