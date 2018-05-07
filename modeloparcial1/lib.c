#include "lib.h"
#include "ingresodatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>







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
        getString("\nIngrese password: minimo 6 maximo 10 caracteres ", lista[index].pass, 6,10);
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

        getStringletras("\nIngrese Nombre de Usuario: ",lista[index].nombre, 3,25);
        getString("\nIngrese password: ", lista[index].pass, 6,10);

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

void BajaUsuario(eUsuario lista[], int tam)
{
    eUsuario aux= {0};
    int numusuario;
    int index;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);

    index=buscarUsuario(lista,tam,numusuario);
    if(index!=-1)
    {
        lista[index]=aux;
    }
    else
    {
        printf("Usuario no encontrado!!!");
    }

}


//HardCodePersonas


void cargarDatosHardCodePersona(eUsuario lista[])
{
    int idUsuario[15]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    char nombre[15][25]= {"Mercedes Bigi","Micaela Colella","Galo Matos","Martin Gerbasi","Paula Bigi","Facundo Musil","Gabriela Perez","Lucia Rodriguez","Adrian Alzaroli","Viviana Musil","Pablo Callejo","Alej Arrue","Laura Lertora","Hugo Viere", "Aldo Liendo"};
    char pass[15][15]= {"xxxBigi","zzzzColella","wwwwMatos","1234Gerbasi","258Bigi","369Musil","8888Perez","1236Rodr","1478Alza","8963Musil","4444Callejo","111Arrue","7777Lertora","9999Viere", "7777Liendo"};
    int calificacion_venta[15]= {43,22,40,36,35,38,20,30,32,17,16,16,14,11,10};
    int cantidadventas[15]= {20,10,4,3,5,8,4,6,4,7,1,4,3,5,8};
    int estado[15]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


    for(int i=0; i<15; i++)
    {
        lista[i].idUsuario=idUsuario[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].pass, pass[i]);
        lista[i].calificacion_venta=calificacion_venta[i];
        lista[i].cantidadventas=cantidadventas[i];
        lista[i].estado=estado[i];

    }
}


//10. LISTAR USUARIOS: Se mostrará una lista de usuarios con la calificación
//promedio de cada uno.

void mostrarListaUsuarios(eUsuario lista[],int tam)
{
    float calificacionpromedio=0;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\n-----------------------------------------------------");
            printf("\nID N: %d",lista[i].idUsuario);
            printf("\nNombre: ");
            puts(lista[i].nombre);


            if (lista[i].cantidadventas !=0)
            {

                calificacionpromedio = (float)lista[i].calificacion_venta/lista[i].cantidadventas;

                printf("Calificacion promedio: %.2f", calificacionpromedio);
            }


        }

    }



}


//ALTA PRODUCTO
//4. PUBLICAR PRODUCTO: Se ingresará el ID del usuario y se pedirán los datos
//del producto a publicar (nombre, precio y stock)



void AltaPorducto(eProducto lista[], eUsuario listau[], int tam_u, int tam)
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
           lista[index].idProducto = index+1;


           getStringletras("\nIngrese Nombre de Producto: ",lista[index].producto, 3,25);
           lista[index].precio = IngresarEnteroFlotante("\nIngrese Precio: ", 1,9999999);//numero de cifras
           lista[index].stock = IngresarEntero("\nIngrese Stock: ", 1, 1000);

            lista[index].estado = 1;

            lista[index].idUsuario = listau[indexusuario].idUsuario;

        }
        else
        {
            printf("No hay mas espacio para Guardar Productos!!!");

        }

    }
    else
    {
        printf("El Usuario no existe");

    }



}

int buscarProductoLibre(eProducto vec[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].idProducto==0)
        {
            index=i;
            break;
        }
    }

    return index;
}

//


