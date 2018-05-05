#include "herramientas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//INGRESO Y VALIDAR DATOS INGRESADOS

float IngresarFlotante(char mensaje[], int min, int max)
{
    char datoflot[14];
    float numero;

    printf("%s:\n", mensaje, min, max);
    gets(datoflot);

    numero = validarFlotante(datoflot, min, max, 14);

    return numero;
}


float validarFlotante(char datoflot[], int min, int max, int tam)
{
    float numeroflotante=0;
    int puntos=0;
    int esflotante=0;
    int contadordecimales=0;
    int cifraentero=0;
    int negativos=0;

    int len;
    len = strlen(datoflot);

    do
    {
        for (int i=0; i<len; i++)
        {
            if(!(isdigit(datoflot[i])))
            {
                if((datoflot[0] == '-') && negativos < 1)
                {
                    negativos++;
                }

                else if((datoflot[i] == '.') && puntos < 1)
                {
                    puntos++;

                    cifraentero=i;

                    if (cifraentero>7)
                    {
                        esflotante=0;
                        printf("Ha superado la el tamano del entero permitido\n");
                        break;

                    }

                }
                else
                {
                    esflotante=0;
                    break;
                }
            }

            else
            {
                esflotante=1;

            }



        if(puntos == 1)
            {
                contadordecimales++;

                if(contadordecimales>6 || contadordecimales < 1 )
                {
                    esflotante=0;
                    printf("Error en cantidad de los decimales\n");
                    break;

                }
            }

        }

        if(esflotante==0)
        {
            printf("Dato no v%clido reingresar:\n", 160, min, max);
            gets(datoflot);
            len = strlen(datoflot);
            puntos=0;
            negativos=0;
            contadordecimales=0;

        }

        if ( len < min || len > max)
        {
            printf("Largo no v%clido reingresar:\n", 160, min, max);
            gets(datoflot);
            len = strlen(datoflot);
            puntos=0;
            negativos=0;
            contadordecimales=0;

        }

    }while(esflotante ==0);

    numeroflotante = atof(datoflot);

    return numeroflotante;

}





int IngresarEntero(int min, int max)
{
    int entero;

    fflush(stdin);
    scanf("%d",&entero);
    entero = validarEntero(entero, min, max);

    return entero;
}




int validarEntero (int dato, int min, int max)
{
    while((dato < min || dato > max) && !(isdigit(dato)))
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar:\n", 160);
        scanf("%d", &dato);

    }

    return dato;

}


long int IngresarLongEntero(long int min, int max)
{
    long int entero;

    fflush(stdin);
    scanf("%ld",&entero);
    entero = validarLongEntero(entero, min, max);

    return entero;
}




long int validarLongEntero (long int dato, int min, int max)
{
    while(dato < min || dato > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar:\n", 160);
        scanf("%ld", &dato);

    }

    return dato;

}

int esTexto(char texto[])
{

    int estexto = 0;

    int len = strlen(texto);

    for (int i=0; i<len; i++)
    {
        if (isalpha(texto[i]))
        {
            estexto = 1;
        }
        else
        {

            estexto = 0;
            break;

        }



    }

    return estexto;

}


//OPERACIONES


float sumar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 + numero2;
    return resultado;
}

float restar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 - numero2;
    return resultado;
}


float dividir(float numero1, float numero2)
{
    float resultado;
    resultado = numero1/numero2;
    return resultado;
}


float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1*numero2;
    return resultado;
}

long long int factorizar(int numero)
{

    long long int factorial = 1;
    for (int i=1;i<=numero;i++)
    {
        factorial = factorial * i;
    }
    return factorial;

}

//HARDCORDEODATOS

void cargarDatosHardCodePersona(EPersona lista[])
{



    long int dni[15]= {24083235,39457791,27775664,51789936,36896235,24083231,39457792,27775663,51789936,36896234,22083235,33457791,24775664,55789936,37896235};
    char nombre[15][50]= {"Mercedes Bigi","Micaela Colella","Galo Matos","Martin Gerbasi","Paula Bigi","Facundo Musil","Gabriela Perez","Lucia Rodriguez","Adrian Alzaroli","Viviana Musil","Pablo Callejo","Alejandra Arrue", "Laura Lertora","Hugo Viere", "Aldo Liendo"};
    unsigned int edad[15]= {43,22,40,36,35,38,20,30,32,17,16,16,14,11,10};
    int estado[15]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    for(int i=0; i<15; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].dni=dni[i];
        lista[i].edad=edad[i];
        lista[i].estado=estado[i];

    }
}


