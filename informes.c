#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musicos.h"

int Informes_musicosMayoraEdad(Musicos arrayM[], int sizeM, Orquesta arrayO[], int sizeO, Instrumentos arrayI[], int sizeI)
{
    int i;
    int posicionOr;
    int posicionIns;
    int flag;
    if((arrayM!=NULL && sizeM>=0) && (arrayO!=NULL && sizeO>=0))
    {
        printf("\n\n B) -- MUSICOS MAYOR A 30 ANOS --");
        for(i=0;i<sizeM;i++)
        {
            if(arrayM[i].isEmpty==0 && arrayM[i].edad>30)
            {
                orquesta_buscarID(arrayO,sizeO,arrayM[i].idOrquesta,&posicionOr);
                instrumentos_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&posicionIns);
                printf("\nID: %d / Nombre: %s / Apellido: %s / Edad: %d / Instrumento: %s / Orquesta: %s",
                arrayM[i].idUnico, arrayM[i].nombre, arrayM[i].apellido, arrayM[i].edad,
                arrayI[posicionIns].nombre, arrayO[posicionOr].nombre);
                flag = 1;
            }
            else
                {
                    continue;
                }
        }
    }
        if(flag==0)
        {
            printf("No hay musicos mayores a 30 años");
        }
    return 0;
}


int Informes_orquestaPorLugar(Orquesta array[], int size)
{
    int i;
    char strAux[30];
    int reintentos = 2;

    if(array!=NULL && size>=0)
    {
        printf("\n\n C) -- LISTAR ORQUESTAS SEGUN LUGAR --");
        if(getString("\nIngrese lugar:(Lugar1-Lugar2-Lugar3-Lugar4)","\n--ERROR--",1,sizeof(strAux),&reintentos,strAux))
        printf(strAux);
        {
                for(i=0;i<size;i++)
                {
                    if(array[i].isEmpty==1)
                        continue;
                    if(strcmp(array[i].lugar,strAux)==0)
                    {
                        printf("\nID: %d / Nombre: %s / Tipo: %d / Tipo Nombre: %s / Lugar: %s",
                        array[i].idUnico, array[i].nombre, array[i].tipo, array[i].tipoNombre, array[i].lugar);
                    }
                }
            }
        }

    return 0;
}

int Informes_musicosPorIdOrquesta(Musicos arrayM[], int sizeM, Instrumentos arrayI[], int sizeI)
{
    int i;
    int id;
    int flag;
    int posicionIns;
    if(arrayM!=NULL && sizeM>0 && arrayI!=NULL && sizeI>0)
    {
        if(!(utn_getUnsignedInt("\n\nIngrese ID de orquesta:","\n--ERROR--",0,4,1,sizeM,3,&id)))
        {
            printf("\n E) -- ORQUESTAS POR ID --");
            for(i=0;i<sizeM;i++)
            {
               if(arrayM[i].idOrquesta==id && arrayM[i].isEmpty==0)
                {
                    instrumentos_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&posicionIns);
                    printf("\nID: %d / Nombre: %s / Apellido: %s / Edad: %d / Instrumento: %s / Tipo: %d / TipoNombre: %s",
                    arrayM[i].idUnico, arrayM[i].nombre, arrayM[i].apellido, arrayM[i].edad,
                    arrayI[posicionIns].nombre, arrayI[posicionIns].tipo, arrayI[posicionIns].tipoNombre);
                    flag=1;
                }
            }
            if(flag==0)
            {
             printf("No se encontraron musicos en la orquesta");
            }
        }
    }
    return 0;
}

int Informes_musicosPorInstrumentoCuerdas(Musicos arrayM[],int sizeM, Instrumentos arrayI[],int sizeI)
{
    int i;
    int posicionIns;

    if(arrayM!=NULL && sizeM>=0 && arrayI!=NULL && sizeI>=0)
              {
                  printf("\n\n G) -- INSTRUMENTO SEGUN TIPO --");
                  for(i=0;i<sizeM;i++)
                  {
                    if(strcmp(arrayM[i].instrumento,"Cuerdas")==0)
                    {
                        instrumentos_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&posicionIns);
                        printf("\nID: %d / Nombre: %s / Apellido: %s / Edad: %d / Nombre Instrumento: %s / Tipo: %d / TipoNombre: %s",
                            arrayM[i].idUnico, arrayM[i].nombre, arrayM[i].apellido, arrayM[i].edad,
                            arrayI[posicionIns].nombre, arrayI[posicionIns].tipo, arrayI[posicionIns].tipoNombre);
                    }
                  }
              }

    return 0;
}

int Informes_contMusicosPorOrquesta(Musicos array[],int size,int idPosicion)
{
    int i;
    int contMusicos = 0;
    if(array!=NULL && size>=0 && idPosicion>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].idOrquesta==idPosicion && array[i].isEmpty==0)
            {
                contMusicos++;
            }
        }
    }
    return contMusicos;
}