void cargarDatosHardCodeProductos(eProducto lista[])
{


    int idProducto[15]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    char producto[15][25]= {"Leche","Queso","Margarina","Harina","Arroz","Fideos","Huevos","Detergente","Lavandina","Desodorante","manteca","azucar", "dulce de leche","crema", "sal"};
    float precio[15]= {100.36,250.25,100.50,200.60,311.32,2363.66,165,50.36,232,1125,200,399,116,388,1000};
    int cantidad_vendida[15]= {0,0,1,2,3,1,1,5,2,1,2,3,1,3,1};
    int stock[15]= {1,2,3,6,5,2,3,3,1,1,2,3,1,5,4};
    int estado[15]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int idUsuario[15]= {2,1,4,3,6,6,2,8,9,11,10,12,13,14,15};



    for(int i=0; i<15; i++)
    {

        strcpy(lista[i].producto, producto[i]);
        lista[i].idProducto=idProducto[i];
        lista[i].cantidad_vendida=cantidad_vendida[i];
        lista[i].stock=stock[i];
        lista[i].precio=precio[i];
        lista[i].estado=estado[i];
        lista[i].idUsuario=idUsuario[i];

    }
}

//LISTAR PUBLICACIONES: Se mostrará una lista de productos indicando: id,
//nombre, precio, cantidad vendida, stock y nombre del usuario.


void mostrarListaProductos(eProducto lista[],eUsuario listau[],int tamu, int tam)
{
    int usuario;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\n---------------------------------------------");
            printf("\nID N: %d",lista[i].idProducto);
            printf("\nNombre: ");
            puts(lista[i].producto);
            printf("Precio: %.2f",lista[i].precio);
            printf("\nCantidad ventas: %d",lista[i].cantidad_vendida);
            printf("\nStock: %d",lista[i].stock);

            usuario = lista[i].idUsuario;

            for(int j=0; j<tamu; j++)
            {

                if(listau[j].idUsuario == usuario && usuario != 0 )
                {
                    printf("\nUsuario: %s", listau[j].nombre);
                }

            }

        }
    }



}


//8. LISTAR PUBLICACIONES DE USUARIO: Se ingresa el ID del usuario y se
//mostrará una lista de productos indicando: id, nombre, precio, cantidad vendida y
//stock.


void mostrarProductosUsuario(eProducto lista[],eUsuario listau[],int tamu, int tam)
{
    int usuario;

    int numusuario;
    int index;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);

    index=buscarUsuario(listau,tamu,numusuario);

    if(index!=-1)
    {
        usuario = listau[index].idUsuario;
        printf("Lista de Productos Publicados por %s \n", listau[index].nombre);
        printf("-------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(lista[i].estado==1 &&  lista[i].idUsuario == usuario)
            {

                printf("\nID N: %d ",lista[i].idProducto);
                printf("Producto: ");
                puts(lista[i].producto);
                printf("Precio: %.2f ",lista[i].precio);
                printf("Cantidad ventas: %d ",lista[i].cantidad_vendida);
                printf("Stock: %d\n",lista[i].stock);

            }



        }





    }
    else
    {
        printf("Usuario no encontrado!!!");
    }




}


//7. COMPRAR PRODUCTO: Se ingresará el ID del producto a comprar, y en el
//caso que haya stock se realizará la compra, en dicho caso se ingresará una
//calificación para el vendedor.

void comprarProducto(eProducto lista[],eUsuario listau[],int tamu, int tam)
{
    int cantidad;
    int numproducto;
    int index;
    int usuario;
    int calificar;



    numproducto = IngresarEntero("ID Producto: ", 1, 1000);

    index=buscarProducto(lista,tam,numproducto);

    if(index!=-1)
    {
         printf("\nCantidad: ");
         scanf("%d",&cantidad);

         if(cantidad >0 && cantidad <= lista[index].stock)
         {
             lista[index].stock = lista[index].stock - cantidad;
             lista[index].cantidad_vendida = lista[index].cantidad_vendida + cantidad;

         }

        usuario = lista[index].idUsuario;
        printf("\nSe ha realizado la compra con exito, Califica al vendedor: %d", usuario);
        scanf("%d",&calificar);
        printf("-------------------------------------------------------\n");

        for(int i=0; i<tamu; i++)
        {
            if(listau[i].idUsuario == usuario)
            {
                listau[i].calificacion_venta = listau[i].calificacion_venta + calificar;
                listau[i].cantidadventas++;

            }



        }





    }
    else
    {
        printf("Producto no encontrado!!!");
    }




}


