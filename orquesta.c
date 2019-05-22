#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int orquesta_Inicializar(Orquesta array[], int size)                                    //cambiar orquesta
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
// inicializar hardcodeo

void inicializarOrquestaConDatos(Orquesta array[], int size, int* contadorID)
{
    char nombre[4][TEXT_SIZE] = {"Orquesta1","Orquesta2","Orquesta3","Orquesta4"};
    char lugar[4][TEXT_SIZE] = {"Lugar1","Lugar2","Lugar3","Lugar4"};
    int tipo[4] = {1,2,3,3};
    int i;
    for (i=0; i<4; i++)
    {
        (*contadorID)++;
        array[i].isEmpty = 0;
        array[i].idUnico = *contadorID;
        strncpy(array[i].nombre,nombre[i],(sizeof(nombre)));
        strncpy(array[i].lugar,lugar[i],(sizeof(lugar)));
        array[i].tipo = tipo[i];
    }

    for(i=4;i<size;i++)
    {
        array[i].isEmpty = 1;
    }
}
//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)                    //cambiar orquesta
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}*/

//String
/** \brief Busca un string en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)                          //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese lugar: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
            utn_getSignedInt("\n1)Sinfonica \t2)Filarmonica \t3)Camara","\nError",1,sizeof(int),1,2,1,&array[posicion].tipo);

            printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: %d ",
                    array[posicion].idUnico,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray)                                      //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
        }
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
/*
int orquesta_modificar(Orquesta array[], int sizeArray)                                //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
            printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: %s ",
                    array[posicion].idUnico,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);

                utn_getChar("\nModificar: A(EDAD) B(ID ORQUESTA) (salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nIngrese nueva edad: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);           //mensaje + cambiar campo edad
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIngrese nuevo ID de Orquesta: ","\nError",1,sizeof(float),0,1,1,&array[posicion].idOrquesta);             //mensaje + cambiar campo varFloat
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
*/
//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
/*
int orquesta_ordenarPorString(Orquesta array[],int size)                              //cambiar orquesta
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo nombre
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
//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        printf("\nORQUESTAS:");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                {
                    continue;
                }

                switch(array[i].tipo)
                {
                case 1:
                strcpy(array[i].tipoNombre,"Sinfonica");
                break;
                case 2:
                strcpy(array[i].tipoNombre,"Filarmonica");
                break;
                case 3:
                strcpy(array[i].tipoNombre,"Camara");
                break;
                }

                    printf("\n ID: %d\t Nombre: %s\t Lugar: %s\t Tipo: %s ",
                    array[i].idUnico,array[i].nombre,array[i].lugar,array[i].tipoNombre);    //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

