#include <stdio.h>
#include <stdlib.h>
#include <string.h> // funciones para manipular cadena de caracteres stre
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
    int len;
    int len2;

    //m a r i a  d e  l a  s     m  e  r  c  e  d  e  s  /0 b  i  g  i /0
    //0 1 2 3 45 6 78 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

    printf("Ingrese Nombre\n");
    gets(nombre);




    printf("Ingrese Apellido\n");
    gets(apellido);


    strcat(nombreyapellido, nombre);

    strcat(nombreyapellido, ", ");

    strcat(nombreyapellido, apellido);


     printf(" %s\n", nombreyapellido);




    len= 200;
    len2 = (strlen(nombreyapellido));
    printf("len %d\n", len);
    printf("len2 %d\n", len2);


    for (int i=0; i<len2; i++)
     {

    if (nombreyapellido[i] != '\0')
    {
        if (i < len2 && i > 0)
       {
            nombreyapellido[i] = tolower(nombre[i]);
       }
        if (i == 0)
       {
            nombreyapellido[i] = toupper(nombre[i]);
       }

    } else
    {
        nombreyapellido[i] = ' ';

    }




     }

      puts(nombreyapellido);



    return 0;
}
