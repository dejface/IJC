/* Subor: error.h
 * Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
 * Datum: 20.3.2019
 * Nazov: Domaca uloha c.1, predmet IJC, priklad b)
 * Prelozene: gcc (GCC) 7.4.0
 *
 * Hlavickovy subor s prototypmi funkcii pre error.c
 *
 */
#ifndef ERROR_H
#define ERROR_H

// funkcia, ktora vypise varovanie podla fmt
void warning_msg(const char *fmt, ...);
//funkcia, kotra vypise chybu a ukonci program pomocou exit
void error_exit(const char *fmt, ...);

#endif