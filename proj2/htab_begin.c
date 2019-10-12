/*******************************************************************/
/* Subor: htab_begin.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Nastavenie iteratora na prvu polozku v tabulke		  		   */
/*******************************************************************/

#include <stdlib.h>
#include "htab.h"
#include "htabp.h"

htab_iterator_t htab_begin(const htab_t * t){
	htab_iterator_t iterator;
	iterator.t = t;
	
	for (unsigned int i = 0; i < t->arr_size; i++){
		if (t->htab[i] != NULL){
			iterator.idx = i;
			iterator.ptr = t->htab[i];
			return iterator;
		}
	}

	iterator.ptr = NULL;
	iterator.idx = 0;

	return iterator;
}