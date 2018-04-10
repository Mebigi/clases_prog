#include <stdio.h>
#include <stdlib.h>
#include <string.h> // funciones para manipular cadena de caracteres stre
#include <ctype.h>



/** \brief int[] coleccion de enteros
 *
 * \param int tamaño
 * \param int dato a buscar
 * \return   int el indice del elementos en caso de encontrarlo o -1 si no lo encuentra
 *
 */

int buscarEntero(int[], int, int);


int main()
{
    int vector[20] = {1,2,3,5,9};
    int index;


    index= buscarEntero(vector, 7, 20);

    if(index==-1)
    {
        printf("no encontor");
    }
   else
    {
        printf("encontro en valor");
    }


}

int buscarEntero(int vector[], int numero , int len)//primero ocurrencia
{

   int posicion = -1;


    for(int i=0; i<len; i++)
    {
       if (vector[i] == numero)
       {
            posicion = i;
            break;
       }

    }
    return posicion;
}
