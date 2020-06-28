#ifndef SETUP_H
   #define SETUP_H

/* Function prototypes. */

/* setUp calls all the other set up functions. */
void setUp(Sea seas[], int *gameVars);

/* Creates seven empty seas. */
void initSeas(Sea seas[]);

/* Set number of Traders and Warships in the seas. */
void setTradersAndWarships(Sea seas[], int *gameVars);

/* Adds merchant ships and warships to the seas. */
void populateSeas(Sea seas[]);

/* Set intial position of Redbeard. */
void setInitialRedbeardPos(Sea seas[], int *gameVars);

void setRedbeardPos(Sea seas[], int *gameVars);

void initArray(int *array, size_t size);


#endif
