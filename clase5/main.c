#include <stdio.h>
#include <stdlib.h>
#define TAM 5

float calcularPromedio(int, int);

int main()
{
    int vector[TAM];
    int i;
    int maximo;
    int flag = 0;
    int opcion;
    int cont20 = 0;
    char seguir = 's';
    int suma =0;
    float promedio;
    int posicion;
    int numero;
    char seguiri;

    /*inicinializar*/

    for(i=0; i<TAM; i++)
    {
        vector[i]=0; //el cero como valor ilogico
    }


    while(seguir=='s')
    {

        printf("1- ingreso datos\n");
        printf("2- mostrar datos\n");
        printf("3- listado reverso\n");
        printf("4- listado pares\n");
        printf("5- listado Maximo\n");
        printf("6- listado mayores 20\n");
        printf("7- promedio\n");
        printf("8- listado Salir\n");

        printf("ingrese una opcion:\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            //ingresar datos
            /*for (i=0; i<TAM; i++)
            {
                printf("ingrese un %d%c numero: ", i+1, 167);
                scanf("%d", &vector[i]);
            }
            break;*/

            printf("INGRESOS\n");
            do
            {
                 printf("Ingrese posicion\n");
                 scanf("%d", &posicion);

                 printf("Ingrese numero\n");
                 scanf("%d", &numero);
                 vector[posicion-1] = numero;

                 printf("Desea continuar ingresando?");

                 seguiri = getche();

            } while (seguiri == 's');
            break;

        case 2:
            //mostrar datos
            for (i=0; i<TAM; i++)
            {

                printf("%d\n", vector[i]);
            }
            break;
        case 3:
            //listado reverso
            printf("listado reverso\n");
            for(TAM-1; i>=0; i--)
            {
                printf("%d\n", vector[i]);
            }
            break;
        case 4:
            //pares
            printf("pares\n");

            for (i=0; i<TAM; i++)
            {

                if ( vector[i] % 2 == 0)
                {
                    printf("%d\n", vector[i]);
                }

            }
            break;
        case 5:
            //maximo
            for(i=1; i<TAM; i++)

            {
                if(vector[i]>maximo || flag == 0)
                {
                    maximo = vector[i];
                    flag = 1;
                }
            }

            printf("El maximo es %d\n y se encontro en las posiciones\n", maximo);
            for(i=0; i<TAM; i++)

            {
                if(vector[i] == maximo)
                {
                    printf("%d\n", i+1);
                }
            }
            break;

        case 6:
            //mayores 20
            printf("pares\n");

            for (i=0; i<TAM; i++)
            {

                if ( vector[i] >20)
                {
                    cont20++;
                }

            }
            break;
        case 7: //proemdio de los valores

            for(i=0; i>TAM; i++)
            {
                suma = suma + vector[i];

            }

           float promedio=calcularPromedio(suma, TAM);
           printf("Promedio: %f\n", promedio);

        case 8:
            //salir
            printf("Salir\n");
            seguir = 'n';
            break;



        }

        system("pause");
        system("cls");

    }



    //printf("DIR: %d\n\n", &vector[0]);












    //printf("Maximio\n");

    //maximo = vector[0];
    // arranco 1 para no compararlo con el 1

    /*for(i=1; i<TAM; i++)

    {
        if(vector[i]>maximo)
        {
            maximo = vector[i];
        }
    }

    printf("El maximo es %d\n y se encontro en las posiciones\n", maximo);
    for(i=0; i<TAM; i++)

    {
        if(vector[i] == maximo)
        {
            printf("%d\n", i+1);
        }
    } */






    return 0;
}

float calcularPromedio(int suma, int cantidad)
{
    float promedio;

    promedio = (float)suma/cantidad;


    return promedio;
}
