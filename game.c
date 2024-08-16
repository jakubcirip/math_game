/*
#include <stdio.h>	
#include <string.h>	
#include <stdlib.h>	
#include <math.h>	
#include <time.h>
*/
#include "math_game.h"

int main(){

		int size=0, min_s=2, max_s=14, factor=1;
		FILE *fs, *fl;
		int scores[MAX_SCORES];
		int levels[MAX_LEVELS];
		int players[MAX_PLAYERS];
		int add_score=0, add_level=0, add_player=0;


		add_score = init_files("scores.txt", 'r', scores);
		add_level = init_files("levels.txt", 'r', levels);
		add_player = init_files("players.txt", 'r', players);
		printf("Score counter: %d\n", add_score);
		printf("Level counter: %d\n", add_level);
		printf("Player counter: %d\n", add_player);


		// start game

		char name[30];
		printf("Enter your name: ");
		if(fgets(name, sizeof(name), stdin) != NULL){
				// deletion "\n"
				name[strcspn(name, "\n")] = '\0';
		}
		FILE *fp = fopen("players.txt", "a");
		if(fp == NULL){
				perror("Chyba pri otvarani suboru players.txt");
				return 1;
		}
//		fprintf(fp, "%s\n", name);
//		fprintf(fp, " ");

		//	fflush(fp);

		fclose(fp);
		printf("Name is: %s\n", name);


		do{
				int res;
				printf("Enter size: (%d-%d): ", min_s, max_s);
				res = scanf("%d", &size);
				if(res != 1){
						printf("Incorrect input, try again!\n");
						while(getchar() != '\n');
				}
				if((res == 1) && (size < min_s || size > max_s)){
						printf("Incorrect size of field!\n");
						size = 0;		
				}
		}
		while(size < min_s || size > max_s);
		printf("Size of field is: %d\n", size);
		srand(time(0));


		char c;
		printf("To start game type 's'\n");
		printf("For end game type 'e'\n");
		int level=1, flag=0, result=0, count=0, counter=0;
		do{
				result=0;
				if(flag == 0){
						scanf("%c", &c);
				}
				if(c == 's'){
						flag = 1;
						count = render_playground(size, factor);
						printf("Enter sum of all numbers: ");
						scanf("%d", &result);
						if(result != count){
								printf("Wrong answer, correct: %d\n", count);
								printf("GAMER OVER\n");
								printf("Level: %d\n", level);
								printf("Your score: %d\n", counter);

								scores[add_score] = counter;
								add_score++;
								sort_score(scores, add_score);

								fs = fopen("scores.txt", "w");
								if(fs == NULL){
										printf("Can't open file scores.txt!\n");
										return 1;
								}
								for(int i=0; i<add_score; i++){
										fprintf(fs, "%d\n", scores[i]);
										/* if(scores[i] == counter){
												fprintf(fs, "%s ", name);
										} */
								}
								fclose(fs);

								levels[add_level] = level;
								add_level++;
								sort_score(levels, add_level);
								fl = fopen("levels.txt", "w");
								if(fl == NULL){
										printf("Can't open file levels.txt!\n");
										return 1;
								}
								for(int i=0; i<add_level; i++){
										/* if(levels[i] == level){
												fprintf(fl, "%s ", name);
										} */
										fprintf(fl, "%d\n", levels[i]);
								}
								fclose(fl);

								break;
						}
						level++;
						counter += count;
				}
				if(c == 'e'){
						break;
				}
				factor++;
		} while(1);

		return 0;
}
