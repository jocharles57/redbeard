#include "redbeard.h"
#include "setup.h"
#include "utilities.h"

/* Calls functions to initialise, populate,
 * and generally set up stuff. */
void setUp(Sea seas[], int *gameVars) {
   initSeas(seas);
   initArray(gameVars, NUMBER_OF_GAMEVARS);
   setTradersAndWarships(seas, gameVars);
   populateSeas(seas);
   setInitialRedbeardPos(seas, gameVars);
   
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

/* Set number of Traders and Warships in the seas. */
void setTradersAndWarships(Sea seas[], int *gameVars) {
   int i;
   srand(time(NULL));
   for (i = 0; i< NUMBER_OF_SEAS; i++) {
      /* Get a random number of traders and warships per sea. */
      seas[i].numberOfTraders = Random(3) + 1;
      seas[i].numberOfWarships = Random(2) + 1;
      /* Allocate memory for the traders and warships. */
      seas[i].traders = malloc(seas[i].numberOfTraders * sizeof(Trader));
      seas[i].warships = malloc(seas[i].numberOfWarships * sizeof(Warship));
      /* Add number of traders and warships to the game totals. */
      gameVars[TOTAL_TRADERS] += seas[i].numberOfTraders;
      gameVars[TOTAL_WARSHIPS] += seas[i].numberOfWarships;
   }
}

/* Adds traders and warships to the seas. */
void populateSeas(Sea seas[]) {
   int i, j;
   int x, y;
   srand(time(NULL));
   for (i = 0; i < NUMBER_OF_SEAS; i++) {
      for (j = 0; j < seas[i].numberOfTraders; j++) {   
         x = seas[i].traders[j].x = Random(10);
         y = seas[i].traders[j].y = Random(10);
         seas[i].pos[y][x] = 'T';
      }
      for (j = 0; j < seas[i].numberOfWarships; j++) {
         x = seas[i].warships[j].x = Random(10);
         y = seas[i].warships[j].y = Random(10);
         seas[i].pos[y][x] = 'W';
      }
   }
}

/* Set position of Redbeard. */
void setInitialRedbeardPos(Sea seas[], int *gameVars) {
   int x, y;
   int currentSea = gameVars[CURRENT_SEA];
   srand(time(NULL));
   x = gameVars[RED_X] = Random(10);
   y = gameVars[RED_Y] = Random(10);
	
   seas[currentSea].pos[y][x] = 'R';
}

void setRedbeardPos(Sea seas[], int *gameVars) {
   int x, y;
   int currentSea = gameVars[CURRENT_SEA];
   x = gameVars[RED_X];
   y = gameVars[RED_Y];
   seas[currentSea].pos[y][x] = 'R';
}
	 
void initArray(int *array, size_t size) {
   int i;
   for (i = 0; i < size; i++) {
      array[i] = 0;
   }
}

