#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 4
#define LONG 20

typedef struct
{
int idUsuario;
char email[LONG];
char Password[LONG];
int idSerie;
int estado;
} eUsuario;

typedef struct
{
int idSerie;
char nombre[LONG];
int canttemporadas;
int aniolanzamiento;
int estado;
} eSerie;


int IngresarOpcionMenu(int, int);
int validarOpcionMenu(int, int, int);
void menuSerie(eSerie [], int);
int buscarLibre(eSerie [],int);


int main()
{
    //eUsuario listaUsuarios[TAM];
    eSerie listaSerie[TAM];

    menuSerie(listaSerie, TAM);






    return 0;
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


void menuSerie(eSerie lista[], int tam)
{
        int opcion;
        int index;

        do{
                fflush(stdin);
                system("cls");
                printf("1 - ALTAS\n");
                printf("2 - BAJAS\n");
                printf("3 - MODIFICACIONES\n");
                printf("4 - MOSTRAR\n");
                printf("5 - ORDENAR\n");
                printf("9 - SALIR\n");

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


                }
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

