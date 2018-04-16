#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct remedio
{
    char laboratorio[30];
    char nombre[20];
    float precio;
};

void fucion1(int a, float b);

void main(void)
{
    int x,y,z;
    struct remedio medic1, medic2;
    struct remedio antiinflamatorios[2];


    antiinflamatorios[0].precio = 10.25;
    fflush(stdin);
    strcpy(antiinflamatorios[0].laboratorio, "Bayer");
    strcpy(antiinflamatorios[0].nombre, "Aspirina");

    fflush(stdin);
    antiinflamatorios[1].precio = 10.25;
    strcpy(antiinflamatorios[1].laboratorio, "Bago");
    strcpy(antiinflamatorios[1].nombre, "Paracetamol");


    for (int i=0; i<2 ; i++)
    {
        printf("laboratorio: %s  medicina: %s  precio: %f\n", antiinflamatorios[i].laboratorio, antiinflamatorios[i].nombre, antiinflamatorios[i].precio );
    }

    medic1.precio = 10.25;
    strcpy(medic1.laboratorio, "Bayer");
    strcpy(medic1.nombre, "Aspirina");




    printf("laboratorio:\n ");
    gets(medic2.laboratorio);

    printf("Nombre:\n ");
    scanf("%s", medic2.nombre);

    printf("Precio:\n ");
    scanf("%f", &medic2.precio);

    printf("laboratorio %s medicina %s precio: %f\n", medic1.laboratorio, medic1.nombre, medic1.precio );
     printf("laboratorio %s medicina %s precio: %f", medic2.laboratorio, medic2.nombre, medic2.precio );
    //...

}
void fucion1(int a, float b)
{
    struct remedio x, vec[10];
    //...

}

