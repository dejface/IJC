/*******************************************************************/
/* Subor: htabp.htab											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Privatny hlavickovy subor s uplnou deklaraciou struktur 		   */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

#ifndef HTABP_H
#define HTABP_H
typedef struct htab {
  size_t arr_size;
  size_t size;
  struct htab_item *htab[]; 
} htab_t;

typedef struct htab_item {
	unsigned int data;
  char *key;
  struct htab_item *next;
}htab_item; 

#endif   