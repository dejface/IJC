/* Subor: error.c
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad b)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Implementovanie funkcii, ktore vykonavaju chybove hlasenia,
 * v pripade error_exit ukoncenie programu
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...){
	va_list args;
	va_start(args,fmt);
	fprintf(stderr,"CHYBA: ");
	vfprintf(stderr,fmt,args);
	va_end(args);
}

void error_exit(const char *fmt, ...){
	va_list args;
	va_start(args,fmt);
	fprintf(stderr,"CHYBA: ");
	vfprintf(stderr,fmt,args);
	va_end(args);

	exit(1);
}