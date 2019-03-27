/* Subor: eratosthenes.c
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad a)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Algoritmus Eratosthenovho sita, nastavi bity v bitovom poli bud na 1,
 * ked dane cislo nie je prvocislo alebo na 0 v opacnom pripade.
 *
 */

#include "bit_array.h"
#include "eratosthenes.h"
#include <math.h>

void Eratosthenes(bit_array_t pole){
	unsigned long max = (bit_array_size(pole));
	for (unsigned long i = 2; i < sqrt(max); i++){
		if (!(bit_array_getbit(pole,i))){
			for (unsigned long j = i*i; j < max; j+=i){
				bit_array_setbit(pole,j,1);
			}
		}
	}
}