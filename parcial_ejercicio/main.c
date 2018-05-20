#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM_U 100
#define TAM_P 1000
#define LONG 25


int main()
{
    {

        eUsuario ListaUsuario[TAM_U]= {0};
        eProducto ListaProducto[TAM_P]= {0};

        cargarDatosHardCodePersona(ListaUsuario);
        cargarDatosHardCodeProductos(ListaProducto);



        int opcion;

        do{


                printf("1. ALTA DE USUARIO\n");
                printf("2. MODIFICAR DATOS DEL USUARIO\n");
                printf("3. BAJA DEL USUARIO\n");
                printf("4. PUBLICAR PRODUCTO\n");
                printf("5. MODIFICAR PUBLICACION\n");
                printf("6. CANCELAR PUBLICACION\n");
                printf("7. COMPRAR PRODUCTO\n");
                printf("8. LISTAR PUBLICACIONES DE USUARIO\n");
                printf("9. LISTAR PUBLICACIONES\n");
                printf("10. LISTAR USUARIOS\n");
                printf("11. Salir\n");



                opcion = IngresarOpcionMenu(1,11);

                switch(opcion){
                    case 1:
                        AltaUsuario(ListaUsuario, TAM_U);
                        break;
                    case 2:
                        ModificacionUsuario(ListaUsuario, TAM_U);
                        break;
                    case 3:
                       BajaUsuario(ListaUsuario, TAM_U);
                        break;
                    case 4:
                        AltaPorducto(ListaProducto, ListaUsuario, TAM_U, TAM_P);
                        break;
                    case 5:
                        modificarProducto(ListaProducto, ListaUsuario, TAM_U, TAM_P);
                        break;
                    case 6:
                        cancelarProducto(ListaProducto, ListaUsuario, TAM_U, TAM_P);
                        break;
                    case 7:
                        comprarProducto(ListaProducto, ListaUsuario, TAM_U, TAM_P);
                        break;
                    case 8:
                        mostrarProductosUsuario(ListaProducto, ListaUsuario, TAM_U, TAM_P);
                        break;
                    case 9:
                        mostrarListaProductos(ListaProducto, ListaUsuario, TAM_U, TAM_P);
                        break;
                    case 10:
                        mostrarListaUsuarios(ListaUsuario, TAM_U);
                        break;
   }

            printf("\n\n");
            system("pause");
            system("cls");

            }while(opcion!=11);



}
    return 0;
}
