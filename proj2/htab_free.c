/*******************************************************************/
/* Subor: htab_free.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Funkcia na uvolnenie alokovaneho miesta, vola htab_clear		   */
/*******************************************************************/
#include "htab.h"
#include <stdlib.h>
#include "htabp.h"

void htab_free(htab_t *t){
	htab_clear(t);
	free(t);
}