int Informes_orquestaMasCincoMusicos(Musicos arrayM[],int size, Orquesta arrayO[])
{
    int i;
    int flag=0;
    int contMusicos;

    if(arrayM!=NULL && arrayO!=NULL && size>=0)
    {
        printf("\n\n A) -- ORQUESTA MAS DE CINCO MUSICOS --");
            for(i=0;i<size;i++)
            {
                if(arrayO[i].isEmpty==0)
                {
                    contMusicos = Informes_contMusicosPorOrquesta(arrayM,size,arrayO[i].idUnico);
                    if(contMusicos>=5)
                    {
                        printf("\nID: %d / Nombre: %s / Tipo: %d / TipoNombre: %s / Lugar: %s",arrayO[i].idUnico, arrayO[i].nombre, arrayO[i].tipo, arrayO[i].tipoNombre, arrayO[i].lugar);
                        flag=1;
                    }
                }
            }
            if(flag==0)
            {
                printf("\nNo hay orquestas con mas de 5 musicos.");
            }
    }
    return 0;
}

int Informes_orquestasConMasMusicos(Musicos arrayM[], int size, Orquesta arrayO[])
{
    int i;
    int cantMusicos;
    int maximoMusicos = 0;

    if(arrayM!=NULL && size>=0 && arrayO!=NULL)
    {
        printf("\n\n F) -- ORQUESTA MAS MUSICOS --");
        for(i=0;i<size;i++)
        {
            if(arrayO[i].isEmpty==0)
            {
                cantMusicos = Informes_contMusicosPorOrquesta(arrayM,size,arrayO[i].idUnico);
                if(cantMusicos > maximoMusicos)
                {
                    maximoMusicos = cantMusicos;
                }
            }
        }
        for(i=0;i<size;i++)
        {
            if(arrayO[i].isEmpty==0)
            {
                cantMusicos = Informes_contMusicosPorOrquesta(arrayM,size,arrayO[i].idUnico);
                if(cantMusicos == maximoMusicos)
                {
                   printf("\nID: %d / Nombre: %s / Tipo: %d / TipoNombre: %s / Lugar: %s / Cantidad de Musicos: %d",
                    arrayO[i].idUnico,arrayO[i].nombre,arrayO[i].tipo,arrayO[i].tipoNombre,arrayO[i].lugar,cantMusicos);
                }
            }
        }
    }
    return 0;
}


int Informes_orquestaCompleta(Musicos arrayM[],int sizeM, Orquesta arrayO[], int sizeO, Instrumentos arrayI[], int sizeI)
{
    int i;
    int j;
    int flag = 0;
    int tipo;
    int contCuerdas = 0;
    int contVientos = 0;
    int contPercusion = 0;

    if(arrayM!=NULL && sizeM>= 0 && arrayO!=NULL)
    {
        printf("\n\n D) -- ORQUESTAS COMPLETAS --");
        for(i=0;i<sizeO;i++)
        {
            if(arrayO[i].isEmpty==0)
            {
                for(j=0;j<sizeM;j++)
                {
                    if(arrayO[i].idUnico==arrayM[j].idOrquesta)
                    {
                        tipo = Instrumentos_tipoInstrumentoPorId(arrayI,sizeI,arrayM[i].idInstrumento);
                        if(tipo==1)
                        {
                            contCuerdas++;
                        }
                        else if(tipo==2 || tipo==3)
                        {
                            contVientos++;
                        }
                        else if(tipo==4)
                        {
                            contPercusion++;
                        }
                    }
                    if(contCuerdas>5 && contVientos>3 && contPercusion>2)
                    {
                        printf("\nID: %d / Nombre: %s / Tipo: %s / Lugar %s",arrayO[i].idUnico,arrayO[i].nombre,arrayO[i].tipoNombre,arrayO[i].lugar);
                        flag = 1;
                        contCuerdas=0;
                        contPercusion=0;
                        contVientos=0;
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("\nNo hay orquestas completas");
        }
    }
    return 0;
}

int Informes_promedioMusicos(Orquesta arrayO[],int size,Musicos arrayM[])
{
    int i;
    int acumMusicos;
    int contOrquestas = 0;
    float promedioMusicos;

    if(arrayO!=NULL && size>=0 && arrayM!=NULL)
    {
        printf("\n\n H) -- PROMEDIO DE MUSICOS --");
        for(i=0;i<size;i++)
        {
            if(arrayO[i].isEmpty==0)
            {
                acumMusicos = acumMusicos + Informes_contMusicosPorOrquesta(arrayM,size,arrayO[i].idUnico);
                contOrquestas++;
            }
        }
        promedioMusicos = (float)acumMusicos / (float)contOrquestas;
        printf("\nEl promedio de musicos es de: %.2f",promedioMusicos);
    }
    return 0;
}
