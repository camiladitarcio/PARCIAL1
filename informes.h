#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



int Informes_listarPorCriterio(Musicos arrayA, Musicos arrayB, int sizeI, int sizeJ, char* criterio);
int Informes_listarCriterioContadorAcumulado(Musicos arrayA, Musicos arrayB, int sizeI, int sizeJ);
int Informes_listarMayorCantidad(Orquesta array[], int size);
int Informes_musicosMayoraEdad(Musicos arrayM[], int sizeM, Orquesta arrayO[], int sizeO, Instrumentos arrayI[], int sizeI);
int Informes_orquestaPorLugar(Orquesta array[], int size);
int Informes_musicosPorIdOrquesta(Musicos arrayM[], int sizeM, Instrumentos arrayI[], int sizeI);
int Informes_musicosPorInstrumentoCuerdas(Musicos arrayM[],int sizeM, Instrumentos arrayI[],int sizeI);
int Informes_contMusicosPorOrquesta(Musicos array[],int size, int idPosicion);
int Informes_orquestaMasCincoMusicos(Musicos array[],int size, Orquesta arrayO[]);
int Informes_orquestasConMasMusicos(Musicos arrayM[], int size, Orquesta arrayO[]);
int Informes_orquestaCompleta(Musicos arrayM[],int sizeM, Orquesta arrayO[], int sizeO, Instrumentos arrayI[], int sizeI);
int Informes_promedioMusicos(Orquesta arrayO[],int size,Musicos arrayM[]);




#endif // INFORMES_H_INCLUDED
