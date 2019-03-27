/* Subor: ppm.h
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad b)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Hlavickovy subor deklaruje ppm s rozmermi a RGB datami, ktore su 
 * ulozene v dynamicky alokovanom poli. 
 *
 */

#include <stdlib.h>

#ifndef PPM_H
#define PPM_H

#define LIMIT 8000*8000*3

struct ppm {
 	unsigned xsize;
  	unsigned ysize;
 	char data[];
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif