/*******************************************************************/
/* Subor: htab_iterator_next.c									   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Nastavi iterator na dalsi zaznam lin.zoznamu, alebo vrati NULL  */
/*******************************************************************/

#include <stdlib.h>
#include "htab.h"
#include "htabp.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it){
	if (it.ptr->next != NULL){
		it.ptr = it.ptr->next;
		return it;
	}
	for (unsigned int i = it.idx + 1; i < it.t->arr_size; i++){
		if (it.t->htab[i] != NULL){
			it.idx = i;
			it.ptr = it.t->htab[i];
			return it;
		}
	}
	it.ptr = NULL;
	return it;
}