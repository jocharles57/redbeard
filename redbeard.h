#ifndef REDBEARD_H
   #define REDBEARD_H
   
/* System wide header files. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Constants. */  
#define SEA_DIMENSION 10
#define NUMBER_OF_SEAS 7
#define NUMBER_OF_GAMEVARS 5
#define MAX_TRADERS_PER_SEA 3
#define MAX_WARSHIPS_PER_SEA 2

/* Structs and typedefs. */   
typedef struct trader {
   int gold;
   int damage;
   int x;
   int y;
} Trader;

typedef struct warship {
   int ammunition;
   int damage;
   int x;
   int y;
} Warship;

typedef struct sea* Seaptr; 

typedef struct sea {
   int pos[SEA_DIMENSION][SEA_DIMENSION];
   Trader *traders;
   Warship *warships;
   int numberOfTraders;
   int numberOfWarships;
   Seaptr nextSea;
} Sea; 

/* If this is varied, change NUMBER_OF_GAMEVARS to suit. */
enum game_vars {CURRENT_SEA, TOTAL_TRADERS, TOTAL_WARSHIPS, RED_X, RED_Y};
 
   
/* Function prototypes. */
void showPrologue(void);
void showOrders();
void getOrder(char buffer[], int length);
void fulfilOrder(Sea seas[], int *currentSea, char c);
void clearInput();

/* Function prototypes for orders. */
void lookoutView(Sea seas[], int *currentSea);
void sail();
void fireCannon();
void broadside();
void report();
void repairDamage();
void allSeasView(Sea seas[]);
 
#endif
