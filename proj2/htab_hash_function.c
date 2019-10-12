/*******************************************************************/
/* Subor: htab_hash_function.c									   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Modul, ktory vypocita index do hash tabulky pomocou rozptylova- */
/* cej funkcie													   */
/*******************************************************************/

#include "htab.h"
#include <stdint.h>
#include "htabp.h"

unsigned int htab_hash_function(const char *str) {
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++){
        h = 65599*h + *p;
    }
    return h;
}