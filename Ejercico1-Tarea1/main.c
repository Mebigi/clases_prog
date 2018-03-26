#include <stdio.h>
#include <stdlib.h>

int main()

/*Enunciado:

debemos lograr tomar un dato por 'PROMPT' (scanF)
y luego mostrarlo por 'ALERT'.(es printF)

*/
{

    char nombre;

    printf("Escriba su nombre:");
    scanf("%c", &nombre);
    printf("\nSu nombre comienza %c", nombre);

    return 0;
}
