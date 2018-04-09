#include <stdio.h>
#include <stdlib.h>
#include <string.h> // funciones para manipular cadena de caracteres stre

int main()
{
    char palabra[100]; // este vector puede guardar hasta 9 caracteres porque el ultimo se reserva para el tamaño es variable
    char palabra2[100]="Hola"; //lo puede hacer unicamente asignar cunado se declara unicamente
    //para indicar el ultimo que lee.
    //H O L A \o  ? # * +
    //0 1 2 3 4 5 6 7 8 9
    // el '\0' se coloca cuando presionamos 'enter'
    // no es posble asingnar una cadena palabra = "Juan" , porque no es un tipo de dato
    int cantidad;
    int comparar;

   /* printf("ingrese una palabra\n");
    fflush(stdin);
    scanf("%s", palabra);// = scanf("%s" (mascara), &palabra[0]); = scanf("%s", &palabra); cuando cargo un elemento del vecotr pongo &palabra[posicion]
    // toma el especio como un enter no se puede para poner nombre y apellido
    printf(" la palabra es %s", palabra);
    */

    printf("ingrese una frase\n");

    gets(palabra);

    printf(" la palabra es %s", palabra);
    //char * es un puntero a char esta haciendo referncia a un adireccion de memoria en este caso un array

    //contar caracteres
    cantidad= strlen(palabra);
    printf(" la palabra es %d", cantidad);

    //comparar dos cadenas
    //comparar = strcmp(palabra, "perro"); // devuleve tre posibles valores 1 0 (son iguales es keysensitive) -1)
    comparar = strcmp(palabra, palabra2);

    printf(" la palabra es %d", comparar);

    //me independizo de may y min
    comparar = stricmp(palabra, palabra2);

    //asingar un cedena a otra
    //strcpy("destino", "origen");

    strcpy(palabra, palabra2);//trabaja como referencia la funcion no necesita devolver nada porque se esta modificando la variable original
    printf("Destino: %s -- Origen %s\n", palabra, palabra2);

    //concatenar string
    strcat(palabra2, palabra); //recibe dos punteros a char y debvuelve un puntero cachar
    puts(palabra2);//muestra string pero no puedo darle formato

    //activiadad ingresar en una veriable nobre de persona en otra apellido, 3er variable apellidoynombre que se guarde "Gomez, Juan"
    //egla de formato la primer letra de cada palabra tiene que estar con mayuscula y la varable nombre y apellido no la puedo tocar
    //tener encuenta nombre y aperllido compuestos
    // converte a minuscula strlwr
    // converte a may  strupr




    return 0;
}
