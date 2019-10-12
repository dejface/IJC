/*******************************************************************/
/* Subor: tail2.cc 												   */
/* Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   */
/* Fakulta: Fakulta informačních technologii (FIT)				   */
/* Datum: 24.04.2019											   */
/* Priklad: 1b)													   */
/* Prelozene: g++ (GCC) 7.4.0									   */
/* 																   */
/* Program, ktory vypise poslednych N riadkov zo suboru.		   */
/* Chova sa priblizne ako POSIX tail -> man tail (c++ varianta)    */
/*******************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <string.h>

#define DEFAULT 10

using namespace std;
bool is_plus = false;

int proccess_arguments(int argc, char **argv);
istream *fileopen(fstream *filename, int argc, char **argv);
void case_plus(istream *filename, int lines);
void tail(istream *filename, int lines);

/* Funkcia ktora parsuje argumenty, vracia hodnotu riadkov na vypisanie*/
int proccess_arguments(int argc, char **argv){
	if (argc > 4){
		cerr << "Zly pocet argumentov!\nPocet musi byt < 4" << '\n';
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
				cerr << "Chybny argument!" << '\n';
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
				cerr << "Chybny argument!" << '\n';
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
istream *fileopen(fstream *filename, int argc, char **argv){
	if (argc == 1 || (argc == 2 && strcmp(argv[1], "-n") == 0) ||
		(argc == 3 && strcmp(argv[1], "-n") == 0)){
		return &cin;
	} else if ((argc == 2 && strcmp(argv[1], "-n") != 0) || 
			  (argc == 3 && strcmp(argv[1], "-n") != 0)) {
		(*filename).open(argv[1], ios::in);
		if ((*filename).fail() || filename == NULL){
			cerr << "Subor sa nepodarilo otvorit!" << '\n';
		} else return filename;
	} else if (argc == 4 && strcmp(argv[2], "-n") == 0) {
		(*filename).open(argv[1], ios::in);
		if ((*filename).fail() || filename == NULL) {
			cerr << "Subor sa nepodarilo otvorit!" << '\n';
		} else return filename;
	} else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
		(*filename).open(argv[3], ios::in);
		if ((*filename).fail() || filename == NULL) {
			cerr << "Subor sa nepodarilo otvorit!" << '\n';
		} else return filename;
	}
	return NULL;
}
/*funkcia, ktorou riesim pripad, ze na prikazovom riadku bol zadany argument
  so znamienkom +, co znamena, ze vypisujeme od zadaneho riadku do konca 
  suboru*/
void case_plus(istream *filename, int lines){
	string row;
	while (getline(*filename,row)){
		if (lines-1 <= 0){
			cout << row << '\n';
		} else lines--;
	}
}

/*hlavna funkcia, ma za ulohu vypisat poslednych n riadkov zo suboru,
  DEFAULT nastaveny na 10 poslednych riadkov*/
void tail(istream * filename, int lines){
	queue < string > myQueue;
	string row;
	int count = 0;
	int line_count = 0;
	if (is_plus){
		case_plus(filename,lines);
	} else {
		while (getline(*filename,row))
			myQueue.push(row);

		count = myQueue.size();

		if (lines < count){
			while ( !myQueue.empty() && line_count < (count - lines)){
				myQueue.pop();
				line_count++;
			}
		}
		while (!myQueue.empty()) {
			cout << myQueue.front() << '\n';
			myQueue.pop();
		}
	}
}

int main(int argc, char **argv){
	ios::sync_with_stdio(false);

	fstream file;
	istream *filename = fileopen(&file, argc, argv);
	if (filename == NULL){
		cerr << "Nepodarilo sa otvorit subor!" << '\n';
		return 1;
	}
	int lines = proccess_arguments(argc,argv);
	if (lines < 0)
		lines = -lines;
	else if (lines == 0)
		return 1;
	
	tail(filename,lines);
	if (file.is_open())
		file.close();
return 0;
}