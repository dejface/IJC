/*******************************************************************/
/* Subor: tail.c 												   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 1a)													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Hlavickovy subor s prototypmi funkcii a definovanymi makrami    */
/*******************************************************************/

#define DEFAULT 10
#define MAX_LINE_LIMIT 1023

int proccess_arguments(int argc, char **argv);
FILE *fileopen(int argc, char **argv);
char **memalloc(int lines);
void freemem(char **memalloc, int lines);
int skip(FILE *filename);
void case_plus(FILE *filename, int lines);
void tail(FILE *filename, int lines, char **dynamic_lines);