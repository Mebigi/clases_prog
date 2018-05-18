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
    int idAuto;
    char producto[15];
    float precio;
    int cantidad_vendida;
    int stock;
    int estado;
    int idUsuario;

}eAuto;


int devolverHorasEstadia();

int imprimirmarcayprecio(int);

int buscarAemarca(eAutoe vec[],int tam,int marca);

int buscarAimarca(eAutoi vec[],int tam,int marca);

void EgresoAuto(eAutoe [], eAutoi [], eUsuario [], int , int );

int buscarAiporid(eAutoi [],int ,int );


float calculadorDeuda(eAutoi [],int ,int );

int buscarAutoEgresadoLibre(eAutoe [],int );

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

int buscarAi(eAutoi [],int ,int );


 /** \brief Baja en una lista tipo de datos eUsuario el ID usuario ingresando
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista

  * \return
  *
  */

void BajaUsuario(eUsuario [], eAutoi [], int, int);
/** \brief Muestra una lista tipo de datos eUsuario
  * \param array tipo de dato eUsuario
    * \param array tipo de dato eAutoi
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
* Y luego se ingresa valores en una lista en un tipo de datos eAuto
  * \param array tipo de dato eUsuario
  * \param array tipo de dato eAuto
  * \param tamanno de la lista

  * \return
  *
  */

void AltaAuto(eAutoi [], eUsuario [], int , int );


 /** \brief Busca en una lista tipo de datos eAuto y Ingresando por ID usuario
  * \param array tipo de dato eAuto
  * \param El id del usuario

  * \return
  *
  */


int buscarAutoLibre(eAutoi [],int );



/** \brief Genera una lista tipo de datos eAuto para realizar pruebas
  * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \return
  *
  */

void cargarDatosHardCodeAutoi(eAutoi []);

 /** \brief imprime lista tipo de datos eAuto y Ingresando por ID usuario
  * \param array tipo de dato eAuto
 * \param array tipo de dato eUsuario
  * \param tamanno de la lista
  * \param El id del usuario

  * \return
  *
  */


void cargarDatosHardCodeAutoe(eAutoe lista[]);




void mostrarAutosUsuario(eAuto [],eUsuario [],int , int );


int buscarAuto(eAuto [],int ,int );

void comprarAuto(eAuto [],eUsuario [],int , int );


void modificarAuto(eAuto [],eUsuario [],int , int );

void cancelarAuto(eAuto [],eUsuario [],int , int );

void mostrarListaAutos(eAutoi [],int );

void imprimirmarca(int );

void recaudacionTotal(eAutoe vec[],int );

void recaudacionMarca(eAutoe vec[],int );

void DatosUsuario(eUsuario [], eAutoi [],int , int );

void propietariosAudi(eUsuario [], eAutoi [],int , int );


#endif
