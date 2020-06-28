#ifndef UTILITIES_H
   #define UTILITIES_H
   
/* Utility functions. */


/* Gets info for readHelpFile(). */
void dohelpfile();

/* Reads command explanation from fp (helpfile).
 * Explanations are terminated by a line containing "#". */   
void readHelpfile(FILE *fp, char *command);   
  
/* Returns a random number between 0 and max. */
/* Begins with a capital R to avoid confict with
 * long random() from stdlib.h */
int Random(int max);

void strtoupper(char *string);
    
#endif
