#include "redbeard.h"
#include "setup.h"
#include "utilities.h"




/* Gets info for readHelpFile(). */
void dohelpfile() {
   char buffer[3];
   FILE *infile = fopen("helpfile", "r");
   printf("Help with which command?: ");
   /*fgets(buffer, 3, stdin);
   if (buffer[strlen(buffer) -1] != '\n') {
      clearInput();
   }
   buffer[0] = toupper(buffer[0]);
   buffer[1] = '\0';*/
   getOrder(buffer, 1);
   readHelpfile(infile, buffer);
   fclose(infile);
}

/* Reads command explanation from fp (helpfile).
 * Explanations are terminated by a line containing "#". */
void readHelpfile(FILE *fp, char *command) {
   char temp[100];
   fgets(temp, 20, fp);
   temp[strlen(temp) - 1] = '\0';
   
   /* Find the command in the file. */
   while (strcmp(temp, command) != 0 && !feof(fp)) {
      fgets(temp, 20, fp);
      temp[strlen(temp) - 1] = '\0';
   }
   /*puts(temp);*/
   puts("");  /* Just a newline. */
   
   /* Print the command explanation. */
   fgets(temp, 100, fp);
   temp[strlen(temp) - 1] = '\0';
   
   while (strcmp(temp, "#") != 0 && !feof(fp)) {
      puts(temp);
      fgets(temp, 100, fp);
      temp[strlen(temp) - 1] = '\0';
   }
}

/* Returns a random number between 0 and max. */
/* Begins with a capital R to avoid confict with
 * long random() from stdlib.h */
int Random(int max) {
   return rand() % max;
} 

void strtoupper(char *string) {
   int i;
   for (i = 0; i < strlen(string); i++) {
      string[i] = toupper(string[i]);
   }
} 

