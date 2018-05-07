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




/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int IngresarOpcionMenu(int, int);

int validarOpcionMenu (int, int, int);


//

void AltaUsuario(eUsuario [], int);


int buscarUsuarioLibre(eUsuario [],int);


//

void ModificacionUsuario(eUsuario [],int);

int buscarUsuario(eUsuario [],int ,int );


//

void BajaUsuario(eUsuario [], int );

void mostrarListaUsuarios(eUsuario [],int );


//




//
void cargarDatosHardCodePersona(eUsuario []);


//Requiere un alta de usuario previo

void AltaPorducto(eProducto [], eUsuario [], int , int );

int buscarProductoLibre(eProducto [],int );



///

void cargarDatosHardCodeProductos(eProducto []);


void mostrarListaProductos(eProducto [],eUsuario [],int , int );


void mostrarProductosUsuario(eProducto [],eUsuario [],int , int );


int buscarProducto(eProducto [],int ,int );

void comprarProducto(eProducto [],eUsuario [],int , int );


void modificarProducto(eProducto [],eUsuario [],int , int );

void cancelarProducto(eProducto [],eUsuario [],int , int );


#endif
