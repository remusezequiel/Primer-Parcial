#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "film.h"
#include "director.h"
#include "funcionesVarias.h"


#define LEN_FILM 100
#define LEN_DIR 20
/******************************COMENTARIOS*************************************************
    1)En la biblioteca "director.h" estan incluidas las funciones que manipulan variables *
    del tipo struct "sDirector" y tambien esta definido un struct "sFecha".               *
    2)En la biblioteca "film.h" estan incluidas las funciones que manipulan variables     *
    del tipo struct "sPelicula".                                                          *
    3)En la biblioteca "funcionesVarias.h" estan definidas las funciones referidas a los  *
    ingresos de datos, validaciones y operaciones matematicas.                            *
*******************************************************************************************/
//FUNCION PRINCIPAL
int main()
{
    system("color 1F");

/*________________________________VARIABLES_______________________________________________*/
    int id;
    int opcion;
    char opcionChar;

    // Tipo struct y se inicializa
    sPelicula pelicula[LEN_FILM];
    inicializarPelicula(pelicula,LEN_FILM);
    //hardcodeoPelicula(pelicula,0,0,"peliUno",1995,"paisUno",5,0);

    // Tipo struct y se inicializa
    sDirector director[LEN_DIR];
    inicializarDirector(director,LEN_DIR);
    //hardcodeoDirector(director,0,1,"dirUno","paisUno",0);
    //ACA IRIA EL HARDCODEO

/*_______________________________________________________________________________________*/
    //MENU DE OPCIONES Y RESTO DEL CODIGO CON RESPECTIVAS LLAMADAS A FUNCIONES
    do
    {
        //MOSTRAR MENU DE OPCIONES
        optionMenu();
        opcion=getOption("Ingrese Una opcion: \n","Ingrese una opcion valida",1,6);
        //PEDIR OPCION
        switch(opcion)
        {
            case 1: // OPCION (1)
                line();
                printf("\t  ALTAS \n");//SE IMPRIME EL TITULO
                line();

                altaPelicula(pelicula,LEN_FILM);//SE LLAMA A LA FUNCION ALTA PELICULA

                break;
            case 2: // OPCION (2)
                //FUNCIONES DE LA OPCION
                printf("\t  MODIFICACIONES\n");//SE IMPRIME EL TITULO
                id=getId(LEN_FILM);//SE LE DA EL VALOR DEL RETORNO DE LA FUNCION INGRESO ID A LA VARIABLE id
                modificacionById(pelicula,LEN_FILM,id);//SE LLAMA A LA FUNCION MODIFICACIONBYID
                break;
            case 3: // OPCION (3)
                //FUNCIONES DE LA OPCION
                line();
                printf("\n \t  BAJA DE PELICULA \n");
                line();
                id=getId(LEN_FILM);
                baja(pelicula,LEN_FILM,id);
                mostrarUnTipo_sPelicula(pelicula[id]);
                printf("\n El estado ahora es: %d \n",pelicula[id].isEmpty);
                line();
                break;
            case 4: // OPCION (4)
                //FUNCIONES DE LA OPCION
                line();
                printf("\t NUEVO DIRECTOR: \n");
                line();
                altaDirector(director,LEN_DIR);
            break;
            case 5: // OPCION (5)
                line();
                printf("ELIMINAR DIRECTOR");
                line();
                id=getId(LEN_DIR);
                bajaDirector(director,LEN_DIR,id);
                mostrarUnTipo_sDirector(director[id]);
                //FUNCIONES DE LA OPCION
                break;
            case 6:// OPCION ()
                //FUNCIONES DE LA OPCION
                line();
                printf("\t  LISTAR \n");//SE IMPRIME EL TITULO
                printf("\t  \t a) Peliculas\n");
                printf("\t  \t b) Directores\n");

                printf("Ingrese una opcion: \n");
                scanf(" %c", &opcionChar);
                if(opcionChar=='a')
                {
                    mostrarListaTipo_sPelicula(pelicula,LEN_FILM);
                }
                else if(opcionChar=='b')
                {
                    mostrarListaTipo_sDirector(director,LEN_DIR);
                    break;
                }

                break;
            default:
                line();
                printf("\n NO ES UNA OPCION VALIDA!!!\n");
                line();

                break;
        }

    }while(opcion != 5);

    return 0;

}

















