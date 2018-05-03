#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    unsigned int edad;
    long int dni;
    int estado;

}EPersona;


typedef struct {

    long int codigo;
	char producto[50];
	char marca[50];
    unsigned int cantidad;
    int estado;

}EProducto;

/** \brief Suma dos numeros flotantes
 *
 * \param un primer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la suma de dos flotantes
 *
 */

float sumar(float numero1, float numero2);

/** \brief Resta dos flotantes
 *
 * \param un primer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la resta de dos flotantes
 *
 */
float restar(float numero1, float numero2);

/** \brief Dividir dos flotantes
 *
 * \param un numero flotante numerador
 * \param un segundo flotante denominador distinto de cero
 * \return un flotante resultado de la division
 *
 */

float dividir(float numero1, float numero2);

/** \brief multiplicar dos flotantes
 *
 * \param un pimer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la multiplicacion
 *
 */

float multiplicar(float numero1, float numero2);

/** \brief factorizar numero entero hasta 20
 *
 * \param un entero
 * \return un resultado de factorizar un entero (long long int)
 *
 */

long long int factorizar(int numero);




 /** \brief lee un numero ingresado flotante
  *
  * \param valor mininimo flotante a ingresar
  * \param valor maximo flotante a ingresar
  * \return un numero flotante
  *
  */


float IngresarFlotante(float, float);

 /** \brief valida numero flotante entre un minimo y un maximo
  *
  * \param valor mininimo a ingresar
  * \param valor maximo a ingresar
  * \return un numero flotante validado
  *
  */

float validarFlotante( float, float, float);

/** \brief leer un numero entero ingresado comprendido entre el minimo valor y el maximo valor
 * \param minimo valor
 * \param maximo valor
 * \return un entrero
 *
 */

int IngresarEntero(int, int);

/** \brief valida un numero entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero validado
 *
 */

int validarEntero (int, int, int);


/** \brief valida que se haya ingresado un dato char que sea una letra
 *
 * \param una cadena de caracteres
 *
 * \return entero si es 1 es texto
 *
 */
 
int esTexto(char []);

/** \brief leer un numero long entero ingresado comprendido entre el minimo valor y el maximo valor

 * \param minimo valor
 * \param maximo valor
 * \return un long entrero
 *
 */

long int IngresarLongEntero(long int, int);

/** \brief valida un numero long entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un long entero validado
 *
 */

long int validarLongEntero (long int, int, int);

/**
 * Carga datos preestablecidos para dinamizar las pruebas del programa
 * @param tipo de dato estrcturado EPersona , con variables Nombre, edad, estado y dni como clave unica
 * @return 
 */

void cargarDatosHardCodePersona(EPersona lista[]);


/**
 * Carga datos pre-establecidos para dinamizar las pruebas del programa
 * @param tipo de dato estrcturado EProducto , con variables Producto, marca, estado y codico como clave unica
 * @return 
 */

void cargarDatosHardCodeProductos(EProductos lista[])


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona [], int, long int);

/**
 * Carga los datos de personas en lista (Array) cuyo tipo de dato es una estrctura EPersona que posee las variables char nombre, int edad y long int dni.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array.

 */

void cargarPersona(EPersona [], int);

/**
 * Ordena por nombre los datos de personas en lista (Array) cuyo tipo de dato es una estrctura EPersona que posee las variables char nombre, int edad y long int dni.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array.

 */

void ordenarListadoPersonas (EPersona [], int );


/**
 * Imprime en consola por nombre los datos de personas en lista (Array) cuyo tipo de dato es una estrctura EPersona que posee las variables char nombre, int edad y long int dni.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array.

 */

void imprimirListadoPersonas (EPersona [], int );

/**
 * Grafica en consola por nombre los datos de personas en lista (Array) cuyo tipo de dato es una estrctura EPersona
 * El el Eje Y el numero de personas que
 * En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo dividido por edad en columnas <18 19-35 >35
 * @param tamaño del array.

 */

void GraficoListadoPersonas (EPersona [], int );
















#endif // FUNCIONES_H_INCLUDED
