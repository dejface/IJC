/*******************************************************************/
/* Subor: htab_clear.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Modul na odalokovanie alokovanych poloziek			  		   */
/*******************************************************************/

#include <stdlib.h>
#include "htab.h"
#include "htabp.h"

void htab_clear(htab_t *t){
	for (unsigned int i = 0; i < t->arr_size; i++)
	{
		htab_item *temp;
		for (htab_item *item = t->htab[i]; item != NULL; item = temp)
		{
			temp = item->next;
			free(item->key);
			free(item);
		}
	}
}