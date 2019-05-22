#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musicos.h" //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Musicos Array de Musicos
* \param arrayB Musicos Array de Musicos
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPorCriterio(Musicos arrayA[], Musicos arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1 && strcmp(arrayA[i].nombre,criterio)!=0)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            else
            {
                musicos_buscarID(arrayB,sizeJ,arrayA[i].idUnico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %d\nID B: %d",
                       arrayA[i].idUnico,arrayB[j].idUnico);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Musicos Array de Musicos
* \param arrayB Musicos Array de Musicos
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int Informes_listarCriterioContadorAcumulado(Musicos arrayA[], Musicos arrayB[], int sizeI, int sizeJ)         //cambiar Musicos
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            musicos_buscarString(arrayA,i,arrayA[i].nombre,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].nombre);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].nombre,arrayA[i].nombre)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        musicos_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Musicos, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].edad*arrayB[j].edad);

                        printf("\nID A: %d\nID B: %d",
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Musicos Array de Musicos
* \param arrayB Musicos Array de Musicos
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_maxContadorAcumulado(Musicos arrayA[], Musicos arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion; //1
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeI];
    int iMaxContador [sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            musicos_buscarString(arrayA,i,arrayA[i].nombre,&auxPosicion);                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].nombre);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].nombre,arrayA[i].nombre)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        musicos_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Musicos, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayA[k].edad*arrayB[j].edad);

                        printf("\nID A: %d\nID B: %d",                                         //imprimo datos que haya que mostrar
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxAcumulado[i]].nombre);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].nombre);
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Musicos Array de Musicos
* \param arrayB Musicos Array de Musicos
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarAuxiliarOrdenar(Musicos arrayA[], Musicos arrayB[], int sizeI, int sizeJ)         //cambiar Musicos
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Musicos arrayAux[sizeI];                                                           //cambiar Musicos y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            musicos_buscarString(arrayA,i,arrayA[i].nombre,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].nombre,arrayA[i].nombre);                              //cambio nombre
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].nombre,arrayA[i].nombre)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        musicos_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Musicos, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].edad*arrayB[j].edad);

                    }
                }
                arrayAux[i].edad=contador;                                    //completo el resto de los campos
                arrayAux[i].edad=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Mayor cantidad
* \param arrayA Musicos Array de Musicos
* \param arrayB Musicos Array de Musicos
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarMayorCantidad(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    int contSinfonica;
    int contFilarmonica;
    int contCamara;

    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(strcmp(array[i].tipoNombre,"Sinfonica")==0)
            {
                contSinfonica++;
            }
            else if(strcmp(array[i].tipoNombre,"Filarmonica")==0)
            {
                contFilarmonica++;
            }
            else if(strcmp(array[i].tipoNombre,"Camara")==0)
            {
                contCamara++;
            }
        }

        if(contSinfonica > contFilarmonica && contSinfonica > contCamara)
        {
            printf("\nLa mayor parte de las orquestas son Sinfonicas");
        }
        else if(contFilarmonica > contCamara && contFilarmonica > contSinfonica)
        {
            printf("\nLa mayor parte de las orquestas son Filarmonicas");
        }
        else
        {
            printf("\nLa mayor parte de las orquestas son de Camara");
        }
    }
        retorno=0;

    return retorno;
}

