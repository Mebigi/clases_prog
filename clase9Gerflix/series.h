#ifndef SERIES_H_INCLUDED
#define SERIES_H_INCLUDED


#define TAM 4
#define LONG 25

typedef struct
{
int idSerie;
char nombre[LONG];
int canttemporadas;
int aniolanzamiento;
int estado;
} eSerie;

int IngresarOpcionMenu(int, int);
int validarOpcionMenu(int, int, int);
void menuSerie(eSerie [], int);
int buscarLibre(eSerie [],int);
int buscarSerie(eSerie [],int, int);
void cargarDatosHardCode(eSerie []);



#endif // FUNCIONES_H_INCLUDED
