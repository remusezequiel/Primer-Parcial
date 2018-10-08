#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "director.h"
#include "funcionesvarias.h"


#define VACIO 0   //baja
#define OCUPADO 1 //alta

int inicializarDirector(sDirector* array, int size)
{
    int retorno = 0, i; /// Valor que retorna si esta todo mal
    if(array != NULL && size>0)
    {
        retorno = 1;
        for (i=0; i<size; i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

int traerIndexVacio(sDirector* array,int size)
{
    int retorno = -1, i;
    if(array != NULL && size>0)
    {
        for (i=0; i<size; i++)
        {
            if (array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int altaDirector(sDirector* array, int size)
{
    sDirector auxDirector;
    int retorno = 0;
    int indice = traerIndexVacio(array, size);
    int i;
    if (indice>-1)
    {
        do//Nombre del director
        {
            getLimitedString("Ingrese el nombre del Director: \n",
                             "ERROR!.Limite de caracteres",
                              auxDirector.nombre,DIR_LEN);
            for(i=0;i<size;i++)
            {
                if(strcmp((array+i)->nombre,auxDirector.nombre)==0 )//No puede haber directores iguales
                {
                    printf("ERROR!.Este Nombre ya fue ingresado!");
                    continue;

                }

            }
        } while (strlen(auxDirector.nombre) == 0);
        do
        {
            getValidInt("Ingrese el dia de nacimiento: \n",
                        "ERROR!. El caracter ingresado no es un numero! \n",
                        " ERROR!. El rango va Anio va desde : 1 a 31 \n",
                        &auxDirector.nacimiento.dia,1,31);

        }while(&auxDirector.nacimiento.dia==NULL);
        do
        {
            getValidInt("Ingrese el mes de nacimiento: \n",
                        "ERROR!. El caracter ingresado no es un numero! \n",
                        " ERROR!. El rango va Anio va desde : 1 a 12 \n",
                        &auxDirector.nacimiento.mes,1,12);
        }while(&auxDirector.nacimiento.mes==NULL);
        do
        {
            getValidInt("Ingrese el anio de nacimiento: \n",
                        "ERROR!. El caracter ingresado no es un numero! \n",
                        " ERROR!. El rango va Anio va desde : 1862 a 2000 \n",
                        &auxDirector.nacimiento.anio,1862,2000);
        }while(&auxDirector.nacimiento.anio==NULL);
        do
        {
            getLimitedString("Ingrese la pais de origen del director: \n",
                             "ERROR!. Limite maximo de caracteres \n",
                           auxDirector.paisDeOrigen,DIR_LEN);
           /* getValidString("Ingrese la pais de origen del director: \n",
                           "ERROR!. Ingrese solo letras \n",
                           "ERROR!. Limite maximo de caracteres \n",
                           auxDirector.paisDeOrigen,DIR_LEN);*/
        } while(strlen(auxDirector.paisDeOrigen) == 0);

        /// IMPORTANT
        auxDirector.idDirector = generarNextId();
        auxDirector.isEmpty = 0;
        array[indice] = auxDirector;
        /// IMPORTANT ^^
        lineaPunteada();
        puts("Alta realizada satisfactoriamente\n");
        lineaPunteada();
        retorno = 1;
    }
    else
    {
        printf("No HAY ESPACIO!\n");
    }
    return retorno;
}

int getByIdDirector(sDirector* array, int size, int idABuscar)
{
    int retorno = -1, i;

    if(array != NULL && size>0)
    {
        for (i=0; i<size; i++)
        {
            if (array[i].idDirector == idABuscar)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int bajaDirector(sDirector* array,int size,int id)
{
    int retorno = -1;
    int indice;
    int respuesta;

    if(size > 0 && array != NULL)
    {
        retorno = -2;
        indice = getByIdDirector(array,size,id);//busco por id. Tomo el valor del ide en la variable indice.

        if(indice >= 0)//si el indice es valido
        {
            respuesta=getAnswer("Desea realmente realizar la baja?(s/n) \n","ERROR DE TIPEO!.\n",'s','n');
            if(respuesta==1)
            {
                array[indice].isEmpty = VACIO;//se da baja al elemento del array correspondiente al indice
                printf("La baja se realizo satisfactoriamente\n");
                retorno = 1;
            }
		}
        else
        {
            printf("No se encontro el Id \n");//sino, informa que no se a encontrado el indice
        }
	}

    return retorno;
}

void mostrarUnTipo_sDirector(sDirector director)
{
    printf("_________________________________________________\n");
    printf("%6d",director.idDirector);
    printf(" %10s",director.nombre);
    printf(" %15d/ %d/ %d",director.nacimiento.dia, director.nacimiento.mes, director.nacimiento.anio);
    printf(" %15s \n",director.paisDeOrigen);
}

int mostrarListaTipo_sDirector(sDirector* array, int size)
{
    int retorno;
    int i;
    retorno = 0;

    printf("LISTA DE PELICULAS: \n");
    printf("__________________________________________________________________\n");
    printf(" ID \t NOMBRE \t NACIMIENTO \t PAIS DE ORIGEN \n");
    if(size > 0 && array != NULL)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty == 0)
            {
                mostrarUnTipo_sDirector(array[i]);
                retorno=1;
            }
        }
    }
        printf("__________________________________________________________________\n");
    return retorno;
}

















