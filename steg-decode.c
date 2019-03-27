/* Subor: steg-decode.c
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad b)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Program na rozsifrovanie a vypisanie tajnej spravy ulozenej v obrazku
 *
 */

#include "ppm.h"
#include "eratosthenes.h"
#include "bit_array.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CAP 123000000L

int main(int argc, char *argv[]){
	if (argc != 2)
		error_exit("Chybne spustenie, spustite v tvare ./steg-decode du1-obrazek.ppm\n");

  struct ppm *p = ppm_read(argv[1]);
	if (p == NULL)
    error_exit("Invalidny subor\n");

  bit_array_alloc(pole,CAP);
  Eratosthenes(pole);

  int velkost = 3 * p->xsize * p->ysize;
  int pocet = 0;
  char term = '\0';

  for (int i = 19; i < velkost; i++){
    if(!(bit_array_getbit(pole,i))){

      term |= ((p->data[i] & 1) << (pocet++));

    	if (pocet == CHAR_BIT){
        if (term == '\0'){
				  printf("\n");
				  term = EOF;
         	break;
				}
      putchar(term);
      term = '\0';
			pocet = 0;
      	}
    }
  }
	if (term != EOF)
		error_exit("Subor nie je ukonceny '\0'\n");

  ppm_free(p);
  bit_array_free(pole);
return 0;
}