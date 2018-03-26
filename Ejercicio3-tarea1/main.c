#include <stdio.h>
#include <stdlib.h>

int main()

/*Enunciado:
Al ingresar una edad debemos informar si la persona es mayor de edad
 (mas de 18 años) o adolescente (entre 13 y 17 años) o niño (menor a 13 años).

 funciona siempre y cuando ingrese un numero, si ingresa una letra hace cualuiqer cosa
*/
{
   int edad;

    printf("Escriba su Edad:");

    scanf("%d", &edad);

    if (edad > 18)
    {
        printf("\n es mayor de edad, tiene %d años", edad);


    }
    else if (edad < 13 && edad >= 0)
    {
        printf("\n es menor de edad, tiene %d años", edad);


    }
    else if (!(edad > 18 || edad < 13))
    {
        printf("\n es Adolescente, tiene %d años", edad);

    }


    else {

         printf("\n es una edad no válida");
    }
    return 0;
}
