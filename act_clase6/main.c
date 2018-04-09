#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//activiadad ingresar en una variable nombre de persona y otra apellido,
//3er variable apellidoynombre que se guarde "Gomez, Juan"
//Regla de formato la primer letra de cada palabra tiene que estar con mayuscula y
//la variable nombre y apellido no la puedo Modificar
//tener encuenta nombre y aperllido compuestos
// converte a minuscula strlwr
// converte a may  strupr

int main()
{
    char nombre[50];
    char apellido[50];
    char nombreyapellido[120];

    //m a r i a  d e  l a  s     m  e  r  c  e  d  e  s  /0 b  i  g  i /0
    //0 1 2 3 45 6 78 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

    printf("Ingrese Nombre\n");
    gets(nombre);

    for(i=0; i<50-1; i++)//negra tiene cantidad de elementos menos 1 para que no desborde.
    {
        if (i==0)
        {
            strlwr(nombre[i]);
        }
        else {

            strlwr(nombre[i]);

        }
        strlwr(nombre[i]); // depende si ordeno de menor a mayor pongo mayor
            {
                aux = vector[i];
                vector[i]=vector[j];
                vector[j]= aux;
            }
        }
    }



    printf("Ingrese Apellido\n");
    gets(apellido);




    printf(" El nombre es %s, %s", nombre, apellido);


    strcat(nombreyapellido, nombre);




    strlwr(nombreyapellido);




    strcat(nombreyapellido, ",");

    strcat(nombreyapellido, apellido);

    strlwr(nombreyapellido);



    puts(nombreyapellido);



    return 0;
}
