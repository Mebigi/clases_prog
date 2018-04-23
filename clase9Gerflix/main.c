#include "usuarios.h"
#include "series.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



#define TAM 4
#define LONG 25









int main()
{


    eSerie listaSerie[TAM]= {{0}};

    cargarDatosHardCode(listaSerie);

    menuSerie(listaSerie, TAM);










    return 0;
}

