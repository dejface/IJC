/*******************************************************************/
/* Subor: io.h 		 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Hlavickovy subor s prototypom funkcie z modulu io.c 			   */
/*******************************************************************/

#ifndef IO_H
#define IO_H

#include <stdio.h>

int get_word(char *s, int max, FILE *f);

#endif