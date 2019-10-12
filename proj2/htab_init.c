/*******************************************************************/
/* Subor: htab_init.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Inicializacia novej tabulky, pri chybe vracia NULL.   		   */
/*******************************************************************/
#include <stdlib.h>
#include "htab.h"
#include "htabp.h"


htab_t *htab_init(size_t n){
	htab_t *t = malloc(sizeof(htab_t) + n * sizeof(htab_item));

	if (t == NULL)
		return NULL;

	if (t->htab == NULL){
		free(t);
		return NULL;
	}

	t->size = 0;
	t->arr_size = n;

	for (unsigned int i = 0; i < n; i++){
		t->htab[i] = NULL;
	}

	return t;
}