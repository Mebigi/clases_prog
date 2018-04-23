#include "usuarios.h"
#include "series.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define TAM 4
#define LONG 25

void menuSerie(eSerie lista[], int tam)
{
        int opcion;
        int index;
        //int carga=0;
        int numserie;
        eUsuario listaUsuarios[TAM]= {{0}};

        do{

                printf("1 - ALTA Serie\n");
                printf("2 - BAJAS\n");
                printf("3 - MODIFICACIONES\n");
                printf("4 - MOSTRAR\n");
                printf("5 - ORDENAR\n");
                printf("9 - menu USUARIOS\n");

                opcion = IngresarOpcionMenu(1,9);

                switch(opcion){
                    case 1:
                        index=buscarLibre(lista,TAM);
                        if(index!=-1){
                            lista[index].idSerie = index+1;
                            fflush(stdin);
                            printf("\nIngrese Nombre: ");
                            gets(lista[index].nombre);
                            fflush(stdin);
                            printf("\nIngrese Cantidad de Temporadas: ");
                            scanf("%d",&lista[index].canttemporadas);
                            fflush(stdin);
                            printf("\nIngrese Año de Lanzamiento: ");
                            scanf("%d",&lista[index].aniolanzamiento);
                            lista[index].estado = 1;



                        }else{
                            printf("No hay mas espacio para guardar series!!!");
                            getche();
                        }
                        break;
                    case 2:
                        printf("ID Serie: ");
                        scanf("%d",&numserie);
                        fflush(stdin);
                        index=buscarSerie(lista,TAM,numserie);
                        if(index!=-1){
                            lista[index].idSerie=0;
                        }else{
                            printf("Serie no encontrada!!!");

                        }
                        break;
                    case 3:
                        printf("ID Serie: ");
                        scanf("%d",&numserie);
                        fflush(stdin);
                        index=buscarSerie(lista,TAM,numserie);
                        if(index!=-1){
                            printf("\nSerie N: %d",lista[index].idSerie);
                            printf("\nModificar nombre: ");
                            gets(lista[index].nombre);
                            fflush(stdin);
                            printf("\nModificar temporadas: ");
                            scanf("%d",&lista[index].canttemporadas);
                            fflush(stdin);
                            printf("\nModificar Lanzamiento: ");
                            scanf("%d",&lista[index].aniolanzamiento);
                            fflush(stdin);
                            printf("\nModificar Estado: ");
                            scanf("%d",&lista[index].estado);


                        }else{
                            printf("Serie no encontrada!!!");
                            getche();
                        }
                        break;

                        case 4:
                            for(int i=0;i<TAM;i++){
                                if(lista[i].estado==1){
                                    printf("\n---------------------");
                                    printf("\nID N: %d",lista[i].idSerie);
                                    printf("\nNombre: ");
                                    puts(lista[i].nombre);
                                    printf("Temporadas: %d",lista[i].canttemporadas);
                                    printf("\nLanzaminento: %d",lista[i].aniolanzamiento);
                                    printf("\nEstado: %d",lista[i].estado);
                                }

                            }

                            /*if (carga == 0){
                            printf("No hay series cargadas\n");

                            }*/

                            break;

                    case 9:
                    printf("\nMenu Usuario\n");
                    menuUsuario(listaUsuarios, lista, TAM);


                }

            printf("\n\n");
            system("pause");
            system("cls");

            }while(opcion!=9);





}







int buscarLibre(eSerie vec[],int tam)
{
    int index = -1;

    for(int i=0;i<tam;i++){
        if(vec[i].idSerie==0){
            index=i;
            break;
        }
    }

     return index;
}




int buscarSerie(eSerie vec[],int tam,int id){

    int retorno= -1;
    for(int i=0;i<tam;i++){
        if(vec[i].idSerie==id){
            retorno = i;
        }
    }
    return retorno;
}



void cargarDatosHardCode(eSerie lista[])
{

    int id[3]={1,2,3};
    char nombre[3][LONG]={"Mad Men","Merli","Game"};
    int lanzamiento[3]={2007,2017,2013};
    int temporadas[3]={7,1,8};
    int estado[3]={1,1,1};

    for(int i=0; i<3; i++)
    {
        lista[i].idSerie=id[i];
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].aniolanzamiento=lanzamiento[i];
        lista[i].canttemporadas=temporadas[i];
        lista[i].estado=estado[i];

    }
}



int IngresarOpcionMenu(int min, int max)
{
    int entero;

    fflush(stdin);
    scanf("%d",&entero);
    entero = validarOpcionMenu(entero, min, max);

    return entero;
}




int validarOpcionMenu (int dato, int min, int max)
{
    while(dato < min || dato > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar:\n", 160);
        scanf("%d", &dato);

    }

    return dato;

}




