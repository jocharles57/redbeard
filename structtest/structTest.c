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

/* Clear the stdin buffer of extraneous input. */
void clearInput();


/* Main function. */
int main(void) {
   int i;
   Seaptr ptr;
   int numWarships = 5;
   
   /* Allocate memory for the sea. */
   ptr = malloc(sizeof(Sea));
   
   /* Allocate memory for the warships. */
   ptr->warships = malloc(numWarships * sizeof(Warship));
   
   /* Give each warship a name. */
   for (i = 0; i < numWarships; i++) {
      char name[SHIP_NAME_MAX_LENGTH];
      printf("Enter name: ");
      fgets(name, SHIP_NAME_MAX_LENGTH + 2, stdin);
      if (name[strlen(name) -1] != '\n') {
         clearInput();
      }
      name[strlen(name) - 1] = '\0';
      /* Allocate memory for the ship's name. */
      ptr->warships[i].name = malloc(strlen(name));
      /* Set the name of the ship. */
      strcpy(ptr->warships[i].name, name);
      
      /* Set the amount of ammunition. */
      ptr->warships[i].ammunition = 10;
      
   }
   
   /* Print out the ships names. */
   printf("WARSHIP         AMMUNITION\n");
   printf("--------------------------\n");
   for (i = 0; i < numWarships; i++) {
      printf("%-10s     %8d\n", ptr->warships[i].name, ptr->warships[i].ammunition);
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
void setTradersAndWarships(Sea seas[]) {
   int i;
   srand(time(NULL));
   for (i = 0; i< NUMBER_OF_SEAS; i++) {
      seas[i].numberOfTraders = Random(3) + 1;
      seas[i].numberOfWarships = Random(2) + 1;
   }
}

/* Adds merchant ships and warships to the seas. */
/** This needs serious rethinking. **/
void populateSeas(Sea seas[]) {
   int i, j;
   Trader trader;
   Warship warship;
   srand(time(NULL));
   
   for (i = 0; i < NUMBER_OF_SEAS; i++) {
      for (j = 0; j < seas[i].numberOfTraders; j++) {   
         trader.x = Random(10);
         trader.y = Random(10);
         seas[i].pos[trader.y][trader.x] = 'T';
      }
      for (j = 0; j < seas[i].numberOfWarships; j++) {
         warship.x = Random(10);
         warship.y = Random(10);
         seas[i].pos[warship.y][warship.x] = 'W';
      }
   }
}
   
