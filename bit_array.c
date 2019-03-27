/* Subor: bit_array.c
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad a)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Modul s prototypom inline funkcii pre optimalizaciu O0
 *
 */

#include "bit_array.h"

extern inline void bit_array_setbit(bit_array_t jmeno_pole,unsigned long index,
									short vyraz);

extern inline unsigned long bit_array_size(bit_array_t jmeno_pole);

extern inline int bit_array_getbit(bit_array_t jmeno_pole,unsigned long index);