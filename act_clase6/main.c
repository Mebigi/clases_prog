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


int IngresarEntero(int);
int esNumero (char[], int);



int main()
{
    char nombre[50];
    char apellido[50];
    char nombreyapellido[120];
    int numero;
    int len;
    int esnum;

    int s = isdigit('2');
    int d = isalpha('a');



    //teara el usuario ingresa un numero una funcio que me diga si es numerico o no cero no es valido 1 es valido
    //parse en c para trasformar en un entero


    //m a r i a  d e  l a  s     m  e  r  c  e  d  e  s  /0 b  i  g  i /0
    //0 1 2 3 45 6 78 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26


    numero = IngresarEntero(10); // un entero de 9 cifras el 10 lugar es para el espacio '\0'




    printf("Ingrese Nombre\n");
    fflush(stdin);
    gets(nombre);// considera los espacios a diferencia de scanf




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


int IngresarEntero(int tam)
{
    char numero[tam];
    int entero;
    int esnum;

    do
    {
        printf("Ingrese Numero\n");
        fflush(stdin);
        scanf("%s",&numero);
        esnum = esNumero(numero, tam);

    }while (esnum == 0);

    entero = atoi(numero);

    return entero;
}

int esNumero(char numero[], int tam)
{

    int esnum = 0;

    int len = strlen(numero);

    for (int i=0; i<len; i++) // tengo en cuenta que el ultimo subindice tiene '\0' como no es un digito debe quedar afuera
    {
       if (isdigit(numero[i]))
       {
           esnum = 1;
       }
       else {

        esnum = 0;
        break;

       }



    }

     return esnum;

}

