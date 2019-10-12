/*******************************************************************/
/* Subor: htab_size.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Vracia velkost tabulky								 		   */
/*******************************************************************/

#include "htab.h"
#include "htabp.h"

size_t htab_size(const htab_t *t){
	return t->size;
}