/* Subor: ppm.c
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad b)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Modul s definiciou externych funkcii pre citanie z ppm suboru
 *
 */

#include "error.h"
#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ppm_free(struct ppm *p){
    free(p);
}

struct ppm * ppm_read(const char * filename)
{
	FILE *f;
	if ((f = fopen(filename,"rb")) == NULL){
		warning_msg("Subor sa nepodarilo otvorit v read-binary mode\n",filename);
		return NULL;
	}
	unsigned xsize, ysize;
	int color;
	char magicnumber[3];

	if (fscanf(f, "%2s %u %u %d", magicnumber, &xsize, &ysize, &color) < 1) {
        warning_msg("Hlavicku suboru %s sa nepodarilo precitat.\n", filename);
        fclose(f);
        return NULL;
    }
    if (strcmp("P6",magicnumber)!=0){
    	warning_msg("Subor %s ma nespravny format. Bol nacitany format-> %s\n",
    				filename, magicnumber);
    	fclose(f);
    	return NULL;
    }
    if (color != 255){
        warning_msg("Prilis velky rozsah farieb suboru %s\n",filename);
        fclose(f);
        return NULL;
    }
    if ((xsize*ysize*3) > LIMIT){
        warning_msg("Obrazok suboru %s je prilis velky a nepodarilo sa ho nacitat.\n"
                    ,filename);
        fclose(f);
        return NULL;
    }
    fscanf(f,"%*c");
    struct ppm *p = malloc(sizeof(struct ppm) + (3 * xsize * ysize) * sizeof(char));

    if (p == NULL){
        warning_msg("Alokacia sa nepodarila\n");
        fclose(f);
        return NULL;
    }
    p->xsize = xsize;
    p->ysize = ysize;

    if (fread(p->data, 1, (xsize*ysize*3), f) != (xsize*ysize*3)){
        warning_msg("Chyba pri nacitani zo suboru %s.\n",filename);
        ppm_free(p);
        fclose(f);
        return NULL;
    } 
   if (fgetc(f) != EOF){
        warning_msg("Chyba vo formate suboru %s\n",filename);
        ppm_free(p);
        fclose(f);
        return NULL;
    }
    fclose (f);
    return p;
}