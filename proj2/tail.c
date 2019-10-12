/*******************************************************************/
/* Subor: tail.c 												   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 1a)													   */
/* Prelozene: gcc (GCC) 7.4.0									   */
/* 																   */
/* Program, ktory vypise poslednych N riadkov zo suboru.		   */
/* Chova sa priblizne ako POSIX tail -> man tail			       */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tail.h"
bool is_plus = false;

/* Funkcia ktora parsuje argumenty, vracia hodnotu riadkov na vypisanie*/
int proccess_arguments(int argc, char **argv){
	if (argc > 4){
		fprintf(stderr,"Zly pocet argumentov!\nPocet musi byt < 4\n");
		exit (1);
	}
	switch(argc){
		case 2:
			return DEFAULT;
			break;
		case 3:
			if (strcmp(argv[1], "-n") == 0){
				if (argv[2][0] == '+'){
					is_plus = true;
				}
			char *err;
			int lines = strtol(argv[2],&err,10);
			if (!err){
				fprintf(stderr,"Chybny argument!\n");
				exit(1);
			}
			return lines;
			}
			break;
		case 4: 
			if (strcmp(argv[1], "-n") == 0){
				if (argv[2][0] == '+'){
					is_plus = true;
				}
			char *err;
			int lines = strtol(argv[2],&err,10);
			if (!err){
				fprintf(stderr,"Chybny argument!\n");
				exit(1);
			}
			return lines;
		}
			break;
	}
	return -1;
}

/*funkcia, ktora zabezpecuje otvorenie suboru, v pripade zlyhania vracia NULL
  a vypise error hlasku														 */
FILE *fileopen(int argc, char **argv){
	if (argc == 1 || (argc == 2 && strcmp(argv[1], "-n") == 0) ||
		(argc == 3 && strcmp(argv[1], "-n") == 0)){
		return stdin;
	} else if ((argc == 2 && strcmp(argv[1], "-n") != 0) || 
			  (argc == 3 && strcmp(argv[1], "-n") != 0)) {
		FILE *filename = fopen(argv[1], "r");
		if (filename == NULL){
			fprintf(stderr, "Subor sa nepodarilo otvorit!\n");
		} else return filename;
	} else if (argc == 4 && strcmp(argv[2], "-n") == 0) {
		FILE *filename = fopen(argv[1], "r");
		if (filename == NULL) {
			fprintf(stderr, "Subor sa nepodarilo otvorit!\n");
		} else return filename;
	} else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
		FILE *filename = fopen(argv[3], "r");
		if (filename == NULL) {
			fprintf(stderr, "Subor sa nepodarilo otvorit!\n");
		} else return filename;
	}
	return NULL;
}

/* funkcia dynamicky alokuje pamat na uchovavanie riadkov */
char **memalloc(int lines){
	char **dynamic_lines;
	dynamic_lines = calloc(lines, sizeof(char *));
	if (dynamic_lines == NULL){
		fprintf(stderr,"Alokacia zlyhala!\n");
		return NULL;
	}
	for (int i = 0; i < lines; i++){
		if ((dynamic_lines[i] = calloc((MAX_LINE_LIMIT + 2), sizeof(char))) == NULL){
			fprintf(stderr,"Alokacia zlyhala!\n");
			return NULL;
		} 
	}
	return dynamic_lines;
}

void freemem(char **memalloc, int lines){
	//prechadzame postupne po prvkoch, ktore su naalokovane a uvolnujeme
	int i = 0;
	while (i < lines){
		free(memalloc[i]);
		i++;
	}
	free(memalloc);
}

/*funkcia ktora mi zabezpeci preskocenie nepotrebnych a nadbytocnych znakov,
  ktore su uz nad limit MAX_LINE_LIMIT*/
int skip(FILE *filename){
	int c;
	char terminate = '\n';
	while (((c = fgetc(filename)) != terminate) && (c != EOF)) {
		;
	}
	if (c == EOF) 
		return 1;
	else
		return 0;
}

/*funkcia, ktorou riesim pripad, ze na prikazovom riadku bol zadany argument
  so znamienkom +, co znamena, ze vypisujeme od zadaneho riadku do konca 
  suboru*/
void case_plus(FILE *filename, int lines){
	char arr[MAX_LINE_LIMIT + 2];
	int line_count = 0;
	bool error = true;
	while (fgets(arr,MAX_LINE_LIMIT + 1,filename) != NULL){
		line_count++;
		int len = strlen(arr);
		if (arr[len - 1] != '\n') {
			if (skip(filename) == 0) {
				arr[len - 1] = '\n';
				if (error) {
					fprintf(stderr,
						"Prekroceny maximalny pocet znakov (%d) na riadku %d\n",
						MAX_LINE_LIMIT,line_count);
					error = false;
				}
			}
		}
		if (line_count >= lines)
			printf("%s", arr);
	}
	printf("\n");
}

/*hlavna funkcia, ma za ulohu vypisat poslednych n riadkov zo suboru,
  DEFAULT nastaveny na 10 poslednych riadkov*/
void tail(FILE *filename, int lines, char **dynamic_lines){
	int line_count = 0;
	char arr[MAX_LINE_LIMIT + 2];
	bool error = true;
	int c;
	if (is_plus){
		case_plus(filename,lines);
	} else {
		while (fgets(arr,MAX_LINE_LIMIT + 1,filename) != NULL){
			int len = strlen(arr);
			if (arr[len - 1] != '\n') {
				if (!feof(filename)) {
					arr[len - 1] = '\n';
					while ((c = fgetc(filename)) != '\n' && c != EOF);
					if (error) {
						fprintf(stderr,
							"Prekroceny maximalny pocet znakov (%d) na riadku %d\n",
							MAX_LINE_LIMIT,line_count+1);
						error = false;
					}
				}
			}
			strcpy(dynamic_lines[line_count % lines], arr);
			line_count++;
		}
		if (line_count == 0){
			fprintf(stderr,"V subore sa nenachadzaju ziadne riadky!\n");
			exit(1);
		}
		if (lines > line_count)
			lines = line_count;

		int this_line = line_count % lines;

		for (int i = this_line; i < lines; i++)
		printf("%s", dynamic_lines[i]);

		for (int i = 0; i < this_line; i++) 
		printf("%s", dynamic_lines[i]);
	}	
}

int main(int argc, char **argv){
	FILE *filename = fileopen(argc,argv);
	if (filename == NULL){
		fprintf(stderr,"Nepodarilo sa otvorit subor!\n");
		return 1;
	}
	int lines = proccess_arguments(argc,argv);
	if (lines < 0)
		lines = -lines;
	else if (lines == 0)
		return 0;
	
	char **dynamic_lines = memalloc(lines);
	if (dynamic_lines != NULL){
		tail(filename,lines,dynamic_lines);
		freemem(dynamic_lines,lines);
	} else {
		fprintf(stderr,"Alokacia pamati zlyhala!\n");
		fclose(filename);
		return 1;
	}

	fclose(filename);
	return 0;
}