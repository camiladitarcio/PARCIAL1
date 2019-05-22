#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "musicos.h"


int Informes_musicosMayoraEdad(Musicos array[], int size)
{
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0 && array[i].edad>30)
            {
                printf("\nID: %d- Nombre: %s- Apellido: %s- Edad: %d- Instrumento: %s- Orquesta: %s\n",
                array[i].idUnico, array[i].nombre, array[i].apellido, array[i].edad,
                array[i].instrumento, array[i].orquesta);
            }
            else
            {
                continue;
            }
        }
    }

    return 0;
}


int Informes_orquestaPorLugar(Orquesta array[], int size)
{
    int i;
    char strAux[30];

    if(array!=NULL && size>=0)
    {

    if(utn_getAlfanumerico("\nIngrese lugar:(Lugar1-Lugar2-Lugar3-Lugar4)","\n--ERROR--",1,20,2,strAux))
    {
            for(i=0;i<size;i++)
            {
                if(strcmp(array[i].lugar,strAux)==0)
                {
                    printf("\nID: %d- Nombre: %s- Tipo: %d- Lugar: %s\n",
                    array[i].idUnico, array[i].nombre, array[i].tipo, array[i].lugar);
                }
                else
                {
                    continue;
                }
            }
        }
        }

    return 0;
}




