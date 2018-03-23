#include <stdio.h>
#include <stdlib.h>

int main()
/*Enunciado:
Al ingresar una edad solo debemos informar si la persona NO es adolescente. entre 13 y 17 años (inclusive)*/
{
   int edad;

    printf("Escriba su Edad:");

    scanf("%d", &edad);

    if (edad > 18 || edad < 13)
    {
        printf("\n NO es adolescente su edad es %d", edad);


    }

    return 0;
}
