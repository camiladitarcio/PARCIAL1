
#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED

#define TEXT_SIZE 20
#include "utn.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
    char tipoNombre[TEXT_SIZE];

}Instrumentos;

// 1 cuerdas
// 2 viento-madera
// 3 viento-metal
// 4 percusion

#endif // FANTASMA_H_INCLUDED

void inicializarInstrumentosConDatos(Instrumentos array[], int size);
int instrumentos_Inicializar(Instrumentos array[], int size);                                    //cambiar instrumentos
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarInt(Instrumentos array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarString(Instrumentos array[], int size, char* valorBuscado, int* indice);                    //cambiar instrumentos
int instrumentos_alta(Instrumentos array[], int size, int* contadorID);                          //cambiar instrumentos
int instrumentos_baja(Instrumentos array[], int sizeArray);                                      //cambiar instrumentos
int instrumentos_bajaValorRepetidoInt(Instrumentos array[], int sizeArray, int valorBuscado);
int instrumentos_modificar(Instrumentos array[], int sizeArray);                                //cambiar instrumentos
int instrumentos_ordenarPorString(Instrumentos array[],int size);                              //cambiar instrumentos
int instrumentos_listar(Instrumentos array[], int size);
int Instrumentos_tipoInstrumentoPorId(Instrumentos array[], int size, int idPosicion);              //cambiar instrumentos



