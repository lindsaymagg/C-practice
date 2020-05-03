#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

/*
Author: Lindsay Maggioncalda lnm22
Homework #1, due 30 January 2019
*/


/*
takes a file as an input (./HoopsStats statsfile.txt). The file
contains a list of basketball players and some stats about them.
outputs a number of lines equal to the number of players, and 
each line is the player’s name, jersey number, and year of graduation. 
lines are sorted in descending order of average points per game. 
In the case of equal points/game, sort by last name.
*/


/* declare player struct */
typedef struct player{
	char name[100];
	int jersey;
	float avg_ppg;
	int gradyear;
	struct player* next;
} player_t;


/* declare printNodeLine function */
void printNodeLine(player_t* playerNode);

/* declare printRoster function */
void printRoster(player_t* fullRoster);

/* declare isLessThan function */
int isGreaterThan(player_t* player1, player_t* player2);


int main (int argc, char *argv[])  {

	/* get filename from command line */
	char* fileName = argv[1];
	/* open file for reading */
	FILE* filePtr = fopen(fileName, "rt"); /* rt means reading text */

	/* create linkedlist of players */
	player_t* roster = NULL;

	/* pointer to last player */
	player_t* last = NULL;

	/* for now, this is one player */
	while (true){

		int condition = 1;

		/* variables to collect to fill currPlayer.*/
		char currName[100];
		int cJersey;
		float cAvg_ppg;
		int cGradyear;

		/* get name of currentPlayer */
		fscanf(filePtr, "%s", currName);
		if (strcmp(currName, "DONE") == 0){
			break;
		}

		/* get jersey number of currentPlayer */
		fscanf(filePtr, "%d", &cJersey);

		/* get average points per game of currentPlayer */
		fscanf(filePtr, "%f", &cAvg_ppg);

		/* get graduation year of currentPlayer */
		fscanf(filePtr, "%d", &cGradyear);

		//printf("%s\n", currName);
		//printf("%d\n", cJersey);
		//printf("%f\n", cAvg_ppg);
		//printf("%d\n", cGradyear);

		/* initialize current player with values we just got from file*/
		player_t *currPlayer = (player_t*) malloc(sizeof(player_t)); 
		strcpy(currPlayer->name, currName); //WE HAVE A PROBLEM HERE
		currPlayer->jersey = cJersey;
		currPlayer->avg_ppg = cAvg_ppg;
		currPlayer->gradyear = cGradyear;
		currPlayer->next = NULL;

		/* if this is the first player we've seen*/
		if (roster == NULL) {
		roster = currPlayer;
		last = currPlayer;
			}

		/* figure out where to place player */
		else {
			//printf("currPlayer is %s\n",currPlayer->name);
			//printf("roster is %s\n",roster->name);
			/* if this player is greater than the first player */
			if (isGreaterThan(currPlayer,roster) == 1) {
				/* put current player at front */
				currPlayer->next = roster;
				roster = currPlayer;
			}

			/* if this player is less than the first player */
			else {
				/* if this player is the second player we've seen */
				if (roster->next == NULL) {
					last->next = currPlayer;
					last = last->next;
				}
				//if multiple nodes in list
				else {
					player_t* prev = roster;
					//printf("prev is %s\n",prev->name);
					player_t* currPoint = roster->next;
					//printf("currPoint is %s\n",currPoint->name);

					//start loop here
					while (condition == 1){

						//if current node is greater than the next node
						if (isGreaterThan(currPlayer,currPoint) == 1){
							prev->next = currPlayer;
							currPlayer->next = currPoint;
							//printf("inserted currPlayer %s between prev %s and currPoint %s\n",currPlayer->name,prev->name,currPoint->name);
							condition = 0;
							break;
						}
						//if less than the next node, keep going. Move pointers
						else {
							//if currPoint->next is null, add to end. move last also
							if (currPoint->next == NULL) {
								currPoint->next = currPlayer;
								last = currPlayer;
								condition = 0;
								break;
							}
							//if currPoint not the last node
							else {
								prev = currPoint;
								currPoint = currPoint->next;
							}
						}
					}
				}
			}
		}
	}

	fclose(filePtr);  /* close the file */

	printRoster(roster);

	while (roster != NULL) {
		player_t* curr = roster;
		roster = roster->next;
		free(curr);
	}

	return 0;	
}


/* prints one player's information as name, jersey, grad year */
void printNodeLine(player_t* playerNode) {
	printf("%s %d %d\n",playerNode->name, playerNode->jersey, playerNode->gradyear);
}

/* prints player info lines for a whole roster of players */
void printRoster(player_t* fullRoster) {
	while (fullRoster != NULL){
		printNodeLine(fullRoster);
		fullRoster = fullRoster->next;
	}
}

/* tells  */
int isGreaterThan(player_t* player1, player_t* player2) {
	if (player1->avg_ppg > player2->avg_ppg || 
		((player1->avg_ppg == player2->avg_ppg) 
		&& (strcmp(player1->name, player2->name) < 0))) return 1; //false
	else return 0; //false
}







