#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

#include "series.h"


typedef struct
{
int idUsuario;
char email[25];
char Password[25];
int idSerie;
int estado;
} eUsuario;


void menuUsuario(eUsuario [], eSerie [], int tam);
int buscarUsuario(eUsuario [],int,int);
int buscarUsuarioLibre(eUsuario [],int);


#endif // FUNCIONES_H_INCLUDED
