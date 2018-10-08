#ifndef SDIRECTOR_H_INCLUDED
#define SDIRECTOR_H_INCLUDED

#include "date.h"

#define DIR_LEN 51

typedef struct
{
    int idDirector;
    char nombre[DIR_LEN];
    sFecha nacimiento;
    char paisDeOrigen[DIR_LEN];
    int isEmpty;

}sDirector;
#endif // SDIRECTOR_H_INCLUDED

//////////////////////////PROTOTIPOS///////////////////////////////

int inicializarDirector(sDirector* , int );
int traerIndexVacio(sDirector* ,int );
int altaDirector(sDirector* , int );

int getByIdDirector(sDirector* array, int size, int idABuscar);
int bajaDirector(sDirector* array,int size,int id);

void mostrarUnTipo_sDirector(sDirector director);
int mostrarListaTipo_sDirector(sDirector* array, int size);

void hardcoreoDirector(sDirector* array,int freeIndex,int auxIdDirector ,char* auxNombre,
                        char* auxPaisDeOrigen, int auxIsEmpty);

//////////////////////////////////////////////////////////////////
