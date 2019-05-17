#include <stdio.h>
#include <stdlib.h>
#include "musicos.h"
#include "orquesta.h"
#include "instrumentos.h"
#include "utn.h"
#define QTY_MUSICOS 1000
#define QTY_ORQUESTAS 50
#define QTY_INSTRUMENTOS 20

int main()
{

    int opcion;
    Musicos arrayMusicos[QTY_MUSICOS];
    Orquesta arrayOrquesta[QTY_ORQUESTAS];
    Instrumentos arrayInstrumentos[QTY_INSTRUMENTOS];
    int contadorIdOrquesta=5;
    int contadorIdMusicos=0;
    int contadorIdInstrumentos=5;

    musicos_Inicializar(arrayMusicos,QTY_MUSICOS);
    inicializarOrquestaConDatos(arrayOrquesta,QTY_ORQUESTAS);
    inicializarInstrumentosConDatos(arrayInstrumentos,QTY_ORQUESTAS);
    do
    {
        utn_getUnsignedInt("\n1)Agregar Orquestas \n2)Eliminar Orquestas \n3)Imprimir Orquestas"
                            "\n4)Agregar Musico \n5)Modificar Musico \n6)Eliminar Musico \n7)Imprimir Musicos"
                            "\n8)Agregar Instrumentos \n9)Imprimir Instrumentos",
                            "\n-- ERROR --",1,sizeof(int),1,7,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta Orquesta
                orquesta_alta(arrayOrquesta,QTY_ORQUESTAS,&contadorIdOrquesta);
                break;

            case 2: //Eliminar Orquesta
                orquesta_baja(arrayOrquesta,QTY_ORQUESTAS);
                break;

            case 3: //Imprimir Orquesta
                orquesta_listar(arrayOrquesta,contadorIdOrquesta);
                break;

            case 4://Agregar Musico
                orquesta_listar(arrayOrquesta,contadorIdOrquesta);
                instrumentos_listar(arrayInstrumentos,contadorIdInstrumentos);
                musicos_alta(arrayMusicos,QTY_MUSICOS,&contadorIdMusicos,arrayOrquesta,contadorIdOrquesta,
                arrayInstrumentos,contadorIdInstrumentos);
                break;

            case 5://Modificar Musicos
                musicos_listar(arrayMusicos,QTY_MUSICOS, arrayOrquesta,arrayInstrumentos);
                musicos_modificar(arrayMusicos,QTY_MUSICOS);
                break;

            case 6://Baja Musicos
                musicos_listar(arrayMusicos,QTY_MUSICOS, arrayOrquesta,arrayInstrumentos);
                musicos_baja(arrayMusicos,QTY_MUSICOS);
                break;

            case 7://Listar Musicos
                musicos_listar(arrayMusicos,QTY_MUSICOS, arrayOrquesta,arrayInstrumentos);
                break;

            case 8://Agregar Instrumento
                instrumentos_alta(arrayInstrumentos,QTY_INSTRUMENTOS,&contadorIdInstrumentos);
                break;

            case 9:
                instrumentos_listar(arrayInstrumentos,contadorIdInstrumentos);
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}

