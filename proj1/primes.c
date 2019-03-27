/* Subor: eratosthenes.c
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad a)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Je potreba zvacsit stack na Unix-like systemoch ulimit -s cislo_v_KiB
 * Vytvara lokalne pole o velkosti 123mil., pomocou Eratosthenovho sita
 * vytriedi prvocisla a vypise poslednych 10 vzostupne.
 *
 */

#include "bit_array.h"
#include "eratosthenes.h"
#include <stdio.h>
#include <assert.h>

#define LIMIT_VYTISKU 10
#define CAP 123000000L

int main(){
	bit_array_create(pole, CAP); 
	Eratosthenes(pole); 
	int index = 10;
	unsigned long primes[10] = {0}; 

	// prechadzanie cisel v poli od najvacsieho
	for (unsigned long i = bit_array_size(pole) - 1L; (i > 1L && index > 0); i--)
		if (bit_array_getbit(pole, i) == 0) 
			primes[--index] = i;
	//vypis prvocisel
	for (int i = index; i < LIMIT_VYTISKU; i++) 
		printf("%lu\n", primes[i]);
}