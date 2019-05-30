#include <stdio.h>
#include <stdlib.h>
#include "musicos.h"
#include "orquesta.h"
#include "instrumentos.h"
#include "utn.h"
#include "informes.h"
#define QTY_MUSICOS 20
#define QTY_ORQUESTAS 20
#define QTY_INSTRUMENTOS 20

int main()
{

    int opcionABM;
    int opcionMenu;
    char opcionInforme;
    Musicos arrayMusicos[QTY_MUSICOS];
    Orquesta arrayOrquesta[QTY_ORQUESTAS];
    Instrumentos arrayInstrumentos[QTY_INSTRUMENTOS];
    //int contadorIdOrquesta=0;
    //int contadorIdMusicos=0;
    //int contadorIdInstrumentos=0;
    int contadorIdOrquesta=4;
    int contadorIdMusicos=6;
    int contadorIdInstrumentos=5;

    //musicos_Inicializar(arrayMusicos,QTY_MUSICOS);
    //orquesta_Inicializar(arrayOrquesta,QTY_ORQUESTAS);
    //instrumentos_Inicializar(arrayInstrumentos,QTY_INSTRUMENTOS);
    inicializarOrquestaConDatos(arrayOrquesta,QTY_ORQUESTAS);
    inicializarMusicosConDatos(arrayMusicos,QTY_MUSICOS);
    inicializarInstrumentosConDatos(arrayInstrumentos,QTY_INSTRUMENTOS);

    do {
             utn_getUnsignedInt("\n\n1)ABM \n2)Informes \n3)Salir","\n-- ERROR --",1,sizeof(int),1,3,1,&opcionMenu);
         switch(opcionMenu)
         {
        case 1:
            do
            {
                // MENU ABM
                utn_getUnsignedInt("\n\n1)Agregar Orquestas \n2)Eliminar Orquestas \n3)Imprimir Orquestas"
                                    "\n4)Agregar Musico \n5)Modificar Musico \n6)Eliminar Musico \n7)Imprimir Musicos"
                                    "\n8)Agregar Instrumentos \n9)Imprimir Instrumentos\n10)SALIR de ABM\n",
                                    "\n-- ERROR --",1,sizeof(int),1,7,1,&opcionABM);
                switch(opcionABM)
                {
                    case 1: //Alta Orquesta
                        orquesta_alta(arrayOrquesta,QTY_ORQUESTAS,&contadorIdOrquesta);
                        break;
                    case 2: //Eliminar Orquesta
                        orquesta_baja(arrayOrquesta,QTY_ORQUESTAS);
                        break;
                    case 3: //Imprimir Orquesta
                        orquesta_listar(arrayOrquesta,QTY_ORQUESTAS);
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
                    case 9://Listar Instrumentos
                        instrumentos_listar(arrayInstrumentos,contadorIdInstrumentos);
                        break;
                    case 10://Salir
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }
            while(opcionABM!=10);
        break;

        case 2:
            do
            {
                // MENU INFORMES
                utn_getChar("\n\nA)Listar orquestas con mas de 5 musicos \nB)Listar musicos mayores a 30 años \nC)Listar orquesta segun lugar ingresado"
                                    "\nD)Listar orquestas completas \nE)Listar musicos segun ID de orquesta \nF)Listar orquesta con mas musicos \n"
                                    "G)Listar musicos que toquen cuerdas\nH)Listar promedio de musicos por orquesta\nJ)SALIR de INFORMES\n",
                                    "\n-- ERROR --",1,2,2,&opcionInforme);
                switch(opcionInforme)
                {
                    case 'A':
                         Informes_orquestaMasCincoMusicos(arrayMusicos,QTY_MUSICOS,arrayOrquesta);
                        break;
                    case 'B':
                        Informes_musicosMayoraEdad(arrayMusicos,QTY_MUSICOS,arrayOrquesta,QTY_ORQUESTAS,arrayInstrumentos,QTY_INSTRUMENTOS);
                        break;
                    case 'C':
                         Informes_orquestaPorLugar(arrayOrquesta,QTY_ORQUESTAS);
                        break;
                    case 'D':
                         Informes_orquestaCompleta(arrayMusicos,QTY_MUSICOS,arrayOrquesta,QTY_ORQUESTAS,arrayInstrumentos,QTY_INSTRUMENTOS);
                        break;
                    case 'E':
                        Informes_musicosPorIdOrquesta(arrayMusicos,QTY_MUSICOS,arrayInstrumentos,QTY_INSTRUMENTOS);
                        break;
                    case 'F':
                        Informes_orquestasConMasMusicos(arrayMusicos,QTY_MUSICOS,arrayOrquesta);
                        break;
                    case 'G':
                        Informes_musicosPorInstrumentoCuerdas(arrayMusicos,QTY_MUSICOS,arrayInstrumentos,QTY_INSTRUMENTOS);
                        break;
                    case 'H':
                        Informes_promedioMusicos(arrayOrquesta,QTY_ORQUESTAS,arrayMusicos);
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcionInforme!='J');
        break;

                    default:
                        printf("\nOpcion no valida");
        }

    }while(opcionMenu!=3);

    return 0;
}
