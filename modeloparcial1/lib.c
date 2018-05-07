#include "lib.h"
#include "time.h"
#include "ingresodatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>




int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

void imprimirmarcayprecio(int marca)
{
    int horas;
    int precio;
    switch(marca){
                    case 1:
                        horas =devolverHorasEstadia();
                        precio = horas * 150;
                        printf("Pagar por estadia ALPHA ROMEO: %d", precio);
                        break;
                    case 2:
                        horas =devolverHorasEstadia();
                        precio = horas * 175;
                        printf("Pagar por estadia FERRARI: %d", precio);
                        break;
                    case 3:
                        horas =devolverHorasEstadia();
                        precio = horas * 200;
                        printf("Pagar por estadia AUDI: %d", precio);
                        break;

                  case 4:
                        horas =devolverHorasEstadia();
                        precio = horas * 250;
                        printf("Pagar por estadia OTROS: %d", precio);
                        break;

    }



}



//OPCIONES MENU

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

//1. ALTA DE USUARIO: Se piden los datos del usuario requeridos para que el
//sistema pueda funcionar.

void AltaUsuario(eUsuario lista[], int tam)
{
    int index;
    index=buscarUsuarioLibre(lista,tam);

    if(index!=-1)
    {
        lista[index].idUsuario = index+1;
        getStringletras("\nIngrese Nombre:", lista[index].nombre, 3,25);
        getString("\nIngrese direccion:", lista[index].direccion, 6,50);
        getString("\nIngrese Tarjeta: 16 caracteres ", lista[index].tarjeta, 16,16);
        lista[index].estado = 1;

    }
    else
    {
        printf("No hay mas espacio para Guardar Usuarios!!!");

    }




}

int buscarUsuarioLibre(eUsuario vec[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].idUsuario==0)
        {
            index=i;
            break;
        }
    }

    return index;
}


//2. MODIFICAR DATOS DEL USUARIO: Se ingresa el ID del usuario, permitiendo
//modificar sus datos.

void ModificacionUsuario(eUsuario lista[],int tam)
{

    int numusuario;

    int index;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);

    index=buscarUsuario(lista,tam,numusuario);


    if(index!=-1)
    {
        lista[index].idUsuario = index+1;

        getString("\nIngrese Tarjeta: 16 caracteres ", lista[index].tarjeta, 16,16);

        lista[index].estado = 1;

    }
    else
    {
        printf("Usuario no encontrado!!!");

    }

}

int buscarUsuario(eUsuario vec[],int tam,int id)
{

    int retorno= -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idUsuario==id)
        {
            retorno = i;
        }
    }
    return retorno;
}




//3. BAJA DEL USUARIO: Se ingresa el ID del usuario y eliminará junto con todos
//sus productos a la venta.

void BajaUsuario(eUsuario lista[], eAutoi listaAi[], int tam)
{
    eUsuario aux= {0};
    eAutoi auxai= {0};
    int numusuario;
    int index;
    int indexai;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);

    index=buscarUsuario(lista,tam,numusuario);
    if(index!=-1)
    {
        indexai=buscarAi(listaAi,tam,numusuario);
         if(index!=-1)
         {
         imprimirmarcayprecio(listaAi[indexai].marca);
         listaAi[indexai]=auxai;
         }
        lista[index]=aux;
    }
    else
    {
        printf("Usuario no encontrado!!!");
    }

}


int buscarAi(eAutoi vec[],int tam,int id)
{

    int retorno= -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idUsuario==id)
        {
            retorno = i;
        }
    }
    return retorno;
}


void EgresoAuto(eAutoe listaAe[], eAutoi listaAi[], eUsuario lista[], int tama, int tamau)
{




    int egreso;

    int index;
    int indexu;

    egreso = IngresarEntero("ID Auto: ", 1, 1000);



    index=buscarAiporid(listaAi,tama,egreso);


    if(index!=-1)
    {

         index=buscarAi(listaAi,tamau,egreso);

         if(index!=-1)
         {
         imprimirmarcayprecio(listaAi[index].marca);

         listaAi[index].estado=0;


        indexu=buscarUsuario(lista,tamau,listaAi[index].idUsuario);

        if(indexu!=-1)
         {

        printf("Nombre Propietario: %s", lista[indexu].nombre);


         }

       }
    }



    else
    {
        printf("Autio no encontrado!!!");

    }






}



int buscarAiporid(eAutoi vec[],int tam,int id)
{

    int retorno= -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            retorno = i;
        }
    }
    return retorno;
}


int buscarAemarca(eAutoe vec[],int tam,int marca)
{

    int retorno= -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].marca==marca)
        {
            retorno = i;
        }
    }
    return retorno;
}

int buscarAimarca(eAutoi vec[],int tam,int marca)
{

    int retorno= -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].marca==marca)
        {
            retorno = i;
        }
    }
    return retorno;
}

//HardCodePersonas


void cargarDatosHardCodePersona(eUsuario lista[])
{

     int idUsuario[4]= {1,2,3,4};
     char nombre[4][25]= {"Juan","Luis","Maria","Jose"};
     char tarjeta[4][20]= {"111-111","222-222","333-333","444-444"};
     char direccion[4][20]= {"mitre","urquiza","belgrano","alsina"};
     int estado[4]= {1,1,1,1};



    for(int i=0; i<4; i++)
    {
        lista[i].idUsuario=idUsuario[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].tarjeta, tarjeta[i]);
        strcpy(lista[i].direccion, direccion[i]);
        lista[i].estado=estado[i];

    }
}


//10. LISTAR USUARIOS: Se mostrará una lista de usuarios con la calificación
//promedio de cada uno.


void mostrarListaUsuarios(eUsuario lista[],int tam)
{


    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\n-----------------------------------------------------");
            printf("\nID N: %d",lista[i].idUsuario);
            printf("\nNombre: ");
            puts(lista[i].nombre);




        }

    }



}


void AltaPorducto(eAutoi lista[], eUsuario listau[], int tam_u, int tam)
{
    int indexusuario;
    int index;
    int numusuario;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);

    indexusuario=buscarUsuario(listau,tam_u,numusuario);

    if(indexusuario!=-1)
    {
        index=buscarProductoLibre(lista,tam);

        if(index!=-1)
        {
           lista[index].id = index+1;


           getString("\nIngrese Patente: ",lista[index].patente, 3,25);
           lista[index].marca = IngresarEntero("\nIngrese Marca: ", 1, 1000);



            lista[index].estado = 1;

            lista[index].idUsuario = listau[indexusuario].idUsuario;

        }
        else
        {
            printf("No hay mas espacio para Guardar Autos!!!");

        }

    }
    else
    {
        printf("El Usuario no existe");

    }



}

int buscarProductoLibre(eAutoi vec[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==0)
        {
            index=i;
            break;
        }
    }

    return index;
}



void cargarDatosHardCodeAutoi(eAutoi lista[])
{

    int id[10]= {1,2,3,4,5,6,7,8,9,10};
    char patente[10][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[10]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[10]= {2,1,2,1,3,3,4,1,4,3};


    for(int i=0; i<10; i++)
    {

        strcpy(lista[i].patente, patente[i]);
        lista[i].id=id[i];
        lista[i].marca=marca[i];
        lista[i].idUsuario=propietario[i];



    }
}



void cargarDatosHardCodeAutoe(eAutoe lista[])
{


    int marca[10]= {1,1,2,3,2,2,3,4,1,1};
    float importe[10]= {100,200,100,300,100,100,200,200,100,100};


    for(int i=0; i<10; i++)
    {

        lista[i].importe=importe[i];
        lista[i].marca=marca[i];

    }
}