void cargarDatosHardCodeProductos(EProducto lista[])
{



    long int codigo[15]= {24083235,39457791,27775664,51789936,36896235,24083231,39457792,27775663,51789936,36896234,22083235,33457791,24775664,55789936,37896235};
    char producto[15][50]= {"Leche","Queso","Margarina","Harina","Arroz","Fideos","Huevos","Detergente","Lavandina","Desodorante","manteca","azucar", "dulce de leche","crema", "sal"};
    char marca[15][50]= {"Sancor","La Serenisima","La Serenisima","Balca Flor","Gallo","Don Felipe","Granja Pio","Magistral","Ayudin","Inpulse","La suipachense","Ledesma", "La Serenisima","Sancor", "celusal"};
	unsigned int cantidad[15]= {1,2,3,6,5,2,3,3,1,1,2,3,1,5,4};
    int estado[15]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    for(int i=0; i<15; i++)
    {
        strcpy(lista[i].marca, marca[i]);
		strcpy(lista[i].producto, producto[i]);
        lista[i].codigo=codigo[i];
        lista[i].cantidad=cantidad[i];
        lista[i].estado=estado[i];

    }
}




//ABM


int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==0)
        {
            index=i;
            break;
        }
    }

    return index;
}



void cargarPersona(EPersona lista[], int index)
{

    char estexto;


    printf("Ingrese DNI: ");

    lista[index].dni= IngresarLongEntero(1000000,99999999);


    fflush(stdin);


        printf("\nIngrese Nombre: ");
        gets(lista[index].nombre);
        estexto= esTexto(lista[index].nombre);

    while (estexto==0)
    {
        printf("\nReigrese Nombre: ");
        gets(lista[index].nombre);
        estexto= esTexto(lista[index].nombre);
    }




        fflush(stdin);
    printf("\nIngrese Edad: ");
    lista[index].edad=IngresarLongEntero(1,150); // segun Google 146 años el hombre mas viejo



    lista[index].estado = 1;

}

void imprimirListadoPersonas (EPersona lista[], int tam)
{
    int i;
    int flag= 0;




    printf("_______________________________________________________\n");



    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {

            printf("\n%s\t\t\%ld\t%d \n", lista[i].nombre, lista[i].dni, lista[i].edad);
            flag = 1;


        }
    }
    if(flag == 0)
    {
        printf("\nNo existen registros cargados\n");
    }

    printf("_______________________________________________________\n");

}






int buscarPorDni(EPersona lista[], int tam, long int dni)
{
    int index = -1;


    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==dni)
        {
            index = i;
        }
    }





    return index;


}

void ordenarListadoPersonas(EPersona lista[], int tam )
{
    EPersona aux[tam];

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].estado == 1)
            {

                if((strcmp(lista[i].nombre,lista[j].nombre))> 0)
                {
                    aux[i]= lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux[i];

                }





            }


        }

    }

}

void GraficoListadoPersonas (EPersona lista[], int tam )
{


    char grafico1[tam][2];
    char grafico2[tam][2];
    char grafico3[tam][2];
    int w=0;
    int j=0;
    int k=0;


    for(int i=0; i<=tam ; i++)
    {

        strcpy(grafico1[i]," ");

        strcpy(grafico2[i]," ");

        strcpy(grafico3[i]," ");

    }




    for(int i=0; i<tam ; i++)
    {
        if(lista[i].edad < 18 && lista[i].edad >0)
        {
            fflush(stdin);
            strcpy(grafico1[w],"*");
            w++;



        }

        if(lista[i].edad > 18 && lista[i].edad <=35)
        {
            fflush(stdin);
            strcpy(grafico2[k],"*");
            k++;



        }

        if(lista[i].edad > 35)
        {
            fflush(stdin);
            strcpy(grafico3[j],"*");
            j++;



        }




    }


    printf("\n");

    for(int i=tam; i>=0 ; i--)
    {
        if( (strcmp(grafico1[i],"*")==0) || (strcmp(grafico2[i],"*")==0) || (strcmp(grafico3[i],"*")==0)  )
        {
            printf("  %d-| %s      ", i+1, grafico1[i]);
            printf("%s       ", grafico2[i]);
            printf("%s\n", grafico3[i]);


        }


    }
    printf("  __|_________________________\n");
    printf("     <18   19-35    >35\n\n");
    printf("Gráfico para una estadística de %d personas con edad menor a 18, %d personas con edades entre 19 y 35, y %d personas con edades mayores a 35.\n", w,k,j);



}


//

long int IngresarLongInt(int min, int max)
{
    char numero[9];
    long int entero;
    int esnum=0;

    do
    {
        printf("Ingrese N%cmero: ", 163);
        fflush(stdin);
        gets(numero);

        if(strlen(numero) >= min && strlen(numero) < max)
        {
            esnum = esNumerolong(numero, 9);
        }
        else
        {

            printf("Error, ");
        }


    }
    while (esnum == 0);

    entero = atol(numero);

    return entero;
}


long int esNumerolong(char numero[], int tam)
{

    long int esnum = 0;

    int len = strlen(numero);

    for (int i=0; i<len; i++)
    {
        if (isdigit(numero[i]))
        {
            esnum = 1;
        }
        else
        {

            esnum = 0;
            break;

        }



    }

    return esnum;

}










