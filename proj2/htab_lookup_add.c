/*******************************************************************/
/* Subor: htab_lookup_add.c										   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 2													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Vyhladanie zaznamu v tabulke, ak sa nachadza, vratime iterator  */
/* ak nie, vytvorime zaznam a priradime ho do tabulky			   */
/*******************************************************************/

#include <stdlib.h>
#include <string.h>
#include "htab.h"
#include "htabp.h"
#include <stdbool.h>

htab_iterator_t htab_lookup_add(htab_t *t, const char *key){
	//ziskanie indexu z tabulky
	unsigned int hash = (htab_hash_function(key) % t->arr_size);

	htab_item *item = t->htab[hash];
	htab_iterator_t iterator;
	iterator.ptr = item;
	iterator.idx = hash;
	int len = strlen(key);

	//prechadzanie zaznamu, ak sa zhoduje s "key" vraciame iterator
	for (; item != NULL; item = item->next)
	{
		if (strcmp(item->key,key) == 0){
			//pridanie poctu vyskytu zaznamu v tabulke
			item->data++;
			return iterator;
		}
		if (item->next == NULL)
			break;
	}

	//alokovanie miesta pre novu polozku
	htab_item *new_item = malloc(sizeof(htab_item));
	if (new_item == NULL){
		fprintf(stderr,"Alokacia sa nepodarila!\n");
		iterator.ptr = NULL;
		return iterator;
	}
	new_item->key = malloc(sizeof(char)*(len+1));
	if (new_item->key == NULL){
		fprintf(stderr,"Alokacia sa nepodarila!\n");
		iterator.ptr = NULL;
		return iterator;
	}
	//priradenie "key" do noveho zaznamu
	strcpy(new_item->key, key);
	new_item->data = 1;
	new_item->next = NULL;
	//pridanie do tabulky
	if (item == NULL)
		t->htab[hash] = new_item;
	else{
		item->next = new_item;
	}
	iterator.ptr = new_item;
	iterator.t = t;
	t->size++;
return iterator;
}