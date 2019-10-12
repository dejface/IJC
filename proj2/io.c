/*******************************************************************/
/* Subor: io.c 													   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Modul s funkciou, ktora ziska slovo zo suboru a vrati ho		   */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "htab.h"
#include "io.h"

int get_word(char *s, int max, FILE *f){
	int i, c = 0;
	static int first_err = 0;

	while ((c = fgetc(f)) != EOF) {
		if (!isspace(c)) {
			break;
		}
	}
	if (c == EOF) {
		return -1;
	}

	ungetc(c, f);
	while ((c = fgetc(f)) != EOF) {
		if (isspace(c) || i == max) {
			if (i == max) {
				if (!first_err) {
					fprintf(stderr,
						"Slovo obsahuje viac ako 127 zankov!\n");
					first_err = 1;
				}
				while (!isspace(c) && c != EOF) {
					c = fgetc(f);
				}
				if (c == EOF)
					return -1;
				i = max - 1;
			}
			break;
		}
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}