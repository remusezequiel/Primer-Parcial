#include "director.h"
#include "date.h"
#define VACIO 1
#define OCUPADO 0

#define CHARLEN 51
#define LEN_HC 10
/********TIPOS DE DATOS**************/
typedef struct
{
    int idPelicula;
    char titulo[CHARLEN];
    int anio;
    char nacionalidad[CHARLEN];
    sDirector director;
    int isEmpty;
}sPelicula;
/************************************/

///////////////////////PROTOTIPOS/////////////////////

int traerIdPeliculaVacio(sPelicula* ,int );
int inicializarPelicula(sPelicula* ,int );
int altaPelicula(sPelicula* , int );
int getById(sPelicula* , int , int );

int mostrarUnTipo_sPelicula(sPelicula );
int mostrarListaTipo_sPelicula(sPelicula* , int );

int baja(sPelicula* , int , int );
int modificacionById(sPelicula* ,int , int );

void hardcodeoPelicula(sPelicula* array,int freeIndex, int auxIdPelicula, char* auxTitulo,
                        int auxAnio, char* auxNacionalidad, int auxDirector, int auxIsEmpty);
////////////////////////////////////////////////////////


