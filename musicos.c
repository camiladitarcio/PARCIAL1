
#include <string.h>
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musicos.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musicos Array of musicos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musicos_Inicializar(Musicos array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief  Inicializa musicos con datos hardcodeados
* \param array musicos Array of musicos
* \param size int Array length
* \return void
*
*/
void inicializarMusicosConDatos(Musicos array[], int size)
{

    int idUnico[6] = {1,2,3,4,5,6};
    char nombre[6][TEXT_SIZE] = {"Mus1","Mus2","Mus3","Mus4","Mus5","Mus6"};
    char apellido[6][TEXT_SIZE] = {"Amus1","Amus2","Amus3","Amus4","Amus5","Amus6"};
    int edad[6] = {30,20,25,27,22,35};
    char orquesta[6][TEXT_SIZE] = {"Sinfonica","Filarmonica","Camara","Camara","Sinfonica","Camara"};
    int idOrquesta[6] = {1,2,4,4,1,3};
    int idInstrumento[6] = {2,5,2,1,3,4};
    char instrumento[6][TEXT_SIZE] = {"Viento-madera","Percusion","Viento-madera","Cuerdas","Viento-madera","Viento-metal"};

    int i;
    for (i=0; i<6; i++)
    {
        array[i].isEmpty = 0;
        array[i].idUnico = idUnico[i];
        strncpy(array[i].nombre,nombre[i],(sizeof(nombre)));
        strncpy(array[i].apellido,apellido[i],(sizeof(apellido)));
        strncpy(array[i].orquesta,orquesta[i],(sizeof(orquesta)));
        strncpy(array[i].instrumento,instrumento[i],(sizeof(instrumento)));
        array[i].edad = edad[i];
        array[i].idOrquesta = idOrquesta[i];
        array[i].idInstrumento = idInstrumento[i];
    }

    for(i=6;i<size;i++)
    {
        array[i].isEmpty = 1;
    }
}

/** \brief Busca el primer lugar vacio en un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musicos_buscarEmpty(Musicos array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarInt(Musicos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarString(Musicos array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musicos_alta(Musicos array[], int size, int* contadorID,
                Orquesta *pOrquesta, int cantOrq,Instrumentos *pInstrumentos, int cantInstrumentos)
{
    int retorno=-1;
    int posicion;
    int idInstrumento;
    int idOrquesta;
    int i;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musicos_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre: ","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getName("\nIngrese apellido: ","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getSignedInt("\nIngrese edad: ","\n-- ERROR --",1,sizeof(int),1,100,1,&array[posicion].edad);

            utn_getSignedInt("\nIngrese ID de orquesta en la que toca: ","\n-- ERROR --",1,sizeof(int),1,cantOrq,1,&idOrquesta);
            for(i=0;i<cantOrq;i++)
            {
                if(idOrquesta==pOrquesta[i].idUnico)
                {
                    if(pOrquesta[i].isEmpty==0)
                    {
                       switch(pOrquesta[i].tipo)
                       {
                            case 1:
                            strcpy(array[posicion].orquesta,"Sinfonica");
                            break;
                            case 2:
                            strcpy(array[posicion].orquesta,"Filarmonica");
                            break;
                            case 3:
                            strcpy(array[posicion].orquesta,"Camara");
                            break;
                       }
                    }
                }
            }//for orq

            utn_getSignedInt("\nIngrese ID de Instrumento que toca: ","\n-- ERROR --",1,sizeof(int),1,cantInstrumentos,1,&idInstrumento);
            for(i=0;i<cantInstrumentos;i++)
            {
                if(idInstrumento==pInstrumentos[i].idUnico)
                {
                    if(pInstrumentos[i].isEmpty==0)
                    {
                       switch(pInstrumentos[i].tipo)
                       {
                            case 1:
                            strcpy(array[posicion].instrumento,"Cuerdas");
                            break;
                            case 2:
                            strcpy(array[posicion].instrumento,"Viento Madera");
                            break;
                            case 3:
                            strcpy(array[posicion].instrumento,"Viento Metal");
                            break;
                            case 4:
                            strcpy(array[posicion].instrumento,"Percusion");
                            break;
                       }
                    }
                }
            }//for inst
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s \n Edad: %d\n Orquesta: %s\n Instrumento: %s\n",
                    posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,
                    array[posicion].edad,array[posicion].orquesta,array[posicion].instrumento);
            retorno=0;
            }

        }

    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_baja(Musicos array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musicos_modificar(Musicos array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int auxEdad;
    int auxOrquesta;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
            printf("\n Posicion: %d / ID: %d / Nombre: %s / Apellido: %s / Edad: %d / ID Orquesta: %d / ID Instrumento: %d /",
                posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,
                array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);

                utn_getChar("\nModificar: A (EDAD) - B (ID ORQUESTA) - S (salir)","\n-- ERROR --",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getSignedInt("\nIngrese nueva edad: ","\n-- ERROR --",1,sizeof(int),1,2,1,&auxEdad);
                        array[posicion].edad = auxEdad;
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIngrese nuevo ID de Orquesta: ","\n-- ERROR --",1,sizeof(float),0,1,1,&auxOrquesta);
                        array[posicion].idOrquesta = auxOrquesta;
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
/*
int musicos_ordenarPorString(Musicos array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo apellido

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].edad;                                //cambiar campo edad
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].apellido);          //cambiar campo apellido


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].edad
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edad=array[j].edad;                        //cambiar campo edad
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].apellido,array[j].apellido);  //cambiar campo apellido

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString);                     //cambiar campo nombre
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edad=bufferInt;                                                        //cambiar campo edad
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].apellido,bufferLongString);                                  //cambiar campo apellido
        }
        retorno=0;
    }
    return retorno;
}
*/

/** \brief Lista los elementos de un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musicos_listar(Musicos array[], int size,
                   Orquesta *pOrquesta,
                   Instrumentos *pInstrumentos)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                {
                continue;
                }

            printf("\n ID: %d\t Nombre: %s\t Apellido: %s \t Edad: %d\t Orquesta: %s\t Instrumento: %s",
                    array[i].idUnico,array[i].nombre,array[i].apellido,
                    array[i].edad,array[i].orquesta,array[i].instrumento);
        }
        retorno=0;
    }
    return retorno;
}
