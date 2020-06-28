/* System wide header files. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Constants. */  
#define SEA_DIMENSION 10
#define SHIP_NAME_MAX_LENGTH 10
#define NUMBER_OF_SEAS 7
#define NUMBER_OF_GAMEVARS 5

typedef struct warship {
   char *name;
   int ammunition;
   int damage;
   int x;
   int y;
} Warship;

typedef struct sea* Seaptr; 

typedef struct sea {
   int pos[SEA_DIMENSION][SEA_DIMENSION];
   Warship *warships;
   int numberOfWarships;
   Seaptr nextSea;
} Sea; 

/* If this is varied, change NUMBER_OF_GAMEVARS to suit. */
enum game_vars {CURRENT_SEA, TOTAL_TRADERS, TOTAL_WARSHIPS, RED_X, RED_Y};


/* Function prototypes. */
/* Clear the stdin buffer of extraneous input. */
void clearInput();
void setWarships(Sea seas[]);
void populateSeas(Sea seas[]);
int Random(int max);
void lookoutView(Sea seas[], int gameVars[]);
void initSeas(Sea seas[]);


/* Main function. */
int main(void) {
   int i;
   Sea seas[NUMBER_OF_SEAS];
   int gameVars[NUMBER_OF_GAMEVARS];
   gameVars[CURRENT_SEA] = 0;
   
   initSeas(seas);
   setWarships(seas);
   populateSeas(seas);
   lookoutView(seas, gameVars);
   
   for (i = 0; i < NUMBER_OF_SEAS; i++) {
      printf("Number of warships in sea %d = %d\n", i, seas[i].numberOfWarships);
   }
   exit(0);
}

/* Clear the stdin buffer of extraneous input. */
void clearInput() {
   while (getchar() != '\n') {
      ; /* do nothing */
   }
}

/* Set number of Traders and Warships in the seas. */
void setWarships(Sea seas[]) {
   int i;
   srand(time(NULL));
   for (i = 0; i< NUMBER_OF_SEAS; i++) {
      seas[i].numberOfWarships = Random(2) + 1;
      seas[i].warships = malloc(seas[i].numberOfWarships * sizeof(Warship));
   }
}

/* Adds merchant ships and warships to the seas. */
/** This needs serious rethinking. **/
void populateSeas(Sea seas[]) {
   int i, j;
   int x, y;
   srand(time(NULL));
   
   for (i = 0; i < NUMBER_OF_SEAS; i++) {
      for (j = 0; j < seas[i].numberOfWarships; j++) {
         x = seas[i].warships[j].x = Random(10);
         y = seas[i].warships[j].y = Random(10);
         seas[i].pos[y][x] = 'W';
      }
   }
}

int Random(int max) {
   return rand() % max;
}

void lookoutView(Sea seas[], int gameVars[]) {
int i, j;
int currentSea = gameVars[CURRENT_SEA];
   printf("\n    1 2 3 4 5 6 7 8 9 10\n");
   for (i = 0; i < SEA_DIMENSION; i++) {
      printf("%2d  ", i + 1);
      for (j = 0; j < SEA_DIMENSION; j++) {
          printf("%c ", seas[currentSea].pos[i][j]);
      }
      puts("");
   }
} 

/* Creates seven empty seas. */
void initSeas(Sea seas[]) {
   int i, j, k;
   for (i = 0; i < NUMBER_OF_SEAS; i++) {
      for (j = 0; j < SEA_DIMENSION; j++) {
         for (k = 0; k < SEA_DIMENSION; k++) {
            seas[i].pos[j][k] = '.';
         }
      }
   }
}

   
