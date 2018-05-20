#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED


typedef struct {
    int idUsuario;
    char nombre[25];
    char pass[15];
    int calificacion_venta;
    int cantidadventas;
    int estado;

}eUsuario;


typedef struct {
    int idProducto;
    char producto[15];
    float precio;
    int cantidad_vendida;
    int stock;
    int estado;
    int idUsuario;

}eProducto;




/** \brief lee numeros enterros ingresados en opciones de mennu
 *
 * \param minimo valor que puede tener entero
 * \param maximo valor que puede tener entero
 * \return un entero
 *
 */

int IngresarOpcionMenu(int, int);

/** \brief Valida entero ingresados en opciones de mennu
 *
 *
 * \param minimo valor que puede tener entero
 * \param maximo valor que puede tener entero
 * \return un entero
 *
 */



int validarOpcionMenu (int, int, int);

/** \brief lee una lista tipo de datos eUsuario
 *
 * \param tamanno de la lista

 *
 */

void AltaUsuario(eUsuario [], int);



 /** \brief lee una lista tipo de datos eUsuario y traer en primer
* subindice la la lista de usuarios que no teien valores cargados
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista

  * \return
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

 /** \brief Busca en una lista tipo de datos eUsuario y Ingresando por ID usuario
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \param El id del usuario

  * \return
  *
  */

int buscarUsuario(eUsuario [],int ,int );


 /** \brief Baja en una lista tipo de datos eUsuario el ID usuario ingresando
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista

  * \return
  *
  */

void BajaUsuario(eUsuario [], int );

/** \brief Muestra una lista tipo de datos eUsuario
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista

  * \return
  *
  */

void mostrarListaUsuarios(eUsuario [],int );

/** \brief Genera una lista tipo de datos eUsuario para realizar pruebas
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \return
  *
  */


void cargarDatosHardCodePersona(eUsuario []);


/** \brief Requiere que el usuario este registradro previemente
* lee de lista tipo de datos eUsuario, ingresando por ID y
* Y luego se ingresa valores en una lista en un tipo de datos eProducto
  * \param array tipo de dato eUsuario
  * \param array tipo de dato eProducto
  * \param tamanno de la lista

  * \return
  *
  */

void AltaPorducto(eProducto [], eUsuario [], int , int );


 /** \brief Busca en una lista tipo de datos eProducto y Ingresando por ID usuario
  * \param array tipo de dato eProducto
  * \param El id del usuario

  * \return
  *
  */


int buscarProductoLibre(eProducto [],int );



/** \brief Genera una lista tipo de datos eProducto para realizar pruebas
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \return
  *
  */

void cargarDatosHardCodeProductos(eProducto []);

 /** \brief imprime lista tipo de datos eProducto y Ingresando por ID usuario
  * \param array tipo de dato eProducto
 * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \param El id del usuario

  * \return
  *
  */


void mostrarListaProductos(eProducto [],eUsuario [],int , int );


void mostrarProductosUsuario(eProducto [],eUsuario [],int , int );


int buscarProducto(eProducto [],int ,int );

void comprarProducto(eProducto [],eUsuario [],int , int );


void modificarProducto(eProducto [],eUsuario [],int , int );

void cancelarProducto(eProducto [],eUsuario [],int , int );


#endif
