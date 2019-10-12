/*******************************************************************/
/* Subor: extern.c 												   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Modul s externou funkciou (kvoli inline v header file)  		   */
/*******************************************************************/

#include "htab.h"
#include "htabp.h"
#include <stdbool.h>

extern inline bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2);