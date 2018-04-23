#include "usuarios.h"
#include "series.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define TAM 4
#define LONG 25

void menuUsuario(eUsuario lista[], eSerie listaserie[], int tam)
{
        int opcion;
        int index;
        //int carga=0;
        int numusuario;

        do{

                printf("1 - ALTA Usuario\n");
                printf("2 - BAJAS\n");
                printf("3 - MODIFICACIONES\n");
                printf("4 - MOSTRAR\n");
                printf("5 - ORDENAR\n");
                printf("9 - menu\n");

                opcion = IngresarOpcionMenu(1,9);

                switch(opcion){
                    case 1:
                        index=buscarUsuarioLibre(lista,TAM);
                        if(index!=-1){
                            lista[index].idUsuario = index+1;
                            fflush(stdin);
                            printf("\nIngrese email: ");
                            gets(lista[index].email);
                            fflush(stdin);
                            printf("\nIngrese password: ");
                            gets(lista[index].Password);
                            lista[index].estado = 1;


                            printf("\nQue serie que desea ver? Ingresar ID: \n");


                            for(int i=0;i<TAM;i++){
                                if(listaserie[i].estado==1){
                                    printf("\n---------------------");
                                    printf("\nID N: %d",listaserie[i].idSerie);
                                    printf(" Nombre: ");
                                    puts(listaserie[i].nombre);
                                    printf(" Temporadas: %d",listaserie[i].canttemporadas);
                                    printf("  Lanzaminento: %d\n",listaserie[i].aniolanzamiento);

                                }

                            }


                            scanf("%d",&lista[index].idSerie);



                        }else{
                            printf("No hay mas espacio para guardar usuarios!!!");
                            getche();
                        }
                        break;
                    case 2:
                        printf("ID Serie: ");
                        scanf("%d",&numusuario);
                        fflush(stdin);
                        index=buscarUsuario(lista,TAM,numusuario);
                        if(index!=-1){
                            lista[index].idUsuario=0;
                        }else{
                            printf("Usuario no encontrado!!!");

                        }
                        break;
                    case 3:
                        printf("ID Serie: ");
                        scanf("%d",&numusuario);
                        fflush(stdin);
                        index=buscarUsuario(lista,TAM,numusuario);
                        if(index!=-1){
                            printf("\nSerie N: %d",lista[index].idUsuario);
                            printf("\nModificar email: ");
                            gets(lista[index].email);
                            fflush(stdin);
                            printf("\nModificar temporadas: ");
                            gets(lista[index].Password);
                            fflush(stdin);
                            printf("\nModificar Serie: ");
                            scanf("%d",&lista[index].idSerie);
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
                                    printf("\nID N: %d",lista[i].idUsuario);
                                    printf("\nemail: ");
                                    puts(lista[i].email);
                                    printf("pass: %d",lista[i].Password);
                                    printf("\nSerie: %d",lista[i].idSerie);
                                    printf("\nEstado: %d",lista[i].estado);
                                }

                            }

                            /*if (carga == 0){
                            printf("No hay series cargadas\n");

                            }*/

                            break;

   }

            printf("\n\n");
            system("pause");
            system("cls");

            }while(opcion!=9);



}

int buscarUsuarioLibre(eUsuario vec[],int tam)
{
    int index = -1;

    for(int i=0;i<tam;i++){
        if(vec[i].idUsuario==0){
            index=i;
            break;
        }
    }

     return index;
}


int buscarUsuario(eUsuario vec[],int tam,int id){

    int retorno= -1;
    for(int i=0;i<tam;i++){
        if(vec[i].idUsuario==id){
            retorno = i;
        }
    }
    return retorno;
}


