/*******************************************************************/
/* Subor: htab_end.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Nastavenie iteratora na posledny zaznam (neexistujuci)  		   */
/*******************************************************************/

#include <stdlib.h>
#include "htab.h"
#include "htabp.h"

htab_iterator_t htab_end(const htab_t *t){
	htab_iterator_t iterator;
	iterator.t = t;

	for (unsigned int i = t->arr_size - 1; i > 0; i--){
		if (t->htab[i] != NULL){
			iterator.idx = i;
			iterator.ptr = NULL;
			return iterator;
		}
	}

	return iterator;
}