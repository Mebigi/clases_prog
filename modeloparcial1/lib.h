#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED


typedef struct {
    int idUsuario;
    char nombre[25];
    char direccion[15];
    char tarjeta[17];
    int estado;

}eUsuario;


typedef struct {
    int id;
    char patente[20];
    int marca;
    int idUsuario;
    int estado;

}eAutoi;


typedef struct {
    int marca;
    float importe;


}eAutoe;


typedef struct {
    int id;
    char patente[20];
    char nombre[25];
    int estado;


}eUsuarioAuto;

/** \brief calcula un numero aleatorio entre 1 y 24
  * \return numero aleatorio entre 1 y 24
 *
 */

int devolverHorasEstadia();

/** \brief imprime en pantalla valores de marca y horas trabajadas en funcion de parametro marca ingresado
 * \param  un entero
 * \return devuelve un entero
 *
 */

int imprimirmarcayprecio(int);

/** \brief A una lista de tipo de dato esctructurado eAutoi cambia la variable estado de 1 a 0 de esta forma indica una baja,
* y relaciona la variable idUsuario la lista eUsuario e imprime el nombre de usuario. llama a la funcion AltaEgreso
* y le pasa parametros
*
* \param tipo de dato eAutoe Array 1
* \param tipo de dato eAutoi Array 2
* \param tipo de dato eAutoi Array 3
* \param entero tamaño Array 1 y 2
* \param entero tamaño Array 2
* \return
*
*/

void EgresoAuto(eAutoe [], eAutoi [], eUsuario [], int , int );

/** \brief A una lista de tipo de dato esctructurado eAutoi busca a partir de un dato ingresado entre las valores de id
 y devuelve un entero que corresponde subindice del array cuyo dato ingresado coincide con el id
*
* \param tipo de dato eAutoi Array
* \param entero tamaño Array
* \param entero ingresado
* \return entero (-1 si no encuentra el valor)
*
*/

int buscarAiporid(eAutoi [],int ,int );

/** \brief imprime y guarda valores y calcula y devuelve el un valor (importe total) cuando se realiza un cambio de estado
* para un usuario identificado con idUsuario de array tipo de dato estructurado eUsuario que posee una variable estado que pasa
*de 1 a 0 cuando se  indica su baja
 *
 * \param entero
 * \param
 * \return flotante (total de los importes)
 *
 */


float calculadorDeuda(eAutoe [], eAutoi [],int ,int );

/** \brief A una lista de tipo de dato esctructurado eAutoe en el indice valores el primer valor donde la variable marca sea igual a cero
* y devuelve el subindice
*
* \param tipo de dato eAutoe Array
* \param entero tamaño Array
* \return entero (-1 si no encuentra el valor)
*
*/

int buscarAutoEgresadoLibre(eAutoe [],int );

/** \brief leer un numero entero ingresado comprendido entre el minimo valor y el maximo valor

 * \param minimo valor
 * \param maximo valor
 * \return un entrero
 *
 */

int IngresarOpcionMenu(int, int);

/** \brief valida un numero entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero validado
 *
 */

int validarOpcionMenu (int, int, int);

/** \brief lee una lista tipo de datos eUsuario
 *
 * \param tamanno de la lista
 *
 */

void AltaUsuario(eUsuario [], int);


/** \brief A una lista de tipo de dato esctructurado eUsuario busca a partir de un dato ingresado entre las valores de id
 y devuelve un entero que corresponde subindice del array cuyo dato ingresado coincide con el id
*
* \param tipo de dato eUsuario Array
* \param entero tamaño Array
* \param entero ingresado
* \return entero (-1 si no encuentra el valor)
*
*/

int buscarUsuarioLibre(eUsuario [],int);

/** \brief Modifica una lista tipo de datos eUsuario y Ingresando por ID usuario
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \return
  *
  */

void ModificacionUsuario(eUsuario [],int);


/** \brief lee una lista tipo de datos eUsuario y traer en primer
* subindice la la lista de usuarios que no teien valores cargados
* \param array tipo de dato eUsuario
* \param tamanno de la lista

* \return
*
*/


int buscarUsuario(eUsuario [],int ,int );

/** \brief A una lista de tipo de dato esctructurado eAutoi busca a partir de un dato ingresado entre las valores de id
 y devuelve un entero que corresponde subindice del array cuyo dato ingresado coincide con el id
*
* \param tipo de dato eAutoi Array
* \param entero tamaño Array
* \param entero ingresado
* \return entero (-1 si no encuentra el valor)
*
*/

int buscarAi(eAutoi [],int ,int );

/** \brief  Cambio de estado  para un usuario identificado con idUsuario de
* array tipo de dato estructurado eUsuario que posee una variable estado que pasa
* de 1 a 0 cuando se  indica su baja
*
* \param tipo de dato eAutoi Array
* \param entero tamaño Array
* \param entero ingresado
*
*/

void BajaUsuario(eUsuario [], eAutoi [], eAutoe [], int, int);

