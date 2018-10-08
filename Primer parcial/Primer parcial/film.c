#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "film.h"
#include "funcionesVarias.h"



int traerIdPeliculaVacio(sPelicula* array,int size)
{
    int retorno = -1, i;
    if(array != NULL && size>0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int inicializarPelicula(sPelicula* array, int size)
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

int altaPelicula(sPelicula* array, int size)
{
    sPelicula auxPelicula;
    int retorno = 0;
    int indice = traerIdPeliculaVacio(array, size);

    if (indice>-1)
    {
        do//Titulo
        {
            getLimitedString("Ingrese el nombre de la pelicula: \n",
                             "ERROR!.Limite de caracteres 50",
                              auxPelicula.titulo,CHARLEN);
        } while (strlen(auxPelicula.titulo) == 0);
        do//Nacionalidad
        {
            getValidString("Ingrese la nacionalidad de la pelicula: \n",
                           "ERROR!. Ingrese solo letras \n",
                           "ERROR!. Limite maximo de caracteres \n",
                           auxPelicula.nacionalidad,CHARLEN);
        } while(strlen(auxPelicula.nacionalidad) == 0);
        do//Anio
        {

            getValidInt("Ingrese el anio de la pelicula: \n",
                        "ERROR!. El caracter ingresado no es un numero! \n",
                        " ERROR!. El rango va Anio va desde : 1895 a 2018 \n",
                        &auxPelicula.anio,1895,2018);
        }while(&auxPelicula.anio == NULL);
        do//idDirector
        {
            getValidInt("Ingrese el identificador del director: \n",
                        "ERROR!. El caracter ingresado no es un numero! \n",
                         " ERROR!. El rango va Anio va desde : 0 a 499 \n",
                         &auxPelicula.director.idDirector,0,499);
        }while(&auxPelicula.director.idDirector == NULL);


        /// IMPORTANT
        auxPelicula.idPelicula = generarNextId();
        auxPelicula.isEmpty = 0;
        array[indice] = auxPelicula;
        /// IMPORTANT ^^
        puts("Alta realizada satisfactoriamente");
        retorno = 1;
    }
    else
    {
        printf("No HAY ESPACIO!\n");
    }
    system("cls");
    return retorno;
}

int getByIdPelicula(sPelicula* array, int size, int idABuscar)
{
    int retorno = -1, i;

    if(array != NULL && size>0)
    {
        for (i=0; i<size; i++)
        {
            if (array[i].idPelicula == idABuscar)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int mostrarUnTipo_sPelicula(sPelicula pelicula)//EJEMPLO CON UN sPelicula sPelicula
{
    printf("_________________________________________________\n");
    printf("%6s",pelicula.titulo);
    printf(" %10d",pelicula.anio);
    printf(" %15s",pelicula.nacionalidad);
    printf(" %10d",pelicula.director.idDirector);
    printf(" %6d\n",pelicula.idPelicula);
    return 0;
}

int mostrarListaTipo_sPelicula(sPelicula* array, int size)//EJEMPLO CON UN TIPO sPelicula
{
    int retorno;
    int i;
    retorno = -1;

    printf("LISTA DE PELICULAS: \n");
    printf("__________________________________________________________________\n");
    printf(" TITULO \t ANIO \t NACIONALIDAD \t DIRECTOR \n");
    if(size > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty == 0)
            {
                mostrarUnTipo_sPelicula(array[i]);

            }
        }
    }
        printf("__________________________________________________________________\n");

    return retorno;
}

/*******************SEGUNDA PARTE***********************/

int baja(sPelicula* array, int size, int id)//antes debe pedirse el id
{
    int retorno = -1;
    int indice;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        indice = getByIdPelicula(array,size,id);//busco por id. Tomo el valor del ide en la variable indice.

        if(indice >= 0)//si el indice es valido
        {
            array[indice].isEmpty = 1;//se da baja al elemento del array correspondiente al indice
			retorno = 1;

			printf("\n La baja se realizo satisfactoriamente \n");
		}
        else
        {
            printf("\n No se encontro el Id \n");//sino, informa que no se a encontrado el indice
        }
	}

    return retorno;
}

int modificacionById(sPelicula* array,int size, int id)
{
    sPelicula auxPelicula;
    int retorno = -1;
    int indice;
    int opcion;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        indice = getByIdPelicula(array, size, id);

        if(indice >= 0)
        {
            do
            {
                //INTRODUCIR LEER LO QUE DESEAMOS MODIFICAR
                line();
                printf("\t MENU OPCIONES PARA MODIFICAR \n");
                printf("1. TITULO \n");
                printf("2. ANIO \n");
                printf("3. NACIONALIDAD \n");
                printf("4. DIRECTOR \n");
                printf("5. SALIR \n");
                line();
                opcion=getOption("Ingrese Una opcion: \n","Ingrese una opcion valida\n",1,5);
                switch(opcion)
                {
                    case 1:
                        do//Titulo
                        {
                            getLimitedString("Ingrese el nombre de la pelicula: \n",
                                             "ERROR!.Limite de caracteres 50\n",
                                              auxPelicula.titulo,CHARLEN);
                        } while (strlen(auxPelicula.titulo) == 0);
                        retorno=getAnswer("Realmente quiere realizar el cambio? (s/n)\n",
                                  "ERROR DE TIPEO!",'s','n');
                        if(retorno==1)
                        {
                            strcpy(array[indice].titulo, auxPelicula.titulo);//1
                        }
                    break;
                    case 2:
                        do//Anio
                        {

                            getValidInt("Ingrese el anio de la pelicula: \n",
                                        "ERROR!. El caracter ingresado no es un numero! \n",
                                        " ERROR!. El rango va Anio va desde : 1895 a 2018 \n",
                                        &auxPelicula.anio,1895,2018);
                        }while(&auxPelicula.anio == NULL);

                        retorno=getAnswer("Realmente quiere realizar el cambio? (s/n)",
                                  "ERROR DE TIPEO!",'s','n');
                        if(retorno==1)
                        {
                            array[indice].anio=auxPelicula.anio;//2
                        }
                    break;
                    case 3:
                       do//Nacionalidad
                        {
                            getValidString("Ingrese la nacionalidad de la pelicula: \n",
                                           "ERROR!. Ingrese solo letras \n",
                                           "ERROR!. Limite maximo de caracteres \n",
                                           auxPelicula.nacionalidad,CHARLEN);
                        } while(strlen(auxPelicula.nacionalidad) == 0);
                       retorno = getAnswer("Realmente quiere realizar el cambio? (s/n)",
                                             "ERROR DE TIPEO!",'s','n');
                        if(retorno == 1)
                        {
                            strcpy(array[indice].nacionalidad, auxPelicula.nacionalidad);//3
                        }
                    break;
                    case 4:
                        do//idDirector
                        {
                            getValidInt("Ingrese el identificador del director: \n",
                                        "ERROR!. El caracter ingresado no es un numero! \n",
                                         " ERROR!. El rango va Anio va desde : 0 a 499 \n",
                                         &auxPelicula.director.idDirector,0,499);
                        }while(&auxPelicula.director.idDirector == NULL);
                        retorno = getAnswer("Realmente quiere realizar el cambio? (s/n)",
                                  "ERROR DE TIPEO!",'s','n');
                        if(retorno==1)
                        {
                            array[indice].director.idDirector=auxPelicula.director.idDirector;//4
                        }
                    break;
                    case 5:
                    break;
                    default:
                            printf("ERROR!. Ingrese una opcion valida! \n");
                }
            }while(opcion!=5);
        }

    }
    system("cls");
    return retorno;
}


/******************************************************/
/**************HARDCODEO DE DATOS**********************/


void hardcodeoPelicula(sPelicula* array,int freeIndex, int auxIdPelicula, char* auxTitulo,
                        int auxAnio, char* auxNacionalidad, sDirector auxDirector, int auxIsEmpty)
{
    array[freeIndex].idPelicula=auxIdPelicula;
    strcpy(array[freeIndex].titulo,auxTitulo);
    array[freeIndex].anio=auxAnio;
    strcpy(array[freeIndex].nacionalidad,auxNacionalidad);
    array[freeIndex].director.idDirector=auxDirector.idDirector;
    array[freeIndex].isEmpty=auxIsEmpty;
}



