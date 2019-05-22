#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED
#define TEXT_SIZE 20
#include "utn.h"
#include "instrumentos.h"
#include "orquesta.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;
    char orquesta[TEXT_SIZE];
    char instrumento[TEXT_SIZE];

}Musicos;


#endif // FANTASMA_H_INCLUDED

int musicos_Inicializar(Musicos array[], int size);
void inicializarMusicosConDatos(Musicos array[], int size, int* contadorID);                              //cambiar musicos
int musicos_buscarEmpty(Musicos array[], int size, int* posicion);                    //cambiar musicos
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar musicos
int musicos_buscarInt(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar musicos
int musicos_buscarString(Musicos array[], int size, char* valorBuscado, int* indice);                    //cambiar musicos
int musicos_alta(Musicos array[], int size, int* contadorID,Orquesta *pOrquesta, int cantOrq,Instrumentos *pInstrumentos, int cantInstrumentos);                      //cambiar musicos
int musicos_baja(Musicos array[], int sizeArray);                                      //cambiar musicos
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado);
int musicos_modificar(Musicos array[], int sizeArray);                                //cambiar musicos
int musicos_ordenarPorString(Musicos array[],int size);                              //cambiar musicos
int musicos_listar(Musicos array[], int size,
                   Orquesta *pOrquesta,
                   Instrumentos *pInstrumentos);                 //cambiar musicos


