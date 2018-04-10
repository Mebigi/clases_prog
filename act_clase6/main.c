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

    int s = isdigit('2');
    int d = isalpha('a');

    //teara el usuario ingresa un numero una funcio que me diga si es numerico ono cero no es valido 1 es valido
    //parese en c para trasformar en un entero


    //m a r i a  d e  l a  s     m  e  r  c  e  d  e  s  /0 b  i  g  i /0
    //0 1 2 3 45 6 78 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

    printf("Ingrese Nombre\n");
    gets(nombre);




    printf("Ingrese Apellido\n");
    gets(apellido);


    strcpy(nombreyapellido, apellido); //evito mugre

    strcat(nombreyapellido, ", ");

    strcat(nombreyapellido, nombre);

    strlwr(nombreyapellido);

    nombreyapellido[0]=toupper(nombreyapellido[0]);

    len = strlen(nombreyapellido);

    for(int i=1; i<len; i++)
    {

        //if (nombreyapellido[i-1] == ' ')
        if(isspace(nombreyapellido[i]))

         {
             nombreyapellido[i+1]=toupper(nombreyapellido[i+1]);
         }



    }





      puts(nombreyapellido);



    return 0;
}
