#include "lib.h"
#include "time.h"
#include "ingresodatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int imprimirmarcayprecio(int marca)
{
    int horas;
    int precio;


    switch(marca)
    {
    case 1:
        horas =devolverHorasEstadia();
        precio = horas * 150;
        printf("\n\tALPHA ROMEO:\t %d$", precio);
        break;
    case 2:
        horas =devolverHorasEstadia();
        precio = horas * 175;
        printf("\n\tFERRARI: \t %d$", precio);
        break;
    case 3:
        horas =devolverHorasEstadia();
        precio = horas * 200;
        printf("\n\tAUDI:    \t %d$", precio);
        break;

    case 4:
        horas =devolverHorasEstadia();
        precio = horas * 250;
        printf("\n\tOTROS:   \t %d$", precio);
        break;

    }


    return precio;

}

void imprimirmarca(int marca)
{

    switch(marca)
    {
    case 1:
        printf("ALPHA ROMEO");
        break;
    case 2:
        printf("FERRARI    ");
        break;
    case 3:
        printf("AUDI       ");
        break;

    case 4:
        printf("OTROS      ");
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

//1. Alta de propietario. Se ingresa:
//* IdPropietario
//* Nombre y Apellido
//* Dirección
//* Número de tarjeta de crédito


void AltaUsuario(eUsuario lista[], int tam)
{
    eUsuario aux = {0};
    int index;
    index=buscarUsuarioLibre(lista,tam);


    if(index!=-1)
    {
        lista[index].idUsuario = index+1;
        printf("\nALTA USUARIO ID: %d\n", index+1);
        getStringletras("\nIngrese Nombre: ", lista[index].nombre, 3,30);
        getString("\nIngrese direccion: ", lista[index].direccion, 6,50);
        getStringEntero("\nIngrese Tarjeta 16 numeros.\n (sin espacios ni guiones): ", lista[index].tarjeta, 16,16);
        lista[index].estado = 1;


        if(Confirmacion("Confirma el Alta?") ==0)
        {
            lista[index]= aux;
            printf("\nAlta de Usuario Cancelada");
        }

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


//2. Modificación de propietario. El propietario
//del auto notifica el cambio en el número de la tarjeta de crédito.

void ModificacionUsuario(eUsuario lista[],int tam)
{

    int numusuario;

    int index;
    char tarjeta[17]; //16 numero mas el espacio


    numusuario = IngresarEntero("\nID Usuario: ", 1, 100); //hasta 100 usuarios puede haber

    index=buscarUsuario(lista,tam,numusuario);


    if(index!=-1)
    {

        printf("\nNombre: %s\n", lista[index].nombre);
        getStringEntero("\nIngrese Tarjeta 16 numeros.\n (sin espacios ni guiones): ", tarjeta, 16,16);


        if (Confirmacion("\nConfirma el cambio?"))
        {
            strcpy(lista[index].tarjeta, tarjeta);
        }
        else
        {
            printf("\nOperaci%cn Cancelada", 162);
        }

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
        if(vec[i].idUsuario==id && vec[i].estado ==1)
        {
            retorno = i;
        }
    }
    return retorno;
}

//3. BAJA DEL USUARIO: Se ingresa el ID del usuario y eliminará junto con todos
//sus productos a la venta.

void BajaUsuario(eUsuario lista[], eAutoi listaAi[], int tamu, int tamai)
{
    eUsuario aux= {0};
    int numusuario;
    int index;
    float total;

    mostrarListaUsuarios(lista, tamu);

    numusuario = IngresarEntero("\nBAJA DEL PROPIETARIO Ingrese ID Usuario: ", 1, 100);

    index=buscarUsuario(lista,tamu,numusuario);

    if(index!=-1)
    {
        printf("\nNombre: %s\n", lista[index].nombre);
        if(Confirmacion("Confirma la Baja?"))
        {
            total = calculadorDeuda(listaAi,tamai,numusuario);

            if(total!=0)
            {

                printf("\n\tTOTAL: %.2f$", total);


            }
            else
            {
                printf("\nEL USUARIO NO TIENE\nAUTOS INGRESADOS");
            }

            lista[index].estado=aux.estado;
        }
    }
    else
    {
        printf("Usuario no encontrado!!!");
    }

}



float calculadorDeuda(eAutoi vec[],int tam,int id)
{

    float total=0;
    eAutoi aux= {0};

    printf("\n\n+++++++TICKET: Estad%ca+++++++\n", 161);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].idUsuario==id)
        {
            total += imprimirmarcayprecio(vec[i].marca);
            vec[i]=aux;
        }
    }

    printf("\n\n+++++++++++++++++++++++++++++\n");

    return total;
}


//4. Ingreso del automóvil (estacionados). Se registra la siguiente información del automóvil que ingresa al estacionamiento.-
//*Patente (string)
//*Marca (Utilizar #define con los siguientes valores: ALPHA_ROMEO, FERRARI, AUDI, OTRO)
//* Propietario (identificador número)



void AltaAuto(eAutoi lista[], eUsuario listau[], int tam_u, int tam)
{
    int indexusuario;
    int index;
    int numusuario;
    eAutoi aux= {0};

    numusuario = IngresarEntero("\nID Usuario: ", 1, 1000);

    indexusuario=buscarUsuario(listau,tam_u,numusuario);

    if(indexusuario!=-1)
    {
        printf("\nNombre: %s\n", listau[indexusuario].nombre);
        index=buscarAutoLibre(lista,tam);

        if(index!=-1)
        {
            lista[index].id = index+1;
            getString("\nIngrese Patente: ",lista[index].patente, 3,25);

            lista[index].marca = IngresarEntero("\n(OPCION 1-ALPHA_ROMEO, 2-FERRARI, 3-AUDI, 4-OTRO )\nIngrese Marca: ", 1, 4);
            lista[index].estado = 1;
            lista[index].idUsuario = listau[indexusuario].idUsuario;

            if(Confirmacion("Confirma el Ingreso del Automovil?") ==0)
            {
                lista[index]= aux;
                printf("\n Ingreso del Automovil Cancelado");
            }
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

int buscarAutoLibre(eAutoi vec[],int tam)
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


//Egreso del Automóvil (No estacionados):
// calcular el valor de la estadía. Para ello se utilizará una función que se encargará de determinar el tiempo de estadía del auto.
//(Esta función ya se encuentra implementada). Al mismo tiempo del egreso se debe emitir un ticket por pantalla informando:
//Nombre del propietario, patente de l auto, marca y valor de la estadía.


void EgresoAuto(eAutoe listaAe[], eAutoi listaAi[], eUsuario lista[], int tama, int tamu)
{

    eAutoi aux= {0};
    int egreso;
    int index;
    int indexu;
    int indexae;
    int importe;

    mostrarListaAutos(listaAi, tama);

    egreso = IngresarEntero("\nIngresar ID Auto: ", 1, 1000);

    index=buscarAiporid(listaAi,tama,egreso);

    if(index!=-1 && listaAi[index].estado == 1)
    {
        indexu=buscarUsuario(lista,tamu,listaAi[index].idUsuario);

        if(indexu!=-1)
        {
            printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tPropietario: %s", lista[indexu].nombre);
        }

        printf(" Patente: %s \n\tMarca\t\t Total ", listaAi[index].patente);

        importe= imprimirmarcayprecio(listaAi[index].marca);

        if(Confirmacion("Confirma la Baja?"))
        {
            listaAi[index].estado=aux.estado;

            indexae=buscarAutoEgresadoLibre(listaAe,tama);

            if(indexae!=-1)
            {
                listaAe[indexae].marca= listaAi[index].marca;
                listaAe[indexae].importe = importe;

            }
            else
            {
                printf("No hay espacio para guardar autos egresados");
            }


        }

    }




    else
    {
        printf("Auto no encontrado");

    }


}


int buscarAutoEgresadoLibre(eAutoe vec[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].marca==0)
        {
            index=i;
            break;
        }
    }

    return index;
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



//10. LISTAR USUARIOS:

void mostrarListaUsuarios(eUsuario lista[],int tam)
{

    printf("\nID N:\t\tNombre\t\tTarjeta");


    for(int i=0; i<tam; i++)
    {

        if(lista[i].estado == 1)
        {
            printf("\n%d\t\t%s\t\t%s\t\t",lista[i].idUsuario,lista[i].nombre,lista[i].tarjeta);


        }

    }


    printf("\n--------------------------------------------------------------\n");
}

void mostrarListaAutos(eAutoi lista[],int tam)
{

    printf("\nID Usuario N\tID Auto N\tPatente N\tMarca N\t");
    printf("\n--------------------------------------------------------------------");
    for(int i=0; i<tam; i++)
    {


        if(lista[i].estado==1)
        {

            printf("\n%d\t\t%d\t\t%s\t\t",lista[i].idUsuario,lista[i].id,lista[i].patente);
            imprimirmarca(lista[i].marca);

        }

    }

    printf("\n--------------------------------------------------------------------");

}


//6. Recaudación total del estacionamiento.-



void recaudacionTotal(eAutoe lista[],int tam)
{
    float total=0;
    printf("\nMarca\t\t\tImporte N\t\n");
    printf("\n--------------------------------------------------------------------\n");
    for(int i=0; i<tam; i++)
    {


        if(lista[i].importe!=0)
        {
            imprimirmarca(lista[i].marca);
            printf("\t\t\t%.2f\n",lista[i].importe);

            total +=lista[i].importe;

        }

    }
    printf("\nTOTAL:\t\t\t\t%.2f\n",total);
    printf("\n--------------------------------------------------------------------");

}

//7. Recaudación total por marca.-

void recaudacionMarca(eAutoe lista[],int tama)
{
    float total=0;
    float importe[4]= {0};

    printf("\nMarca      \t\t\tImporte\t\n");
    printf("\n--------------------------------------------------------------------\n");
    for(int i=0; i<tama; i++)
    {

        if(lista[i].importe>0)
        {
            total +=lista[i].importe;
            switch(lista[i].marca)
            {

            case 1:
                importe[0] +=lista[i].importe;
                break;
            case 2:
                importe[1] +=lista[i].importe;
                break;
            case 3:
                importe[2] +=lista[i].importe;
                break;
            case 4:
                importe[3] +=lista[i].importe;
                break;


            }



        }




    }


    printf("ALPHA_ROMEO\t\t\t%.2f\n",importe[0]);
    printf("FERRARI    \t\t\t%.2f\n",importe[1]);
    printf("AUDI       \t\t\t%.2f\n",importe[2]);
    printf("OTRO       \t\t\t%.2f\n",importe[3]);
    printf("\nTOTAL:   \t\t\t%.2f\n",total);
    printf("\n--------------------------------------------------------------------");
}


//8. Ingresar el Id de un propietario e informar nombre del propietario, unto a la patente y marca de todos los autos que tiene estacionados.-

void DatosUsuario(eUsuario listau[], eAutoi lista[],int tamu, int tama)
{

    int numusuario;
    int index;


    numusuario = IngresarEntero("\nID Usuario: ", 1, 100); //hasta 100 usuarios puede haber

    index=buscarUsuario(listau,tamu,numusuario);


    if(index!=-1)
    {

        printf("\nNombre: %s\n", listau[index].nombre);

        printf("\nID Auto N\tPatente N\tMarca N\t");
        printf("\n--------------------------------------------------------------------");
        for(int i=0; i<tama; i++)
        {
            if(lista[i].estado==1 && listau[index].idUsuario == lista[i].idUsuario)
            {
                printf("\n%d\t\t%s\t\t",lista[i].id,lista[i].patente);
                imprimirmarca(lista[i].marca);

            }

        }

        printf("\n--------------------------------------------------------------------");


    }
    else
    {
        printf("Usuario no encontrado!!!");
    }

}
//9. Todos los datos de los propietarios cuyos autos estacionados sean de la marca AUDI.-

void propietariosAudi(eUsuario listau[], eAutoi lista[],int tamu, int tama)
{

    for (int j=0; j<tamu; j++)
    {
        if(listau[j].estado==1)
        {
            for(int i=0; i<tama; i++)
            {
                if(lista[i].marca==AUDI && listau[j].idUsuario == lista[i].idUsuario && lista[i].estado==1)
                {
                    printf("\n%s\t\t",listau[j].nombre);
                    printf("%s\t\t",listau[j].direccion);
                    printf("%s\t\t",listau[j].tarjeta);
                    break;

                }
            }


        }

    }


}

//10. Listado de los autos estacionados con sus propietarios, ordenados por patente.-

void autosEstacionados(eAutoi lista[], eUsuario listau[],int tama, int tamu)
{

   eUsuarioAuto planilla[20]={0};

    for (int j=0; j<tamu; j++)
    {   //primero recorro el vector mas grande el del usuario
        if(listau[j].estado==1)
            //si el usuario esta activo busca que autos tiene
       {
         for(int i=0; i<tama; i++)
         {
              if(lista[i].idUsuario==listau[j].idUsuario && lista[i].estado==1)
              {
                      strcpy(planilla[i].patente,lista[i].patente);
                      strcpy(planilla[i].nombre,listau[j].nombre);
                      planilla[i].id=lista[i].id;
                      planilla[i].estado= lista[i].estado;



              }


         }
       }
    }
imprimirListadoUsuarioAuto(planilla, tama);


}



void imprimirListadoUsuarioAuto (eUsuarioAuto lista[], int tam)
{
    int i;
    int flag= 0;

   ordenarListadoUsuarioAuto(lista, tam);

   printf("\nPatente\t\tID\t\tNombre \n");

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {

            printf("\n%s\t\t\%d\t\t%s \n", lista[i].patente, lista[i].id, lista[i].nombre);
            flag = 1;


        }
    }
    if(flag == 0)
    {
        printf("\nNo existen registros cargados\n");
    }



}




 void ordenarListadoUsuarioAuto(eUsuarioAuto lista[], int tam)
 {

    eUsuarioAuto aux[tam];

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].estado== 1)
            {

                if((strcmp(lista[i].patente,lista[j].patente))> 0)
                {
                    aux[i]= lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux[i];

                }

            }

        }
    }


 }

//HardCode


void cargarDatosHardCodePersona(eUsuario lista[])
{

    int idUsuario[4]= {1,2,3,4};
    char nombre[4][25]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[4][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[4][20]= {"mitre   ","urquiza ","belgrano","alsina  "};
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


void cargarDatosHardCodeAutoi(eAutoi lista[])
{

    int id[10]= {1,2,3,4,5,6,7,8,9,10};
    char patente[10][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[10]=       {1,3,3,2,2,3,3,4,3,1};
    int propietario[10]= {2,1,2,1,3,3,4,1,4,3};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};


    for(int i=0; i<10; i++)
    {

        strcpy(lista[i].patente, patente[i]);
        lista[i].id=id[i];
        lista[i].marca=marca[i];
        lista[i].estado=estado[i];
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


