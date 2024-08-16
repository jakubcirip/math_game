/*
 *	Name: Header file for math game
 *	Author: Jakub Cirip
 */

#ifndef GAMEHEADER
#define GAMEHEADER

#include <stdio.h>	
#include <string.h>	
#include <stdlib.h>	
#include <math.h>	
#include <time.h>

#define MAX_SCORES 300
#define MAX_LEVELS 300
#define MAX_PLAYERS 300

/* Function for sort score, level.. */
void sort_score(int scores[], int count);

/* Function for generate random number for game (with factor) */ 
int random_number(int size, int factor);

/* Function for render playground of game */
int render_playground(int size, int factor);

/* initialization of files for scores, levels and players */
int init_files(const char *name, char option, int array[]);

#endif