int buscarProducto(eProducto vec[],int tam,int id)
{

    int retorno= -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].idProducto==id)
        {
            retorno = i;
        }
    }
    return retorno;
}


//5. MODIFICAR PUBLICACIÓN: Se ingresará el ID del usuario y se listarán los
//productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
//cantidad vendida y stock), luego ingresar el ID del producto y se pedirá que se
//ingrese un nuevo precio y stock.

void modificarProducto(eProducto lista[],eUsuario listau[],int tamu, int tam)
{
    int usuario;
    int numusuario;
    int index;
    int flag=0;
    int numuprod;
    int indexprod;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);



    index=buscarUsuario(listau,tamu,numusuario);

    if(index !=-1)
    {
    usuario = listau[index].idUsuario;


     for(int i=0;i<tam;i++)
     {
        if(lista[i].idUsuario == usuario && lista[i].estado==1)
        {

            printf("\nLista de Productos Publicados por el usuario\n--------------------------------------------");
            printf("\nID N: %d",lista[i].idProducto);
            printf("\nNombre: ");
            puts(lista[i].producto);
            printf("Precio: %.2f",lista[i].precio);
            printf("\nCantidad: %d",lista[i].cantidad_vendida);
            printf("\nStock: %d",lista[i].stock);
            flag=1;
               printf("\n--------------------------------------------\n");

        }

    }

    if(flag == 0)
    {
        printf("El susuario no tiene  productos publicados.");

    }

    printf("\nID Producto que desea editar: ");
    scanf("%d",&numuprod);
    fflush(stdin);

    indexprod=buscarProducto(lista,tam,numuprod);

    if(indexprod !=-1 && lista[indexprod].idUsuario == usuario)
    {

           lista[indexprod].precio = IngresarEnteroFlotante("\nIngrese Precio: ", 1,9999999);//numero de cifras
           lista[indexprod].stock = IngresarEntero("\nIngrese Stock: ", 1, 1000);

    }
     else{
           printf("El usuario ingresado no posee ese producto");

    }

    }

    else{
           printf("No se encontro en usuario.");

    }

}

//6. CANCELAR PUBLICACIÓN: Se ingresará el ID del usuario y se listarán los
//productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
//cantidad vendida y stock), luego ingresar el ID del producto que se quiere
//cancelar su publicación.

void cancelarProducto(eProducto lista[],eUsuario listau[],int tamu, int tam)
{
    eProducto aux={0};
    int usuario;
    int numusuario;
    int index;
    int flag=0;
    int numuprod;
    int indexprod;

    numusuario = IngresarEntero("ID Usuario: ", 1, 1000);



    index=buscarUsuario(listau,tamu,numusuario);

    if(index !=-1)
    {
    usuario = listau[index].idUsuario;


     for(int i=0;i<tam;i++)
     {
        if(lista[i].idUsuario == usuario && lista[i].estado==1)
        {

            printf("\nLista de Productos Publicados por el usuario\n--------------------------------------------");
            printf("\nID N: %d",lista[i].idProducto);
            printf("\nNombre: ");
            puts(lista[i].producto);
            printf("Precio: %.2f",lista[i].precio);
            printf("\nCantidad: %d",lista[i].cantidad_vendida);
            printf("\nStock: %d",lista[i].stock);
            flag=1;
               printf("\n--------------------------------------------\n");

        }

    }

    if(flag == 0)
    {
        printf("El susuario no tiene  productos publicados.");

    }

    printf("\nID Producto que desea editar: ");
    scanf("%d",&numuprod);
    fflush(stdin);

    indexprod=buscarProducto(lista,tam,numuprod);

    if(indexprod !=-1 && lista[indexprod].idUsuario == usuario)
    {


       lista[indexprod]=aux;


    }
     else{
           printf("El usuario ingresado no posee ese producto");

    }

    }

    else{
           printf("No se encontro en usuario.");

    }

}
