/*******************************************************************/
/* Subor: wordcount.c 											   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Inicializacia novej tabulky, pri chybe vracia NULL.   		   */
/*******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"
#include "htabp.h"

#define HTAB_SIZE 4129

/*
	Velkost tabulky by sa mali blizit k mocnine cisla 2 a mala by byt prvocislo

	Testoval som na 1,5MB subore
	Pozn. Hodnoty testov su uvadzane v priemere z 10 spusteni
	#################################
	Velkost tabulky [37]
	Time static: 0.290s
	Time dynamic: 0.2303s
	#################################
	Velkost tabulky [67]
	Time static: 0.233s
	Time dynamic: 0.234s
	#################################
	Velkost tabulky [509]
	Time static: 0.119s
	Time dynamic: 0.152s
	#################################
	Velkost tabulky [4129]
	Time static: 0.137s
	Time dynamic: 0.139s
	#################################
	Velkost tabulky [16381]
	Time static: 0.127s
	Time dynamic: 0.130s
	#################################
	Velkost tabulky [32771]
	Time static: 0.142s
	Time dynamic: 0.137s

	Napokon som vybral hodnotu tabulky 4129, ktora mi prisla ako najlepsia volba.
	Pri vacsej hodnote by bolo zbytocne naalokovaneho viac priestoru, naopak pri
	mensej hodnote by cely program pracovla dlhsie.
 */

int main(void){
	//inicializacia tabulky
	htab_t *htab = htab_init(HTAB_SIZE);
	if (htab == NULL){
		fprintf(stderr,"Alokacia sa nepodarila!\n");
		return 1;
	}
	// alokovanie priestoru pre dynamicky retazec 
	char *array = malloc(sizeof(char) * WORD_MAX);
	if (array == NULL){
		fprintf(stderr,"Alokacia sa nepodarila!\n");
		return 1;
	}
	htab_iterator_t iterator;
	//vyhladavanie a pridavanie zaznamov do tabulky
	while(get_word(array, WORD_MAX, stdin) != -1){
		iterator = htab_lookup_add(htab,array);
	}
	//nastavenie iteratoru na zaciatok zoznamu
	htab_iterator_t iterator_begin = htab_begin(htab);
	//nastavenie iteratoru na koniec zoznamu
	htab_iterator_t iterator_end = htab_end(htab);

	/*kontrolovanie vystupov
	FILE *fp;
	fp = fopen("output.txt","w");*/

	//vypis hodnot
	while (htab_iterator_equal(iterator_begin, iterator_end) == false)
	{
		iterator.ptr = iterator_begin.ptr;
		printf("%s\t%d\n", iterator.ptr->key, iterator.ptr->data);
	//	fprintf(fp,"%s\t%d\n", iterator.ptr->key, iterator.ptr->data);
		iterator_begin = htab_iterator_next(iterator_begin);
	}
	//fclose(fp);

	//uvolnenie alokovanej pamate
	htab_free(htab);
	free(array);

return 0;
}