/** \brief Muestra una lista tipo de datos eUsuario
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista

  * \return
  *
  */

void mostrarListaUsuarios(eUsuario [],int );

/** \brief Muestra una lista tipo de datos eUsuario cuya variable estado sea = 0
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista

  * \return
  *
  */

void mostrarListaUsuariosInactivos(eUsuario [],int );

/** \brief Genera una lista tipo de datos eUsuario para realizar pruebas
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \return
  *
  */



void cargarDatosHardCodePersona(eUsuario []);


/** \brief Requiere que el usuario este registradro previemente
* lee de lista tipo de datos eUsuario, ingresando por ID y
* Y luego se ingresa valores en una lista en un tipo de datos eAuto
  * \param array tipo de dato eUsuario
  * \param array tipo de dato eAuto
  * \param tamanno de la lista

  * \return
  *
  */

void AltaAuto(eAutoi [], eUsuario [], int , int );

/** \brief lee una lista tipo de datos eAutoi y traer en primer
* subindice la la lista de usuarios que no teien valores cargados
  * \param array tipo de dato eAutoi
  * \param tamanno de la lista

  * \return
  *
  */



int buscarAutoLibre(eAutoi [],int );

/** \brief Genera una lista tipo de datos eAutoi para realizar pruebas
  * \param array tipo de dato eAutoi
  * \param tamanno de la lista
  * \return
  *
  */

void cargarDatosHardCodeAutoi(eAutoi []);

/** \brief Genera una lista tipo de datos eAutoe para realizar pruebas
  * \param array tipo de dato eAutoe
  * \param tamanno de la lista
  * \return
  *
  */




void cargarDatosHardCodeAutoe(eAutoe lista[]);

 /** \brief imprime lista tipo de datos eAuto y Ingresando por ID usuario
  * \param array tipo de dato eAuto
  * \param tamanno de la lista
  * \param El id del usuario

  * \return
  *
  */
void mostrarListaAutos(eAutoi [],int );


 /** \brief imprime un strng a partir de una parametro entero

  * \param entero

  * \return
  *
  */

void imprimirmarca(int );

 /** \brief imprime un entero total de la sumatoria de valores de la variable importe de una lista
 de datos estructurados eAutoe

  * \param lista eAutoe
  * \param entero tamaño de la lista


  * \return
  *
  */


void recaudacionTotal(eAutoe vec[],int );

 /** \brief imprime un entero total de la sumatoria de valores de la variable importe de una lista
 * de datos estructurados eAutoe para cada tipo de marca

  * \param lista eAutoe
  * \param entero tamaño de la lista
  * \return
  *
  */


void recaudacionMarca(eAutoe vec[],int );


 /** \brief lee un entero id y busca en la lista de propietarios eUsuarios y en una lista de autos ingresados imprime en pantalla
  * valores de dichas variables

* \param tipo de dato eAutoi Array 1
* \param tipo de dato eAutoi Array 2
* \param entero tamaño Array 1
* \param entero tamaño Array 2
* \return
*
*/


void DatosUsuario(eUsuario [], eAutoi [],int , int );

 /** \brief imprime un entero total de la sumatoria de valores de la variable importe de una lista
 * de datos estructurados eAutoe cuando la marca = 3 AUDI
  * \param lista eUsuario
  * \param lista eAutoe
  * \param entero tamaño de la lista propietarios
  * \param entero tamaño de la lista autos egresados
  * \return
  *
  */

void propietariosAudi(eUsuario [], eAutoi [],int , int );

 /** \brief imprime un entero total de la sumatoria de valores de la variable importe de una lista
 * de datos estructurados eAutoe
  * \param lista eUsuario
  * \param lista eAutoe
  * \param entero tamaño de la lista propietarios
  * \param entero tamaño de la lista autos egresados
  * \return
  *
  */

void autosEstacionados(eAutoi [], eUsuario [],int , int );

 /** \brief iordena alfabeticamente por valores varaible patente de un array de tipo de datos estrcturado eUsuarioAuto
  * \param lista eUsuarioAuto
  * \param entero tamaño de la lista
  * \return
  *
  */

void ordenarListadoUsuarioAuto(eUsuarioAuto [], int);
/** \brief imprime en pantalla  alfabeticamente  array de tipo de datos estrcturado eUsuarioAuto
  * \param lista eUsuarioAuto
  * \param entero tamaño de la lista
  * \return
  *
  */

void imprimirListadoUsuarioAuto (eUsuarioAuto [], int );

/** \brief cargo a una lista de un tipo de datos eAutoe (marca e importe) los parametros determinados
  * \param array tipo de dato eAutoe
  * \param tamanno de la lista
  * \param entero marca
  * \param flotante importe

  * \return
  *
  */

void AltaEgreso(eAutoe [], int, int, float );

/** \brief imprime en pantalla  array de tipo de datos estrcturado eAutoe
  * \param lista eAutoe
  * \param entero tamaño de la lista
  * \return
  *
  */

void ListadoAutosEgresados(eAutoe vec[],int );

#endif
