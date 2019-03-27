/* Subor: bit_array.h
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad a)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Hlavickovy subor definujuci bitove pole vyuzivajuci makra.
 * Pri pouziti USE_INLINE sa vykonavaju definovane inline funkcie.
 *
 */

#include <limits.h>
#include "error.h"
#include <stdlib.h>
#include <assert.h>
#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

typedef unsigned long *bit_array_t;

#define size (sizeof(unsigned long) * CHAR_BIT)								   \

//makro na vytvorenie bitoveho pola
#define bit_array_create(jmeno_pole, velikost)								   \
 	unsigned long jmeno_pole												   \
 	[((velikost) / size + 1) + (((velikost) % (size)) ? 1 : 0 )] = {(velikost),0}; \
 	static_assert(velikost > 0,"bit_array_create: ERROR -> Snaha o vytvorenie pola mensieho ako 1\n")\

#define bit_array_alloc(jmeno_pole,velikost)\
 	assert(velikost > 0); \
 	unsigned long *jmeno_pole = calloc(((velikost) / size + 1) + ((velikost) % (size)), size);\
 	if((jmeno_pole) == NULL){\
 		fprintf(stderr,"bit_array_alloc: Chyba alokace paměti.\n"); \
 		bit_array_free((jmeno_pole)); \
 		return 1;\
 	} \
 	(jmeno_pole)[0]=(velikost);\

#define bit_array_free(jmeno_pole) free((jmeno_pole))\

#ifdef USE_INLINE
	inline unsigned long bit_array_size(bit_array_t jmeno_pole){
		return jmeno_pole[0];
	}
#else
	#define bit_array_size(jmeno_pole) jmeno_pole[0]		
#endif

#ifdef USE_INLINE
    inline void bit_array_setbit(bit_array_t jmeno_pole, 				\
	unsigned long index, short vyraz){
		if (index >= bit_array_size(jmeno_pole)){
			error_exit("bit_array_setbit: Index %lu mimo rozsah 0..%lu\n",
            (unsigned long)index, (unsigned long)bit_array_size(jmeno_pole)-1);
		}
		if(vyraz){
			jmeno_pole[1 + index / size] |= 1UL << (index % size);
		} else{
			jmeno_pole[1 + index / size] &= ~(1UL << (index % size));
		}
	}
#else
	#define bit_array_setbit(jmeno_pole,index,vyraz) do {					   \
			if (index >= bit_array_size(jmeno_pole)){						   \
			error_exit("bit_array_setbit: Index %lu mimo rozsah 0..%lu\n",	   \
            (unsigned long)index, (unsigned long)bit_array_size(jmeno_pole)-1);\
			}																   \
			else {															   \
				vyraz ? (jmeno_pole[index / size + 1] |= 1UL << (index % size)):\
				(jmeno_pole[index / size + 1] &= ~(1UL << (index % size)));     \
			}																   \
		}																	   \
		while(0)														   
#endif

#ifdef USE_INLINE
	inline int bit_array_getbit(bit_array_t jmeno_pole,				   \
	unsigned long index){									
		if (index > bit_array_size(jmeno_pole) || index <= 0)
			error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu\n",
            (unsigned long)index, (unsigned long)bit_array_size(jmeno_pole)-1);
		return (jmeno_pole[index / size + 1] & (1UL << (index % size))) > 0;
	}
#else 
	#define bit_array_getbit(jmeno_pole,index)								   \
		(index > bit_array_size(jmeno_pole)  || index <= 0) ? 			   \
			error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu\n",	   \
            (unsigned long)index, (unsigned long)bit_array_size(jmeno_pole)),0 \
            : 																   \
            (unsigned long)((jmeno_pole[index / size + 1] &					   \
            (1UL << (index % size))) > 0)
#endif
#endif