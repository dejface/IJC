/*******************************************************************/
/* Subor: hatb_bucket_count.c 									   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Vracia pocet prvkov tabulky							   		   */
/*******************************************************************/

#include <stdlib.h>
#include "htab.h"
#include "htabp.h"

size_t htab_bucket_count(const htab_t *t){
	return t->arr_size;
}