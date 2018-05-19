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


int devolverHorasEstadia();

int imprimirmarcayprecio(int);

void EgresoAuto(eAutoe [], eAutoi [], eUsuario [], int , int );

int buscarAiporid(eAutoi [],int ,int );

float calculadorDeuda(eAutoe [], eAutoi [],int ,int );

int buscarAutoEgresadoLibre(eAutoe [],int );

int IngresarOpcionMenu(int, int);

int validarOpcionMenu (int, int, int);

void AltaUsuario(eUsuario [], int);

int buscarUsuarioLibre(eUsuario [],int);

void ModificacionUsuario(eUsuario [],int);

int buscarUsuario(eUsuario [],int ,int );

int buscarAi(eAutoi [],int ,int );

void BajaUsuario(eUsuario [], eAutoi [], eAutoe [], int, int);

void mostrarListaUsuarios(eUsuario [],int );
void mostrarListaUsuariosInactivos(eUsuario [],int );

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

int buscarAutoLibre(eAutoi [],int );

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

void mostrarListaAutos(eAutoi [],int );


void imprimirmarca(int );

void recaudacionTotal(eAutoe vec[],int );

void recaudacionMarca(eAutoe vec[],int );

void DatosUsuario(eUsuario [], eAutoi [],int , int );

void propietariosAudi(eUsuario [], eAutoi [],int , int );

void autosEstacionados(eAutoi [], eUsuario [],int , int );

void ordenarListadoUsuarioAuto(eUsuarioAuto [], int);

void imprimirListadoUsuarioAuto (eUsuarioAuto [], int );

void AltaEgreso(eAutoe [], int, int, float );

void ListadoAutosEgresados(eAutoe vec[],int );

#endif
