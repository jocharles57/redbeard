#include "redbeard.h"
#include "setup.h"
#include "utilities.h"

int main(void) {
   Sea seas[NUMBER_OF_SEAS];
   int gameVars[NUMBER_OF_GAMEVARS];
   char order[1 + 2];  /* One for the order, two more for testing. */
   
   int keepLooping = 1;
   gameVars[CURRENT_SEA] = 0;  
   
   showPrologue();
   setUp(seas, gameVars);
   showOrders();
   
   /* Here we go loop de game loop ... */
   while (keepLooping) {
      printf("\nOrder, cap'n?: ");
      getOrder(order, 1);
      fulfilOrder(seas, gameVars, order[0]);
      if (order[0] == 'X') {
         printf("Exiting ...\n");
         break;
      }
   }
   exit(0); 
}

void showPrologue(void) {
   printf("\n***** REDBEARD - SCOURGE OF THE SEVEN SEAS *****\n\n"
          "YOU ARE REDBEARD, TERROR OF THE SEAS. YOUR MISSION\n"
          "IS TO RAID AS MANY MERCHANT SHIPS AS YOU CAN, AND\n"
          "CARRY OFF THEIR GOLD.\n"
          "ATTACK AND DESTROY ANY WARSHIPS IN THE VICINITY.\n"
          "GOOD HUNTING!!\n\n");
}


/* Show the menu. */
void showOrders() {
   printf("\n");
   printf("L = LOOKOUT'S VIEW        S = SAIL\n");
   printf("F = FIRE CANNON           B = BROADSIDE\n");
   printf("R = REPORT                D = REPAIR DAMAGE\n");
   printf("A = ALL SEAS VIEW         X = EXIT\n");
   printf("H = HELP\n");

}

/* Get an order from stdin. If input is too long, 
   take first char and clear the input buffer. */
void getOrder(char buffer[], int length) {
   int extras = 2;
   fgets(buffer, length + extras, stdin);
   if (buffer[strlen(buffer) -1] != '\n') {
      clearInput();
   }
   strtoupper(buffer);
   buffer[strlen(buffer) -1] = '\0';
}

/* Clear the stdin buffer of extraneous input. */
void clearInput() {
   while (getchar() != '\n') {
      ; /* do nothing */
   }
}

/* Do the order. */
void fulfilOrder(Sea seas[], int *gameVars, char c){
   printf("\nAye aye, cap'n ...\n");
   switch (c) {
   case 'L': lookoutView(seas, gameVars); break;
   case 'S': sail(seas, gameVars); break;
   case 'F': fireCannon(); break;
   case 'B': broadside(); break;
   case 'R': report(); break;
   case 'D': repairDamage(); break;
   case 'A': allSeasView(seas); break;
   case 'H': dohelpfile(); break;
   case 'X': /* do clean up */; break;
   default: printf("Not an order. Use one of these:\n");
            showOrders();
   }
}

void lookoutView(Sea seas[], int *gameVars) {
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

void allSeasView(Sea seas[]) {
   int i /*, j, k*/ ;
   for (i = 0; i < NUMBER_OF_SEAS; i++) {
      printf("    Sea #%d", i+1);
      lookoutView(seas, &i);
      puts("\n");
   }
}

void sail(Sea seas[], int *gameVars) {
   char buffer[2 + 1];
   /* Clear redbeard's current position. */
   int currentSea = gameVars[CURRENT_SEA];
   int redx = gameVars[RED_X];
   int redy = gameVars[RED_Y];
   seas[currentSea].pos[redy][redx] = '.';
   /* Ask for direction to sail. */
   printf("Which direction? (N, SW, etc): ");
   getOrder(buffer, 2);
   if (strcmp(buffer, "N") == 0) {
      gameVars[RED_Y] -= 1;
   }
   else if (strcmp(buffer, "NE") == 0) {
      gameVars[RED_X] += 1;
      gameVars[RED_Y] -= 1;
   }
   else if (strcmp(buffer, "E") == 0) {
      gameVars[RED_X] += 1;
   }
   else if (strcmp(buffer, "SE") == 0) {
      gameVars[RED_X] += 1;
      gameVars[RED_Y] += 1;
   }
   else if (strcmp(buffer, "S") == 0) {
      gameVars[RED_Y] += 1;
   }
   else if (strcmp(buffer, "SW") == 0) {
      gameVars[RED_X] -= 1;
      gameVars[RED_Y] += 1;
   }
   else if (strcmp(buffer, "W") == 0) {
      gameVars[RED_X] -= 1;
   }
   else if (strcmp(buffer, "NW") == 0) {
      gameVars[RED_X] -= 1;
      gameVars[RED_Y] -= 1;
   }
   else {
      puts("Not a direction.");
      return;
   } 
   
   /* Impose restrictions on movement. */
   /* No movement sideways beyond sea boundary. */
   if (gameVars[RED_X] < 0) {
      gameVars[RED_X] = 0;
      puts("You've reached the edge of the sea.");
   }
   if (gameVars[RED_X] > (SEA_DIMENSION - 1)) {
      gameVars[RED_X] = SEA_DIMENSION - 1;
      puts("You've reached the edge of the sea.");
   }
   /* Movement in Y direction past the sea boundaries
      moves into a new sea. */
   if (gameVars[RED_Y] < 0) {
      if (gameVars[CURRENT_SEA] < (NUMBER_OF_SEAS - 1)) {
         gameVars[CURRENT_SEA] += 1;
         gameVars[RED_Y] += SEA_DIMENSION;
         puts("Moving to a new sea!");
      }
      else {
         gameVars[RED_Y] = 0;
         puts("You've reached the edge of the sea.");
      }
   }
   if (gameVars[RED_Y] > (SEA_DIMENSION - 1)) {
      if (gameVars[CURRENT_SEA] > 0) {
         gameVars[CURRENT_SEA] -= 1;
         gameVars[RED_Y] -= SEA_DIMENSION;
         puts("Moving to a new sea!");
      }
      else {
         gameVars[RED_Y] = SEA_DIMENSION - 1;
         puts("You've reached the edge of the sea.");
      }
   }
   
   /* Set the new position. */
   printf("Setting course %s\n", buffer);
   setRedbeardPos(seas, gameVars);
   lookoutView(seas, gameVars);
}

void fireCannon(void) {
}

void broadside(void) {
}

void report(void) {
}

void repairDamage(void) {
}

