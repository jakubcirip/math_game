/*
#include <stdio.h>	
#include <string.h>	
#include <stdlib.h>	
#include <math.h>	
#include <time.h>
*/
#include "math_game.h"

void sort_score(int scores[], int count){
		int temp;
		for(int i=0; i<count-1; i++){
				for(int j=i+1; j<count; j++){
						if(scores[j] > scores[i]){
								temp = scores[i];
								scores[i] = scores[j];
								scores[j] = temp;
						}
				}
		}
}

int random_number(int size, int factor){
		int lower=1, upper=size+factor;
		int num = (rand() % (upper - lower + 1)) + lower;
		return num;
}

int render_playground(int size, int factor){
		int counter=0, c=0;
		for(int i=0; i<size; i++){
				printf("\n");
				for(int k=0; k<size+1; k++){
						int x=random_number(size, 0);
						int z=random_number(size, 0);
						if(x>(size/2) && z>(size/2) && k<size){
								c = random_number(size, factor);
								counter += c;
								printf(" %d ", c);
						} else {
								printf("    ");
						}
				}
				printf("\n");
		}

		return counter;
}

	/* open files for palyers, scores and levels, and initialize it */
int init_files(const char *name, char option, int array[]){
		FILE *fp;
		int counter=0;
		fp = fopen(name, &option);
		if(fp == NULL){
				printf("Can't open file %s!\n", name);
				return 1;
		}
		while(fscanf(fp, "%d", &array[counter]) != EOF){
				counter++;
		}
		fclose(fp);
		return counter;
}





/*
/	old render function
/
int render_playground(int size, int factor){
		int counter=0, c=0;
		for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
						printf("+  -  ");
				}
				printf("+\n");
				for(int k=0; k<size+1; k++){
						int x=random_number(size, 0);
						int z=random_number(size, 0);
						if(x>(size/2) && z>(size/2) && k<size){
								c = random_number(size, factor);
								counter += c;
								printf("| %d  ", c);
						} else {
								printf("|     ");
						}
				}
				printf("\n");
		}
		for(int jj=0; jj<size; jj++){
				printf("+ - ");
		}
		printf("+\n");
		// printf("%d\n\n", counter);

		return counter;
}
/
/
*/
