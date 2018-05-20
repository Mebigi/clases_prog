#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM_U 100
#define TAM_A 20
#define LONG 25


int main()
{
    {


        eUsuario ListaUsuario[TAM_U]= {0};
        eAutoi ListaAutoi[TAM_A]= {0};
        eAutoe ListaAutoe[TAM_A]= {0};



        cargarDatosHardCodePersona(ListaUsuario);
        cargarDatosHardCodeAutoi(ListaAutoi);
        cargarDatosHardCodeAutoe(ListaAutoe);



        int opcion;

        do
        {


            printf("1. ALTA DE PROPIETARIO\n");
            printf("2. MODIFICAR DATOS DEL PROPIETARIO\n");
            printf("3. BAJA DEL PROPIETARIO\n");
            printf("4. INGRESO AUTOMOVIL\n");
            printf("5. ENGRESO AUTOMOVIL\n");
            printf("6. RECAUDACIÓN TOTAL DEL ESTACIONAMIENTO\n");
            printf("7. RECAUDACIÓN TOTAL POR MARCA\n");
            printf("8. CONSULTA DATOS PROPIETARIO POR ID\n");
            printf("9. PROPIETARIOS DE LA MARCA AUDI\n");
            printf("10. LISTADO DE LOS AUTOS ESTACIONADOS y PROPIETARIOS\n");
            printf("11. LISTADO USUARIOS ACTIVOS\n");
            printf("12. LISTADO USUARIOS INACTIVOS\n");
            printf("13. LISTADO AUTOS INGRESADOS\n");
            printf("14. LISTADO AUTOS EGRESOSADOS\n");
            printf("15. Salir\n");



            printf("\nINGRESAR UNA OPCION: ");

            opcion = IngresarOpcionMenu(1,15);

            printf("\n....................................................................");


            switch(opcion)
            {
            case 1:
                AltaUsuario(ListaUsuario, TAM_U);
                break;
            case 2:
                ModificacionUsuario(ListaUsuario, TAM_U);
                break;
            case 3:
                BajaUsuario(ListaUsuario, ListaAutoi, ListaAutoe, TAM_U, TAM_A);
                break;
            case 4:
                AltaAuto(ListaAutoi, ListaUsuario, TAM_U, TAM_A);
                break;

            case 5:
                EgresoAuto(ListaAutoe, ListaAutoi, ListaUsuario, TAM_A, TAM_U);
                break;

            case 6:
                recaudacionTotal(ListaAutoe, TAM_A);
                break;
            case 7:
                recaudacionMarca(ListaAutoe, TAM_A);
                break;

            case 8:
                DatosUsuario(ListaUsuario, ListaAutoi, TAM_U, TAM_A);
                break;
            case 9:
                propietariosAudi(ListaUsuario, ListaAutoi, TAM_U, TAM_A);
                break;
            case 10:
                autosEstacionados(ListaAutoi, ListaUsuario, TAM_A, TAM_U);
                break;
            case 11:
                mostrarListaUsuarios(ListaUsuario, TAM_U);
                break;
            case 12:
                mostrarListaUsuariosInactivos(ListaUsuario, TAM_U);
                break;
            case 13:
                mostrarListaAutos(ListaAutoi, TAM_A);
                break;
            case 14:
                ListadoAutosEgresados(ListaAutoe, TAM_A);
                break;


             }

            printf("\n\n");
            system("pause");
            system("cls");

        }
        while(opcion!=16);



    }
    return 0;
}
